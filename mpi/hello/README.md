```sh
$ mpirun ./hello -np 4
```
> MPI C++ bindings that have been removed from the MPI standard more than one decade ago, and I do not know if MS-MPI still provides them. Your best bet is to modernize your code and use the plain C bindings, or an other C++ish layer such as Boost.MPI
