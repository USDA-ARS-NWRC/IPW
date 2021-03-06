PATH="$PATH:$IPW/lib"

pgm=`basename $0`
optstring=
synopsis='image1 image2'
description='%description'

set -- `getopt "$optstring" $* 2>/dev/null` ||
	exec usage $pgm "$synopsis" "$description"

while :; do
	case $1 in
	--)	shift
		break
		;;
	*)	exec sherror $pgm '"getopt" failed'
		;;
	esac

	shift
done

case $# in
2)	;;
*)	exec usage $pgm "$synopsis" "$description"
	;;
esac

case $2 in
-)	exec usage $pgm "$synopsis" "$description"
	;;
esac

tmp=$WORKDIR/`basename $0`$$
tmp2=$WORKDIR/`basename $0`$$-2
trap 'rm -f $tmp $tmp2' 0
trap 'exit 0' 1 2 3 15

case $1 in
-)	rmhdr >$tmp || exit 1
	;;
*)	rmhdr $1 >$tmp || exit 1
	;;
esac

rmhdr $2 > $tmp2 || exit 1
cmp -s $tmp2 $tmp

case $? in
0)	echo "Images \"$1\", \"$2\" are identical"
	;;
*)	echo "Images \"$1\", \"$2\" differ"
	;;
esac

exit 0
