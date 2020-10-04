#!/bin/bash

read n
pow=$((6-n))
lim=$(( 2**pow ))
pow=$((5-n))
ch=$((2**pow))
# echo "$lim"
# echo "$ch"

for i in $(seq "$((lim-1))")
do
	for j in $(seq 100)
	do
		echo -n "_"
	done
	echo ''
done

for i in $(seq "$n")
do
	offset=
for it in $(seq "$n")
do

	ch=$((ch*2))
done