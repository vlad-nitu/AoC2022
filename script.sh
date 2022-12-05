#!/bin/bash

if [ -z "$1" ]
  then
    echo "No argument supplied"
	exit 1
fi

DIR=0"$1"
CMAKE="cmake-build-debug"
if [ ! -d "$DIR" ]; then
mkdir 0"$1" && touch 0"$1"/0"$1"A.cpp && touch 0"$1"/0"$1"B.cpp
fi

if [ -d "$CMAKE" ]; then
cd "$CMAKE"
touch 0"$1"A.in && touch 0"$1"A.out && touch 0"$1"B.in && touch 0"$1"B.out
cd .. 
else
	echo "No $CMAKE folder created, try building the project first"
	exit 1
fi
