#!/bin/sh

# Check command line arguments
if [ $# -ne 1 ]
then
    echo "Usage: $0 <day>"
    exit 1
fi

input=$1

# Check value of day
if [ $input -lt 1 ] || [ $input -gt 25 ]
then
    echo "day must be between 1 and 25 inclusive"
    exit 1
fi

# Check if solution exists
if ! [ -e "solutions/$input.cpp" ]
then
    echo "Solution for day $input not found"
    exit 1
fi

# Check if input file exists
if ! [ -e "input/$input.txt" ]
then
    echo "Input file for day $input not found"
    exit 1
fi

# Compile program
cd solutions
g++ -o "$input" "$input.cpp"

# Run it
./"$1" < ../input/"$1.txt"