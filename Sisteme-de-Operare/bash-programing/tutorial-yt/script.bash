#!/bin/bash

for arg in $@; do
    if [ -f $arg ]; then
        echo $arg is a file
    elif [ -d $arg ]; then
        echo $arg is a dir
    else
        echo We do not know what $A is
    fi
done
