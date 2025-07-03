#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tadlista.h"

typedef struct tipo_veiculo {
	char placa[16];
	char marca[64];
	char modelo[64];
	int km;
} * t_veiculo;

Lista loadVeiculos(char *filename){
	FILE *arq = fopen(filename, "rt");
	Lista lst = newLista();
	char linha[128];
	t_veiculo p;
	char *token;

	while(!feof(arq)){
		fgets(linha, 100, arq);

		if(linha[strlen(linha)-1] == '\n')
			linha[strlen(linha)-1] = '\0';

        p = (t_veiculo)malloc(sizeof(struct tipo_veiculo));

		token = strtok(linha, ", ");
		strcpy(p->placa, token);
		token = strtok(NULL, ", ");
		strcpy(p->marca, token);
		token = strtok(NULL, ", ");
		strcpy(p->modelo, token);
		token = strtok(NULL, ", ");
		p->km = atoi(token);

		appendLista(lst, p);
	}

    fclose(arq);

	return lst;
}

void printListaVeiculos(Lista l){
	for(int i=0; i < lenLista(l); i++){
		t_veiculo v = (t_veiculo)getElem(l, i);
		printf("%s%8s%10s%7d\n", v->placa, v->marca, v->modelo, v->km);
	}
}

int main(){
    Lista lstVeiculos = loadVeiculos("bdveiculos.txt");
    printListaVeiculos(lstVeiculos);
	return 0;
}
