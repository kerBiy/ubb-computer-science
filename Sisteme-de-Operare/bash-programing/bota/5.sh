#!/bin/bash

# 5. Să se scrie un script bash care pentru fiecare argument 
# din linia de comandă:
# - dacă e fișier, va afişa numele, numărul de caractere 
# și de linii (în această ordine)
# - dacă e director, va afişa numele și câte fișiere 
# conține (inclusiv în subdirectoare).
# (comenzi: find, grep, test, wc)

for arg in $@; do
    if [ -f $arg ]; then
        chrNum=$(cat $arg | wc -c)
        lineNum=$(cat $arg | wc -l)
        echo "Fisierul: $arg: $chrNum caractere, $lineNum linii"
    elif [ -d $arg ]; then
        fileNum=$(find $arg | wc -l)
        echo "Directorul: $arg: $fileNum de fisiere"
    else 
        echo "The arg $arg is not valid."
    fi
done
