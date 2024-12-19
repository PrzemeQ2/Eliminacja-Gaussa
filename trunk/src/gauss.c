#include "gauss.h"

/**
 * Returns 0 - elimination successful
 * Returns 1 - singular matrix (division by zero)
 */
int eliminate(Matrix *mat, Matrix *b) {
    for (int k = 0; k < mat->r; k++) {
        if (mat->data[k][k] == 0) {   // Warunek sprawdza, czy na diagonali macierzy są niezerowe elementy
            int variable = -1;        // Jeśli nie to odpowiednie wiersze są zamieniane lub funckja zwraca 1 (macierz osobliwa) 
            for (int i = k + 1; i < mat->r; i++) {
                if (mat->data[i][k] != 0) {
                    variable = i;
                    break;
                }
            }
            if (variable == -1) {
                return 1;
            }
            swap(mat, b, k, variable);
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

void scale(Matrix *mat, Matrix *b, int r) { // skaluje wybrany wiersz
    double coefficient = mat->data[r][r];
    if (coefficient != 0) {
        for (int j = r; j < mat->c; j++) {
            mat->data[r][j] /= coefficient;
        }
        b->data[r][0] /= coefficient;
    }
}

void swap(Matrix *mat, Matrix *b, int r1, int r2) { // przestawia wiersze r1 i r2
    double *tempr = mat->data[r1];
    mat->data[r1] = mat->data[r2];
    mat->data[r2] = tempr;

    double tempb = b->data[r1][0];
    b->data[r1][0] = b->data[r2][0];
    b->data[r2][0] = tempb;
}
