#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

#include "mpi.h"

//****************************************************************************80
//
//  Purpose:
//
//    MAIN is the main program for HELLO.
//
//****************************************************************************80

int main(int argc, char *argv[])
{
  int id;
  int p_num;
  //
  //  Initialize MPI.
  //
  MPI::Init(argc, argv);
  //
  //  Get the number of processes.
  //
  p_num = MPI::COMM_WORLD.Get_size();
  //
  //  Get the individual process ID.
  //
  id = MPI::COMM_WORLD.Get_rank();
  //
  //  Only process 0 prints this message.
  //
  if (id == 0)
  {
    cout << "\n";
    cout << "HELLO - Master process:\n";
    cout << "  C++ version\n";
    cout << "\n";
    cout << "  The number of processes is " << p_num << "\n";
    cout << "\n";
  }
  //
  //  Every process prints this message.
  //
  cout << "  Hello from process " << id << "\n";
  //
  //  Shut down MPI.
  //
  MPI::Finalize();

  return 0;
}
