#include <stdio.h>
#include <omp.h>
#include <math.h>

#define MAX 10

int main(){
    double Data[MAX];
    double add_Data[MAX],mul_Data[MAX],sqrt_Data[MAX],log_Data[MAX];
    #pragma omp parallel num_threads(4)
    {
        #pragma omp sections
        {
            #pragma omp section
            {
                #pragma omp parallel for
                for(int i = 0; i < MAX; i++){
                    add_Data[i] = Data[i] + Data[i];
                    printf("add_data : %d\n", omp_get_thread_num());
                }
            }
            #pragma omp section
            {
                #pragma omp parallel for
                for(int i = 0; i < MAX; i++){
                    mul_Data[i] = Data[i]*Data[i];
                    printf("mul_data : %d\n", omp_get_thread_num());
                }
            }
            #pragma omp section
            {
                #pragma omp parallel for
                for(int i = 0; i < MAX; i++){
                    sqrt_Data[i] = sqrt(Data[i]);
                    printf("sqrt_data : %d\n", omp_get_thread_num());
                }
            }
            #pragma omp section
            {
                #pragma omp parallel for
                for(int i = 0; i < MAX; i++){
                    log_Data[i] = log(Data[i]);
                    printf("log_data : %d\n", omp_get_thread_num());
                }
            }
        }
    }
}