#include <omp.h>
#include <stdlib.h>
#include <stdio.h>
#include "PerformanceCounter.h"

#define n 4096
float A[n][n];
float B[n][n];
float C[n][n];



int main( int argc, const char* argv[])
{
    for(int i = 0; i<n;++i)
    {
        for(int j=0; j<n; ++j )
        {
            A[i][j] = (float)rand() / (float)RAND_MAX;
            B[i][j] = (float)rand() / (float)RAND_MAX;
            C[i][j] = 0;
        }
    }

    
    StartCounter();
    #pragma omp parallel for
    for( int i=0; i<n; ++i ) 
    {
        for(int k=0; k<n; ++k )
        {
            for( int j=0; j<n; ++j)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    printf("%0.6f", GetCounter());
    return 0;
} 