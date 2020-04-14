#include <omp.h>
#include <stdlib.h>
#include <stdio.h>
#include "PerformanceCounter.h"

#define s 256
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
    #pragma omp parallel for
    for( int ih=0; ih<n; ih += s )
    {
        #pragma omp parallel for
        for( int jh=0; jh<n; jh += s )
        {
            for(int kh=0; kh<n; kh += s )
            {
                for( int il=0; il<s; ++il)
                {
                    for( int kl=0; kl<s; ++kl)
                    {
                        for( int jl=0; jl<s; ++jl)
                        {    
                            C[ih + il][jh+jl] += A[ih+il][kh+kl] * B[kh+kl][jh+jl];
                        }
                    }
                    
                }
            }
        }
    }
    printf("%0.6f", GetCounter());
    return 0;
} 