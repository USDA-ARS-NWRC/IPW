/*
** NAME
**      pgmwrite -- writes a pgm image
**
** DESCRIPTION
**
*/
#include "ipw.h"
#include "pixio.h"
#include "pgm.h"

#define CBARSIZE 20

void
pgmwrite(void)
{
  pixel_t   * ibp;          /* pointer to image             */
  pixel_t   * mbp;          /* pointer to mask image        */
  char      * ob;
  char      * obp;
  long        line, samp;
  char        osbuf[100];


        /* allocate image input and output buffers */
 
  ob = (char *) ecalloc (parm.nsamps, sizeof (char));
  if (ob == NULL) {
    error ("Unable to allocate output buffer for image");
  }

  if (parm.cbar)
    (void) sprintf(osbuf, "%s\n%d %d\n%d\n",
                   "P5", parm.nsamps, parm.nlines+CBARSIZE+CBARSIZE, 255);
  else
    (void) sprintf(osbuf, "%s\n%d %d\n%d\n",
                   "P5", parm.nsamps, parm.nlines, 255);
  uputs(parm.output, osbuf);

  mbp = parm.maskd;
  ibp = parm.imd;
 
  for (line = 0; line < parm.nlines; line++) {
    obp = ob;
    if (parm.imask == ERROR)
      for (samp = 0; samp < parm.nsamps; samp++) {
        *obp++ = (char) parm.CLUT[*ibp].r;
        ibp++;
      }
    else
      for (samp = 0; samp < parm.nsamps; samp++) {
        if (*mbp++)
          *obp++ = (char) parm.CLUT[*ibp].r;
        else
          *obp++ = (char) parm.M.c.r;
        ibp++;
      }
    (void) uwrite(parm.output, (addr_t) ob, (int) (obp - ob) );
  }

  if (parm.cbar) {
    obp = ob;
    for (samp = 0; samp < parm.nsamps; samp++) {
      *obp++ = (char) parm.M.c.r;
    }
    for (line = 0; line < CBARSIZE; line++)
      (void) uwrite(parm.output, (addr_t) ob, (int) (obp - ob) );
    obp = ob;
    for (samp = 0; samp < parm.nsamps; samp++) {
      *obp++ = (char) parm.CLUT[samp * ipow2(parm.nbits) / parm.nsamps].r;
    }
    for (line = 0; line < CBARSIZE; line++)
      (void) uwrite(parm.output, (addr_t) ob, (int) (obp - ob) );
  }

  (void) free (ob);
}
