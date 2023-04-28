#!/bin/bash
#
#  Create new quad_local_output.txt, and write to it.
#
mpirun -np 1 ./build/quad 1000000000 > quad_local_output.txt

#
#  Append to existing quad_local_output.txt.
#
mpirun -np 2 ./build/quad 1000000000 >> quad_local_output.txt

mpirun -np 4 ./build/quad 10000000 >> quad_local_output.txt
mpirun -np 4 ./build/quad 100000000 >> quad_local_output.txt
mpirun -np 4 ./build/quad 1000000000 >> quad_local_output.txt

mpirun -np 8 ./build/quad 1000000000 >> quad_local_output.txt

#
echo "quad_local: Normal end of execution."
