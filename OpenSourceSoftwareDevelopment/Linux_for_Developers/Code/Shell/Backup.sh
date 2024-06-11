#!/bin/bash

src_dir=$1; dst_dir=$2;
for file in $( ls -d "$src_dir/"*"/" )
do
	echo "Compressing $file ..."
	backup=$( basename $file )
	gzip -rc $file >> "$dst_dir/$backup.tar.gz"
done
