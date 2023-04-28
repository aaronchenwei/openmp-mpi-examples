# openmp-mpi-examples

**OpenMP** is a set of compiler's directives, library procedures and environment variables which was developed for creating multi-threading apps for systems with shared memory (SMP computers) in 1997. This tool was initially designed for Fortan and later C and C++ were included as well. Nowadays, OpenMP is supported by the most popular C/C++ compilers: gcc, icc, PGI compiler. (Notice, that OpenMP isn't any kind of library in typical sense of that word. It doesn't affect the output binary file directly.)

## Prerequisites

- C/C++ Compiler (gcc/g++)
- [MPICH](https://www.mpich.org/) or [OpenMPI](https://www.open-mpi.org/)

### Ubuntu Linux

```sh
$ sudo apt install build-essential mpich libmpich-dev
``` 

### Alma Linux 8 / CentOS 8

```sh
$ sudo dnf groupinstall "Development Tools"
$ sudo dnf install mpich mpich-devel
```

After installation of above packages are done, we need to modify `.bashrc` (or simmilar) to load module `mpich`.

```sh
module load mpi/mpich-x86_64
```

### OpenSUSE Tumbleweed

```sh
$ sudo zypper install -t pattern devel_basis
$ sudo zypper install mpich-devel
```

Modify `.bashrc` as below.

```sh
export PATH=$PATH:/usr/lib64/mpi/gcc/mpich/bin
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/lib64/mpi/gcc/mpich/lib64
```
