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

