typedef void *t_dado;

typedef struct tipo_no {
	t_dado dado;
	struct tipo_no *ant;
	struct tipo_no *prox;
} * t_no;

typedef struct tcabec {
	t_no prim;
	t_no ult;
	int tam;
} * Lista;

Lista newLista();
int lenLista(Lista lst);
Lista appendLista(Lista lst, t_dado ptr);
t_dado getElem(Lista lst, int pos);
Lista insereLista(Lista lst, int pos, t_dado ptr);
t_dado remLista(Lista lst, int pos);