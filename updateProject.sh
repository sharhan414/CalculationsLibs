#!/bin/bash

#git status
git add -A

if [ ! -v $1 ]
then
	git commit -m "update: $1"
else
	currentDate=$( date )
	git commit -m "update: is $currentDate"
fi
git push
