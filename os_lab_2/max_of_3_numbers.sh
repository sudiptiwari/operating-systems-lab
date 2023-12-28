#!/bin/bash
echo "Enter 3 numbers:"
read -p "First number: " a # -p is for prompt display
read -p "Second number: " b
read -p "Third number: " c

# Mind the space inside if condition check
if [ $a -gt $b -a $a -gt $c ]; then # -gt is greater than
    echo $a" is the greatest."
elif [ $b -gt $c -a $b -gt $a ]; then
    echo $b" is the greatest."
else
    echo $c" is the greatest."
fi

