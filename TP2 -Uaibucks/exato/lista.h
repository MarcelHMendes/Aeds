typedef struct Lista{
struct celula_str *first,*last;
}TipoLista;

typedef int TipoChave;

typedef struct {
    TipoChave vertice;
    int demand;
}TItem;


typedef struct celula_str{
    TItem item;
    struct celula_str *prox;
}Celula;

typedef Celula *apontador;


/////procedimentos e funçoes de manipulação de Listas///////
void FLvazia(TipoLista *lista);
int Vazia(TipoLista *lista);
void Insere(TItem x,TipoLista *lista);
void removecel(TipoLista *lista,TipoChave chave);
void ImprimeGL(TipoLista lista);
/////////////////////////////////////////////////////////////
void insereGrafo(TipoLista *lista,int v);//inserção da aresta no grafo
void insereHead(TipoLista *lista,int p);
void imprimeDemanda(TipoLista lista);
int verifVizinho(TipoLista lista,TItem x);
void escolhe(TItem dAux,TItem *cSol,TipoLista lista);
void dfs(TipoLista *lista,int ini,int *visitado,int cont);
void DFS(TipoLista *lista,int ini,int *visitado,int n);
void conv(int k,int *buf,int n);
int escolheExato(TItem *cSol,TipoLista *lista,int n);//alterar para n