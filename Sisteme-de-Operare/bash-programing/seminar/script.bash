#!/bin/bash

D=$1

if [ -z "$D" ]; then
    echo "ERROR: No directory provided for monitoring" >&2
    exit 1
fi

if [ ! -d "$D" ]; then
    echo "ERROR: Directory $D does not exist" >&2
    exit 1
fi

STATE=""

while true; do
    S=""

    for P in `find $D`; do
        if [ -f $P ]; then
            LS=`ls -l $P | shasum -a 1`
            CONTENT=`shasum -a 1 $P`
        else
            LS=`ls -ld $P | shasum -a 1`
            CONTENT=`ls -l $P | shasum -a 1`
        fi
        S="$S\n$LS $CONTENT"
    done

    if [ -n "$STATE" ] && [ "$S" != "$STATE" ]; then
        echo "Directory state changed"
    fi

    STATE="$S"
    sleep 1
done

