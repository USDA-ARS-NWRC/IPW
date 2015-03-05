/*
 * Copyright (c) 1990 The Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that: (1) source distributions retain this entire copyright
 * notice and comment, and (2) distributions including binaries display
 * the following acknowledgement:  ``This product includes software
 * developed by the Computer Systems Laboratory, University of
 * California, Santa Barbara and its contributors'' in the documentation
 * or other materials provided with the distribution and in all
 * advertising materials mentioning features or use of this software.
 *
 * Neither the name of the University nor the names of its contributors
 * may be used to endorse or promote products derived from this software
 * without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 */

/*
** NAME
**	syserr -- note occurrence of UNIX system error
**
** SYNOPSIS
**	void syserr()
**
** DESCRIPTION
**	Syserr notes the occurrence of a UNIX system error.  The current value
**	of "errno" is made accessible to the _error() error handler.
**
** GLOBALS MODIFIED
**	_errno
**
** APPLICATION USAGE
**	Call syserr() immediately after a UNIX system call returns an error
**	indication.
*/

/* LINTLIBRARY */

#include <errno.h>

#include "ipw.h"
#include "_error.h"

void
syserr(void)
{
	_errno = errno;
}
