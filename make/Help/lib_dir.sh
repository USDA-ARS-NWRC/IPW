#  shell script to make help file for "lib_dir"

cat << END
all		Make all the libraries, their man pages and the lists of
		  functions (default).
libs		Make all the libraries.
install		Install the libraries, their include files and man pages.
install-libs	Install the libraries and their include files.

funcs		Make all the functions.
add-funcs	Add all the functions to their respective libraries.
delete-funcs	Remove the functions from their respective libraries.

man		Make the HTML and troff man pages for all the functions.
install-man	Install the HTML and troff man pages.
uninstall-man	Uninstall the HTML and troff man pages.
clean-man	Remove the HTML and troff man pages from the directories
		  where man pages are made.

lib-list	Make the text and HTML files with the list of libraries.
		  (Only available for non-standard libraries)

debug		Make debugging versions of the libraries.
install-debug	Install the debugging libraries.
clean-debug	Remove the debugging versions of the libraries.
uninstall-debug	Uninstall debugging libraries.

clean		Remove all built libraries, object files, and the built
		  man pages.
uninstall	Uninstall the libraries, their include files and man pages.
uninstall-libs	Uninstall the libraries and their include files.
END
