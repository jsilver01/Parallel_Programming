#include <stdio.h>
#include <omp.h>

#define N 1000000000

int main(){
    int i;
    double x, pi, sum = 0.0;
    double width = 1.0 / N;

    //omp_set_num_threads(1);
    //omp_set_num_threads(2);
    //omp_set_num_threads(4);
    omp_set_num_threads(8);
    double start = omp_get_wtime();
    #pragma omp parallel
    {
        double privatesum = 0.0;
        #pragma omp for
        for(int i = 0 ; i < N; i++){
            x = (i + 0.5) * width;
            double height = 4.0 / (1.0 + x * x);
            privatesum += height;
        }

        #pragma omp atomic
        sum += privatesum;
    }

    pi = width * sum;

    double end = omp_get_wtime();

    printf("atomic version PI = %f\n",pi);
    printf("atomic version time = %f seconds\n",end-start);
    return 0;
}