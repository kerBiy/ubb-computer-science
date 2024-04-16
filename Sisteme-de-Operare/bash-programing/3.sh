#!/bin/bash

find . -type f -name "*.log" | \
while read file; do
    sort -o $file $file
done
