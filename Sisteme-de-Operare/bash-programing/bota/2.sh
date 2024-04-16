#!/bin/bash

# Să se scrie un script bash care afișează primele 3 linii și 
# ultimele 3 linii ale fiecărui fișier de tip text din 
# dintr-un director dat ca argument în linia de comandă.
# Dacă un fișier text are mai puțin de 6 linii,
# atunci conţinutul acestuia va fi afişat în întregime.
# (comenzi: find, file, grep, wc, head, tail)

if ! [ $# -eq 1 ] || ! [ -d $1 ]; then
    echo "Argumentul nu este valid." >&2
    exit 1
fi

for file in $(find $1 -type f -name "*.txt"); do
    echo "Linii din fisierul $file:"
    lineNum=$(wc -l $file | awk '{print $1}')

    if [ $lineNum -le 6 ]; then
        cat "$file"
    else 
        first_lines=$(head -n 3 $file)
        last_lines=$(tail -n 3 $file)

        echo "Fisrt 3 lines:"
        echo "$first_lines"

        echo "Last 3 lines:"
        echo "$last_lines"
    fi
done
