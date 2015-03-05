#  For now, this file should define the local configuration

#  The full paths to the various shells and interpreters

SH=/bin/sh
AWK=/usr/bin/awk
SED=/usr/bin/sed
PERL=/usr/bin/perl

#  This needs to be a standard C compiler
CC=gcc

#  The graph command is used by the grhist command
GRAPH=

#  If GNU C Compiler, does it have the -iquote option?
GCC_HAS_IQUOTE=yes

#  The site-specific include file
include $(IPW)/conf/site.mk
