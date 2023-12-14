#include <stdio.h>
#include <omp.h>

#define MAX 10

int main(){
    int i =0, j = 0;
    int count = 0;

    omp_set_num_threads(4);

    #pragma omp parallel shared(count) private(i,j)
    {
        #pragma omp for collapse(2)
        for(i = 0; i < MAX; i++){
            for(j = 0; j<MAX; j++){
#pragma omp atomic
                    count++;
#pragma omp parallel for ordered
                    printf("i*MAX+j : %2d, thread num : %d\n", i*MAX+j, omp_get_thread_num());
            }
        }
    }
    printf("count = %d", count);
}