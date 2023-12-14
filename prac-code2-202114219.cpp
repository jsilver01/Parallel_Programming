#include <iostream>
#include <omp.h>
#include <math.h>

#define MAX 10000000

int main()
{
    float* data;
    int i=0;
    data = new float[MAX];

    for(i=0; i< MAX; i++)
        data[i]=i;

#pragma omp parallel
    {
#pragma omp for
    for(i=0; i<MAX;i++)
        data[i] = sqrt(data[i]);
#pragma omp for
        for(i=0;i<5;i++)
            printf("before master, tid=%d, data[%d] = %.4f\n",omp_get_thread_num(),i,data[i]);

#pragma omp master
        {
             for(i=0;i<5;i++)
                 printf("master, tid=%d, data[%d] = %.4f\n",omp_get_thread_num(),i,data[i]);
        }
#pragma omp for
        for(i=0;i<5;i++)
            printf("after master, tid=%d, data[%d] = %.4f\n",omp_get_thread_num(),i,data[i]);

#pragma omp for
        for(i=0;i<5;i++)
            data[i] = log(data[i]);

    }

    delete data;
    return 0;
}