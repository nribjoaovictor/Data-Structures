#include <stdio.h>
#include <stdlib.h>
typedef struct E {int dado; struct E *ant; struct E *prox} t_Elemento;

int len(t_elemento *inicio){
  int tam = 0;

  if(inicio == NULL) return 0;

  while(inicio->prox != NULL){
    tam = tam + 1;
    inicio = inicio->prox;
  }

  return tam + 1;
}

t_Elemento *append(t_Elemento *inicio, t_Elemento *fim, int valor){
  t_Elemento *no = (malloc(sizeof(t_Elemento)));
  no->dado = valor;
  no->prox = NULL;
  no->ant = fim;

  return inicio;
}

int main() {
  t_elemento *Lista, *aux;
  
  Lista = (t_Elemento *)malloc(sizeof(t_Elemento));
  aux = Lista;
  
  Lista->dado = 23;
  Lista->ant = NULL;
  Lista->prox = (t_Elemento *)malloc(sizeof(t_Elemento));
  aux = Lista->prox;
  
  aux->dado = 45;
  aux->ant = Lista;
  aux->prox = (t_Elemento *)malloc(sizeof(t_Elemento));
  aux = aux->prox;
  
  aux->dado = 97;
  aux->ant = Lista->prox;
  aux->prox = NULL; 

  append(Lista, aux, int valor)   

  return 0;
}