#!/bin/bash

# 9. Să se scrie un script bash care afişează, pentru fiecare fişier 
# dat ca argument, linia care apare de cele mai multe ori. Afişarea 
# se va face în ordinea descrescătoare a numărului de apariţii.
# (comenzi: sort, uniq, head)

if [ $# -eq 0 ]; then
    echo "No files provided." >&2
    exit 1
fi

for file in "$@"; do
    if [ ! -f "$file" ]; then
        echo "File '$file' not found." >&2
        continue
    fi

    lines_with_counts=$(sort "$file" | uniq -c | sort -nr)
    most_frequent_line=$(echo "$lines_with_counts" | head -n 1)

    echo "Most frequent line in '$file': $most_frequent_line"
done

exit 0
