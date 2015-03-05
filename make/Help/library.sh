#  shell script to make help file for "library"

cat << END
all		Make the library, the functions' man pages and the lists of
		  of functions.  (default target)
library		Make the library.
funcs		Make the object files for all the functions' source
		  files.
add-funcs	Add the object files into the library.
install		Install the library, the include files and the man pages.
install-lib	Install the library and its include files.
delete-funcs	Delete the object files from the library.

man		Make the HTML and troff man pages for the public functions.
install-man	Install the HTML and troff man pages.
uninstall-man	Uninstall the HTML and troff man pages.
clean-man	Remove the HTML and troff man pages from the directories
		  where man pages are made.
func-list	Make or update the text and HTML files with the list of
		  all the functions by category.
redo-func-list	Remake the text and HTML files with the list of all the
		  functions by category.

debug		Make a debugging version of the library.
install-debug	Install the debugging version of the library.
clean-debug	Remove all the debugging versions of the object files.

clean-objs	Remove all the object files.
clean		Remove all object files, their debugging versions, and
		  their man pages.
uninstall	Uninstall the library, the include files and the man pages.
uninstall-lib	Uninstall the library and its include files.
uninstall-debug Uninstall the debugging version of the library.
END
