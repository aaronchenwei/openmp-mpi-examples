#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <mpi.h>

int main(int argc, char *argv[])

/******************************************************************************/
/*
  Purpose:

    PRIME counts the prime numbers between 2 and N_HI.

  Discussion:

    This program uses MPI to divide the work among P processes.

    Each process prints out its partial result and wall clock time.

    Process 0 prints the total and total time.
*/
{
  int i;
  int id;
  int id_n_hi;
  int id_n_lo;
  int id_total;
  int j;
  int n_hi = 100000;
  int n_lo = 2;
  int p;
  int prime;
  double wtime;
  int total;

  /*
    Initialize MPI.
  */
  MPI_Init(&argc, &argv);
  /*
    Get the number of processes.
  */
  MPI_Comm_size(MPI_COMM_WORLD, &p);
  /*
    Determine this processes's rank.
  */
  MPI_Comm_rank(MPI_COMM_WORLD, &id);
  /*
    Work that only process 0 should do.
  */
  if (id == 0)
  {
    printf("\n");
    printf("PRIME\n");
    printf("  C version\n");
    printf("  Number of processes = %d\n", p);
    printf("\n");
    printf("        ID      N_LO      N_HI         TOTAL        TIME\n");
    printf("\n");
    total = 0;
    wtime = MPI_Wtime();
  }
  /*
    Each process computes a portion of the sum.
  */
  id_total = 0;

  id_n_lo = ((p - id) * n_lo + (id) * (n_hi + 1)) / (p);

  id_n_hi = ((p - id - 1) * n_lo + (id + 1) * (n_hi + 1)) / (p)-1;

  for (i = id_n_lo; i <= id_n_hi; i++)
  {
    prime = 1;

    for (j = 2; j < i; j++)
    {
      if (i % j == 0)
      {
        prime = 0;
        break;
      }
    }
    if (prime)
    {
      id_total = id_total + 1;
    }
  }
  printf("  %8d  %8d  %8d  %12d\n", id, id_n_lo, id_n_hi, id_total);
  /*
    Use REDUCE to gather up the partial totals and send to process 0.
  */
  MPI_Reduce(&id_total, &total, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

  if (id == 0)
  {
    wtime = MPI_Wtime() - wtime;
    printf("\n");
    printf("     Total  %8d  %8d  %12d  %14f\n", n_lo, n_hi, total, wtime);
  }

  MPI_Finalize();

  return 0;
}
