#include <stdio.h>
#include <stdlib.h>
#include "block.h"

void Algoritmo1(int n,int **A,int **B,int **C){
	int i,j,k;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			C[i][j] = 0;
			for(k=0;k<n;k++){
				C[i][j] = C[i][j] + A[i][k]*B[k][j];
			}
		}
	}
}


void Algoritmo2(int n,int bsize,int **A,int **B,int **C){
	int i,j,k,j2,k2;
	int soma = 0;

	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			C[i][j] = 0;		
		}	
	}	

	for(k2=0;k2<n;k2+=bsize){
		for(j2=0;j2<n;j2+=bsize){
			for(i=0;i<n;i++){
				for(j=j2;j<j2+bsize;j++){
					soma = C[i][j];
					for(k=k2;k<k2+bsize;k++){
						soma = soma + A[i][k]*B[k][j];
					}
					C[i][j] = soma;
				}	
			}
		}
	}
}
