#! /bin/bash

LIBDIR="/usr/local/lib/gwakeonlan"

if [ ! -f /usr/local/bin/gwakeonlan ]; then
	cp gwakeonlan /usr/local/bin;
fi;

if [ ! -d "$LIBDIR" ]; then
	mkdir "$LIBDIR";
fi;

if [ -d "$LIBDIR" ]; then
	cp libQt*.so.4 "$LIBDIR";
fi;

