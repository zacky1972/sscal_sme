#!/bin/sh

PATH=.:$PATH

apple_blas 1000 -
apple_blas 10000 -
apple_blas 100000 -
apple_blas 1000000 -
apple_blas 10000000 -
echo "----"
apple_blas 1000 +
apple_blas 10000 +
apple_blas 100000 +
apple_blas 1000000 +
apple_blas 10000000 +
echo "===="
open_blas 1000 -
open_blas 10000 -
open_blas 100000 -
open_blas 1000000 -
open_blas 10000000 -
echo "----"
open_blas 1000 +
open_blas 10000 +
open_blas 100000 +
open_blas 1000000 +
open_blas 10000000 +
echo "===="
if [ -e sme ]; then
if [ "$(uname -m)" = "arm64" ] || [ "$(uname -m)" = "aarch64" ]; then
if [ "$(uname -o)" = "Darwin" ]; then
if sysctl hw.optional | grep "SME: 1" >/dev/null; then
sme 1000 -
sme 10000 -
sme 100000 -
sme 1000000 -
sme 10000000 -
echo "----"
sme 1000 +
sme 10000 +
sme 100000 +
sme 1000000 +
sme 10000000 +
fi
fi
fi
fi
echo "===="
clang_for 1000 -
clang_for 10000 -
clang_for 100000 -
clang_for 1000000 -
clang_for 10000000 -
echo "----"
clang_for 1000 +
clang_for 10000 +
clang_for 100000 +
clang_for 1000000 +
clang_for 10000000 +
echo "===="
if [ -e neon ]; then
if [ "$(uname -m)" = "arm64" ] || [ "$(uname -m)" = "aarch64" ]; then
neon 1000 -
neon 10000 -
neon 100000 -
neon 1000000 -
neon 10000000 -
echo "----"
neon 1000 +
neon 10000 +
neon 100000 +
neon 1000000 +
neon 10000000 +
echo "===="
neon2 1000 -
neon2 10000 -
neon2 100000 -
neon2 1000000 -
neon2 10000000 -
echo "----"
neon2 1000 +
neon2 10000 +
neon2 100000 +
neon2 1000000 +
neon2 10000000 +
echo "===="
fi
fi

