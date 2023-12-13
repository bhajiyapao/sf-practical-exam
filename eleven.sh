#!/bin/bash

echo "Enter a sentence"
read sentence

count_vowels() {
    echo "$1" | tr -cd 'aeiouAEIOU' | wc -c
}

val=1

if ((val == 0)); then
    echo "$(echo "$sentence" | wc -w)"
else
    val=0
    export val
    echo "$(count_vowels "$sentence")"
fi
