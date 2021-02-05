/*
	BY BENSAID ZINE EL ABIDINE
*/

#include <stdio.h>
#include <stdlib.h> 

#include "calculator.h"

typedef struct ENTRE{
	int **matrix1;
	int **matrix2;
	int **matrix3;
	int indiceLigne;
	int indiceCol;
	int l;
}ENTRE;

void *calculCij(void * args){
	ENTRE * E = (ENTRE *) args;
	E->matrix3[E->indiceLigne][E->indiceCol] = 0;
	for (int i = 0; i < E->l; ++i) {
				E->matrix3[E->indiceLigne][E->indiceCol] = E->matrix3[E->indiceLigne][E->indiceCol] + (E->matrix1[E->indiceLigne][i] * E->matrix2[i][E->indiceCol]);
	}
}
