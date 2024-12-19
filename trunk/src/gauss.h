#ifndef _GAUSS_H
#define _GAUSS_H

#include "mat_io.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b);

void scale(Matrix *mat, Matrix *b, int r);

void swap(Matrix *mat, Matrix *b, int r1, int r2);

#endif
