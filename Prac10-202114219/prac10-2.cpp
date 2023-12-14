#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <math.h>

#define MAX 5000

int main(){
    double* Data = new double[MAX];
    int flag[2][MAX] = {0}; 
    double result_data = 0.0;

    for(int i = 0; i<MAX; i++)
        Data[i] = ((float)i)+1.0;

#pragma omp parallel num_threads(3)
    {
        #pragma omp sections
        {
            #pragma omp section
            {
                for(int i = 0; i<MAX; i++){
                    Data[i] = sqrt(Data[i]);
                    flag[0][i] = 1;
                }
            }
            #pragma omp section
            {
                for(int i = 0; i<MAX ; i++){
                    while(flag[0][i]!=1){} //busy waiting
                    Data[i] = log(Data[i]);
                    flag[1][i] = 1;
                }
            }
            #pragma omp section
            {
                for(int i = 0;i <MAX; i++){
                    while(flag[1][i] != 1){} //busy waiting
                    Data[i] = ldexp(Data[i],7);
                }
            }
        }
    }
    printf("DATA : %f, %f, %f, %f\n", Data[0], Data[1], Data[2], Data[3]);
    delete[] Data;
    return 0;
}