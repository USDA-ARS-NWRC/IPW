/*
**	15-pt Kronrod quadrature pts and wts on [a,b], normalized to
**	produce average over tlen
**
**	weights and abscissae copied from quadpack
**/

static double   xgk_15[] = {
	0.0e+00,
	-0.4058451513773972e+00, 0.4058451513773972e+00,
	-0.7415311855993944e+00, 0.7415311855993944e+00,
	-0.9491079123427585e+00, 0.9491079123427585e+00,
	-0.2077849550078985e+00, 0.2077849550078985e+00,
	-0.5860872354676911e+00, 0.5860872354676911e+00,
	-0.8648644233597691e+00, 0.8648644233597691e+00,
	-0.9914553711208126e+00, 0.9914553711208126e+00
};

static double   wgk_15[] = {
	0.2094821410847278e+00,
	0.1903505780647854e+00, 0.1903505780647854e+00,
	0.1406532597155259e+00, 0.1406532597155259e+00,
	0.6309209262997855e-01, 0.6309209262997855e-01,
	0.2044329400752989e+00, 0.2044329400752989e+00,
	0.1690047266392679e+00, 0.1690047266392679e+00,
	0.1047900103222502e+00, 0.1047900103222502e+00,
	0.2293532201052922e-01, 0.2293532201052922e-01
};

/*
**	21-pt Kronrod quadrature pts and wts on [a,b], normalized to
**	produce average over tlen
*/

static double   xgk_21[] = {
	0.0000000000000000e+00,
	-0.1488743389816312e+00, 0.1488743389816312e+00,
	-0.4333953941292472e+00, 0.4333953941292472e+00,
	-0.6794095682990244e+00, 0.6794095682990244e+00,
	-0.8650633666889845e+00, 0.8650633666889845e+00,
	-0.9739065285171717e+00, 0.9739065285171717e+00,
	-0.2943928627014602e+00, 0.2943928627014602e+00,
	-0.5627571346686047e+00, 0.5627571346686047e+00,
	-0.7808177265864169e+00, 0.7808177265864169e+00,
	-0.9301574913557082e+00, 0.9301574913557082e+00,
	-0.9956571630258081e+00, 0.9956571630258081e+00,
};

static double   wgk_21[] = {
	0.1494455540029169e+00,
	0.1347092173114733e+00, 0.1347092173114733e+00,
	0.1477391049013385e+00, 0.1477391049013385e+00,
	0.1093871588022976e+00, 0.1093871588022976e+00,
	0.9312545458369761e-01, 0.9312545458369761e-01,
	0.1427759385770601e+00, 0.1427759385770601e+00,
	0.1234919762620659e+00, 0.1234919762620659e+00,
	0.3255816230796473e-01, 0.3255816230796473e-01,
	0.9312545458369761e-01, 0.9312545458369761e-01,
	0.5475589657435200e-01, 0.5475589657435200e-01,
	0.1169463886737187e-01, 0.1169463886737187e-01,
};
