#!/bin/bash
#
#  Create new prime_local_output.txt, and write to it.
#
mpirun -np 1 ./prime > prime_local_output.txt

#
#  Append to existing prime_local_output.txt.
#
mpirun -np 2 ./prime >> prime_local_output.txt

mpirun -np 4 ./prime >> prime_local_output.txt

mpirun -np 8 ./prime >> prime_local_output.txt

#
echo "prime_local: Normal end of execution."
