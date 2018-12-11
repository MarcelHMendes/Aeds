#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include <math.h>

void Ordena(TItem *t, int size) {//Ordenação em relação ao vértice
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
            while (j>=0 && value.vertice < t[j].vertice) {
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
	int i,i2,i3,ret;//iteradores e variavel de retorno para scanf
	int soma = 0;
	int q;
	int max = 0;
	int cont1;
	int cont2;

	ret = scanf("%d",&n);//numero de vertices
	ret = scanf("%d",&m);//numero de caminhos


	TItem *dAux = (TItem*) malloc((n+1)*sizeof(TItem));//vetor auxiliar. 
	TItem *cSol = (TItem*) malloc((n+1)*sizeof(TItem));//conjunto candidato a solução.
	int *vSol = (int*) malloc((n+1)*sizeof(int));//Vertices candidatos a solução.
	TItem *solFinal = (TItem*) malloc((n+1)*sizeof(TItem));//conjunto de vertices da solução final.				

	TipoLista *grafo = (TipoLista *) malloc((n+1)*sizeof(TipoLista));//Lista de adjacencia
	
	for(i=0;i<n+1;i++){//Inicializando o grafo
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
		
	
	
	q = pow(2,n);
	for(i=1;i < q;i++){
		soma = 0;
		cont1 = 0;
		cont2 = 0;
		conv(i,vSol,n);//Conversao do numero inteiro para binario
		
		i3 = 1;
		for(i2=0;i2<=n;i2++){
			cSol[i2].vertice = -1; 
		}

		for(i2 = n;i2>=1;i2--){
			if(vSol[i2] == 1){
				cSol[i3] = dAux[i2];		
				i3++;
			}

		}		

		soma = escolheExato(cSol,grafo,n);//Funçao que calcula a soma das demandas das soluçoes possiveis.
		if(soma > max){//Trecho de codigo que seleciona a solucao otima.
			max = soma;
			for(i2=0;i2<=n;i2++){
				solFinal[i2] = cSol[i2];	
			}
		}
		else if(soma == max){//Se existem duas solucoes otimas a que conter mais numeros de vertice sera selecionada
				for(i2=1;i2<=n;i2++){
					if(solFinal[i2].vertice != -1) cont1++;
				}
				for(i2=1;i2<=n;i2++){
					if(cSol[i2].vertice != -1) cont2++;
				}
				if(cont2 > cont1){
					for(i2=0;i2<=n;i2++){
						solFinal[i2] = cSol[i2];
					}
				}
		}
		//////////////////////////////////////////////////////////////////
	}
	
	cont1 = 0;
	for(i=1;i<=n;i++){
		if(solFinal[i].vertice != -1) cont1++;
	}


	Ordena(solFinal,(n+1));

	printf("%d %d\n",cont1,max);
	for(i=1;i<=n;i++){
		if(solFinal[i].vertice != -1)
			printf("%d ",solFinal[i].vertice);
	}
	printf("\n");

	free(dAux);
	free(cSol);
	free(vSol);
	free(solFinal);

	return 0;
	
}
