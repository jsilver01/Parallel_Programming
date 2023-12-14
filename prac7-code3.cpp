#include <stdio.h>
#include <omp.h>

#define N 100

int main(void){
    int i, sum = 0, local_sum;

    omp_set_num_threads(4);

#pragma omp parallel private(local_sum)
    {
        local_sum = 0;
#pragma omp for
        for(i = 0; i <= N; i++)
            local_sum = local_sum + i;
        
        //#pragma omp atomic
            sum += local_sum;
    }
    printf("sum = %d\n", sum);

    return 0;
}