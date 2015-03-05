
#include "ipw.h"
#include "pgm.h"

int
main(
    int             argc,
    char          **argv)
{

    static OPTION_T opt_b = {
                'b', "output image bits (default: 16)",
                INT_OPTARGS, "bits",
                OPTIONAL, 1, 1
        };

    static OPTION_T operands = {
        OPERAND, "input image file",
        STR_OPERANDS, "image",
        OPTIONAL, 1, 1,
    };

    static OPTION_T *optv[] = {
	&opt_b,
        &operands,
        0
    };

 /*
  * begin
  */
    ipwenter(argc, argv, optv, IPW_DESCRIPTION);
 /*
  * process options
  */
    if (got_opt(opt_b)) {
        parm.nbits = int_arg(opt_b, 0);
    } else {
        parm.nbits = 16;
    }

 /*
  * access input file(s)
  */
    if (!got_opt(operands)) {
        parm.i_fd = ustdin();
    }
    else {
        parm.i_fd = uropen(str_arg(operands, 0));
        if (parm.i_fd == ERROR) {
            error("can't open \"%s\"", str_arg(operands, 0));
        }
    }

    no_tty(parm.i_fd);
 /*
  * access output file
  */
    parm.o_fd = ustdout();
    no_tty(parm.o_fd);

 /*
  * do it
  */
    headers();
    norm();
    output();
 /*
  * end
  */
    ipwexit(EXIT_SUCCESS);
}
