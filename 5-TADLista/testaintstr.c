#include <stdio.h>
#include <stdlib.h>
#include "tadlista.h"

void printListaInt(Lista lst){
	if (lst == NULL) printf("NULL\n");
	else if(lenLista(lst) == 0) printf("[]\n");
	else {
		printf("[");
		for(int i=0; i < lenLista(lst)-1; i++){
			int *ptr = getElem(lst,i);
			printf("%d, ", *ptr);
		}
		int *ptr = getElem(lst,lenLista(lst)-1);
		printf("%d]\n",*ptr);
	}
}

int *cria_int(int v){
	int *p = (int *)malloc(sizeof(int));
    *p = v;
    return p;
}

void printListaStr(Lista lst){
	if (lst == NULL) printf("NULL\n");
	else if(lenLista(lst) == 0) printf("[]\n");
	else {
		printf("[");
		for(int i=0; i < lenLista(lst)-1; i++){
			char *ptr = getElem(lst,i);
			printf("%s, ", ptr);
		}
		char *ptr = getElem(lst,lenLista(lst)-1);
		printf("%s]\n",ptr);
	}
}

char *cria_str(char *s){
	char *p = (char *)malloc(strlen(s)+1);
    strcpy(p,s);
    return p;
}

int main(){
	Lista lstInt = newLista();
	Lista lstStr = newLista();
	int *pi;
	char *ps;

	pi = cria_int(45); appendLista(lstInt, p); 
	pi = cria_int(33); appendLista(lstInt, p);
	pi = cria_int(91); appendLista(lstInt, p);

	ps = cria_str("Azul"); appendLista(lstStr, p); 
	ps = cria_str("Laranja"); appendLista(lstStr, p);
	ps = cria_str("Vermelho"); appendLista(lstStr, p);

	return 0;
}