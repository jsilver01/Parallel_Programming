void mxv(float (*matrix_d)[COLS], float* vector,float* result,int nocol, int norow){
			float local_result = 0.0;
#pragma omp parallel for num_threads(4) private(local_result)
    for(int y=0; y<norow; y++){
				local_result = 0.0;
        for(int x=0;x<nocol;x++){
            local_result += matrix_d[y][x] * vector[x];
        }
				result[y] += local_result;
    }
}