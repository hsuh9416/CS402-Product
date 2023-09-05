#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//  size range -> range(400, 600)
int lower = 800;
int upper = 900;

int getRan(){
    return rand() % (upper-lower + 1) + lower;
}

int **genMatrix(int _r, int _c){
    // Create
    int **matrix;
    matrix = (int **)malloc(_r*sizeof(int *));
    for(int k=0;k<_r;k++) 
        matrix[k] = (int *)malloc(_c*sizeof(int));

    // Allocate
    for (int i =0;i<_r;i++) 
        for (int j=0;j<_c;j++) {
            matrix[i][j] = rand();
        }
    return matrix;
}

int **mulMatrix(int** mtx1, int** mtx2, int _r, int _m, int _k){
    // Create
    int **matrix;
    matrix = (int **)malloc(_r*sizeof(int *));
    for(int k = 0;k< _r; k++) 
        matrix[k] = (int *)malloc(_k*sizeof(int));

    // Allocate - Multiple(Column First) 
    for (int i=0;i<_k;i++)
        for (int j=0; j<_r;j++) {
            matrix[j][i] = 0;
            for(int l=0;l<_m;l++) 
                matrix[j][i] += mtx1[j][l] * mtx2[l][i];
        }

    return matrix;
}

void showMatrix(int** mtx, int row, int col){
    for (int i=0;i<row;i++){
        for (int j=0; j<col;j++) printf("%d ", mtx[i][j]);
        printf("\n");
    }
}

int main(void)
{
    clock_t sTime, eTime;
    double time_elasped;
    sTime = clock();

    srand(time(NULL));

    int n = getRan(); // Row of first matrix
    int m = -1; // Column of first matrix & Row of second matrix
    int k = -1; // Column of second matrix

    do {
        m = getRan();
    } while(n == m);

    do {
        k = getRan();
    } while(m == k); 

    int **mtx1 = genMatrix(n, m); // First matrix
    int **mtx2 = genMatrix(m, k); // Second matrix
    int **mtx3 = mulMatrix(mtx1, mtx2, n, m, k); // Product matrix
    // showMatrix(mtx3, n, k);

    // free from memory
    for (int i=0;i<n;i++) free(mtx1[i]); free(mtx1);
    for (int i=0;i<m;i++) free(mtx2[i]); free(mtx2);
    for (int i=0;i<n;i++) free(mtx3[i]); free(mtx3);
    
    eTime = clock();
    // Elasped time calculation
    time_elasped = ((double)(eTime - sTime)) / CLOCKS_PER_SEC;
    printf("TIME_ELASPED: %f sec. \n", time_elasped);

    return 0;
}