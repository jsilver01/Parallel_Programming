#include <iostream>
#include <stdlib.h>
#include <omp.h>

void swap(int& a, int& b){
    int tmp = 0;
    if(a>b){
        tmp = a;
        a = b;
        b = tmp;
    }
}

int main(){
    int number[20];
    for(int i =0; i<20;i++){
        number[i] = rand() % 100 + 1;
    }
    int numberCount = 20;

    double start, end;

    omp_set_num_threads(4);
    start = omp_get_wtime();
    #pragma omp parallel
    {
        for(int i=0;i<numberCount;i++){
            if(i%2 ==0){
                #pragma omp for
                    for(int j=0;j<numberCount-1;j+=2){
                    swap(number[j],number[j+1]);
                    }
            }   
            else{
                #pragma omp for
                    for(int j = 1;j<numberCount-1; j+=2){
                    swap(number[j],number[j+1]);
                    }
            }
        }
    }
    end = omp_get_wtime();
    printf("Extime = %f seconds\n", end-start);
    for(int i = 0; i< numberCount ; i++){
        printf("%d\n", number[i]);
    }
    return 0;
}