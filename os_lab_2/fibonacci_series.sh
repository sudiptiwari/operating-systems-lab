#!/bin/bash

echo "Enter the number of fibonacci numbers to display: "
read num_of_terms
a=0
b=1
counter=2

echo "Fibonacci series upto $num_of_terms terms:"
echo -n "$a, $b"
while [ $counter -lt $num_of_terms ]; do

	#Calculate next_term
	next_term=$((a+b))
	echo -n ", $next_term"

	#Update value
	a=$b
	b=$next_term
	counter=$((counter+1))
done
echo "" #New line after the series	
