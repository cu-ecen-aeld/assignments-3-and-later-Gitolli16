#!/bin/bash
#finder.sh


filesdir=$1
searchstr=$2

if [ -z "$searchstr" ] || [ -z "$filesdir" ]; then
        echo "missing param"
        exit 1

elif [ ! -d "$filesdir" ]; then
        echo "dir doesnt exist"
        exit 1

else
        echo "The number of files are $(find "$filesdir" -type f | wc -l) and the number of matching lines are $(grep -rl "$searchstr" "$filesdir" | wc -l)"

fi

