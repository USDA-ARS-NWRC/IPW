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
**	hnsamps -- number of samples in image line
**
** SYNOPSIS
**	#include "bih.h"
**
**	int
**	hnsamps(
**		int             fd)	|* image file descriptor	 *|
**
** DESCRIPTION
**	hnsamps determines the number of samples in the image currently being
**	read/written on file descriptor fd.
**
**	hnsamps may not be called before a BIH is read/written from/to fd.
**
** RETURN VALUE
**	number of samples in image line
**
** GLOBALS ACCESSED
**	_bih
*/

#include "ipw.h"
#include "_bih.h"

int
hnsamps(
	int             fd)		/* image file descriptor	 */
{
	ASSERT_OK_FD(fd);
	assert(_bih[fd] != NULL);

	return (bih_nsamps(_bih[fd][0]));
}
