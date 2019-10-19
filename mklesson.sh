#!/bin/bash

if [ ! -z "$1" ]; then
    mkdir $1
    cp skeleton.ino $1/$1.ino
fi
