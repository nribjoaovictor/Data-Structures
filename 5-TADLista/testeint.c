#include <stdio.h>
#include <stdlib.h>
#include "tadlista.h"

void printLista(Lista lst){
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

int main(){
	Lista lst;
	lst = newLista();
	int *p;
    
    p = cria_int(45); appendLista(lst, p); 
	p = cria_int(33); appendLista(lst, p);
	p = cria_int(91); appendLista(lst, p);
	p = cria_int(87); appendLista(lst, p);
	p = cria_int(19); appendLista(lst, p);

	printf("Tamanho da lista %d\n", lenLista(lst));
	printLista(lst);

	p = cria_int(44); lst = insereLista(lst, 0, p);
	p = cria_int(53); lst = insereLista(lst, lenLista(lst), p);
	p = cria_int(28); lst = insereLista(lst, 3, p);
	p = cria_int(32); lst = insereLista(lst, lenLista(lst)-1, p);
	p = cria_int(86); lst = insereLista(lst, 100, p);

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
	p = cria_int(245); appendLista(lst2, p);

	remLista(lst2, 0);
	printf("\nTamanho da lista %d\n", lenLista(lst2));
	printLista(lst2);

	return 0;
}