#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include <string.h>


//////Funçoes de manipulaçao de Lista///////////////////
void FLvazia(TipoLista *lista){
    lista->first = (apontador)  malloc(sizeof(Celula));
    lista->first->prox = NULL;
    lista->last = lista->first;

}

int Vazia(TipoLista *lista){
    if(lista->first->prox == NULL) return 1;
    return (0);
}

void Insere(TItem x,TipoLista *lista){
    apontador novo;
    novo = (apontador) malloc(sizeof(Celula));
    novo->item = x;
    novo->prox = lista->first->prox;
    lista->first->prox = novo;


}

void ImprimeGL(TipoLista lista){
    apontador Aux;
    int cont = 0;
    Aux = lista.first->prox;
    while (Aux->prox != NULL){
        printf("%d ",Aux->item.vertice);
        Aux = Aux->prox;
        cont++;
    }
    printf("%d ",Aux->item.vertice);
    printf("\n");
}

//Funçoes do grafo
void insereGrafo(TipoLista *lista,int v){//insercao da aresta no grafo
    TItem x;
    x.vertice = v;
    x.demand = -1;

    Insere(x,lista);
}
 
void insereHead(TipoLista *lista,int p){//insercao da demanda na celula cabeca
    TItem x;
    x.demand = p;
   
    lista->first->item = x;
}

void imprimeDemanda(TipoLista lista){
    printf("%d ",lista.first->item.demand);
}

int verifVizinho(TipoLista lista,TItem x){//Verifica se vertice x e vizinho de outro determinado vertice
    apontador aux = lista.first->prox;
    while(aux != NULL){
        if(aux->item.vertice == x.vertice){
            return 1;
        }
        aux = aux->prox; 
    }

    return 0;
}

void escolhe(TItem dAux,TItem *cSol,TipoLista lista){//usado para heuristica
    int i = 0;
    int k = 0;
    while(cSol[i].vertice != -1){
        k = verifVizinho(lista,cSol[i]);
        if(k == 1) break;
        i++;
    }
    if(k != 1){
        cSol[i] = dAux;   
    }
}

void conv(int k,int *buf,int n){
    int i;
    int r;
    for(i=n; i>=0 ;i--){
        r = k >> i;
        if(r & 1) {
           buf[n-i] = 1;
        } 
        else {
            buf[n-i] = 0;
        }
    }

}

int escolheExato(TItem *cSol,TipoLista *lista,int n){//usado para o exato
    int i = 2;
    int i2 = 0;
    int k = 0;
    int soma = 0;

   for(i2=1;i2 <= n;i2++){
        i = i2+1;
        while((cSol[i].vertice != -1) && (i < n+1)){
            k = verifVizinho(lista[cSol[i2].vertice],cSol[i]);
            if(k == 1) return -1;
            i++;
        }      
    }

    i = 1;
    while((cSol[i].vertice != -1) && (i < n+1)){//soma as demandas dos vertices cadidatos a solucao
        soma += cSol[i].demand;
        i++;
    }

    return soma;
}

void OrdenaV(TItem *t, int size) {
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