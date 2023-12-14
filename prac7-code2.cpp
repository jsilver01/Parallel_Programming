#include <stdio.h>
#include <omp.h>

#define NUM 100

void swap(int& a, int& b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int main(void){
    int data[NUM][NUM]= {0};
    #pragma omp parallel num_threads(4)
    {
        #pragma omp for //nowait
        for(int i = 0; i < NUM; i++){
            for(int j = 0; j < NUM; j++){
                data[i][j] = i * NUM + j + 1;
            }
        }
    }

    for(int i = 0; i < NUM/2; i++){
        #pragma omp for //nowait
        for(int j = 0; j < NUM; j++){
            swap(data[i][j], data[NUM-i-1][NUM-j-1]);
        }
    }

    for(int i =0; i < NUM; i++){
        for(int j = 0; j < NUM; j++){
            printf("data[%3d][%3d] = [%3d]\n",i,j,data[i][j]);
        }
    }

    return 0;
}