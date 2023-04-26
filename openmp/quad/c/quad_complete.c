#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <omp.h>

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for QUAD.

  Discussion:

    QUAD is a sketch of a C program to estimate the integral of
    a function F(X) between A and B.

    This program is only a sketch.  Your job is to finish it,
    debug it, and get it to run.

    Experiment to get a value of N that gives you a 'reasonable' accuracy.

    NOW modify the program so that it will run under OpenMP.  Replace
    CPU time by wall clock time.

    Show that your program STILL gets the right answer.

    Then determine the speedup when you run the OpenMP version on
    1, 2, 4, 8 processors.

*/

/******************************************************************************/

int main(int argc, char *argv[])
{
  double a = 0.0;
  double b = 10.0;
  double error;
  double exact = 0.49936338107645674464;
  int flops;
  int i;
  double mflops;
  int n = 1000000;
  double pi = 3.141592653589793;
  double total;
  double wtime;
  double wtime1;
  double wtime2;
  double *x;

  printf("\n");
  printf("QUAD:\n");
  printf("  C version\n");
  printf("\n");
  printf("  Estimate the integral of f(x) from A to B.\n");
  printf("  f(x) = 50 / ( pi * ( 2500 * x * x + 1 ) ).\n");
  printf("  A = %f\n", a);
  printf("  B = %f\n", b);
  printf("  Exact integral from 0 to 10 is 0.49936338107645674464...\n");

  x = (double *)malloc(n * sizeof(double));
  /*
    Step 1:
    Load the array X with evenly spaced values between A and B.
  */
  for (i = 0; i < n; i++)
  {
    x[i] = ((double)(n - i - 1) * a + (double)(i)*b) / (double)(n - 1);
  }
  /*
    Step 2:

    Use a FOR loop to add to TOTAL the value of the function at each X.

    Set FLOPS, the number of floating point operations, by counting the
    number of floating operations in the statement that updates TOTAL,
    and multiplying by N (number of times you did the loop).

    add the OpenMP include file,

    insert OpenMP directives before the loop of the form

      # pragma omp parallel private ( ... ) shared ( ... )
      # pragma omp for reduction ( + : ... )
  */
  wtime1 = omp_get_wtime();
  total = 0.0;

#pragma omp parallel private(i) \
    shared(n, pi, x)

#pragma omp for reduction(+ : total)
  for (i = 0; i < n; i++)
  {
    total = total + 50 / pi / (2500.0 * x[i] * x[i] + 1.0);
  }

  flops = 6 * n;
  wtime2 = omp_get_wtime();
  total = (b - a) * total / (double)n;
  /*
    Step 3:
    Print quadrature estimate, Error, W time, MFLOPS rate
  */
  error = fabs(total - exact);
  wtime = wtime2 - wtime1;
  mflops = (double)(flops) / 1000000.0 / wtime;

  printf("\n");
  printf("  Estimate = %f\n", total);
  printf("  Error    = %e\n", error);
  printf("  W time   = %f\n", wtime);
  printf("  FLOPS    = %d\n", flops);
  printf("  MFLOPS   = %f\n", mflops);

  free(x);

  return 0;
}
