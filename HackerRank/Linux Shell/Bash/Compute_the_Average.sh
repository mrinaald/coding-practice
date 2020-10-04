#!/bin/bash

read n
sum=0
for i in $(seq "$n");
do
	read num
	sum=$((sum+num))
done

printf "%.3f" $(echo "scale=5; $sum / $n" | bc)