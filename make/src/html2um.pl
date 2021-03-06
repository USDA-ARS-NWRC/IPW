#  NAME
#	html2um - convert IPW HTML man page to Unix man page
#
#  SYNOPSIS
#	html2un name section date left-footer main-header
#
#  DESCRIPTION
#	A perl script to convert an HTML version of an IPW man page into a
#	Unix man page, i.e., a troff document.
#
#	The script reads the HTML man page from standard input and writes the
#	Unix man page to standard output.
#
#  OPERANDS
#
#	The operands define the arguments for the .TH macro in the output.
#	The .TH macro defines the title of the man page.
#
#  	name	    = the name of the man page
#  	section	    = the section of the manual pages this man page belongs to
#			use 1 for commands
#			use 3 for functions
#  	date 	    = date the man page was last revised
#  	left-footer = left portion of the footer that appears on each page
#			of the man page (usually IPW version, e.g., IPW v2.0)
#  	main-header = main (center) portion of the header that appears on each
#			page of the man page
#			  use "IPW User Commands" if section = 1
#			  use "IPW Library Functions" if section = 3


#  construct the .TH macro from the arguments
#  quote the arguments because they have whitespace, e.g.,
#  {date} = 1 April 1997
$THmacro = ".TH" ;
while ($arg = shift @ARGV) {
	$THmacro .= " \"$arg\"" ;
}

$replacePP = ".PP";
$inPRE = 0;
$ULcount = 0;
$ULleader = "\n.sp";
$inADDRESS = 0;
$b4NAME = 1;

while (<>)
	{
	chop;

	#  Ignore any comments
	next if /^<!--/;

	#  Ignore all the document before the NAME section
	if (/<H2>\s*NAME/) {
	    s%^%$THmacro\n%;
	    $b4NAME = 0;
	    }
	next if $b4NAME;

	#  Remove the paragraph with the horizontal line above the ADDRESS
	s%<P><HR></P>%%g;

	#  Remove all the ADDRESS of the document
	s%<ADDRESS>.*%% and $inADDRESS = 1;
	s%.*</ADDRESS>%% and $inADDRESS = 0;
	next if $inADDRESS;


	#  Escape any backslashes
	s%\\%\\\\%g;

	#  Font tags
	s%<B>%\\fB%g;
	s%</B>%\\fP%g;

	s%<I>%\\fI%g;
	s%</I>%\\fP%g;

	s%<SAMP>%\\f(CR%g;
	s%</SAMP>%\\fP%g;

	#  Header tags
	s%<H1 [^>\n]*>.*%$THmacro%;
	s%</H1>%%;

	s%<H2>%.SH % and ($inSYNOPSIS = m%.SH\s+SYNOPSIS%);
	s%</H2>%%;

	#  Remove the line containing the IPW group
	s%<P ALIGN=CENTER>IPW.*%%;

	#  Text blocks: paragraphs, lists, preformated blocks
	s%<BR>%\n.br\n%;

	s%<P>%\n$replacePP\n%;
	s%</P>%%;

	s%<PRE>%\n.sp\n.nf\n.ft CR\n% and $inPRE = 1;
	s%</PRE>%.ft R\n.fi\n% and $inPRE = 0;

	s%<DL>%% and $replacePP = ".sp";
	s%</DL>%% and $replacePP = ".PP";

	s%<DT>%\n.HP\n.na\n% if $inSYNOPSIS;
	s%<DT>%\n.TP\n% if ! $inSYNOPSIS;
	s%</DT>%%;

	#  Unordered lists just become indented paragraphs
	#  put a single line above the start of an outer-level list
	s%<UL>%\n.sp\n.RS\n% and $ULcount++ if $ULcount == 0;
	s%<UL>%\n.RS\n% and $ULcount++ if $ULcount != 0;

	s%<LI>%%;
	s%</LI>%\n.br\n%;


	#  Remove all other unknown HTML tags
	s%</?\w+( [^>]*)?>%%g;

	#  Convert special character notation to their actual characters
	s%&lt;%<%g;
	s%&gt;%>%g;
	s%&quot;%"%g;
	s%&nbsp;%\\ %g;
	s%&amp;%\&%g;

	#  Omit any extra leading newlines (don't want blank lines in output)
	s%^\s*\n+%%;

	#  Trim trailing whitespace
	s%\s+$%%;

	if (! $inPRE) {
		next if /^\s*$/;
	}

	print "$_\n";
}
