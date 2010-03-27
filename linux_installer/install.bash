#! /bin/bash

LIBDIR="/usr/local/lib/gwakeonlan"

if [ ! -f /usr/local/bin/gwakeonlan ]; then
	cp gwakeonlan /usr/local/bin;

	chmod 755 /usr/local/bin/gwakeonlan
fi;

if [ ! -d "$LIBDIR" ]; then
	mkdir "$LIBDIR";
fi;

if [ -d "$LIBDIR" ]; then
	cp libQt*.so.4 "$LIBDIR";

	chmod 755 -R "$LIBDIR"
fi;

