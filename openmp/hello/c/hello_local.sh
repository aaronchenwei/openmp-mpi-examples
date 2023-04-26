#!/bin/bash
#
#  Create new hello_local_output.txt, and write to it.
#
export OMP_NUM_THREADS=1
./hello > hello_local_output.txt
#
#  Append to existing hello_local_output.txt.
#
export OMP_NUM_THREADS=2
./hello >> hello_local_output.txt

export OMP_NUM_THREADS=4
./hello >> hello_local_output.txt

export OMP_NUM_THREADS=8
./hello >> hello_local_output.txt
#
echo "hello_local: Normal end of execution."
