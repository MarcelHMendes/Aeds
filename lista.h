typedef struct Lista{
struct celula_str *first,*last;
}TLista;

typedef struct {
    int IdUser;
    char *nome;
    //TLista *listaSeg;
    //TLista *timeLine;

}TItemUser;

typedef struct {
    int IDMsg;
    char *Msg;
    int likes;
    int t;

}TItemMsg;

typedef struct celula_str{
    TItemUser item;
    TItemMsg item2;
    struct celula_str *prox;
}Celula;

typedef Celula *apontador;



/////procedimentos e funçoes de manipulação de Listas///////
void FLvazia(TLista *Lista);
int Vazia(TLista *lista);
void InsereUser(TItemUser x,TLista *lista);
void InsereMsg(TItemMsg  x,TLista *lista);
void removecel(TLista *lista,int idUser);
void Imprime(TLista *Lista);
/////////////////////////////////////////////////////////////

///////Funçoes do Programa////////////////////////
void IniciarAmizade(TItemUser a,TItemUser b);
void CancelarAmizade(TLista *listaU,TLista *listaU2,int idUser);
void PostarMsg(TItemMsg m,TItemUser *a);
void CurtirMsg(TLista *listaTime,int idMsg);
void exibirTimeline(TItemUser a);
void VerAmigos(TLista *listaU);
void CriaUser(TItemUser a,TLista *listaU,TLista *listaT,int vetor);
void printa(TLista *Lista);//função de teste
/////////////////////////////////////
