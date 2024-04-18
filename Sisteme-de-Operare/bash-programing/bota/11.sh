#!/bin/bash

# 11. Să se scrie un script bash care pentru fiecare fişier cu drepturile
# 755 dintr-un director (şi subdirectoarele sale) dat ca argument îi va 
# modifica drepturile de acces în 744. Înainte de a modifica drepturile 
# de acces, script-ul va cere confirmarea din partea utilizatorului 
# (pentru fiecare fişier în parte).
# (comenzi: find, chmod, read)

if [ $# -ne 1 ]; then
    echo "Invalid args." >&2
    exit 1
fi

for file in $(find $1 -type f -perm 755); do
    echo "Do you want to change the rights for $file? (y/n)"
    read -p "Your choice: " answer

    if echo $answer | grep -i -q "^y"; then
        chmod 744 $file
        echo "Permisions of file $file changed"
    else
        echo "Skiping file $file"
    fi
done

exit 0
