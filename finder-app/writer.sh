#!/bin/bash
#writer.sh


writefile=$1
writestr=$2

if [ -z "$writefile" ] || [ -z "$writestr" ]; then
    echo "missing param"
    exit 1
fi

# Write the string to the file (overwrite if exists)
mkdir -p "$(dirname "$writefile")"
echo "$writestr" > "$writefile"


if [ ! -f "$writefile" ]; then
    echo "unable to create file"
    exit 1
fi
