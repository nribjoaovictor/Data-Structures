#include <stdio.h>
#include <stdlib.h>
typedef struct E {int dado; struct E *ant; struct E *prox} t_Elemento;
int main() {
  t_Elemento *Lista, *aux;
  
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

  return 0;
}