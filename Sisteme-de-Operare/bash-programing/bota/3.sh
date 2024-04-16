#!/bin/bash

# 3. Să se scrie un script bash care calculează numărul mediu
# de linii ale fișierelor de tip text dintr-un director dat ca argument.
# (comenzi: find, file, grep, wc)

if ! [ $# -eq 1 ] || ! [ -d $1 ]; then
    echo "Argumentul nu este valid." >&2
    exit 1
fi

sum=0
count=0

for file in $(find $1 -type f -name "*.txt"); do
    lineNum=$(wc -l < $file)
    sum=$((sum + lineNum))
    count=$((count + 1))
done

average=$(awk "BEGIN {printf \"%.2f\", $sum / $count}")
echo "The average is: $average"
