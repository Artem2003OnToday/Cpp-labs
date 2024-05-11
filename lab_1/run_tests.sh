#!/usr/bin/env bash

g++ tests.cpp doctest_main.cpp -std=c++20 -o tests.out
./tests.out
