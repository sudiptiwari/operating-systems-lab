#!/bin/bash
echo "Enter 3 numbers:"
read -p "First number: " a
read -p "Second number: " b
read -p "Third number: " c

if [ $a -gt $b -a $a -gt $c ]; then
    echo $a" is the greatest."
elif [ $b -gt $c -a $b -gt $a ]; then
    echo $b" is the greatest."
else
    echo $c" is the greatest."
fi

