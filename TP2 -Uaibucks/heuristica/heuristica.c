#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void Ordena(TItem *t, int size) {
    int i , j;
    TItem value;
    int gap = 1;
    while(gap<size) {
        gap = 3*gap+1;
    }
    while (gap>1) {
        gap /= 3;
        for(i=gap;i<size;i++) {
            value = t[i];
            j = i - gap;
            while (j>=0 && value.demand < t[j].demand) {
                t[j + gap] = t[j];
                j -= gap;
            }
            t[j + gap] = value;
        }
    }
}

int main(){

	int n,m;
	int v,w,p;
	int i,ret;
	int soma = 0;
	int cont = 0;

	ret = scanf("%d",&n);//numero de vertices
	ret = scanf("%d",&m);//numero de caminhos


	TItem *dAux = (TItem*) malloc((n+1)*sizeof(TItem));//vetor auxiliar
	TItem *cSol = (TItem*) malloc(n*sizeof(TItem));//conjunto solução

				
	TipoLista *grafo = (TipoLista *) malloc((n+1)*sizeof(TipoLista));
	
	for(i=0;i<n+1;i++){//Inicializando Grafo
		FLvazia(&grafo[i]);
	} 
	
	for(i=1;i<n+1;i++){//Inserindo demandas
		ret = scanf("%d",&p);
		if(ret) insereHead(&grafo[i],p);

		dAux[i].vertice = i;
		dAux[i].demand = p;		
	}

	for(i=1;i<m+1;i++){//Inserindo arestas no grafo
		ret = scanf("%d",&v);
		ret = scanf("%d",&w);

		if(ret) insereGrafo(&grafo[v],w);
		if(ret) insereGrafo(&grafo[w],v);
	}

	Ordena(dAux,(n+1));//Ordena o vetor em ordem crescente,menos demanda para o de maior demanda

	for(i=0;i<n;i++){
		cSol[i].vertice = -1;
	}


	cSol[0] = dAux[n];
	

	for(i=n-1;i>=1;i--){
		escolhe(dAux[i],cSol,grafo[dAux[i].vertice]);//Funcao que escolhe se o vertice vai fazer parte do conjunto solucao ou nao
	}
	
	for(i=0;i<n;i++){//soma das demandas dos vertices selecionados.
		if(cSol[i].vertice != -1){
			soma += cSol[i].demand;
			cont++;

		}
	}	
	printf("%d %d\n",cont,soma);
	OrdenaV(cSol,n);
	for(i=0;i<n;i++){
		if(cSol[i].vertice != -1){
			printf("%d ",cSol[i].vertice);
		}
	}
	printf("\n");

	free(dAux);
	free(cSol);
	free(grafo);
	

	return 0;
	
}

