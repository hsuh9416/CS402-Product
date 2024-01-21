#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//  size range -> range(800, 900)
int lower = 800;
int upper = 900;

/**
 * function getRan: get Random number range from given lower number to upper number
 * @param
 * @return (int) Generated integer number
 */
int getRan(){
    return rand() % (upper-lower + 1) + lower;
}

/**
 * function genMatrix: Generate a matrix by given row and column
 * @param _r - (int) the intended total number of row
 * @param _c - (int) the intended total number of column
 * @return (double**) Generated matrix
 */
double **genMatrix(int _r, int _c){
    // Create
    double **matrix;
    matrix = (double **)malloc(_r*sizeof(double *));
    for(int k=0;k<_r;k++) 
        matrix[k] = (double *)malloc(_c*sizeof(double));

    // Allocate
    for (int i =0;i<_r;i++) 
        for (int j=0;j<_c;j++) {
            matrix[i][j] = (double)rand()/RAND_MAX;
        }
    return matrix;
}

/**
 * function mulMatrix: Multiply the given matrices and return the result
 * @param mtx1 - (double**) the first matrix
 * @param mtx2 - (double**) the second matrix
 * @param _r - (int) the total row number of the first matrix 
 * @param _m - (int) the total column(row) number of the first(second) matrix
 * @param _k - (int) the total column number of the second matrix
 * @return (double**) Generated matrix
 */
double **mulMatrix(double** mtx1, double** mtx2, int _r, int _m, int _k){
    // Create
    double **matrix;
    matrix = (double **)malloc(_r * sizeof(double *))
    ;
    for(int k = 0;k< _r; k++) 
        matrix[k] = (double *)malloc(_k * sizeof(double));

    // Allocate - Multiple(Row First) 
    for (int i=0;i<_r;i++)
        for (int j=0; j<_k;j++) {
            matrix[i][j] = 0;
            for(int l=0;l<_m;l++) 
                matrix[i][j] += mtx1[i][l] * mtx2[l][j];
        }

    return matrix;
}

/**
 * (This function is optional)
 * function showMatrix: Show the generated matrix
 * @param doulble** mtx - generated matrix(2D array)
 * @param int row - the total number of row
 * @param int col - the total number of column
 * @return None
 */
void showMatrix(double** mtx, int row, int col){
    for (int i=0;i<row;i++){
        for (int j=0; j<col;j++) printf("%f ", mtx[i][j]);
        printf("\n");
    }
}

// main function
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

    double **mtx1 = genMatrix(n, m);
    double **mtx2 = genMatrix(m, k);
    double **mtx3 = mulMatrix(mtx1, mtx2, n, m, k);
    // showMatrix(mtx3, n, k);
    
    // free from memory
    for (int i=0;i<n;i++) free(mtx1[i]); free(mtx1);
    for (int i=0;i<m;i++) free(mtx2[i]); free(mtx2);
    for (int i=0;i<n;i++) free(mtx3[i]); free(mtx3);
    
    return 0;
}