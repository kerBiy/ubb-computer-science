#!/bin/bash

# 4. Să se scrie un script bash care afișează numele fișierelor
# dintr-un director dat ca argument care conțin numere cu peste 5 cifre.
# (comenzi: find, grep, sed)

if ! [ $# -eq 1 ] || ! [ -d $1 ]; then
    echo "The args are not valid." >&2
    exit 1
fi

for file in $(find $1 -type f); do
    count=$(grep -E -o "[0-9]{5,}" $file | wc -l)
    if [ $count -gt 0 ]; then
        file_name=$(echo $file | sed -E "s!.*/!!")
        echo $file_name
    fi
done
