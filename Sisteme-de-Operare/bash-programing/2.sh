#!/bin/bash

count=0

find . -type f -name "*.c" | \
while read file; do
    lines=`wc -l < $file`

    if [ $lines -gt 500 ]; then
        echo $file

        count=`expr $count + 1`


        if [ $count -eq 2 ]; then
            break
        fi
    fi
done
