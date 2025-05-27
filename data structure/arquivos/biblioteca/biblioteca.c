#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct livros {
    int id;
    char titulo[100];
    char autor[100];
    int ano;
    int disponiveis;
};

void leitura_arquivo(const char *filename, struct livros *livro, int *quantidade){
    FILE *file = fopen(filename,"rt");
    char buffer[256];
    *quantidade = 0;
    while (fgets(buffer, sizeof(buffer),file)){
        char *token = strtok(buffer,";");
        if (token!=NULL) livro[*quantidade].id = atoi(token);
        token = strtok (NULL,";");
        if (token!=NULL) strcpy (livro[*quantidade].titulo, token);
        token = strtok (NULL,";");
        if (token!=NULL) strcpy (livro[*quantidade].autor, token);
        token = strtok (NULL,";");
        if (token!=NULL) livro[*quantidade].ano = atoi(token);
        token = strtok (NULL,";");
        if (token!=NULL) livro[*quantidade].disponiveis = atoi(token);
        (*quantidade)++;
    }
    fclose(file);
}

void print(const char *filename, struct livros *livro, int quantidade){
    int antigo = 2025;
    int maior_quantidade = 0;
    FILE *file = fopen(filename,"a+");
    for (int i=0; i<quantidade; i++){
        fprintf(file, "ID: %d   Título: %s   Autor: %s   Ano: %d   Quantidade:%d \n", livro[i].id, livro[i].titulo,livro[i].autor, livro[i].ano, livro[i].disponiveis);
        if (livro[i].ano<antigo){
            antigo = livro[i].ano;
        }
        if (livro[i].disponiveis>maior_quantidade){
            maior_quantidade = livro[i].disponiveis;
        }
    }
    for (int j=0; j<quantidade; j++){
        if (maior_quantidade == livro[j].disponiveis){
            fprintf(file, "\n\n Maior quantidade do exemplar: ID: %d   Título: %s   Autor: %s   Ano: %d   Quantidade:%d \n", livro[j].id, livro[j].titulo,livro[j].autor, livro[j].ano, livro[j].disponiveis);
        }
        if (antigo == livro[j].ano){
            fprintf(file,"\n\n Livro mais antigo: ID: %d   Título: %s   Autor: %s   Ano: %d   Quantidade:%d \n", livro[j].id, livro[j].titulo,livro[j].autor, livro[j].ano, livro[j].disponiveis);
        }
    }
    fclose(file);
}



int main(){
    int quantidade;
    struct livros livro[15];
    leitura_arquivo("livros.txt", livro, &quantidade);
    print("relatorio.txt", livro, quantidade);
    return 0;
}