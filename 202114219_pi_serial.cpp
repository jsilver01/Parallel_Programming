#include <stdio.h>
#include <omp.h>

#define N 1000000000

int main(){
    int i;
    double x, pi, sum = 0.0;
    double width = 1.0 / N;

    double start = omp_get_wtime();

    for (int i = 0; i < N; i++) {
        x = (i + 0.5) * width;
        double height = 4.0 / (1.0 + x * x);
        sum += height;
    }
    pi = width * sum;

    double end = omp_get_wtime();

    printf("serial version PI = %f\n", pi);
    printf("serial version time = %f seconds\n", end - start);
    
    return 0;
}