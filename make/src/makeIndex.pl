#  A perl script to generate the index for IPW user commands.
#
#  Synopsis
#	{script} {dir} ...
#
#  The list of directories are assumed to command categories.
#  The script fetchs the list of commands for each category from the
#  category's "Makefile".  For each command, the script fetches its
#  description from its "NameDesc.txt" file.
#
#  In the source directory for each command, the script searches
#  the keyword phrase file "Keywords".  Its format is one keyword
#  phrase per line.
#
#  The output is written to standard output.  The output is an HTML
#  document which is an alphabetical index of the keywords and
#  the commands.
#
#  The script outputs each category directory to standard error,
#  to give the user an idea of its progress.


print STDERR "Building index ...\n";

#  Loop through each category directory
foreach $dir (@ARGV) {
    print STDERR "  directory: $dir ...\n";

    #  Loop through each command's source directory
    foreach $cmd (split /\s+/,
		     `make --no-print-directory -f $dir/Makefile print-dirs`) {

	#  Fetch the command's description
	$file = "$dir/$cmd/NameDesc.txt";
	if (-r $file) {
	    ($desc = `cat $file`) =~ s/^\S+\s+-\s+//;
	     $desc =~ s/\s+$//;
	} else {
	    $desc = '';
	}
	$Commands{$cmd} = $desc;

	#  Load in the keywords file
	$file = "$dir/$cmd/Keywords";
	if (-r $file) {
	    @keywds = `cat $file`;

	    #  For each keyword,
	    #	  insert it into the master alphabetic list
	    #	  add current command to its list
	    foreach $keywd (@keywds) {
		chop $keywd;
		if (defined($Keywords{$keywd})) {
		    push @{ $Keywords{$keywd} }, $cmd;
		} else {
		    $Keywords{$keywd} = [ $cmd ] ;
		}
	    }

	    #  For each keyword
	}
    }  # foreach command
}  # foreach category


#  Print top of HTML document
print "<P ALIGN=CENTER>\n<TT>\n\n";

foreach $letter ('A' .. 'Z') {
    print '&nbsp;&nbsp;<A HREF="#', $letter, '">', $letter, "</A>\n";
    print "<BR><BR>\n" if $letter eq 'M';
}

print "</TT>\n<P>\n\n";


#  Make a master sorted list of commands and keywords
@Everything = sort((keys %Commands), (keys %Keywords));

#  Loop through the alphabet, printing those items starting with each letter

$item = shift @Everything;
$first = substr($item, 0, 1);
$first =~ tr/a-z/A-Z/;

$manDir = '../man1/';

foreach $letter ('A' .. 'Z') {
    print "\n", '<H2><A NAME="', $letter, '">', $letter, "</A></H2>\n";
    print "<UL>\n";

    #  Print those items starting with this letter
    while ($first eq $letter) {
	if (defined $Commands{$item}) {
	    print '  <LI><A HREF="', $manDir, $item, '.html">', $item,
		  "</A> -\n\t", $Commands{$item}, "\n";
	} else {
	    print '  <LI>', $item, "\n    <UL>\n";
	    foreach $cmd (@{ $Keywords{$item} }) {
		print '    <LI><A HREF="', $manDir, $cmd, '.html">', $cmd,
		      "</A>\n";
	    }
	    print "    </UL>\n";
	}
	$item = shift @Everything;
	$first = substr($item, 0, 1);
	$first =~ tr/a-z/A-Z/;
    }  # while

    print "</UL>\n";
}  # foreach letter

exit 0;
