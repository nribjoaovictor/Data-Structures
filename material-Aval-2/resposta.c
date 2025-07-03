#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tadlista.h"

typedef struct tadprojetos{
    int id;
    char nome_projeto[128];
} * t_projeto;

typedef struct tadmembros{
    int id;
    char nome[128];
} * t_membro;

typedef struct tadrelacao {
    int id_membro;
    int id_projeto;
} * t_relacao ;

Lista load_projeto(char *fileName){
    FILE *file = fopen(fileName,"rt");
    Lista lst = newLista();
    char buffer[256];
    t_projeto projeto;

    while (fgets(buffer, sizeof(buffer),file)){
        if (buffer[strlen(buffer)-1] == '\n')
            buffer[strlen(buffer)-1] = '\0';
    
        projeto = (t_projeto)malloc(sizeof(struct tadprojetos));

        char *token = strtok(buffer,", ");
        if (token!=NULL) projeto->id = atoi(token);
        token = strtok(NULL,".");
        if (token!=NULL) strcpy (projeto->nome_projeto, token);

        appendLista(lst, projeto);
    }
    fclose(file);
    return lst;
}

Lista load_membros(char *fileName){
    FILE *file = fopen(fileName,"rt");
    Lista lst = newLista();
    char buffer[256];
    t_membro membro;

    while (fgets(buffer, sizeof(buffer),file)){
        if (buffer[strlen(buffer)-1] == '\n')
            buffer[strlen(buffer)-1] = '\0';
    
        membro = (t_membro)malloc(sizeof(struct tadmembros));

        char *token = strtok(buffer,", ");
        if (token!=NULL) membro->id = atoi(token);
        token = strtok(NULL,".");
        if (token!=NULL) strcpy (membro->nome, token);

        appendLista(lst, membro);
    }
    fclose(file);
    return lst;
}

Lista load_relacoes(char *fileName){
    FILE *file = fopen(fileName,"rt");
    Lista lst = newLista();
    char buffer[256];
    t_relacao relacao;

    while (fgets(buffer, sizeof(buffer),file)){
        if (buffer[strlen(buffer)-1] == '\n')
            buffer[strlen(buffer)-1] = '\0';
    
        relacao = (t_relacao)malloc(sizeof(struct tadrelacao));

        char *token = strtok(buffer,", ");
        if (token!=NULL) relacao->id_membro = atoi(token);
        token = strtok(NULL,".");
        if (token!=NULL) relacao->id_projeto = atoi(token);
        appendLista(lst, relacao);
    }
    fclose(file);
    return lst;
}

Lista membros_projeto(char *id_proj, Lista lst_relacoes, Lista lst_membros){
    Lista lst = newLista();
    
    for (int i=0; i<lenLista(lst_relacoes);i++){
        t_relacao relacao = getElem(lst_relacoes,i);
        if (atoi(id_proj) == relacao->id_projeto){
            for (int j=0; j<lenLista(lst_membros); j++){
                t_membro membro = getElem(lst_membros, j);
                if (relacao->id_membro == membro->id){
                    appendLista(lst,membro);
                }
            }
        }    
    }
    return lst;
}

Lista projetos_membro(char *id_mem, Lista lst_relacoes, Lista lst_projetos){
    Lista lst = newLista();
    for (int i=0; i<lenLista(lst_relacoes);i++){
        t_relacao relacao = getElem(lst_relacoes,i);
        if (atoi(id_mem) == relacao->id_membro){
            for (int j=0; j<lenLista(lst_projetos); j++){
                t_projeto projeto = getElem(lst_projetos, j);
                if (relacao->id_projeto == projeto->id){
                    appendLista(lst,projeto);
                }
            }
        }    
    }
    return lst;
}

int main(){
    Lista lst_projeto = load_projeto("bdprojetos.txt");
    /*
    for (int i=0; i<lenLista(lst_projeto);i++){
        t_projeto p = getElem(lst_projeto, i);
        printf("%d %s\n", p->id, p->nome_projeto);
    }
    */
    Lista lst_membro = load_membros("bdmembros.txt");
    /*
    for (int j=0; j<lenLista(lst_membro);j++){
        t_membro m = getElem(lst_membro, j);
        printf("%d %s\n", m->id, m->nome);
    }
    */
    Lista lst_relacao = load_relacoes("bdrelacoes.txt");
    /*
    for (int j=0; j<lenLista(lst_relacao);j++){
        t_relacao m = getElem(lst_relacao, j);
        printf("%d %d\n", m->id_membro, m->id_projeto);
    }
    */
   int opcao = 0;
    while (opcao!=3){
        printf("MENU APP LISTA\n");
        printf("====================\n");
        printf("1. Membros de 1 Projeto\n");
        printf("2. Projetos de 1 Membro\n");
        printf("3. Sair\n");
        printf("Escolha 1 opcao:");
        scanf("%d", &opcao);
        if (opcao != 1 && opcao !=2 && opcao !=3){
            printf("Nao existe essa opcao\n\n");           
        } else {
            char id[10];
            if (opcao == 1){
                printf("Digite o id de um projeto: ");
                scanf("%s",id);
                Lista lst_membros_projeto = membros_projeto(id, lst_relacao, lst_membro);
                for (int j=0; j<lenLista(lst_membros_projeto);j++){
                    t_membro m = getElem(lst_membros_projeto, j);
                    printf("%d %s\n", m->id, m->nome);
                }
            } else if (opcao==2){
                printf("Digite o id de um membro: ");
                scanf("%s",id);
                Lista lst_projetos_membro = projetos_membro(id,lst_relacao,lst_projeto);
                for (int i=0; i<lenLista(lst_projetos_membro);i++){
                    t_projeto p = getElem(lst_projetos_membro, i);
                    printf("%d %s\n", p->id, p->nome_projeto);
                }
            }
            printf("\n");
        }
    }
}