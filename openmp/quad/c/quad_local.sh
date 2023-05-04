#!/bin/bash
#
#  Create new quad_local_output.txt, and write to it.
#
export OMP_NUM_THREADS=1
./build/quad > quad_local_output.txt
#
#  Append to existing quad_local_output.txt.
#
export OMP_NUM_THREADS=2
./build/quad >> quad_local_output.txt

export OMP_NUM_THREADS=4
./build/quad >> quad_local_output.txt

export OMP_NUM_THREADS=8
./build/quad >> quad_local_output.txt
#
echo "quad_local: Normal end of execution."
