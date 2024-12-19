#include "gauss.h"

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b) {
    for (int k = 0; k < mat->r; k++) {
        
        int max_row = k;
        for (int i = k + 1; i < mat->r; i++) {
            if (fabs(mat->data[i][k]) > fabs(mat->data[max_row][k])) {
                max_row = i;
            }
        }

        
        if (max_row != k) {
            swap(mat, b, k, max_row);
        }

        
        if (mat->data[k][k] == 0) {
            return 1; 
        }

        
        scale(mat, b, k);

    
        for (int i = k + 1; i < mat->r; i++) {
            double factor = mat->data[i][k] / mat->data[k][k];
            for (int j = k; j < mat->c; j++) {
                mat->data[i][j] -= factor * mat->data[k][j];
            }
            b->data[i][0] -= factor * b->data[k][0];
        }
    }
    return 0;
}

void scale(Matrix *mat, Matrix *b, int r) { 
    double coefficient = mat->data[r][r];
    if (coefficient != 0) {
        for (int j = r; j < mat->c; j++) {
            mat->data[r][j] /= coefficient;
        }
        b->data[r][0] /= coefficient;
    }
}

void swap(Matrix *mat, Matrix *b, int r1, int r2) { 
    double *tempr = mat->data[r1];
    mat->data[r1] = mat->data[r2];
    mat->data[r2] = tempr;

    double tempb = b->data[r1][0];
    b->data[r1][0] = b->data[r2][0];
    b->data[r2][0] = tempb;
}
