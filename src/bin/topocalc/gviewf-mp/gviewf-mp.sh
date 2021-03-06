PATH="$PATH:$IPW/lib"

pgm=`basename $0`
optstring='xm:'

synopsis='[-x] [-m mask] elev_image'
description='%description'
 
tdir=$WORKDIR/$pgm.$$

set -- `getopt "$optstring" $* 2>/dev/null` || {
	usage $pgm "$synopsis" "$description"
	exit 1
}

# parse options

angles=16
mask=
maskf=

while :; do
	case $1 in
	--)	shift
		break
		;;
	-H)	usage $pgm "$synopsis" "$description"
		exit 1
		;;
	-m)	mask=$2
		shift
		;;
	-x	angles=32
		shift
		;;
	*)	sherror $pgm '"getopt" failed'
		exit 1
		;;
	esac
	shift
done

image=$1
case $# in
0)	test -t 0 && {
	sherror $pgm "can't read image data from terminal"
	exit 1
	}
	;;
1)	;;
*)	usage $pgm "$synopsis" "$description"
	exit 1
	;;
esac

test -r $image || {
	sherror $pgm "can't open file", $image
	exit 1
}

case $mask in
'')	maskf=
	;;
*)	test -r $mask || {
		sherror $pgm "can't open mask file", $mask
		exit 1
	}
	maskf="-m $mask"
esac

# can't write image data to terminal

test -t 1 && {
	sherror $pgm "can't write image data to a terminal"
	exit 1
}

trap 'rm -f -r $tdir' 0
trap 'exit 0' 1 2 3 15

# make directory for temporary files
mkdir $tdir

# get maximum elevation
maxelev=`imgstat -a $image | awk '{print $3}'`


# horizons in S and N directions
ghorizon $maskf -e $maxelev -a 0 $image > $tdir/horz.s &
ghorizon $maskf -e $maxelev -a 180 $image > $tdir/horz.n &

# horizons in SSW and SSE directions
ghorizon $maskf -e $maxelev -a -22.5 $image > $tdir/horz.ssw &
ghorizon $maskf -e $maxelev -a 22.5 $image > $tdir/horz.sse &

wait

# horizons in SW and SE directions
ghorizon $maskf -e $maxelev -a -45 $image > $tdir/horz.sw &
ghorizon $maskf -e $maxelev -a 45 $image > $tdir/horz.se &

# horizons in WSW and ESE directions
ghorizon $maskf -e $maxelev -a -67.5 $image > $tdir/horz.wsw &
ghorizon $maskf -e $maxelev -a 67.5 $image > $tdir/horz.ese &

wait

# horizons in W and E directions
ghorizon $maskf -e $maxelev -a -90 $image > $tdir/horz.w &
ghorizon $maskf -e $maxelev -a 90 $image > $tdir/horz.e &

# horizons in WNW and ENE directions
ghorizon $maskf -e $maxelev -a -112.5 $image > $tdir/horz.wnw &
ghorizon $maskf -e $maxelev -a 112.5 $image > $tdir/horz.ene &

wait

# horizons in NW and NE directions
ghorizon $maskf -e $maxelev -a -135 $image > $tdir/horz.nw &
ghorizon $maskf -e $maxelev -a 135 $image > $tdir/horz.ne &

# horizons in NNW and NNE directions
ghorizon $maskf -e $maxelev -a -157.5 $image > $tdir/horz.nnw &
ghorizon $maskf -e $maxelev -a 157.5 $image > $tdir/horz.nne &

wait

if [ $angles -eq 32 ] ; then
  ghorizon $maskf -e $maxelev -a  -11.25 $image > $tdir/horz.ssws &
  ghorizon $maskf -e $maxelev -a   11.25 $image > $tdir/horz.sses &
  ghorizon $maskf -e $maxelev -a  -33.75 $image > $tdir/horz.sws &
  ghorizon $maskf -e $maxelev -a   33.75 $image > $tdir/horz.ses &
  wait
  ghorizon $maskf -e $maxelev -a  -56.25 $image > $tdir/horz.wsws &
  ghorizon $maskf -e $maxelev -a   56.25 $image > $tdir/horz.eses &
  ghorizon $maskf -e $maxelev -a  -78.75 $image > $tdir/horz.ws &
  ghorizon $maskf -e $maxelev -a   78.75 $image > $tdir/horz.es &
  wait
  ghorizon $maskf -e $maxelev -a -101.25 $image > $tdir/horz.wnws &
  ghorizon $maskf -e $maxelev -a  101.25 $image > $tdir/horz.enes &
  ghorizon $maskf -e $maxelev -a -123.75 $image > $tdir/horz.nws &
  ghorizon $maskf -e $maxelev -a  123.75 $image > $tdir/horz.nes &
  wait
  ghorizon $maskf -e $maxelev -a -146.25 $image > $tdir/horz.nnws &
  ghorizon $maskf -e $maxelev -a  146.25 $image > $tdir/horz.nnes &
  ghorizon $maskf -e $maxelev -a -168.75 $image > $tdir/horz.nnwn &
  ghorizon $maskf -e $maxelev -a  168.75 $image > $tdir/horz.nnen &
  wait
fi

# create gradient file
ggradient $image > $tdir/gradient

# mux horizon together and pipe into view factor calculations
mux $tdir/horz.* | \
	$IPW/aux/viewf/viewcalc -s $tdir/gradient


exit 0
