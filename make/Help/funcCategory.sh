#  shell script to make help file for "funcCategory"

cat << END
all		Compile all the functions, add them to the library, and
		  make their man pages and the lists of of functions
		  (default target).
funcs		Make the object files for all the functions' source
		  files.
add-funcs	Add the object files into the library.
install		Install the include files and the man pages.
delete-funcs	Delete the object files from the library.

man		Make the HTML and troff man pages for the public functions.
install-man	Install the HTML and troff man pages.
uninstall-man	Uninstall the HTML and troff man pages.
man-dirs	Make the directories where the man pages reside (Man/{func}),
		  and in each directory, create initial copies of the man
		  page and Makefile.
clean-man	Remove the HTML and troff man pages from the directories
		  where man pages are made.
func-list	Make or update the text and HTML files with the list of
		  the functions in this category.
redo-func-list	Remake the text and HTML files with the list of this
		  this category's functions.

debug		Make debugging versions of the object files in the
		  subdirectory "Debug", and add these object
		  files into the debugging version of the library.
clean-debug	Remove all the debugging versions of the object files.

clean-objs	Remove all the object files.
clean		Remove all object files, their debugging versions, and
		  their man pages.
uninstall	Uninstall the include files and the man pages.
END
