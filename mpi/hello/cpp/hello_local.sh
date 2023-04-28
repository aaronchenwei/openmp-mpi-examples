#!/bin/bash
#
#  Create new hello_local_output.txt, and write to it.
#
mpirun -np 1 ./build/hello > hello_local_output.txt

#
#  Append to existing hello_local_output.txt.
#
mpirun -np 2 ./build/hello >> hello_local_output.txt

mpirun -np 4 ./build/hello >> hello_local_output.txt

mpirun -np 8 ./build/hello >> hello_local_output.txt

#
echo "hello_local: Normal end of execution."
