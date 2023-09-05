#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int lower = 400;
int upper = 600;

int getRan(){
    return rand() % (upper-lower + 1) + lower;
}

double **genMatrix(int _r, int _c){
    double **matrix;
    matrix = (double **)malloc(_r * sizeof(double *));
    for(int k = 0;k< _r; k++) 
        matrix[k] = (double *)malloc(_c * sizeof(double));

    for (int i = 0; i < _r; i++) 
        for (int j = 0; j < _c; j++) {
            matrix[i][j] = (double)rand();
        }
    return matrix;
}

double **mulMatrix(double** mtx1, double** mtx2, int _r, int _m, int _k){
    // Generate frame first
    double **matrix;
    matrix = (double **)malloc(_r * sizeof(double *))
    ;
    for(int k = 0;k< _r; k++) 
        matrix[k] = (double *)malloc(_k * sizeof(double));

    // Multiple then allocate

    for (int i = 0; i < _r; i++)
        for (int j = 0; j < _k; j++) {
            matrix[i][j] = 0;
            for(int l=0; l< _m; l++) 
                
                matrix[i][j] += mtx1[i][l] * mtx2[l][j];
        }

    return matrix;
}

void showMatrix(double** mtx, int row, int col){
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++) printf("%f ", mtx[i][j]);
        printf("\n");
    }
}

int main(void)
{
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

    // # Test Code
    // int n = 1; // Row of first matrix
    // int m = 2; // Column of first matrix & Row of second matrix
    // int k = 3; // Column of second matrix

    double **mtx1 = genMatrix(n, m);
    // showMatrix(mtx1, n, m);
    printf("\n");
    double **mtx2 = genMatrix(m, k);
    // showMatrix(mtx2, m, k);
    printf("\n");
    double **mtx3 = mulMatrix(mtx1, mtx2, n, m, k);
    // showMatrix(mtx3, n, k);
    printf("\n");

    for (int i = 0; i < n; i++) free(mtx1[i]);
    free(mtx1);
    for (int i = 0; i < m; i++) free(mtx2[i]);
    free(mtx2);
    for (int i = 0; i < n; i++) free(mtx3[i]);
    free(mtx3
    );
    
    return 0;
}

