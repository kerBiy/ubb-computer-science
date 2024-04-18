#!/bin/bash

longestLine=""
maxLength=0

for file in $(find "$1" -type f); do
    while read line; do
        currLength=${#line}
    
        if [ $currLength -gt $maxLength ]; then
            maxLength=$currLength
            longestLine="$line"
        fi

    done < "$file"
done
echo "The longest line is: $longestLine"
