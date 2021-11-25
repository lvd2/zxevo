#!/bin/bash

# usage: 1251toutf8.sh filename

# make the conversion
iconv -f cp1251 -t utf8 $1 >/tmp/111.111
if [ $? -ne 0 ]
then
	echo Error converting $1!
	exit 1
fi

# reverse conversion
iconv -f utf8 -t cp1251 /tmp/111.111 >/tmp/222.222
if [ $? -ne 0 ]
then
	echo Error back-converting $1!
	exit 1
fi

# compare reverse converted file with the original
diff $1 /tmp/222.222
if [ $? -ne 0 ]
then
	echo Error comparing $1!
	exit 1
fi

# comparison ok, replace the file
cp /tmp/111.111 $1

# remove temporary files
rm -f /tmp/111.111
rm -f /tmp/222.222

exit 0

