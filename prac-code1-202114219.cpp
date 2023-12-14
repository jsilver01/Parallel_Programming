#include <iostream>
#include <omp.h>

int main()
{
#pragma omp parallel num_threads(4)
{
    printf("병렬 영역 single 전 : %d번 Thread 동작\n",omp_get_thread_num());
#pragma omp single
    {
        printf("병렬 영역 single  :  %d번 Thread 동작\n", omp_get_thread_num());
    }
    printf("병렬 영역 single 후 : %d번 Thread 동작\n",omp_get_thread_num());
}
    return 0;
}