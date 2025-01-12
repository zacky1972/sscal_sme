#!/bin/sh

PATH=.:$PATH

neon8 992 -
neon8 9984 -
neon8 100000 -
neon8 1000000 -
neon8 10000000 -
echo "----"
neon8 992 +
neon8 9984 +
neon8 100000 +
neon8 1000000 +
neon8 10000000 +
echo "===="

