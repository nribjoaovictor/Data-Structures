#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tadlista.h"

void printLista(Lista lst){
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
	Lista lst;
	lst = newLista();
	char *p;
    
    p = cria_str("Azul"); appendLista(lst, p); 
	p = cria_str("Laranja"); appendLista(lst, p);
	p = cria_str("Vermelho"); appendLista(lst, p);
	p = cria_str("Amarelo"); appendLista(lst, p);
	p = cria_str("Verde"); appendLista(lst, p);

	printf("Tamanho da lista %d\n", lenLista(lst));
	printLista(lst);

	p = cria_str("Violeta"); lst = insereLista(lst, 0, p);
	p = cria_str("Magenta"); lst = insereLista(lst, lenLista(lst), p);
	p = cria_str("Azul"); lst = insereLista(lst, 3, p);
	p = cria_str("Branco"); lst = insereLista(lst, lenLista(lst)-1, p);
	p = cria_str("Preto"); lst = insereLista(lst, 100, p);

	printf("\nTamanho da lista %d\n", lenLista(lst));
	printLista(lst);

	remLista(lst, 0);
	printf("\nTamanho da lista %d\n", lenLista(lst));
	printLista(lst);

	remLista(lst, lenLista(lst)-1);
	printf("\nTamanho da lista %d\n", lenLista(lst));
	printLista(lst);

	remLista(lst, 3);
	printf("\nTamanho da lista %d\n", lenLista(lst));
	printLista(lst);

	Lista lst2;
	lst2 = newLista();
	p = cria_str("Marrom"); appendLista(lst2, p);

	remLista(lst2, 0);
	printf("\nTamanho da lista %d\n", lenLista(lst2));
	printLista(lst2);

	return 0;
}