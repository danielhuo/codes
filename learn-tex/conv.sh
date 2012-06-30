#!/bin/bash

files=`find ./ -iname "*.tex"`
for f in $files; do
    iconv -f=gbk -t=utf8 $f -o $f.utf8
    mv $f /tmp/$f
    mv $f.utf8 $f
done
