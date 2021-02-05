						       PARALLEL MATRIX-MATRIX MULTIPLICATION 
							   BY : BENSAID Zine El Abidine
								   04/02/2021

-- Introduction
 
 Soient A[n,l] et B[l,m]  deux matrices d’entiers.
 Ce programme a pour le but de calculer le produit matriciel en parallele C[n,m] = A*B.
 Tous les éléments de C se calculent en parallèle.
 Le code est en c en utilisant la bibliothéque pthread.

-- Execution:
                 un fichier makefile compile tous les fichier et cree un fichier executable OUT
                 pour execute le fichier OUT ecrire :
                 ./OUT [n] [m] [l]
