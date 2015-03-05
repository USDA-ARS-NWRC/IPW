/* nad83.h - 1983 datum state plane constants */
/* WARNING: the 1983 datum is incompatible with the 1927 formulae and GCTP and
 * should be used with newer the SPCS formulae instead, not yet available in C.
 * C version by Philip Thompson (phils@athena.mit.edu), 10/5/90.
 * Computer Resource Lab., Dept. Architecture and Urban Planning,
 * MIT, Cambridge MA  02139
 */
NadRec Nad83[] = {
{ "ALABAMA         EAST         ", 1, "NAD83",  101,
 { 6.378137000000000e+06,  6.694380022900000e-03, -8.550000000000000e+05,
   9.999600000000000e-01,  0.000000000000000e+00,  0.000000000000000e+00,
   3.030000000000000e+05,  2.000000000000000e+05,  0.000000000000000e+00}},
{ "ALABAMA         WEST         ", 1, "NAD83",  102,
 { 6.378137000000000e+06,  6.694380022900000e-03, -8.730000000000000e+05,
   9.999333333333333e-01,  0.000000000000000e+00,  0.000000000000000e+00,
   3.000000000000000e+05,  6.000000000000000e+05,  0.000000000000000e+00}},
{ "ALASKA          ZONE NO. 10  ", 2, "NAD83", 5010,
 { 6.378137000000000e+06,  6.694380022900000e-03, -1.760000000000000e+06,
   1.000000000000000e+00,  5.350000000000000e+05,  5.150000000000000e+05,
   5.100000000000000e+05,  1.000000000000000e+06,  0.000000000000000e+00}},
{ "SAMOA                        ", 0, "NAD83", 5302,
 { 6.378137000000000e+06,  6.694380022900000e-03, -1.700000000000000e+06,
   1.000000000000000e+00, -1.416000000000000e+05, -1.416000000000000e+05,
  -1.416000000000000e+05,  1.524003048006096e+05,  9.516931165862332e+04}},
{ "ARIZONA         EAST         ", 1, "NAD83",  201,
 { 6.378137000000000e+06,  6.694380022900000e-03, -1.101000000000000e+06,
   9.999000000000000e-01,  0.000000000000000e+00,  0.000000000000000e+00,
   3.100000000000000e+05,  2.133600000000000e+05,  0.000000000000000e+00}},
{ "ARIZONA         CENTRAL      ", 1, "NAD83",  202,
 { 6.378137000000000e+06,  6.694380022900000e-03, -1.115500000000000e+06,
   9.999000000000000e-01,  0.000000000000000e+00,  0.000000000000000e+00,
   3.100000000000000e+05,  2.133600000000000e+05,  0.000000000000000e+00}},
{ "ARIZONA         WEST         ", 1, "NAD83",  203,
 { 6.378137000000000e+06,  6.694380022900000e-03, -1.134500000000000e+06,
   9.999333333333333e-01,  0.000000000000000e+00,  0.000000000000000e+00,
   3.100000000000000e+05,  2.133600000000000e+05,  0.000000000000000e+00}},
{ "ARKANSAS        NORTH        ", 2, "NAD83",  301,
 { 6.378137000000000e+06,  6.694380022900000e-03, -9.200000000000000e+05,
   1.000000000000000e+00,  3.614000000000000e+05,  3.456000000000000e+05,
   3.420000000000000e+05,  4.000000000000000e+05,  0.000000000000000e+00}},
{ "ARKANSAS        SOUTH        ", 2, "NAD83",  302,
 { 6.378137000000000e+06,  6.694380022900000e-03, -9.200000000000000e+05,
   1.000000000000000e+00,  3.446000000000000e+05,  3.318000000000000e+05,
   3.240000000000000e+05,  4.000000000000000e+05,  4.000000000000000e+05}},
{ "CALIFORNIA      I            ", 2, "NAD83",  401,
 { 6.378137000000000e+06,  6.694380022900000e-03, -1.220000000000000e+06,
   1.000000000000000e+00,  4.140000000000000e+05,  4.000000000000000e+05,
   3.920000000000000e+05,  2.000000000000000e+06,  5.000000000000000e+05}},
{ "CALIFORNIA      II           ", 2, "NAD83",  402,
 { 6.378137000000000e+06,  6.694380022900000e-03, -1.220000000000000e+06,
   1.000000000000000e+00,  3.950000000000000e+05,  3.820000000000000e+05,
   3.740000000000000e+05,  2.000000000000000e+06,  5.000000000000000e+05}},
{ "CALIFORNIA      III          ", 2, "NAD83",  403,
 { 6.378137000000000e+06,  6.694380022900000e-03, -1.203000000000000e+06,
   1.000000000000000e+00,  3.826000000000000e+05,  3.704000000000000e+05,
   3.630000000000000e+05,  2.000000000000000e+06,  5.000000000000000e+05}},
{ "CALIFORNIA      IV           ", 2, "NAD83",  404,
 { 6.378137000000000e+06,  6.694380022900000e-03, -1.190000000000000e+06,
   1.000000000000000e+00,  3.715000000000000e+05,  3.600000000000000e+05,
   3.520000000000000e+05,  2.000000000000000e+06,  5.000000000000000e+05}},
{ "CALIFORNIA      V            ", 2, "NAD83",  405,
 { 6.378137000000000e+06,  6.694380022900000e-03, -1.180000000000000e+06,
   1.000000000000000e+00,  3.528000000000000e+05,  3.402000000000000e+05,
   3.330000000000000e+05,  2.000000000000000e+06,  5.000000000000000e+05}},
{ "CALIFORNIA      VI           ", 2, "NAD83",  406,
 { 6.378137000000000e+06,  6.694380022900000e-03, -1.161500000000000e+06,
   1.000000000000000e+00,  3.353000000000000e+05,  3.247000000000000e+05,
   3.210000000000000e+05,  2.000000000000000e+06,  5.000000000000000e+05}},
{ "CALIFORNIA      VII          ", 0, "NAD83",  407,
 { 6.378137000000000e+06,  6.694380022900000e-03, -1.182000000000000e+06,
   1.000000000000000e+00,  3.425000000000000e+05,  3.352000000000000e+05,
   3.408000000000000e+05,  1.276106450596901e+06,  1.268253006858014e+06}},
{ "COLORADO        NORTH        ", 2, "NAD83",  501,
 { 6.378137000000000e+06,  6.694380022900000e-03, -1.053000000000000e+06,
   1.000000000000000e+00,  4.047000000000000e+05,  3.943000000000000e+05,
   3.920000000000000e+05,  9.144018289000000e+05,  3.048006096000000e+05}},
{ "COLORADO        CENTRAL      ", 2, "NAD83",  502,
 { 6.378137000000000e+06,  6.694380022900000e-03, -1.053000000000000e+06,
   1.000000000000000e+00,  3.945000000000000e+05,  3.827000000000000e+05,
   3.750000000000000e+05,  9.144018289000000e+05,  3.048006096000000e+05}},
{ "COLORADO        SOUTH        ", 2, "NAD83",  503,
 { 6.378137000000000e+06,  6.694380022900000e-03, -1.053000000000000e+06,
   1.000000000000000e+00,  3.826000000000000e+05,  3.714000000000000e+05,
   3.640000000000000e+05,  9.144018289000000e+05,  3.048006096000000e+05}},
{ "CONNECTICUT     ---          ", 2, "NAD83",  600,
 { 6.378137000000000e+06,  6.694380022900000e-03, -7.245000000000000e+05,
   1.000000000000000e+00,  4.152000000000000e+05,  4.112000000000000e+05,
   4.050000000000000e+05,  3.048006096000000e+05,  1.524003048000000e+05}},
{ "DELAWARE        ---          ", 1, "NAD83",  700,
 { 6.378137000000000e+06,  6.694380022900000e-03, -7.525000000000000e+05,
   9.999950000000000e-01,  0.000000000000000e+00,  0.000000000000000e+00,
   3.800000000000000e+05,  2.000000000000000e+05,  0.000000000000000e+00}},
{ "FLORIDA         EAST         ", 1, "NAD83",  901,
 { 6.378137000000000e+06,  6.694380022900000e-03, -8.100000000000000e+05,
   9.999411764705882e-01,  0.000000000000000e+00,  0.000000000000000e+00,
   2.420000000000000e+05,  2.000000000000000e+05,  0.000000000000000e+00}},
{ "FLORIDA         WEST         ", 1, "NAD83",  902,
 { 6.378137000000000e+06,  6.694380022900000e-03, -8.200000000000000e+05,
   9.999411764705882e-01,  0.000000000000000e+00,  0.000000000000000e+00,
   2.420000000000000e+05,  2.000000000000000e+05,  0.000000000000000e+00}},
{ "FLORIDA         NORTH        ", 2, "NAD83",  903,
 { 6.378137000000000e+06,  6.694380022900000e-03, -8.430000000000000e+05,
   1.000000000000000e+00,  3.045000000000000e+05,  2.935000000000000e+05,
   2.900000000000000e+05,  6.000000000000000e+05,  0.000000000000000e+00}},
{ "GEORGIA         EAST         ", 1, "NAD83", 1001,
 { 6.378137000000000e+06,  6.694380022900000e-03, -8.210000000000000e+05,
   9.999000000000000e-01,  0.000000000000000e+00,  0.000000000000000e+00,
   3.000000000000000e+05,  2.000000000000000e+05,  0.000000000000000e+00}},
{ "GEORGIA         WEST         ", 1, "NAD83", 1002,
 { 6.378137000000000e+06,  6.694380022900000e-03, -8.410000000000000e+05,
   9.999000000000000e-01,  0.000000000000000e+00,  0.000000000000000e+00,
   3.000000000000000e+05,  7.000000000000000e+05,  0.000000000000000e+00}},
{ "HAWAII          1            ", 1, "NAD83", 5101,
 { 6.378137000000000e+06,  6.694380022900000e-03, -1.553000000000000e+06,
   9.999666666666667e-01,  0.000000000000000e+00,  0.000000000000000e+00,
   1.850000000000000e+05,  5.000000000000000e+05,  0.000000000000000e+00}},
{ "HAWAII          2            ", 1, "NAD83", 5102,
 { 6.378137000000000e+06,  6.694380022900000e-03, -1.564000000000000e+06,
   9.999666666666667e-01,  0.000000000000000e+00,  0.000000000000000e+00,
   2.020000000000000e+05,  5.000000000000000e+05,  0.000000000000000e+00}},
{ "HAWAII          3            ", 1, "NAD83", 5103,
 { 6.378137000000000e+06,  6.694380022900000e-03, -1.580000000000000e+06,
   9.999900000000000e-01,  0.000000000000000e+00,  0.000000000000000e+00,
   2.110000000000000e+05,  5.000000000000000e+05,  0.000000000000000e+00}},
{ "HAWAII          4            ", 1, "NAD83", 5104,
 { 6.378137000000000e+06,  6.694380022900000e-03, -1.593000000000000e+06,
   9.999900000000000e-01,  0.000000000000000e+00,  0.000000000000000e+00,
   2.150000000000000e+05,  5.000000000000000e+05,  0.000000000000000e+00}},
{ "HAWAII          5            ", 1, "NAD83", 5105,
 { 6.378137000000000e+06,  6.694380022900000e-03, -1.601000000000000e+06,
   1.000000000000000e+00,  0.000000000000000e+00,  0.000000000000000e+00,
   2.140000000000000e+05,  5.000000000000000e+05,  0.000000000000000e+00}},
{ "IDAHO           EAST         ", 1, "NAD83", 1101,
 { 6.378137000000000e+06,  6.694380022900000e-03, -1.121000000000000e+06,
   9.999473684210526e-01,  0.000000000000000e+00,  0.000000000000000e+00,
   4.140000000000000e+05,  2.000000000000000e+05,  0.000000000000000e+00}},
{ "IDAHO           CENTRAL      ", 1, "NAD83", 1102,
 { 6.378137000000000e+06,  6.694380022900000e-03, -1.140000000000000e+06,
   9.999473684210526e-01,  0.000000000000000e+00,  0.000000000000000e+00,
   4.140000000000000e+05,  5.000000000000000e+05,  0.000000000000000e+00}},
{ "IDAHO           WEST         ", 1, "NAD83", 1103,
 { 6.378137000000000e+06,  6.694380022900000e-03, -1.154500000000000e+06,
   9.999333333333333e-01,  0.000000000000000e+00,  0.000000000000000e+00,
   4.140000000000000e+05,  8.000000000000000e+05,  0.000000000000000e+00}},
{ "ILLINOIS        EAST         ", 1, "NAD83", 1201,
 { 6.378137000000000e+06,  6.694380022900000e-03, -8.820000000000000e+05,
   9.999750000000000e-01,  0.000000000000000e+00,  0.000000000000000e+00,
   3.640000000000000e+05,  3.000000000000000e+05,  0.000000000000000e+00}},
{ "ILLINOIS        WEST         ", 1, "NAD83", 1202,
 { 6.378137000000000e+06,  6.694380022900000e-03, -9.010000000000000e+05,
   9.999411764705882e-01,  0.000000000000000e+00,  0.000000000000000e+00,
   3.640000000000000e+05,  7.000000000000000e+05,  0.000000000000000e+00}},
{ "INDIANA         EAST         ", 1, "NAD83", 1301,
 { 6.378137000000000e+06,  6.694380022900000e-03, -8.540000000000000e+05,
   9.999666666666667e-01,  0.000000000000000e+00,  0.000000000000000e+00,
   3.730000000000000e+05,  1.000000000000000e+05,  2.500000000000000e+05}},
{ "INDIANA         WEST         ", 1, "NAD83", 1302,
 { 6.378137000000000e+06,  6.694380022900000e-03, -8.705000000000000e+05,
   9.999666666666667e-01,  0.000000000000000e+00,  0.000000000000000e+00,
   3.730000000000000e+05,  9.000000000000000e+05,  2.500000000000000e+05}},
{ "IOWA            NORTH        ", 2, "NAD83", 1401,
 { 6.378137000000000e+06,  6.694380022900000e-03, -9.330000000000000e+05,
   1.000000000000000e+00,  4.316000000000000e+05,  4.204000000000000e+05,
   4.130000000000000e+05,  1.500000000000000e+06,  1.000000000000000e+06}},
{ "IOWA            SOUTH        ", 2, "NAD83", 1402,
 { 6.378137000000000e+06,  6.694380022900000e-03, -9.330000000000000e+05,
   1.000000000000000e+00,  4.147000000000000e+05,  4.037000000000000e+05,
   4.000000000000000e+05,  5.000000000000000e+05,  0.000000000000000e+00}},
{ "KANSAS          NORTH        ", 2, "NAD83", 1501,
 { 6.378137000000000e+06,  6.694380022900000e-03, -9.800000000000000e+05,
   1.000000000000000e+00,  3.947000000000000e+05,  3.843000000000000e+05,
   3.820000000000000e+05,  4.000000000000000e+05,  0.000000000000000e+00}},
{ "KANSAS          SOUTH        ", 2, "NAD83", 1502,
 { 6.378137000000000e+06,  6.694380022900000e-03, -9.830000000000000e+05,
   1.000000000000000e+00,  3.834000000000000e+05,  3.716000000000000e+05,
   3.640000000000000e+05,  4.000000000000000e+05,  4.000000000000000e+05}},
{ "KENTUCKY        NORTH        ", 2, "NAD83", 1601,
 { 6.378137000000000e+06,  6.694380022900000e-03, -8.415000000000000e+05,
   1.000000000000000e+00,  3.858000000000000e+05,  3.758000000000000e+05,
   3.730000000000000e+05,  5.000000000000000e+05,  0.000000000000000e+00}},
{ "KENTUCKY        SOUTH        ", 2, "NAD83", 1602,
 { 6.378137000000000e+06,  6.694380022900000e-03, -8.545000000000000e+05,
   1.000000000000000e+00,  3.756000000000000e+05,  3.644000000000000e+05,
   3.620000000000000e+05,  5.000000000000000e+05,  5.000000000000000e+05}},
{ "LOUISIANA       NORTH        ", 2, "NAD83", 1701,
 { 6.378137000000000e+06,  6.694380022900000e-03, -9.230000000000000e+05,
   1.000000000000000e+00,  3.240000000000000e+05,  3.110000000000000e+05,
   3.030000000000000e+05,  1.000000000000000e+06,  0.000000000000000e+00}},
{ "LOUISIANA       SOUTH        ", 2, "NAD83", 1702,
 { 6.378137000000000e+06,  6.694380022900000e-03, -9.120000000000000e+05,
   1.000000000000000e+00,  3.042000000000000e+05,  2.918000000000000e+05,
   2.830000000000000e+05,  1.000000000000000e+06,  0.000000000000000e+00}},
{ "LOUISIANA       OFFSHORE     ", 2, "NAD83", 1703,
 { 6.378137000000000e+06,  6.694380022900000e-03, -9.120000000000000e+05,
   1.000000000000000e+00,  2.750000000000000e+05,  2.610000000000000e+05,
   2.530000000000000e+05,  1.000000000000000e+06,  0.000000000000000e+00}},
{ "MAINE           EAST         ", 1, "NAD83", 1801,
 { 6.378137000000000e+06,  6.694380022900000e-03, -6.830000000000000e+05,
   9.999000000000000e-01,  0.000000000000000e+00,  0.000000000000000e+00,
   4.340000000000000e+05,  3.000000000000000e+05,  0.000000000000000e+00}},
{ "MAINE           WEST         ", 1, "NAD83", 1802,
 { 6.378137000000000e+06,  6.694380022900000e-03, -7.010000000000000e+05,
   9.999666666666667e-01,  0.000000000000000e+00,  0.000000000000000e+00,
   4.250000000000000e+05,  9.000000000000000e+05,  0.000000000000000e+00}},
{ "MARYLAND        ---          ", 2, "NAD83", 1900,
 { 6.378137000000000e+06,  6.694380022900000e-03, -7.700000000000000e+05,
   1.000000000000000e+00,  3.927000000000000e+05,  3.818000000000000e+05,
   3.740000000000000e+05,  4.000000000000000e+05,  0.000000000000000e+00}},
{ "MASSACHUSETTS   MAINLAND     ", 2, "NAD83", 2001,
 { 6.378137000000000e+06,  6.694380022900000e-03, -7.130000000000000e+05,
   1.000000000000000e+00,  4.241000000000000e+05,  4.143000000000000e+05,
   4.100000000000000e+05,  2.000000000000000e+05,  7.500000000000000e+05}},
{ "MASSACHUSETTS   ISLAND       ", 2, "NAD83", 2002,
 { 6.378137000000000e+06,  6.694380022900000e-03, -7.030000000000000e+05,
   1.000000000000000e+00,  4.129000000000000e+05,  4.117000000000000e+05,
   4.100000000000000e+05,  5.000000000000000e+05,  0.000000000000000e+00}},
{ "MICHIGAN        EAST         ", 0, "NAD83", 2101,
 { 6.378137000000000e+06,  6.694380022900000e-03, -8.340000000000000e+05,
   9.999428571428571e-01,  0.000000000000000e+00,  0.000000000000000e+00,
   4.130000000000000e+05,  0.000000000000000e+00,  0.000000000000000e+00}},
{ "MICHIGAN       CENTRAL/M     ", 0, "NAD83", 2102,
 { 6.378137000000000e+06,  6.694380022900000e-03, -8.545000000000000e+05,
   9.999090909090909e-01,  0.000000000000000e+00,  0.000000000000000e+00,
   4.130000000000000e+05,  1.524003048006096e+05,  0.000000000000000e+00}},
{ "MICHIGAN        WEST         ", 0, "NAD83", 2103,
 { 6.378137000000000e+06,  6.694380022900000e-03, -8.845000000000000e+05,
   9.999090909090909e-01,  0.000000000000000e+00,  0.000000000000000e+00,
   4.130000000000000e+05,  1.524003048006096e+05,  0.000000000000000e+00}},
{ "MICHIGAN        NORTH        ", 2, "NAD83", 2111,
 { 6.378137000000000e+06,  6.694380022900000e-03, -8.700000000000000e+05,
   1.000000000000000e+00,  4.705000000000000e+05,  4.529000000000000e+05,
   4.447000000000000e+05,  8.000000000000000e+06,  0.000000000000000e+00}},
{ "MICHIGAN        CENTRAL/L    ", 2, "NAD83", 2112,
 { 6.378137000000000e+06,  6.694380022900000e-03, -8.422000000000000e+05,
   1.000000000000000e+00,  4.542000000000000e+05,  4.411000000000000e+05,
   4.319000000000000e+05,  6.000000000000000e+06,  0.000000000000000e+00}},
{ "MICHIGAN        SOUTH        ", 2, "NAD83", 2113,
 { 6.378137000000000e+06,  6.694380022900000e-03, -8.422000000000000e+05,
   1.000000000000000e+00,  4.340000000000000e+05,  4.206000000000000e+05,
   4.130000000000000e+05,  4.000000000000000e+06,  0.000000000000000e+00}},
{ "MINNESOTA       NORTH        ", 2, "NAD83", 2201,
 { 6.378137000000000e+06,  6.694380022900000e-03, -9.306000000000000e+05,
   1.000000000000000e+00,  4.838000000000000e+05,  4.702000000000000e+05,
   4.630000000000000e+05,  8.000000000000000e+05,  1.000000000000000e+05}},
{ "MINNESOTA       CENTRAL      ", 2, "NAD83", 2202,
 { 6.378137000000000e+06,  6.694380022900000e-03, -9.415000000000000e+05,
   1.000000000000000e+00,  4.703000000000000e+05,  4.537000000000000e+05,
   4.500000000000000e+05,  8.000000000000000e+05,  1.000000000000000e+05}},
{ "MINNESOTA       SOUTH        ", 2, "NAD83", 2203,
 { 6.378137000000000e+06,  6.694380022900000e-03, -9.400000000000000e+05,
   1.000000000000000e+00,  4.513000000000000e+05,  4.347000000000000e+05,
   4.300000000000000e+05,  8.000000000000000e+05,  1.000000000000000e+05}},
{ "MISSISSIPPI     EAST         ", 1, "NAD83", 2301,
 { 6.378137000000000e+06,  6.694380022900000e-03, -8.850000000000000e+05,
   9.999500000000000e-01,  0.000000000000000e+00,  0.000000000000000e+00,
   2.930000000000000e+05,  3.000000000000000e+05,  0.000000000000000e+00}},
{ "MISSISSIPPI     WEST         ", 1, "NAD83", 2302,
 { 6.378137000000000e+06,  6.694380022900000e-03, -9.020000000000000e+05,
   9.999500000000000e-01,  0.000000000000000e+00,  0.000000000000000e+00,
   2.930000000000000e+05,  7.000000000000000e+05,  0.000000000000000e+00}},
{ "MISSOURI        EAST         ", 1, "NAD83", 2401,
 { 6.378137000000000e+06,  6.694380022900000e-03, -9.030000000000000e+05,
   9.999333333333333e-01,  0.000000000000000e+00,  0.000000000000000e+00,
   3.550000000000000e+05,  2.500000000000000e+05,  0.000000000000000e+00}},
{ "MISSOURI        CENTRAL      ", 1, "NAD83", 2402,
 { 6.378137000000000e+06,  6.694380022900000e-03, -9.230000000000000e+05,
   9.999333333333333e-01,  0.000000000000000e+00,  0.000000000000000e+00,
   3.550000000000000e+05,  5.000000000000000e+05,  0.000000000000000e+00}},
{ "MISSOURI        WEST         ", 1, "NAD83", 2403,
 { 6.378137000000000e+06,  6.694380022900000e-03, -9.430000000000000e+05,
   9.999411764705882e-01,  0.000000000000000e+00,  0.000000000000000e+00,
   3.610000000000000e+05,  8.500000000000000e+05,  0.000000000000000e+00}},
{ "MONTANA                      ", 2, "NAD83", 2500,
 { 6.378137000000000e+06,  6.694380022900000e-03, -1.093000000000000e+06,
   1.000000000000000e+00,  4.900000000000000e+05,  4.500000000000000e+05,
   4.415000000000000e+05,  6.000000000000000e+05,  0.000000000000000e+00}},
{ "MONTANA                      ", 0, "NAD83", 2502,
 { 6.378137000000000e+06,  6.694380022900000e-03, -1.093000000000000e+06,
   1.000000000000000e+00,  4.900000000000000e+05,  4.500000000000000e+05,
   4.415000000000000e+05,  6.000000000000000e+05,  0.000000000000000e+00}},
{ "MONTANA                      ", 0, "NAD83", 2503,
 { 6.378137000000000e+06,  6.694380022900000e-03, -1.093000000000000e+06,
   1.000000000000000e+00,  4.900000000000000e+05,  4.500000000000000e+05,
   4.415000000000000e+05,  6.000000000000000e+05,  0.000000000000000e+00}},
{ "NEBRASKA                     ", 2, "NAD83", 2600,
 { 6.378137000000000e+06,  6.694380022900000e-03, -1.000000000000000e+06,
   1.000000000000000e+00,  4.300000000000000e+05,  4.000000000000000e+05,
   3.950000000000000e+05,  5.000000000000000e+05,  0.000000000000000e+00}},
{ "NEBRASKA                     ", 0, "NAD83", 2602,
 { 6.378137000000000e+06,  6.694380022900000e-03, -1.000000000000000e+06,
   1.000000000000000e+00,  4.300000000000000e+05,  4.000000000000000e+05,
   3.950000000000000e+05,  5.000000000000000e+05,  0.000000000000000e+00}},
{ "NEVADA          EAST         ", 1, "NAD83", 2701,
 { 6.378137000000000e+06,  6.694380022900000e-03, -1.153500000000000e+06,
   9.999000000000000e-01,  0.000000000000000e+00,  0.000000000000000e+00,
   3.445000000000000e+05,  2.000000000000000e+05,  8.000000000000000e+06}},
{ "NEVADA          CENTRAL      ", 1, "NAD83", 2702,
 { 6.378137000000000e+06,  6.694380022900000e-03, -1.164000000000000e+06,
   9.999000000000000e-01,  0.000000000000000e+00,  0.000000000000000e+00,
   3.445000000000000e+05,  5.000000000000000e+05,  6.000000000000000e+06}},
{ "NEVADA          WEST         ", 1, "NAD83", 2703,
 { 6.378137000000000e+06,  6.694380022900000e-03, -1.183500000000000e+06,
   9.999000000000000e-01,  0.000000000000000e+00,  0.000000000000000e+00,
   3.445000000000000e+05,  8.000000000000000e+05,  4.000000000000000e+06}},
{ "NEW HAMPSHIRE   ---          ", 1, "NAD83", 2800,
 { 6.378137000000000e+06,  6.694380022900000e-03, -7.140000000000000e+05,
   9.999666666666667e-01,  0.000000000000000e+00,  0.000000000000000e+00,
   4.230000000000000e+05,  3.000000000000000e+05,  0.000000000000000e+00}},
{ "NEW JERSEY      ---          ", 1, "NAD83", 2900,
 { 6.378137000000000e+06,  6.694380022900000e-03, -7.430000000000000e+05,
   9.999000000000000e-01,  0.000000000000000e+00,  0.000000000000000e+00,
   3.850000000000000e+05,  1.500000000000000e+05,  0.000000000000000e+00}},
{ "NEW MEXICO      EAST         ", 1, "NAD83", 3001,
 { 6.378137000000000e+06,  6.694380022900000e-03, -1.042000000000000e+06,
   9.999090909090909e-01,  0.000000000000000e+00,  0.000000000000000e+00,
   3.100000000000000e+05,  1.650000000000000e+05,  0.000000000000000e+00}},
{ "NEW MEXICO      CENTRAL      ", 1, "NAD83", 3002,
 { 6.378137000000000e+06,  6.694380022900000e-03, -1.061500000000000e+06,
   9.999000000000000e-01,  0.000000000000000e+00,  0.000000000000000e+00,
   3.100000000000000e+05,  5.000000000000000e+05,  0.000000000000000e+00}},
{ "NEW MEXICO      WEST         ", 1, "NAD83", 3003,
 { 6.378137000000000e+06,  6.694380022900000e-03, -1.075000000000000e+06,
   9.999166666666667e-01,  0.000000000000000e+00,  0.000000000000000e+00,
   3.100000000000000e+05,  8.300000000000000e+05,  0.000000000000000e+00}},
{ "NEW YORK        EAST         ", 1, "NAD83", 3101,
 { 6.378137000000000e+06,  6.694380022900000e-03, -7.430000000000000e+05,
   9.999000000000000e-01,  0.000000000000000e+00,  0.000000000000000e+00,
   3.850000000000000e+05,  1.500000000000000e+05,  0.000000000000000e+00}},
{ "NEW YORK        CENTRAL      ", 1, "NAD83", 3102,
 { 6.378137000000000e+06,  6.694380022900000e-03, -7.635000000000000e+05,
   9.999375000000000e-01,  0.000000000000000e+00,  0.000000000000000e+00,
   4.000000000000000e+05,  2.500000000000000e+05,  0.000000000000000e+00}},
{ "NEW YORK        WEST         ", 1, "NAD83", 3103,
 { 6.378137000000000e+06,  6.694380022900000e-03, -7.835000000000000e+05,
   9.999375000000000e-01,  0.000000000000000e+00,  0.000000000000000e+00,
   4.000000000000000e+05,  3.500000000000000e+05,  0.000000000000000e+00}},
{ "NEW YORK        LONG ISLAND  ", 2, "NAD83", 3104,
 { 6.378137000000000e+06,  6.694380022900000e-03, -7.400000000000000e+05,
   1.000000000000000e+00,  4.102000000000000e+05,  4.040000000000000e+05,
   4.010000000000000e+05,  3.000000000000000e+05,  0.000000000000000e+00}},
{ "NORTH CAROLINA  ---          ", 2, "NAD83", 3200,
 { 6.378137000000000e+06,  6.694380022900000e-03, -7.900000000000000e+05,
   1.000000000000000e+00,  3.610000000000000e+05,  3.420000000000000e+05,
   3.345000000000000e+05,  6.000000000000000e+05,  0.000000000000000e+00}},
{ "NORTH DAKOTA    NORTH        ", 2, "NAD83", 3301,
 { 6.378137000000000e+06,  6.694380022900000e-03, -1.003000000000000e+06,
   1.000000000000000e+00,  4.844000000000000e+05,  4.726000000000000e+05,
   4.700000000000000e+05,  6.000000000000000e+05,  0.000000000000000e+00}},
{ "NORTH DAKOTA    SOUTH        ", 2, "NAD83", 3302,
 { 6.378137000000000e+06,  6.694380022900000e-03, -1.003000000000000e+06,
   1.000000000000000e+00,  4.729000000000000e+05,  4.611000000000000e+05,
   4.540000000000000e+05,  6.000000000000000e+05,  0.000000000000000e+00}},
{ "OHIO            NORTH        ", 2, "NAD83", 3401,
 { 6.378137000000000e+06,  6.694380022900000e-03, -8.230000000000000e+05,
   1.000000000000000e+00,  4.142000000000000e+05,  4.026000000000000e+05,
   3.940000000000000e+05,  6.000000000000000e+05,  0.000000000000000e+00}},
{ "OHIO            SOUTH        ", 2, "NAD83", 3402,
 { 6.378137000000000e+06,  6.694380022900000e-03, -8.230000000000000e+05,
   1.000000000000000e+00,  4.002000000000000e+05,  3.844000000000000e+05,
   3.800000000000000e+05,  6.000000000000000e+05,  0.000000000000000e+00}},
{ "OKLAHOMA        NORTH        ", 2, "NAD83", 3501,
 { 6.378137000000000e+06,  6.694380022900000e-03, -9.800000000000000e+05,
   1.000000000000000e+00,  3.646000000000000e+05,  3.534000000000000e+05,
   3.500000000000000e+05,  6.000000000000000e+05,  0.000000000000000e+00}},
{ "OKLAHOMA        SOUTH        ", 2, "NAD83", 3502,
 { 6.378137000000000e+06,  6.694380022900000e-03, -9.800000000000000e+05,
   1.000000000000000e+00,  3.514000000000000e+05,  3.356000000000000e+05,
   3.320000000000000e+05,  6.000000000000000e+05,  0.000000000000000e+00}},
{ "OREGON          NORTH        ", 2, "NAD83", 3601,
 { 6.378137000000000e+06,  6.694380022900000e-03, -1.203000000000000e+06,
   1.000000000000000e+00,  4.600000000000000e+05,  4.420000000000000e+05,
   4.340000000000000e+05,  2.500000000000000e+06,  0.000000000000000e+00}},
{ "OREGON          SOUTH        ", 2, "NAD83", 3602,
 { 6.378137000000000e+06,  6.694380022900000e-03, -1.203000000000000e+06,
   1.000000000000000e+00,  4.400000000000000e+05,  4.220000000000000e+05,
   4.140000000000000e+05,  1.500000000000000e+06,  0.000000000000000e+00}},
{ "PENNSYLVANIA    NORTH        ", 2, "NAD83", 3701,
 { 6.378137000000000e+06,  6.694380022900000e-03, -7.745000000000000e+05,
   1.000000000000000e+00,  4.157000000000000e+05,  4.053000000000000e+05,
   4.010000000000000e+05,  6.000000000000000e+05,  0.000000000000000e+00}},
{ "PENNSYLVANIA    SOUTH        ", 2, "NAD83", 3702,
 { 6.378137000000000e+06,  6.694380022900000e-03, -7.745000000000000e+05,
   1.000000000000000e+00,  4.058000000000000e+05,  3.956000000000000e+05,
   3.920000000000000e+05,  6.000000000000000e+05,  0.000000000000000e+00}},
{ "RHODE ISLAND    ---          ", 1, "NAD83", 3800,
 { 6.378137000000000e+06,  6.694380022900000e-03, -7.130000000000000e+05,
   9.999937500000000e-01,  0.000000000000000e+00,  0.000000000000000e+00,
   4.105000000000000e+05,  1.000000000000000e+05,  0.000000000000000e+00}},
{ "SOUTH CAROLINA               ", 2, "NAD83", 3900,
 { 6.378137000000000e+06,  6.694380022900000e-03, -8.100000000000000e+05,
   1.000000000000000e+00,  3.450000000000000e+05,  3.230000000000000e+05,
   3.150000000000000e+05,  6.096000000000000e+05,  0.000000000000000e+00}},
{ "SOUTH CAROLINA               ", 0, "NAD83", 3902,
 { 6.378137000000000e+06,  6.694380022900000e-03, -8.100000000000000e+05,
   1.000000000000000e+00,  3.450000000000000e+05,  3.230000000000000e+05,
   3.150000000000000e+05,  6.096000000000000e+05,  0.000000000000000e+00}},
{ "SOUTH DAKOTA    NORTH        ", 2, "NAD83", 4001,
 { 6.378137000000000e+06,  6.694380022900000e-03, -1.000000000000000e+06,
   1.000000000000000e+00,  4.541000000000000e+05,  4.425000000000000e+05,
   4.350000000000000e+05,  6.000000000000000e+05,  0.000000000000000e+00}},
{ "SOUTH DAKOTA    SOUTH        ", 2, "NAD83", 4002,
 { 6.378137000000000e+06,  6.694380022900000e-03, -1.002000000000000e+06,
   1.000000000000000e+00,  4.424000000000000e+05,  4.250000000000000e+05,
   4.220000000000000e+05,  6.000000000000000e+05,  0.000000000000000e+00}},
{ "TENNESSEE       ---          ", 2, "NAD83", 4100,
 { 6.378137000000000e+06,  6.694380022900000e-03, -8.600000000000000e+05,
   1.000000000000000e+00,  3.625000000000000e+05,  3.515000000000000e+05,
   3.420000000000000e+05,  6.000000000000000e+05,  0.000000000000000e+00}},
{ "TEXAS           NORTH        ", 2, "NAD83", 4201,
 { 6.378137000000000e+06,  6.694380022900000e-03, -1.013000000000000e+06,
   1.000000000000000e+00,  3.611000000000000e+05,  3.439000000000000e+05,
   3.400000000000000e+05,  2.000000000000000e+05,  1.000000000000000e+06}},
{ "TEXAS           NORTH CENTRAL", 2, "NAD83", 4202,
 { 6.378137000000000e+06,  6.694380022900000e-03, -9.830000000000000e+05,
   1.000000000000000e+00,  3.358000000000000e+05,  3.208000000000000e+05,
   3.140000000000000e+05,  6.000000000000000e+05,  2.000000000000000e+06}},
{ "TEXAS           CENTRAL      ", 2, "NAD83", 4203,
 { 6.378137000000000e+06,  6.694380022900000e-03, -1.002000000000000e+06,
   1.000000000000000e+00,  3.153000000000000e+05,  3.007000000000000e+05,
   2.940000000000000e+05,  7.000000000000000e+05,  3.000000000000000e+06}},
{ "TEXAS           SOUTH CENTRAL", 2, "NAD83", 4204,
 { 6.378137000000000e+06,  6.694380022900000e-03, -9.900000000000000e+05,
   1.000000000000000e+00,  3.017000000000000e+05,  2.823000000000000e+05,
   2.750000000000000e+05,  6.000000000000000e+05,  4.000000000000000e+06}},
{ "TEXAS           SOUTH        ", 2, "NAD83", 4205,
 { 6.378137000000000e+06,  6.694380022900000e-03, -9.830000000000000e+05,
   1.000000000000000e+00,  2.750000000000000e+05,  2.610000000000000e+05,
   2.540000000000000e+05,  3.000000000000000e+05,  5.000000000000000e+06}},
{ "UTAH            NORTH        ", 2, "NAD83", 4301,
 { 6.378137000000000e+06,  6.694380022900000e-03, -1.113000000000000e+06,
   1.000000000000000e+00,  4.147000000000000e+05,  4.043000000000000e+05,
   4.020000000000000e+05,  5.000000000000000e+05,  1.000000000000000e+06}},
{ "UTAH            CENTRAL      ", 2, "NAD83", 4302,
 { 6.378137000000000e+06,  6.694380022900000e-03, -1.113000000000000e+06,
   1.000000000000000e+00,  4.039000000000000e+05,  3.901000000000000e+05,
   3.820000000000000e+05,  5.000000000000000e+05,  2.000000000000000e+06}},
{ "UTAH            SOUTH        ", 2, "NAD83", 4303,
 { 6.378137000000000e+06,  6.694380022900000e-03, -1.113000000000000e+06,
   1.000000000000000e+00,  3.821000000000000e+05,  3.713000000000000e+05,
   3.640000000000000e+05,  5.000000000000000e+05,  3.000000000000000e+06}},
{ "VERMONT         ---          ", 1, "NAD83", 4400,
 { 6.378137000000000e+06,  6.694380022900000e-03, -7.230000000000000e+05,
   9.999642857142857e-01,  0.000000000000000e+00,  0.000000000000000e+00,
   4.230000000000000e+05,  5.000000000000000e+05,  0.000000000000000e+00}},
{ "VIRGINIA        NORTH        ", 2, "NAD83", 4501,
 { 6.378137000000000e+06,  6.694380022900000e-03, -7.830000000000000e+05,
   1.000000000000000e+00,  3.912000000000000e+05,  3.802000000000000e+05,
   3.740000000000000e+05,  3.500000000000000e+06,  2.000000000000000e+06}},
{ "VIRGINIA        SOUTH        ", 2, "NAD83", 4502,
 { 6.378137000000000e+06,  6.694380022900000e-03, -7.830000000000000e+05,
   1.000000000000000e+00,  3.758000000000000e+05,  3.646000000000000e+05,
   3.620000000000000e+05,  3.500000000000000e+06,  1.000000000000000e+06}},
{ "WASHINGTON      NORTH        ", 2, "NAD83", 4601,
 { 6.378137000000000e+06,  6.694380022900000e-03, -1.205000000000000e+06,
   1.000000000000000e+00,  4.844000000000000e+05,  4.730000000000000e+05,
   4.700000000000000e+05,  5.000000000000000e+05,  0.000000000000000e+00}},
{ "WASHINGTON      SOUTH        ", 2, "NAD83", 4602,
 { 6.378137000000000e+06,  6.694380022900000e-03, -1.203000000000000e+06,
   1.000000000000000e+00,  4.720000000000000e+05,  4.550000000000000e+05,
   4.520000000000000e+05,  5.000000000000000e+05,  0.000000000000000e+00}},
{ "WEST VIRGINIA   NORTH        ", 2, "NAD83", 4701,
 { 6.378137000000000e+06,  6.694380022900000e-03, -7.930000000000000e+05,
   1.000000000000000e+00,  4.015000000000000e+05,  3.900000000000000e+05,
   3.830000000000000e+05,  6.000000000000000e+05,  0.000000000000000e+00}},
{ "WEST VIRGINIA   SOUTH        ", 2, "NAD83", 4702,
 { 6.378137000000000e+06,  6.694380022900000e-03, -8.100000000000000e+05,
   1.000000000000000e+00,  3.853000000000000e+05,  3.729000000000000e+05,
   3.700000000000000e+05,  6.000000000000000e+05,  0.000000000000000e+00}},
{ "WISCONSIN       NORTH        ", 2, "NAD83", 4801,
 { 6.378137000000000e+06,  6.694380022900000e-03, -9.000000000000000e+05,
   1.000000000000000e+00,  4.646000000000000e+05,  4.534000000000000e+05,
   4.510000000000000e+05,  6.000000000000000e+05,  0.000000000000000e+00}},
{ "WISCONSIN       CENTRAL      ", 2, "NAD83", 4802,
 { 6.378137000000000e+06,  6.694380022900000e-03, -9.000000000000000e+05,
   1.000000000000000e+00,  4.530000000000000e+05,  4.415000000000000e+05,
   4.350000000000000e+05,  6.000000000000000e+05,  0.000000000000000e+00}},
{ "WISCONSIN       SOUTH        ", 2, "NAD83", 4803,
 { 6.378137000000000e+06,  6.694380022900000e-03, -9.000000000000000e+05,
   1.000000000000000e+00,  4.404000000000000e+05,  4.244000000000000e+05,
   4.200000000000000e+05,  6.000000000000000e+05,  0.000000000000000e+00}},
{ "WYOMING         EAST         ", 0, "NAD83", 4901,
 { 6.378137000000000e+06,  6.694380022900000e-03, -1.051000000000000e+06,
   9.999411764705882e-01,  0.000000000000000e+00,  0.000000000000000e+00,
   4.040000000000000e+05,  1.524003048006096e+05,  0.000000000000000e+00}},
{ "WYOMING         EAST CENTRAL ", 0, "NAD83", 4902,
 { 6.378137000000000e+06,  6.694380022900000e-03, -1.072000000000000e+06,
   9.999411764705882e-01,  0.000000000000000e+00,  0.000000000000000e+00,
   4.040000000000000e+05,  1.524003048006096e+05,  0.000000000000000e+00}},
{ "WYOMING         WEST CENTRAL ", 0, "NAD83", 4903,
 { 6.378137000000000e+06,  6.694380022900000e-03, -1.084500000000000e+06,
   9.999411764705882e-01,  0.000000000000000e+00,  0.000000000000000e+00,
   4.040000000000000e+05,  1.524003048006096e+05,  0.000000000000000e+00}},
{ "WYOMING         WEST         ", 0, "NAD83", 4904,
 { 6.378137000000000e+06,  6.694380022900000e-03, -1.100500000000000e+06,
   9.999411764705882e-01,  0.000000000000000e+00,  0.000000000000000e+00,
   4.040000000000000e+05,  1.524003048006096e+05,  0.000000000000000e+00}},
{ "ALASKA          ZONE NO. 1   ", 4, "NAD83", 5001,
 { 6.378137000000000e+06,  6.694380022900000e-03, -1.334000000000000e+06,
   9.999000000000000e-01,  0.000000000000000e+00, -3.652116315000000e+05,
   5.700000000000000e+05,  5.000000000000000e+06, -5.000000000000000e+06}},
{ "ALASKA          ZONE NO. 2   ", 1, "NAD83", 5002,
 { 6.378137000000000e+06,  6.694380022900000e-03, -1.420000000000000e+06,
   9.999000000000000e-01,  0.000000000000000e+00,  0.000000000000000e+00,
   5.400000000000000e+05,  5.000000000000000e+05,  0.000000000000000e+00}},
{ "ALASKA          ZONE NO. 3   ", 1, "NAD83", 5003,
 { 6.378137000000000e+06,  6.694380022900000e-03, -1.460000000000000e+06,
   9.999000000000000e-01,  0.000000000000000e+00,  0.000000000000000e+00,
   5.400000000000000e+05,  5.000000000000000e+05,  0.000000000000000e+00}},
{ "ALASKA          ZONE NO. 4   ", 1, "NAD83", 5004,
 { 6.378137000000000e+06,  6.694380022900000e-03, -1.500000000000000e+06,
   9.999000000000000e-01,  0.000000000000000e+00,  0.000000000000000e+00,
   5.400000000000000e+05,  5.000000000000000e+05,  0.000000000000000e+00}},
{ "ALASKA          ZONE NO. 5   ", 1, "NAD83", 5005,
 { 6.378137000000000e+06,  6.694380022900000e-03, -1.540000000000000e+06,
   9.999000000000000e-01,  0.000000000000000e+00,  0.000000000000000e+00,
   5.400000000000000e+05,  5.000000000000000e+05,  0.000000000000000e+00}},
{ "ALASKA          ZONE NO. 6   ", 1, "NAD83", 5006,
 { 6.378137000000000e+06,  6.694380022900000e-03, -1.580000000000000e+06,
   9.999000000000000e-01,  0.000000000000000e+00,  0.000000000000000e+00,
   5.400000000000000e+05,  5.000000000000000e+05,  0.000000000000000e+00}},
{ "ALASKA          ZONE NO. 7   ", 1, "NAD83", 5007,
 { 6.378137000000000e+06,  6.694380022900000e-03, -1.620000000000000e+06,
   9.999000000000000e-01,  0.000000000000000e+00,  0.000000000000000e+00,
   5.400000000000000e+05,  5.000000000000000e+05,  0.000000000000000e+00}},
{ "ALASKA          ZONE NO. 8   ", 1, "NAD83", 5008,
 { 6.378137000000000e+06,  6.694380022900000e-03, -1.660000000000000e+06,
   9.999000000000000e-01,  0.000000000000000e+00,  0.000000000000000e+00,
   5.400000000000000e+05,  5.000000000000000e+05,  0.000000000000000e+00}},
{ "ALASKA          ZONE NO. 9   ", 1, "NAD83", 5009,
 { 6.378137000000000e+06,  6.694380022900000e-03, -1.700000000000000e+06,
   9.999000000000000e-01,  0.000000000000000e+00,  0.000000000000000e+00,
   5.400000000000000e+05,  5.000000000000000e+05,  0.000000000000000e+00}},
{ "PUERTO RICO                  ", 2, "NAD83", 5301,
 { 6.378137000000000e+06,  6.694380022900000e-03, -6.626000000000000e+05,
   1.000000000000000e+00,  1.826000000000000e+05,  1.802000000000000e+05,
   1.750000000000000e+05,  2.000000000000000e+05,  2.000000000000000e+05}},
{ "VIRGIN ISLANDS               ", 2, "NAD83", 5201,
 { 6.378137000000000e+06,  6.694380022900000e-03, -6.626000000000000e+05,
   1.000000000000000e+00,  1.826000000000000e+05,  1.802000000000000e+05,
   1.750000000000000e+05,  2.000000000000000e+05,  2.000000000000000e+05}},
{ "ST. CROIX                    ", 0, "NAD83", 5202,
 { 6.378137000000000e+06,  6.694380022900000e-03, -6.626000000000000e+05,
   1.000000000000000e+00,  1.826000000000000e+05,  1.802000000000000e+05,
   1.750000000000000e+05,  1.524003048006096e+05,  3.048006096012192e+04}},
{ "GUAM                         ", 0, "NAD83", 5400,
 { 6.378137000000000e+06,  6.694380022900000e-03,  1.444455502540000e+06,
   1.328208788700000e+05,  5.000000000000000e+04,  5.000000000000000e+04,
   0.000000000000000e+00,  0.000000000000000e+00,  0.000000000000000e+00}}
};
