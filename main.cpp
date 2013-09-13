#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <armadillo>
#include <math.h>

#include "lib.h"
using namespace std;
using namespace arma;
#include <time.h>
int main(int argc, char** argv)
  {
    int N = 1000;
    int i, j, * indx;
    double **A, * f, *x, d, h = 1.0/(N-1);
    clock_t t;
    f = new double[N];
    x = new double[N];

    for(i = 0; i < N; i++)
           x[i] = i*h;


    for(i = 0; i < N; i++)
           f[i] = 100*exp(-(10*x[i])*h*h);


    A = (double **) matrix(N, N, sizeof(double));
    // Initialize tridiagonal array with 2's and -1's
    for(i = 0; i < N; i++)
        for(j = 0; j < N; j++)
            if(i == j)
                A[i][j] = 2.0;
            else if((j-1 == i) || (i-1 == j) )
                A[i][j] = -1.0;
            else A[i][j] = 0.0;
    t = clock();
    ludcmp(A, N, indx, &d);
    lubksb(A, N, indx, f);

    t = clock() -t;
    fprintf(stdout, "Execution time %.5f for N=%d\n", (float) t/CLOCKS_PER_SEC, N);


    delete [] f;
    delete [] x;
    free_matrix((void **) A);


return 0;


}
