#include <stdio.h>
#include <omp.h>

int main(void){
    omp_set_num_threads(4);
    #pragma omp parallel
{
    printf("A tid = %d \n", omp_get_thread_num());
    //#pragma omp barrier
    printf("B tid = %d \n",omp_get_thread_num());
}
    return 0;
}