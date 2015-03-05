#  This is a Perl script to format the names and descriptions in a command
#  or library function category.  The script reads from standard input,
#  and assumes that each input line is of the form:
#
#	name whitespace description
#
#  The name must not contain any whitespace characters.  The description
#  can contain whitespace (in fact, it almost always does).
#
#  This script determines the length of the longest name, and
#  then prints each input line to standard output with each description
#  aligned.  For example, if the input is:
#
#	ipw - list IPW commands
#	cnhist.all - cumulative normalized histogram of one or more images
#	prhdr - print IPW image headers
#
#  then, the output would be:
#
#	  ipw        - list IPW commands
#	  cnhist.all - cumulative normalized histogram of one or more images
#	  prhdr      - print IPW image headers
#
#  Note that each output line has 2 spaces before the name.


#  Loop through input lines, determine longest name, and save lines.
$length = 0;
while (<>) {
    chop;
    if (/^(\S+)\s+/) {
	if (length($1) > $length) {
	    $length = length($1);
	}
	push @names, $1;
	$descriptions{$1} = $';
    }
}

#  Now output each name with its description in the proper format
foreach $name (@names) {
    printf "  %-${length}s %s\n", $name, $descriptions{$name};
}
