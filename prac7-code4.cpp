#include <stdio.h>
#include <omp.h>

using namespace std;

#define MAX 1000

int main(int argc, char* argv[]){
    float* data;
    data = new float[MAX];

    int i = 0;
    for(i = 0; i < MAX; i++){
        data[i]=i;
    }

    float max = 0;

    #pragma omp parallel for
    for(i = 0; i < MAX; i++){
        
        #pragma omp critical(MAXVALUE)
        {
            if(max < data[i]){
                max = data[i];
            }
        }
    }

    printf("최대값 : %.3f\n",max);
    delete data;
    return 0;
}
