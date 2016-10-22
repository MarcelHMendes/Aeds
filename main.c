#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#define MAXUSUARIOS 100

int RetornaIndice(TItemUser x[],int idUser){
    int aux;
    for(aux = 0;aux < MAXUSUARIOS;aux++){
        if((x[aux]).IdUser = idUser){
            return (aux);

        }
    }
    return (-1);

}

int main(){
    int aux,indiceU,indiceA;

    TLista *listaSeg[MAXUSUARIOS];
    TLista *listaTime[MAXUSUARIOS];

    TItemUser u[MAXUSUARIOS];

    for(aux = 0;aux < MAXUSUARIOS;aux++){
        listaSeg[aux] = (TLista*) malloc(sizeof(TLista));
    }

    for(aux = 0;aux < MAXUSUARIOS;aux++){
        listaTime[aux] = (TLista*) malloc(sizeof(TLista));
    }


    FILE *arq = fopen("teste.txt","r");
    FILE *arq2 = fopen("teste2.txt","w");
    char *token = (char*) malloc(sizeof(char));
    char *nome = (char*) malloc(sizeof(char));
    char *part = (char*) malloc(sizeof(char));
    int idUser1;
    int idUser2;

    int qtde;

/////////////Leitra usuarios//////////////////////////////

    while(token != "\n"){
        fscanf(arq,"%[^;]",token);
        idUser = atoi(token);
    }





    fclose(arq);
    return 0;
}
////CRIAR UMA FUNÇAO QUE DADO O USUARIO RETORNA O RESPECTIVO INDICE
