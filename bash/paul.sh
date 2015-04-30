#!/bin/bash

cat /dev/random | base64 | tr -dc 'A-Z' | fold -w 40000 | head -n 1 | sed 's/..../&\
/g' | sort
