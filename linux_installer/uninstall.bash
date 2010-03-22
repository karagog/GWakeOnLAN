#! /bin/bash

LIBDIR="/usr/local/lib/gwakeonlan"

if [ -f /usr/local/bin/gwakeonlan ]; then
	rm /usr/local/bin/gwakeonlan;
fi;

if [ -d "$LIBDIR" ]; then
	rm -rf "$LIBDIR";
fi;


