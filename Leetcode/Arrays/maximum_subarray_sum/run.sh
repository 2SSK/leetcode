#!/usr/bin/env bash

INPUT_FILE="input.txt"
OUTPUT_FILE="output.txt"

g++ -std=c++20 -o output *.cpp

if [[ $? -ne 0 ]]; then
    echo "Compilation failed."
    exit 1
fi

./output < "$INPUT_FILE" > "$OUTPUT_FILE"

rm output
