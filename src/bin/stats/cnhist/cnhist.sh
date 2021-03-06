PATH="$PATH:$IPW/lib"

synopsis='[begin [end]]'
description='%description'

case $# in
0)	lo=0
	hi=-1
	;;
1)	lo=$1
	hi=-1
	;;
2)	lo=$1
	hi=$2
	;;
*)	lo=-H
	;;
esac

case $lo in
-H)	exec usage $0 "$synopsis" "$description"
	;;
esac

{
	echo $lo $hi 
	primg -r -a
} |
	awk '
		# NR == DN + 2

		NR == 1 {
			lo = $1 + 2

			hi = $2
			if (hi >= 0) {
				hi += 2
			}

			next
		}

		NR < lo {
			hist[NR] = 0
			next
		}

		hi < 0 || NR <= hi {
			sum += $1
			hist[NR] = sum 
			next
		}

		hi >= 0 && NR > hi {
			hist[NR] = sum
		}

		END {
			for (i = 2; i <= NR; ++i) {
				print hist[i] / sum
			}
		}
	' 
