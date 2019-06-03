#!/bin/bash

if [ ! -d trash ]
then
	mkdir -p trash;
fi

if [ -e $1 ]
then
	for i in $@; 
	do
		[ -f "$i" ] || break
		mv $i ./trash
		touch ./trash/$i
	done
else
	echo "File $1 does not exist"
fi

if [ -d trash ]
then
	find ./trash -mmin +60 -type f -delete
fi
