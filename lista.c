#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

//////Funçoes de manipulaçao de Lista///////////////////
void FLvazia(TLista *lista){
    lista->first = (apontador)  malloc(sizeof(Celula));
    lista->first->prox = NULL;
    lista->last = lista->first;

}

int Vazia(TLista *lista){
    return (lista->first == lista->last);
}

void InsereUser(TItemUser x,TLista *lista){

    if(Vazia(lista)){
        FLvazia(lista);
    }

    apontador novo = (apontador) malloc(sizeof(Celula));
    lista->last->prox = novo;
    lista->last = lista->last->prox;
    novo->item = x;
    lista->last->prox = NULL;

}

void InsereMsg(TItemMsg x,TLista *lista){
    apontador novo;

    novo = (apontador) malloc(sizeof(Celula));
    novo->item2 = x;
    lista->last->prox = novo;
    novo->prox = NULL;
    lista->last = novo;

}

void removecel(TLista *lista,int idUser){
    apontador tmp;

    tmp = lista->first;

    while(tmp->prox->item.IdUser != idUser){
        tmp = tmp->prox;
    }
    free(tmp->prox);
    tmp->prox = tmp->prox->prox;//pode estar errado


}

void Imprime(TLista *Lista){
    apontador Aux;
    Aux = Lista->first->prox;
    while (Aux != NULL){
        printf ("%s\n",Aux->item2.Msg);//pode dar erro
        Aux = Aux->prox;
    }
}
/////////////////////////////////////////////////
//////CRIAR FUNÇAO CRIAUSUARIO
//////Funçoes do Programa////////////////////////
void CriaUser(TItemUser a,TLista *listaU,TLista *listaT,int vetor){////testar
    vetor = a.IdUser;
    FLvazia(listaU);
    FLvazia(listaT);

}

//void IniciarAmizade(TItemUser a,TItemUser b){//Testar
//    InsereUser(b,a.listaSeg);
//    InsereUser(a,b.listaSeg);
//s}

void CancelarAmizade(TLista *listaU,TLista *listaU2,int idUser){//Testar
    removecel(listaU,idUser);
    removecel(listaU2,idUser);
}

void PostarMsg(TItemMsg m,TItemUser *a){
////dificil implementaçao
//inserir na timeline do user a e seus amigos
//setar likes igual a 0
}

void CurtirMsg(TLista *listaTime,int idMsg){
    apontador tmp;

    tmp = listaTime->first->prox;
    while(tmp->item2.IDMsg != idMsg){
        tmp= tmp->prox;
    }
    tmp->item2.likes++;

}

void VerAmigos(TLista *listaU){
    Imprime(listaU);
}

void printa(TLista *Lista){
    apontador Aux;
    Aux = Lista->first->prox;
    if(Aux == NULL) printf("Lista vazia\n");
    while (Aux != NULL){
       printf ("%d\n",Aux->item.IdUser);
       Aux = Aux->prox;
    }


}

