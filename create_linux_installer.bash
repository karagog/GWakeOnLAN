#! /bin/bash

SOURCE_DIR=linux_installer
TARGET_DIR=gwakeonlan_v$1
EXECUTABLE=gwakeonlan

cp $EXECUTABLE $SOURCE_DIR

cp $SOURCE_DIR $TARGET_DIR -r
rm "$TARGET_DIR"/.svn -rf

tar -czf $TARGET_DIR.tar.gz $TARGET_DIR

rm $TARGET_DIR -rf

