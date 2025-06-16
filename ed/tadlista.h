typedef struct tipo_no {
    int dado;
    struct tipo_no *ant;
    struct tipo_no *prox;

} * t_no;

typedef struct tcabec{
    t_no inicio;
    t_no fim;
    int tam;
} *Lista;


Lista NewLista();
/*
int len(Lista lst);
Lista append(Lista lst, int valor);
Lista insert(Lista lst, int pos, int valor);
int remove(Lista lst, int pos);
int getElem(Lista lst, int pos);
*/