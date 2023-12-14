#include <iostream>
#include <omp.h>
#include <stdlib.h>

int main(void) {
    float matrix[ROWS][COLS];
    float results[ROWS];
    float vec[COLS];
	int i, j=0;

    double start_time, end_time;

    for (j = 0; j < ROWS; j++) {
        for (i = 0; i < COLS; i++) {
            matrix[j][i] = (((float) j) * COLS + (float) i) / ((float) 1000.);
        }
    }

    for (i = 0; i < COLS; i++)
        vec[i] = ((float) i) / (float) 1000.;
        
    for (i=0;i<ROWS;i++)
                results[i] = 0.0;

#pragma omp barrier
    start_time = omp_get_wtime();
    mxv(matrix, vec, results, COLS, ROWS);
    end_time = omp_get_wtime();

    for (i = 0; i < ROWS; i++) {
        printf("resi=%f\n", results[i]);
    }
    printf("Exe. Time = %f msec\n", (end_time - start_time) * 1000.0);

    return 0;
}