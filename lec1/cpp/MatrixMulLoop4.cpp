#include <stdlib.h>
#include <stdio.h>
#include "PerformanceCounter.h"

#define n 4096
double A[n][n];
double B[n][n];
double C[n][n];



int main( int argc, const char* argv[])
{
    for(int i = 0; i<n;++i)
    {
        for(int j=0; j<n; ++j )
        {
            A[i][j] = (double)rand() / (double)RAND_MAX;
            B[i][j] = (double)rand() / (double)RAND_MAX;
            C[i][j] = 0;
        }
    }

    
    StartCounter();
    for( int j=0; j<n; ++j)
    {
        for(int k=0; k<n; ++k )
        {
            for( int i=0; i<n; ++i )
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    printf("%0.6f", GetCounter());
    return 0;
}