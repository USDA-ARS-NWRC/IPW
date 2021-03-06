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
**	orhread -- read an IPW ORH header
**
** SYNOPSIS
**	#include "orh.h"
**
**	ORH_T **
**	orhread(
**		int     fd)		|* image file descriptor	 *|
**
** DESCRIPTION
**	orhread reads a ORH image header from file descriptor fd.  An array
**	of ORH_T pointers is allocated, one per band.  If a band has a ORH
**	header, then an ORH_T header is allocated and its address is placed
**	in the corresponding array element; otherwise, the corresponding
**	array element is NULL.
**
**	Before calling orhread, the caller must verify (by calling hrname())
**	that a ORH header is available for ingesting.
**
**	orhread is called by application programs to ingest ORH headers.
**
** RETURN VALUE
**	pointer to array of ORH_T pointers; else NULL if EOF or error
**
** ERRORS
**	can't allocate array of "or" header pointers
**	"or" header: bad band "{band}"
**	can't allocate "or" header
**	"or" header: key "{key}" has no value
**	"or" header: bad key "{key}"
*/

#include <string.h>

#include "ipw.h"
#include "hdrio.h"
#include "bih.h"
#include "orh.h"
#include "_orh.h"

ORH_T **
orhread(
	int             fd)		/* image file descriptor	 */
{
	char           *hname;		/* current header name		 */
	int             nbands;		/* # bands			 */
	ORH_T         **orhpp;		/* -> array of ORH pointers	 */

 /*
  * allocate array of header pointers
  */
	nbands = hnbands(fd);
	assert(nbands > 0);

 /* NOSTRICT */
	orhpp = (ORH_T **) hdralloc(nbands, sizeof(ORH_T *), fd, ORH_HNAME);
	if (orhpp == NULL) {
		return (NULL);
	}
 /*
  * loop through per-band headers
  */
	while ((hname = hrname(fd)) != NULL && streq(hname, ORH_HNAME)) {
		int             band;	/* current header band #	 */
		int             err;	/* hgetrec return value		 */
		ORH_T          *orhp;	/* -> current ORH		 */

		char            key[HREC_MAX + 1];	/* keyword	 */
		char            value[HREC_MAX + 1];	/* value string	 */

 /*
  * get header band #
  */
		band = hrband(fd);
		if (band < 0 || band >= nbands) {
			uferr(fd);
			usrerr("\"%s\" header: bad band \"%d\"",
			       ORH_HNAME, band);
			return (NULL);
		}
 /*
  * allocate header
  */
 /* NOSTRICT */
		orhp = (ORH_T *) hdralloc(1, sizeof(ORH_T), fd, ORH_HNAME);
		if (orhp == NULL) {
			return (NULL);
		}

		orhpp[band] = orhp;
 /*
  * ingest records
  */
		while ((err = hgetrec(fd, (char *) NULL, key, value))
		       == HGOT_DATA) {
 /*
  * ignore all-comment records
  */
			if (key[0] == EOS) {
				continue;
			}
 /*
  * barf if missing value
  */
			if (value[0] == EOS) {
				uferr(fd);
				usrerr("\"%s\" header, key \"%s\": no value",
				       ORH_HNAME, key);
				return (NULL);
			}
 /*
  * match key to header field, ingest value
  */
			if (streq(key, ORH_OR)) {
				orhp->orient = strdup(value);
				if (orhp->orient == NULL) {
					return (NULL);
				}
			}
			else if (streq(key, ORH_ORIGIN)) {
				orhp->origin = strdup(value);
				if (orhp->origin == NULL) {
					return (NULL);
				}
			}
 /*
  * ignore unrecognized keys
  */
		}

		if (err == ERROR) {
			return (NULL);
		}
	}

	if (hname == NULL) {
		return (NULL);
	}
 /*
  * verify the header
  */
	if (!_orhcheck(orhpp, nbands)) {
		uferr(fd);
		return (NULL);
	}

	return (orhpp);
}
