PATH="$PATH:$IPW/lib"

pgm=`basename $0`
optstring='nz:t:w:g:r:s:d:x:d:i:b:l:o:'
synopsis='[-n] -z elev -t tau -w omega -g g -r R0 [-s S0] [-x w1,w2] \
	-d y,m,d,[h,m,s] -i delta_t -b d,m,s -l d,m,s -o out_prefix [image]'
description='%description'

set -- `getopt "$optstring" $* 2>/dev/null` || {
	exec usage $pgm "$synopsis" "$description"
}

elev=
tau=
omega=
gfact=
R0=
S0=
wrange=
year=
month=
day=
hour=0
min=0
sec=0
delta_t=
date=
lat=
lon=
out_prefix=
net=

# parse options, if none print description

case $# in
0|1)	exec usage $pgm "$synopsis" "$description"
	;;
esac

while :; do
	case $1 in
	--)	shift
		break
		;;
	-H)	exec usage $pgm "$synopsis" "$description"
		;;
	-n)	net="-n"
		;;
	-z)	elev=$2
		shift
		;;
	-t)	tau=$2
		shift
		;;
	-w)	omega=$2
		shift
		;;
	-g)	gfact=$2
		shift
		;;
	-r)	R0=$2
		shift
		;;
	-s)	S0=$2
		shift
		;;
	-x)	wrange=$2
		shift
		;;
	-d)	date=$2
		shift
		;;
	-i)	delta_t=$2
		shift
		;;
	-b)	lat=$2
		shift
		;;
	-l)	lon=$2
		shift
		;;
	-o)	out_prefix=$2
		shift
		;;
	*)	exec sherror $pgm '"getopt" failed'
		;;
	esac
	shift
done

# list of temporary files used
# directory for all is $WORKDIR/$pgm.$$
#
# iX - copy of input if stdin
# iZ - elevation image (1 band)
# iGR - gradient image (2 bands)
# iVF - view factor/albedo image (3 bands)
#
# the following files are re-created for each time step
#
# shade - cosine illumination angle, corrected for horizons
# hor - horizon mask
# erad - beam and diffuse radiation over elevation grid

# Can only have 1 input image.  If stdin must make duplicate copy
# because we need multiple access.

img=$1
case $# in
0)	test -t 0 && {
	exec sherror $pgm "can't read image data from terminal"
	}
	;;
1)	;;
*)	exec usage $pgm "$synopsis" "$description"
	;;
esac


# parse date into year, month, day, hour, min, sec

case $date in
'')	exec usage $pgm "$synopsis" "$description"
	;;
*)	year=` echo $date | awk -F, '{print $1}'`
	month=`echo $date | awk -F, '{print $2}'`
	day=`  echo $date | awk -F, '{print $3}'`
	hour=` echo $date | awk -F, '{print $4}'`
	min=`  echo $date | awk -F, '{print $5}'`
	sec=`  echo $date | awk -F, '{print $6}'`
	;;
esac

# make sure all essential arguments in

case $delta_t in
'')	exec sherror $pgm "-i arg missing"
	;;
esac

case $elev in
'')	exec sherror $pgm "-z arg missing"
	;;
esac

case $tau in
'')	exec sherror $pgm "-t arg missing"
	;;
esac

case $omega in
'')	exec sherror $pgm "-w arg missing"
	;;
esac

case $gfact in
'')	exec sherror $pgm "-g arg missing"
	;;
esac

case $R0 in
'')	exec sherror $pgm "-r arg missing"
	;;
esac

case $S0 in
'')	case $wrange in
	'')	exec sherror $pgm "-s and -x args missing, one must be present"
		;;
	*)	S0=`solar -d $year,$month,$day -w $wrange -a`
		;;
	esac
esac

case $out_prefix in
'')	exec sherror $pgm "-o arg missing"
	;;
esac

case $year in
'')	exec sherror $pgm "-d arg missing or incomplete"
	;;
esac

case $month in
'')	exec sherror $pgm "-d arg missing or incomplete"
	;;
esac

case $day in
'')	exec sherror $pgm "-d arg missing or incomplete"
	;;
esac

case $hour in
'')	hour=0
	;;
esac

case $min in
'')	min=0
	;;
esac

case $sec in
'')	sec=0
	;;
esac

case $lat in
'')	exec sherror $pgm "-b arg missing or incomplete"
	;;
esac

case $lon in
'')	exec sherror $pgm "-l arg missing or incomplete"
	;;
esac


if [ $delta_t -le 0 ] ; then
	echo "Illegal delta_t";
	exit 1
fi

tdir=$WORKDIR/$pgm.$$
mkdir $tdir

case $img in
''|'-')
	cat $img > $tdir/iX
	image=$tdir/iX
	;;
*)	test -r $img || {
		exec sherror $pgm "can't open file", $image
	}
	image=$img
	;;
esac


# elevation file
efile=$tdir/iZ
demux -b 0 $image > $efile

# slope/aspect file
grfile=$tdir/iGR
demux -b 1,2 $image > $grfile

# sky view, terrain view, and albedo
vfile=$tdir/iVF
demux -b 3,4,5 $image > $vfile

# horizon output file (overwritten each time step)
hfile=$tdir/hor

# shade output file (overwritten each time step)
sfile=$tdir/shade


j=0
currdate="$year,$month,$day,$hour,$min,$sec"
currtime=`addtime -d $currdate -h 0 -c`
endtime=`addtime -d $currdate -h 24 -c`


# Loop on times

while [ $currtime -le $endtime ]
do

#   Extension for output files

	ext=`echo $j | awk '{printf "%02d", $1}'`
	tfile=$out_prefix.$ext
	rfile=$tdir/erad.$ext

#   Get sun angles for this time

	angout=`sunang -t $currdate -b $lat -l $lon`
	mu=`expr "$angout" : '.*-u \(.*\) -a'`
	azm=`expr "$angout" : '.*-a \(.*\)'`
	sun_down=`echo $mu | grep -c "-"`

#   If sun below horizon print message (don't run models)

	if [ $sun_down -ne 0 ] ; then

		echo Sun below horizon at $currdate: $tfile not created

	else

#	Run elevrad to get beam & diffuse

		elevrad -n 8 -z $elev -t $tau -w $omega -g $gfact -r $R0 -s $S0 \
			-u $mu $tdir/iZ > $rfile

#	Run horizon to get sun-below-horizon mask

		horizon -u $mu -a $azm $efile > $hfile

#	Run shade to get cossine local illumination angle; mask by horizon mask

		shade -u $mu -a $azm $grfile | \
			mux - $hfile | \
			bitcom -m -a > $sfile

#	Form input file and run toporad

		mux $rfile $sfile $vfile | toporad $net > $tfile
	fi

#   Increment time and index

	currdate=`addtime -d $currdate -h $delta_t`
	currtime=`addtime -d $currdate -h 0 -c`
	j=`expr $j + 1`

done

# remove temporary files

rm -rf $tdir

exit 0
