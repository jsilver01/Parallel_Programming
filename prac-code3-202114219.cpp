#include <iostream>
#include <omp.h>

int main(){
    int data[12];
    
    for(int i = 0; i<12; i++){
        data[i]=i;
    }

    #pragma omp parallel for num_threads(4) ordered
    for (int i=0; i<11; i++){
        data[i] += data[i+1];
        printf("tid = %d, %d\n",omp_get_thread_num(), data[i]);
    }
    return 0;
}
