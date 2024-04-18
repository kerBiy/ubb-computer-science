#!/bin/bash

# Sa se afiseze ordonate descrescator dupa dimensiune toate fisierele din directorul /tmp ale caror dimensiune inmultita cu 1000000 este mai mare decat numarul i-node-ului acelui fisier. Folositi comanda stat pentru a afla numarul i-nod-ului (Inode).

nr=1000000

for file in $(find /tmp -type f); do
    size=$(du -b "$file" | awk '{print $1}')
    finalSize=$((size * nr))

    iNode=$(stat $file | grep -E -o "Inode: [0-9]*" | awk '{print $2}')

    if [ $finalSize -gt $iNode ]; then
        echo $size $file
    fi
done | $(sort -nr)

exit 0
