#!/bin/bash

#1. Să se scrie un script bash care primeşte ca argument un număr natural N şi generează N fişiere de tip text, astfel:
#- numele fişierelor vor fi de forma: file_X.txt, unde X = {1, 2, ..., N}
#- fiecare fişier generat va conţine doar liniile de la X la X + 5 ale fişierului /etc/passwd.
#(comenzi: touch, sed)

if [ $# -eq 0 ]; then
    echo 'Numar insuficient de argumente.' >&2
    exit 1                                  
fi

for i in `seq 1 $1`; do
    sed -n "$i,+5p" ../passwd  > file_$i.txt 
done
