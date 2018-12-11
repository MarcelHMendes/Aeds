#include <stdio.h>
#include <stdlib.h>
#include "block.h"


int main(){
	int i,j,n,b;

	scanf("%d",&n);
	scanf("%d",&b);

	//Alocando matrizes
	int **A = (int**) malloc(n*sizeof(int*));
	for(i=0;i<n;i++){
		A[i] = (int*) malloc(n*sizeof(int));
	}

	int **B = (int**) malloc(n*sizeof(int*));
	for(i=0;i<n;i++){
		B[i] = (int*) malloc(n*sizeof(int));
	}

	int **C = (int**) malloc(n*sizeof(int*));
	for(i=0;i<n;i++){
		C[i] = (int*) malloc(n*sizeof(int));
	}


	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&A[i][j]);		
		}
	}

	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&B[i][j]);		
		}
	}

	Algoritmo2(n,b,A,B,C);

	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d ",C[i][j]);		
		}
		printf("\n");
	}

	return 0;
}
