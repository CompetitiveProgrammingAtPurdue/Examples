#!/bin/bash

#This runs the generator and solution, and stores the input and output.
#Install tee if you haven't already.
./Stream_Generator | tee input.txt | ./Stream > output.txt
