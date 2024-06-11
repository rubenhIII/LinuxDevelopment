#!/bin/bash

i_max=10;

for (( i=0; i<=$i_max; i++))
do
	echo $i
done

for file in $(ls | grep .txt)
do
	echo "$file is a text file"
done
