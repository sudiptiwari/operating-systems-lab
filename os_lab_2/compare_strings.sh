#!/bin/bash

echo "Enter two strings:"
read -p "Enter first string: " string1
read -p "Enter second string: " string2

if [ "$string1" = "$string2" ]; then
    echo "Strings are equal"
else
    echo "Strings are not equal"
fi
