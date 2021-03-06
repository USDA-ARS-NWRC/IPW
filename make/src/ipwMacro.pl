#  NAME
#	ipwMacro - simple macro processor for text files
#
#  SYNOPSIS
#	ipwMacro [ -Dname=string ] ... [ file ] ...
#
#  DESCRIPTION
#	ipwMacro is a simple macro processor for text files.  It
#	scans one or more text files replacing each call to a macro
#	with its definition.  There are two formats for a macro
#	call:
#
#		%macro		%{macro}
#
#	where "macro" is the name of the macro.  A macro name is
#	a letter followed by zero or more letters, digits, and
#	underscores.  The second format for a macro call (which uses
#	braces) allows the macro's name to be delimited from the
#	following text that could be incorrectly interpreted as
#	part of the macro's name.
#
#	A macro call may have an optional list of arguments.  The
#	arguments are separated by commas, and the entire list is
#	enclosed in parentheses.  For example, here's a call to the
#	macro "foo" with 3 arguments.
#
#	    %foo(45,hello there,!!)
#
#	The left parenthesis "(" must immediately follow the macro's
#	name (or the right brace in the alternate call format).  If
#	whitespace preceeds the left parenthesis, the processor assumes
#	the macro call has no arguments.  The processor will only look
#	for an argument list if the macro call refers to a macro that
#	requires arguments.
#
#	If an argument is a string of text which contains a comma or
#	a right parenthesis ")", the argument must be quoted:
#
#	    %capitals("Boston, MA","Portland, OR","Columbus, OH")
#
#	The definition of a macro is a string of text that replaces each
#	call to that macro.  The string may be fixed, or it may vary
#	depend upon the arguments supplied to a macro call.
#
#	To refer to the arguments in a macro call, a macro's definition
#	uses one of these two notations:
#
#		%number			%{number}
#
#	where "number" is an unsigned integer that denotes the desired
#	argument.  Arguments are numbered from 1 on, so the first argument
#	is %1, the second argument is %2, and so on.  The notation %0
#	refers to the macro's name.
#
#	For example, if the macro "foo" is defined as the string
#	"There are %1 %{2} in the box.", then the macro call:
#
#	    %foo(7,foxes)
#
#	would be replaced with the string:
#
#	    There are 7 foxes in the box.
#
#	If a macro's definition refers to an argument that wasn't given
#	in a call to the macro, then the argument is assumed is to be
#	the empty string.
#
#	After a macro's definition has been scanned and arguments substituted,
#	the resulting string is then recursively scanned for additional
#	macro calls.  Hence, one macro may invoke one or more other macros
#	in its string.
#
#	Furthermore, the arguments themselves are scanned for macros
#	before they are substituted into the macro's definition.  The
#	exception to this is the macro "define" -- its arguments are
#	not scanned for macros.
#
#	These are the predefined macros:
#
#	    %define(name,string)
#
#		This macro defines a user-defined macro with the given
#		"name" (which must match the format for macro names noted
#		above), and whose definition is the given string.
#
#	    %include(file,...)
#
#		This macro causes the contents of the specified file(s)
#		to be included into the current file.  Each file's contents
#		are scanned for macro calls.
#
#	    %mod_date
#		This macro is defined as the modification date of the
#		input text file being scanned.  The date's format is:
#
#			day month-name year
#
#		For example, "7 February 1997".  Note: this macro is
#		defined as the empty string if the input file is standard
#		input.
#
#	If a macro call is found which contains a name which is neither
#	a pre-defined nor user-defined macro, the macro call is left
#	unchanged.
#
#	The list of input files specified as operands are scanned in
#	the given order.  The text resulting from the macro substitution
#	is written to standard output.  If no input files are specified,
#	then standard input is read.  Standard input can be explicitly
#	refered to by using "-" as an input filename.
#
#  OPTIONS
#	-Dname=string
#		Defines a macro called "name" as the given string.  This
#		is equivalent to the macro call:
#
#			%define(name,string)
#
#  OPERANDS
#	file	The name of the text file to scan (default: standard input)
#
#  HISTORY
#	Mar 1997
#	     "modDate" perl script written by J. Domingo, OSU
#
#	Feb 1998
#	     Rewrote original "ipwMacro" (which was a "sh" script invoking
#	     "sed") as a perl script.  Integrated the "modDate" script.
#	     J. Domingo, OSU
#
#	Apr 1998
#	     Reorganize the script to make the macro processor more powerful
#	     by adding arguments to macro calls, and also more simple by
#	     reducing # of pre-defined commands and options.  J. Domingo, OSU


#  Initialize constants

@MonthNames = (January, February, March, April, May, June, July, August,
		September, October, November, December);

$prefix = "%";

#  Make sure any non-alphanumeric characters are escaped in the prefix
#  to prevent them from being interpreted as meta-characters with pattern
#  operators.

$prefix =~ s/(\W)/\\$1/g;

$Usage = "Usage: $0 [ -Dname=string ... ] [ file ... ]\n";


#  Initialize global variables

%Predefined = (
		"define"	=>	"",
		"include"	=>	"",
		"mod_date"	=>	"",
	      );

%Macros = ();

%ArgLessMacros = (
		 "mod_date"	=>	"",
		 );

%MacroCalls = ();

%OpenFiles = ();

@OpenFileStack = ();


#  Process options

while ($arg = shift (@ARGV)) {
    if ($arg =~ /^-D/) {
	if ($arg =~ /^-D(.*)=(.*)$/) {
	    if (! define_macro($1, $2)) {
		print STDERR "$0: Error with command-line argument \"$arg\":\n";
		print STDERR "\t$Error\n";
		exit 1;
	    }
	} else {
	    print STDERR "$Usage";
	    exit 1;
	}
    }

    elsif ($arg =~ /^-./ ) {
	print STDERR "$0: Unknown option: $arg\n";
	print STDERR "$Usage";
	exit 1;
    }

    else {
	#  Done with options
	unshift @ARGV, $arg;
	last;
    }
}  # while


#  Scan each input file for macros
if ($#ARGV < 0) {
    scan_file("-");
} else {
    foreach $file (@ARGV) {
	scan_file($file);
    }
}

exit 0;

# ----------------------------------------------------------------------------
#
# subroutine: define_macro (name, string)
#
# This subroutine defines a macro with the "name" as the given "string".
# It is an error to attempt to redefine one of the predefined macros.

sub define_macro
{
    my $name = shift;
    my $string = shift;
    my $usesArgs = 0;	# does the macro use arguments?

    if ($name eq "") {
	$Error = "Empty string for macro name";
        return 0;
    }

    elsif ($name !~ /^[A-Za-z]\w*$/ ) {
	$Error = "Invalid macro name: \"$name\"";
        return 0;
    }

    elsif (defined($Predefined{$name})) {
	$Error = "Cannot redefine a predefined macro: \"$name\"";
        return 0;
    }


    #  Divide the macro's string into separate elements.  Each element
    #  is either a string or an argument reference.  Each argument reference
    #  is stored in a special format to distinguish it from a string: it
    #  has a formfeed character "\f" prepended to it.

    my @elements = ();
    while ($string ne "") {
	if ($string =~ /%(\d+)/ || $string =~ /%\{(\d+)\}/) {
	    push @elements, $` if $` ne "";
	    push @elements, "\f$1";
	    $string = $';
	    $usesArgs = 1;
	} else {
	    push @elements, $string;
	    $string = "";
	}
    }

    $Macros{$name} = [ @elements ];
    $ArgLessMacros{$name} = "" if ! $usesArgs;
    return 1;
}

# ----------------------------------------------------------------------------
#
# subroutine: print_macro (name)
#
# This subroutine print a macro's definition to standard error.

sub print_macro
{
    my $name = shift;
    my $element;

    if ($name eq "") {
	print STDERR "$0: Missing macro name in 'print_macro' subroutine\n";
        exit 1;
    }

    print STDERR "$name: ";
    if (defined($Predefined{$name})) {
	print STDERR "(predefined)\n";
    }

    elsif (! defined($Macros{$name})) {
	print STDERR "(undefined)\n";
    }

    else {
	print STDERR "\n";
	foreach $element ( @{$Macros{$name}} ) {
	    if ($element =~ /^\f(\d+)$/) {
		print STDERR "\targument: $1\n";
	    } else {
		print STDERR "\tstring: <$element>\n";
	    }
	}
    }
}

# ----------------------------------------------------------------------------
#
# subroutine: scan_file (fileName)
#
# This subroutine reads lines from the given file and scans each
# line for macros.  Macros are substituted with their definitions.
# If this is an input file, each line is written to standard output.
# If it's an include file, then all its lines are collected and
# returned as a single string.

sub scan_file
{
    my $fileName = shift;
    local *INPUT;

    my $includeFile;
    my $line;
    my $output;


    #  Is the filename in the list of currently open files?
    if (defined($OpenFiles{$fileName})) {
	error("Circular dependency detected among these files:",
	      join("\n\t", @OpenFileStack) );
    }

    if (! open (INPUT, $fileName)) {
	error("cannot open " . ($fileName eq "-" ? "standard input"
						 : "input file \"$fileName\""));
    }
    $OpenFiles{$fileName} = 1;
    push @OpenFileStack, $fileName;

    #  An input file or include file?
    if ($#OpenFileStack > 0) {
	$includeFile = 1;
    } else {
	$includeFile = 0;
    }

    if ($includeFile) {
	$output = "";
	while ($line = <INPUT>) {
	    $output .= scan_text($line);
	}
    }

    else {
	while ($line = <INPUT>) {
	    $output = scan_text($line);
	    print $output;
	}
    }

    close INPUT;
    undef $OpenFiles{$fileName};
    pop @OpenFileStack;

    return $output if $includeFile;
}

# ----------------------------------------------------------------------------
#
# subroutine: error (message_line [, ...])
#
# This subroutine prints an error message and exits the current script
# with status code 1.

sub error
{
    my $currenFile;
    my $line;

    #  Is there a file open?
    if ($currentFile = pop @OpenFileStack) {
	printf STDERR "$0: Error on line $. of %s:\n", 
			$currentFile eq "-" ? "standard input"
					    : "input file \"$currentFile\"";
	foreach $line (@_) {
	    print STDERR "\t$line\n";
	}
    }

    else {
	printf STDERR "$0: %s\n", shift @_;
	foreach $line (@_) {
	    print STDERR "\t$line\n";
	}
    }

    exit 1;
}

# ----------------------------------------------------------------------------
#
# subroutine: scan_text (string)
#
# This subroutine scans a string of text for macro calls.  After substituting
# each macro call, the resulting string is returned.

sub scan_text
{
    my $text = shift;
    my $macro;
    my $output = "";
    my @args;
    my $arg;
    my $quotedStr;
    my $element;
    my $defn;
    my $numDefs = 0;	# number of "define" macros encountered

    #  Look for the start of a macro call
    while ( $text =~ /$prefix([A-Za-z]\w*)/ ||
	    $text =~ /$prefix\{([A-Za-z]\w*)\}/ ) {
	$macro = $1;
	$text = $';

	#  Output text preceeding macro
	$output .= $`;

	#  If unknown macro, then just output the macro call as is,
	#  and go back to looking for next macro call.
	if (! defined($Macros{$macro}) && ! defined($Predefined{$macro})) {
	    $output .= $&;
	    next;
	    }

	#  Is this macro currently being called?
	if (defined($MacroCalls{$macro})) {
	    error("Circular dependency detected among these macros:",
		  join(', ' , (keys %MacroCalls)) );
	}
	$MacroCalls{$macro} = 1 if defined($Macros{$macro});

	#  Does the macro take an argument list?  If so, is
	#  there an argument list? (i.e., an immediate "(")
	@args = ();
	if ( ! defined($ArgLessMacros{$macro}) && $text =~ /^\(/ ) {
	    $text = $';

	    #  An argument is the sequence of characters and quoted
	    #  strings up to the terminating "," or ")".
	    #  A quoted string is zero or more characters and special
	    #  character notations surrounded by double quotes (").
	    #  A special character notation is the "\" character
	    #  followed by any other character (to allow double quotes
	    #  in a string).
	    $arg = '';
	    while (1) {
		if ( $text =~ /([,)"])/ ) {
		    $arg .= $`;
		    $text = $';
		    if ($& eq '"') {  # start of quoted string
			#  collect quoted string up to ending quote
			if ( $text =~ /^(([^\\"]|\\.)*)"/ ) {
			    $text = $';
			    ($quotedStr = $1) =~ s/\\(.)/$1/g;
			    $arg .= $quotedStr;
			    next;
			} else {
			    error("Incomplete quoted string in macro's" .
				  " argument list");
			}
		    } else {
			#  Done with the current argument.  Scan it for
			#  macros first.
			$arg = scan_text($arg) if $macro ne "define";
			push @args, $arg;
			$arg = '';
			last if ($& eq ")");
		    }
		} else {
		    error("Incomplete argument list for macro \"$macro\"");
		}
	   } # while reading argument list
	} # if arguments

	#  Check if macro is one of the predefined macros
	if ($macro eq "define") {
	    if ($#args != 1 ) {
		error("the macro \"define\" requires 2 arguments");
	    }
	    if (! define_macro($args[0], $args[1])) {
		error($Error);
	    }
	    $numDefs++;
	}

	elsif ($macro eq "include") {
	    #  Concatenate the contents of all the files listed as arguments
	    #  into a single string
	    foreach $arg (@args) {
		$output .= scan_file($arg);
	    }
	}

	elsif ($macro eq "mod_date") {
	    if ($#args != -1 ) {
		error("the macro \"mod_date\" requires no arguments");
	    }
	    #  Current input file is first file opened (bottom of the stack)
	    $output .= mod_date($OpenFileStack[0]);
	}

	else {
	    #  User-defined macro, so substitute the arguments into the
	    #  macro's definition
	    $defn = "";
	    foreach $element ( @{$Macros{$macro}} ) {
		if ($element =~ /^\f(\d+)$/) {
		    $defn .= ($1 == 0 ? $macro : $args[$1-1]);
		} else {
		    $defn .= $element;
		}
	    }
	    $output .= scan_text($defn);
	}

	#  Done with macro call.
	undef $MacroCalls{$macro};

    }  # while looking for macro calls

    $output .= $text;

    #  If we encountered 1 or more "define" macros, and the output
    #  is just a blank line, then return the empty string (i.e.,
    #  ignore the newline), so as not to have blank lines in output
    #  for lines in the input which just had "define" macros.
    if ($output =~ /^\s*\n$/ && $numDefs > 0) {
	$output = "";
    }

    return $output;
}

# ----------------------------------------------------------------------------
#
# subroutine: mod_date (fileName)
#
# This subroutine returns the modification date of the given file.

sub mod_date
{
    my $file = shift;
    my $modTime;

    if ($file eq "-") {
	return "";
    }

    #  Get the date the file was last modified
    if (! ($modTime = (stat $file)[9])) {
	return "";
    }

    local($sec, $min, $hour, $mday, $mon, $year, $wday, $yday, $isdst) =
							 localtime($modTime);
    my $month = $MonthNames[$mon];
    $year += 1900;
    "$mday $month $year";
}
