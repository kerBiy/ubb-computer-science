#!/bin/bash

# 6. Să se scrie un script bash care primește ca argumente
# oricâte nume de fișiere. Scriptul va citi de la tastatură
# un cuvânt, va determina și afișa numărul de apariţii ale
# cuvântului în fiecare fișier furnizat ca argument.
# (comenzi: read, grep)

echo "Plese enter the word: "
read word

for arg in $@; do
    if [ -f $arg ]; then
        count=$(cat $arg | grep -Ec "\b$word\b")
        echo "The file $arg: has $count"
    else
        echo "$arg is not a file."
    fi
done

