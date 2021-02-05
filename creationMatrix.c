/*
	BY BENSAID ZINE EL ABIDINE
*/

#include <stdio.h>
#include <stdlib.h> 

#include "creationMatrix.h"

void create2Matrix(int **matrix1, int **matrix2, int n, int m, int l){
	int i,j;
	static int upperValue = 99;
	static int lowerValue = 1; 
	for (i = 0; i < n; ++i) {
		for (j = 0; j < l; ++j) {
			matrix1[i][j] = (rand() % (upperValue - lowerValue + 1)) + lowerValue;
		}
	}
	
	for (i = 0; i < l; ++i) {
		for (j = 0; j < m; ++j) {
			matrix2[i][j] = (rand() % (upperValue - lowerValue + 1)) + lowerValue;
		}
	}
}
