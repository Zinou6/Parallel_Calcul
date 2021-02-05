/*
	BY BENSAID ZINE EL ABIDINE
*/

#include <stdio.h>
#include <stdlib.h> 
#include <pthread.h>

#include "creationMatrix.h"
#include "displayMatrix.h"
#include "calculator.h"

typedef struct ENTRE{
	int **matrix1;
	int **matrix2;
	int **matrix3;
	int indiceLigne;
	int indiceCol;
	int l;
}ENTRE;

int main(int argc, char **argv){
	int i;
	int n,m,l;
	
	n = atoi (argv[1]);
	m = atoi (argv[2]);
	l = atoi (argv[3]);
	
	int NBR_THREADS = n*m;
	
	/* *** *** *** ***  creation de deux matrices aleatoire  *** *** *** *** */ 
	int **A = (int **)malloc(n * sizeof(int *));
	for (i = 0; i < n; i++)
		A[i] = (int *)malloc(l * sizeof(int));
		
	int **B = (int **)malloc(l * sizeof(int *));
	for (i = 0; i < l; i++)
		B[i] = (int *)malloc(m * sizeof(int));
		
	create2Matrix(A, B, n, m, l);
	
	printMatrix(A, n, l);
	printf("\n\n");	
	printMatrix(B, l, m);
	
	/* *** *** *** ***  allocation la matrice de resultat C = A*B  *** *** *** *** */
	int **C = (int **)malloc(n * sizeof(int *));
	for (i = 0; i < n; i++)
		C[i] = (int *)malloc(m * sizeof(int));
	
	/* *** *** *** ***  remplir une structure pour faire un passage argement dans creat_thread fonction  *** *** *** *** */ 	
	ENTRE Entre;
	Entre.matrix1 = A;
	Entre.matrix2 = B;
	Entre.matrix3 = C;
	Entre.l = l;

	/* *** *** *** ***  creation des threads  *** *** *** *** */
	pthread_t *threads = (pthread_t*) malloc(sizeof(pthread_t) * NBR_THREADS);
	for (i = 0; i < n; i++){
		Entre.indiceLigne = i;
		for (int j = 0; j < m; j++){	
			Entre.indiceCol = j;
			if(pthread_create(&threads[i], NULL,calculCij,&Entre)){ //chaque thread calcule un element C[i][j]  
				fprintf(stderr, "Error creating thread\n");
				return 0;
			} 
			if(pthread_join(threads[i], NULL)){ 
				fprintf(stderr, "Error joining thread\n");
			return 1;
			}
		}
	}
	printf("\n\n");	
	printMatrix(C, n, m);
	
}
