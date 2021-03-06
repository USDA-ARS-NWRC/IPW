#  shell script to make help file for "bin_dir"

cat << END
all		Make all the commands, their man pages and the lists of
		  of commands (default).
cmd		Make all the commands.
install-cmd	Make and install all the commands.
install		Install all the commands, their man pages, and any auxiliary
		  scripts and files.

man		Make the HTML and troff man pages for all the commands.
install-man	Install the HTML and troff man pages.
uninstall-man	Uninstall the HTML and troff man pages.
clean-man	Remove the HTML and troff man pages from the directories
		  where man pages are made.
cmd-list	Make or update the text and HTML files with the list of all
		  the commands.
redo-cmd-list	Remake the text and HTML files with the list of all the
		  commands.

clean		Remove all copies of commands from their source directories,
		  their object files, their debugging versions, and their
		  man pages.
uninstall	Uninstall the commands, along with their HTML and troff
		  man pages.
END
