#!/bin/bash

# 7. Să se scrie un script bash care primește ca argumente 
# oricâte nume de fișiere. Scriptul va citi de la tastatură două 
# cuvinte și va înlocui TOATE aparițiile primului cuvânt cu cel 
# de-al doilea în fiecare fișier furnizat ca argument.
# (comenzi: read, sed)

if [ $# -eq 0 ]; then
    echo "The args are not valid." >&2
    exit 1
fi

read -p "Enter the word you want to replace: " firstWord
read -p "With what word: " secondWord

for file in $*; do
    if [ -f $file ]; then     
        touch $file.tmp
        sed "s/$firstWord/$secondWord/g" $file > $file.tmp
        mv $file.tmp $file
        echo "$file was modified."
    else
        echo "$file is not a file."
    fi
done

exit 0
