#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* APPEND
typedef struct E{
    int dado;
    struct E *anterior;
    struct E *proximo;
} t_elementos;


int main(){
    t_elementos *lista, *aux;
    lista =(t_elementos *)malloc(sizeof(t_elementos));

    aux = lista;

    lista -> dado = 23;
    lista -> anterior = NULL;
    lista -> proximo = (t_elementos *)malloc(sizeof(t_elementos));
    
    aux = lista->proximo;

    aux->dado=45;
    aux->anterior=lista;
    aux->proximo=(t_elementos *)malloc(sizeof(t_elementos));
    
    aux = aux->proximo;

    aux->dado=95;
    aux->anterior= lista->proximo;
    aux->proximo->proximo=NULL;
    
    return 0;
}*/



/*
typedef struct E{
    int dado;
    struct E *anterior;
    struct E *proximo;
} t_elementos;

int len(t_elementos *inicio){
    int tam=0;
    if(inicio==NULL) return 0;
    while (inicio->proximo != NULL) {
        tam = tam+1;
        inicio = inicio->proximo;
    }
    return tam+1;
}


int main(){
    t_elementos *lista, *aux;
    lista =(t_elementos *)malloc(sizeof(t_elementos));

    aux = lista;

    lista -> dado = 23;
    lista -> anterior = NULL;
    lista -> proximo = (t_elementos *)malloc(sizeof(t_elementos));
    
    aux = lista->proximo;

    aux->dado=45;
    aux->anterior=lista;
    aux->proximo=(t_elementos *)malloc(sizeof(t_elementos));
    
    aux = aux->proximo;

    aux->dado=95;
    aux->anterior= lista->proximo;
    aux->proximo->proximo=NULL;
    
    printf("%d", len(lista));

    return 0;
}*/


typedef struct E{
    int dado;
    struct E *anterior;
    struct E *proximo;
} t_elementos;


typedef struct cabec{
    t_elementos *inicio;
    t_elementos *fim;
    int tam;
} * lista;

int len(t_elementos *inicio){
    int tam=0;
    if(inicio==NULL) return 0;
    while (inicio->proximo != NULL) {
        tam = tam+1;
        inicio = inicio->proximo;
    }
    return tam+1;
}


t_elementos *append (t_elementos *inicio, t_elementos *fim, int valor){
    t_elementos *no = (malloc(sizeof(t_elementos)));
    no->dado = valor;
    no->proximo = NULL;
    no->anterior = fim;

    return inicio;
    //inicio só está sendo usado pq estamos retornando
}



int main(){
    t_elementos *lista, *fim;
    lista =(t_elementos *)malloc(sizeof(t_elementos));

    fim = lista;
    //int tam = 0; //tamanho da lista

    lista -> dado = 23;
    lista -> anterior = NULL;
    lista -> proximo = (t_elementos *)malloc(sizeof(t_elementos));
    
    fim = lista->proximo;

    fim->dado=45;
    fim->anterior=lista;
    fim->proximo=(t_elementos *)malloc(sizeof(t_elementos));
    
    fim = fim->proximo;

    fim->dado=95;
    fim->anterior= lista->proximo;
    fim->proximo=NULL;
    
    printf("%d", len(lista));

    append(lista, fim, 234);
    //lista é o primeiro nó e o aux é o ultimo nó da struct
    

    return 0;
}


