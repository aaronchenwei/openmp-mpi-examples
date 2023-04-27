# openmp-mpi-examples

## Prerequisites

- C/C++ Compiler (gcc/g++)
- [MPICH](https://www.mpich.org/) or [OpenMPI](https://www.open-mpi.org/)

### Ubuntu Linux

```sh
$ sudo apt install build-essential mpich libmpich-dev
``` 

### Alma Linux 8

```sh
$ sudo dnf groupinstall "Development Tools"
$ sudo dnf install mpich mpich-devel
```

After installation of above packages are done, we need to modify `.bashrc` (or simmilar) to add mpich to `PATH` and `LD_LIBRARY_PATH`.

```sh
export PATH=$PATH:/usr/lib64/mpich/bin
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/lib64/mpich/lib
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
