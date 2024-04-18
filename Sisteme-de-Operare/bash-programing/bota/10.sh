#!/bin/bash

# 10. Să se scrie un script bash care va afişa toate numele de 
# fişiere dintr-un director dat ca argument şi din subdirectoarele
# sale, care au numele mai scurte de 8 caractere. Pentru acestea, 
# dacă sunt fişiere text, li se vor afişa primele 10 linii.

if [ $# -eq 0 ]; then
    echo "Invalid args." >&2
    exit 1
fi

for file in $(find $1 -type f); do
    fileName=$(echo $file | sed -E "s@.*/@@")
    chrCount=$(echo $fileName | sed -E "s/\..*//" | wc -c)    
    
    if [ $chrCount -lt 8 ]; then
        echo "File $fileName has less then 8 lines."
    
        if [ $(echo $fileName | grep -c ".txt") -ne 0 ]; then
            echo "And because it's txt the first 10 lines are:"
            head -n 10 $file
        fi
    fi
done 

exit 0
