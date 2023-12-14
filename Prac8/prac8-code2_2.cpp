#include <iostream>
#include <omp.h>
#include <stdlib.h>

#define ROWS 4
#define COLS 1000000 //0

void mxv(float (*matrix_d)[COLS], float* vector,float* result,int nocol, int norow){
#pragma omp parallel for num_threads(4)
    for(int y=0; y<norow; y++){
        for(int x=0;x<nocol;x++){
            result[y] += matrix_d[y][x] * vector[x];
        }
    }
}