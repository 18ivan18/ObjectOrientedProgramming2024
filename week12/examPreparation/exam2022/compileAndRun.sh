#!/bin/bash

g++ *.cpp -c
g++ *.o -o main
cat input.txt | main
rm main