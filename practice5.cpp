#include <iostream>
#include <omp.h>

int main() {
    const int array_size = 100000;
    double A[array_size];
    double B[array_size];
    double result = 0.0;

    int num_threads;
    double start_time, end_time;

    //배열 초기화
    #pragma omp parallel for
    for (int i = 0; i < array_size; i++) {
        A[i] = (i + 1) / 100000.0;
        B[i] = (100000 - i) / 100000.0;
    }

    for (num_threads = 1; num_threads <= 4; num_threads *= 2) {
        omp_set_num_threads(num_threads);

        start_time = omp_get_wtime();
        #pragma omp parallel for reduction(+:result)
        for (int i = 0; i < array_size; i++) {
            result += A[i] * B[i];
        }
        end_time = omp_get_wtime();

        printf("Number of threads: %d\n", num_threads);
        printf("Result: %lf\n", result);
        result = 0;
        printf("Time: %lf seconds\n", (end_time - start_time));
        printf("\n");
    }

    return 0;
}
