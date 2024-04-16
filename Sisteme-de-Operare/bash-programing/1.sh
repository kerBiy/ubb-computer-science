#!/bin/bash

cat who | awk '{print $1}' | sort | \
while read user; do
    num_processes=`cat ps | grep -c "^$user"`
    echo "$user $num_processes"
done
