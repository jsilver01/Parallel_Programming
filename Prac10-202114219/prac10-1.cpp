#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <math.h>

#define MAX 100000

int main(){
    double* Data = new double[MAX];
    double result_data = 0.0;

    for(int i = 0; i<MAX; i++)
        Data[i] = ((float)i)+1.0;

#pragma omp parallel num_threads(2) shared(result_data)
    {
        #pragma omp sections
        {
            #pragma omp section
            {
                for(int i = 0; i < MAX; i++)
                {
                    #pragma omp critical(sc1)
                    {
                        result_data += sqrt(Data[i]);
                    }
                }
            }
            #pragma omp section
            {
                for(int i =0 ; i<MAX; i++)
                {
                    #pragma omp critical(sc1)
                    {
                        result_data += log(Data[i]);
                    }
                }
            }
        }
    }
    printf("Result Data : %lf\n", result_data);
    delete Data, result_data;
    return 0;
}