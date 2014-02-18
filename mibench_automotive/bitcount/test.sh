#!/bin/bash

ERRORS=0

for i in `seq 1 1000`
do
	timeout 1 ./bitcnts 1 `./fuzz.exe` > /dev/null 2>&1
	if [ "$?" = "124" ]; then
		ERRORS=`expr $ERRORS + 1`
	fi
done

echo total errors: $ERRORS