#include <stdio.h>
#include <omp.h>

#define MAX 20

int Fibonacci(int n){
    int x, y;
    if(n<2){
        return n;
    }else{
#pragma omp task shared(x)
        x = Fibonacci(n-1);
#pragma omp task shared(y)
        y = Fibonacci(n-2);
#pragma omp taskwait
        return x + y;
    }
}

int main(){
    int FibNumver[MAX] = {0};

#pragma omp parallel
    {
#pragma omp single
        {
            for(int i = 0;i<MAX; i++)
                FibNumver[i] = Fibonacci(i);
        }
    }

    printf("피보나치 수 : ");
    for(int i = 1; i < MAX; i++){
        printf("%d ", FibNumver[i]);
    }
    printf("\n");
    return 0;
}