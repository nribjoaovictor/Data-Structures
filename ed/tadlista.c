#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tadlista.h"
//aspas duplas são para pontos h's que não estão na localização padrão 


Lista NewLista(){
    Lista aux =(Lista)malloc(sizeof(sizeof(struct tcabec)));
    aux -> tam=0;
    aux -> inicio = NULL;
    aux -> fim = NULL;
}

int len(Lista lst){
    return lst -> tam;
}



Lista appendLista(Lista lst, int valor){
    t_no aux =(struct tipo_no *) malloc(sizeof(struct tipo_no ));
    aux-> dado = valor;
    aux ->prox = NULL;
    if (lst->tam>0){
        aux -> ant = lst -> fim;
        lst -> fim -> prox = aux;
        lst -> fim = aux;
        
    }
    else {
        aux -> ant=NULL;
        lst -> inicio = aux;
        lst -> fim = aux;
    }
    lst -> tam++;
    return lst;
}


int getElem(Lista lst, int pos){
    t_no cursor = lst->inicio;
    for (int i=0; i<pos; i++){
        cursor = cursor ->prox;
    }
    return cursor -> dado;
}