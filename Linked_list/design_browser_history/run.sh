#!/usr/bin/env bash

INPUT_FILE="input.txt"
OUTPUT_FILE="output.txt"

g++ -std=c++20 -o output *.cpp

# Check if compilation was successful
if [[ $? -ne 0 ]]; then
  echo "Compilation failed."
  exit 1
fi

# Run the compiled program with input from input.txt and redirect the output to output.txt
./output < "$INPUT_FILE" > "$OUTPUT_FILE"

rm output
