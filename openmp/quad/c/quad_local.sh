#!/bin/bash
#
#  Create new quad_local_output.txt, and write to it.
#
export OMP_NUM_THREADS=1
./quad > quad_local_output.txt
#
#  Append to existing quad_local_output.txt.
#
export OMP_NUM_THREADS=2
./quad >> quad_local_output.txt

export OMP_NUM_THREADS=4
./quad >> quad_local_output.txt

export OMP_NUM_THREADS=8
./quad >> quad_local_output.txt
#
echo "quad_local: Normal end of execution."
