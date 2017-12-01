#!/bin/sh

for zip in *.zip;do
	unzip $zip
	cd ${zip%%.*}
	make
	mkdir ans
	for filename in ../*.p; do
		./parser $filename 1> ans/r${filename##*/} 2>&1
	done
done
