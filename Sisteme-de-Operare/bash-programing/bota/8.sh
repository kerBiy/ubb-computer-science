#!/bin/bash

# 8. Să se scrie un script bash care are ca argumente triplete 
# formate dintr-un nume de fisier, un cuvant si un numar k. 
# Pentru fiecare astfel de triplet, se vor afişa toate 
# liniile fişierului care contin cuvăntul respectiv exact de k ori.
# (comenzi: shift, wc, sed, grep)

if [ $# -lt 3 ]; then
    echo "Invalid args." >&2
    exit 1
fi

while [ ! $# -eq 0 ]; do
    file=$1
    word=$2
    nr=$3

    regex="\<$word\>"
    for ((i=1; i<$nr; i++)); do
        regex+=".*\<$word\>"
    done

    lines=$(grep -E "$regex" "$file")
    
    echo "The file $file lines:"
    echo "$lines"

    shift 3
done

exit 0
