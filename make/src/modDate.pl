#  NAME
#	modDate - print modification date-time for a file
#
#  SYNOPSIS
#	modDate [-t] file ...
#
#
#  DESCRIPTION
#	modDate prints the modification date-time of each file
#	specified.  If only 1 file is specified, its modification
#	date-time is written to standard output on a single line.  If
#	more than 1 file is specified, then the script writes an output
#	line for each file in this format:
#
#		filename: date-time
#
#	If a file does not exist, its modification date-time is printed
#	as "?".
#
#  OPTIONS
#	-t	This causes the full date-time to be printed in this
#		format:
#
#			month day, year time
#
#		where the month is a 3-letter abbreviation.  The default
#		format just prints the date portion as:
#
#			day month year
#
#		where month is the full name of the month, e.g. January.
#
#  OPERANDS
#	file	A file whose modification date will be printed.
#
#  EXAMPLES
#	If the current directory contained the following files:
#
#	     % ls -l
#	     -rw-r--r--   1 ipw      usgs          171 Aug  7  1992 Makefile
#	     -rw-r--r--   1 ipw      usgs         4983 May 23  1996 main.c
#	     -rwxrwxr-x   1 ipw      usgs        56232 Mar 31 14:53 a.out
#
#
#	then, here's how to print the modification dates for all the
#	files:
#
#	     % modDate *
#	     Makefile: 7 August 1992
#	     main.c: 23 May 1996
#	     a.out: 31 March 1997
#
#	To display the dates and times for all the files:
#
#	     % modDate -t *
#	     Makefile: Aug 7, 1992 03:45
#	     main.c: May 23, 1996 22:01
#	     a.out: Mar 31, 1998 14:53
#
#	To display just a single file's modification date:
#
#	     % modDate main.c
#	     23 May 1996
#
#  FILES
#	None.
#
#  DIAGNOSTICS
#	None.
#
#  HISTORY
#	Mar 1997
#	     Written by J. Domingo, OSU
#
#	Jan 1999
#	     Added the -t option.  J. Domingo, OSU
#
#  SEE ALSO
#	Unix:
#	     ls


@monthNames = (January, February, March, April, May, June, July, August,
		September, October, November, December);

if ($ARGV[0] eq "-t") {
   shift @ARGV;
   $printTime = 1;
} else {
   $printTime = 0;
}

$numArgs = scalar(@ARGV);
if ($numArgs > 1) {
    $printName = 1;
} elsif ($numArgs == 1) {
    $printName = 0;
} else {
    printf STDERR "Usage: $0 [ -t ] file ...\n";
    exit 1;
}

foreach $file (@ARGV) {
    if (! -e $file) {
	print "$file: " if $printName;
	print "?\n";
    } else {
	#  Get the date the file was last modified
	if (! ($modTime = (stat _)[9])) {
	    print "$file: " if $printName;
	    print "?\n";
	} else {
	    ($sec, $min, $hour, $mday, $mon, $year, $wday, $yday, $isdst) =
			localtime($modTime);
	    $month = $monthNames[$mon];
	    $year += 1900;
	    print "$file: " if $printName;
	    if ($printTime) {
		print substr($month, 0, 3), " $mday, $year ";
		printf "%02d:%02d\n", $hour, $min;
	    } else {
		print "$mday $month $year\n";
	    }
	}
    }
}  # foreach

exit 0;
