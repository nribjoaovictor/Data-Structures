#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct produtos{
    char id[10];
    char nome[100];
    char fabricante[100];
    float preco;
    int quantidade;
};
void leitura_arquivo(const char *filename, struct produtos *produto, int *quant){
    FILE *file = fopen(filename,"rt");
    char buffer[256];
    *quant = 0;
    while (fgets(buffer, sizeof(buffer), file)) {
        char *token = strtok(buffer,",");
        if (token!=NULL) strcpy (produto[*quant].id, token);
        token = strtok(NULL,",");
        if (token!=NULL) strcpy (produto[*quant].nome, token);
        token = strtok(NULL,",");
        if (token!=NULL) strcpy (produto[*quant].fabricante, token);
        token = strtok(NULL,",");
        if (token!=NULL) produto[*quant].preco = atof(token);
        token = strtok(NULL,",");
        if (token!=NULL) produto[*quant].quantidade = atoi(token);
        (*quant)++;
    }
    fclose(file);
}
void produto_caro(struct produtos *produto,int *quant, char *caro){
    float produto_mais_caro=0;
    for (int i=0; i<*quant; i++){
        if (produto_mais_caro<produto[i].preco){
            strcpy(caro,produto[i].nome);
            produto_mais_caro = produto[i].preco;
        }
    }
}
void produto_estoque(struct produtos *produto,int *quant, char *estoque ){
    int maior_estoque=0;
    for (int i=0; i<*quant; i++){
        if (maior_estoque<produto[i].quantidade){
            strcpy(estoque, produto[i].id);
            maior_estoque=produto[i].quantidade;
        }
    }
}   
void print(const char *filename, struct produtos *produto, int *quantidade,char *caro, char *estoque){
    FILE *file = fopen(filename,"a+");
    for (int j=0; j<*quantidade; j++){
        fprintf(file,"%s  %s  %s   %f    %i\n\n", produto[j].id, produto[j].nome, produto[j].fabricante, produto[j].preco, produto[j].quantidade);
    }
    fprintf(file,"-------------------------------------------------------------------------------");
    for (int i=0; i<*quantidade; i++){
        if (strcmp(caro, produto[i].nome)==0) {
            fprintf(file,"mais caro: %s  %s  %s   %f    %i\n\n", produto[i].id, produto[i].nome, produto[i].fabricante, produto[i].preco, produto[i].quantidade);
            fprintf(file,"-------------------------------------------------------------------------------");
        }
        if (strcmp(estoque, produto[i].id)==0){
            fprintf(file,"maior estoque : %s  %s  %s   %f   %i\n\n", produto[i].id, produto[i].nome, produto[i].fabricante, produto[i].preco, produto[i].quantidade);
        }
    }
    fclose(file);
}
int main() {
    struct produtos produto[10];
    int quantidade = 0;
    char caro[100];
    char estoque[100];
    leitura_arquivo("produtos.txt", produto, &quantidade);
    produto_caro(produto, &quantidade, caro);
    produto_estoque(produto,&quantidade, estoque);
    print("estoque.txt",produto,&quantidade,caro,estoque);
    return 0;
}