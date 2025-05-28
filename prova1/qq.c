#include <stdio.h>
#include <string.h>
#include <stdlib.h>



struct valor_total_por_marca{
    char marca[100];
    float valor_total;
};

struct t_produto{
    char id[100];
    char nome[100];
    char categoria[100];
    char marca[100];
    float preco;
    int garantia;
    int quantidade;
};

void load_tabela(const char *filename, struct t_produto *tab, int *ptam){
    FILE *file = fopen(filename,"rt");
    *ptam = 0;
    char buffer[256];
    fgets(buffer,sizeof(buffer),file);
    while (fgets(buffer,sizeof(buffer),file)){
        char *token = strtok(buffer,",");
        if (token!=NULL) strcpy (tab[*ptam].id,token);
        token = strtok(NULL,",");
        if (token!=NULL) strcpy (tab[*ptam].nome,token);
        token = strtok(NULL,",");
        if (token!=NULL) strcpy (tab[*ptam].categoria,token);
        token = strtok(NULL,",");
        if (token!=NULL) strcpy (tab[*ptam].marca,token);
        token = strtok(NULL,",");
        if (token!=NULL) tab[*ptam].preco = atof(token);
        token = strtok(NULL,",");
        if (token!=NULL) tab[*ptam].garantia = atoi(token);
        token = strtok(NULL,",");
        if (token!=NULL) tab[*ptam].quantidade = atoi(token);
        (*ptam)++;
    }
    fclose(file);
}

void faz_relatorio(const char *filename, struct t_produto *tab, struct valor_total_por_marca *valor, int tam){

    float maior_valor_total = 0;
    char marca_maior_valor_total[100];
    float menor_valor_total = 100000000;
    char marca_menor_valor_total[100];


    FILE *file = fopen(filename,"a+");
    fprintf(file,"RELATÓRIO TOTAL EM ESTOQUE (R$) \n\n");
    
    for (int i=0; i<tam; i++){
        strcpy(valor[i].marca,tab[i].marca);
        valor[i].valor_total += (tab[i].preco * tab[i].quantidade);
    }

    
    for (int z=0; z<tam; z++){
        fprintf(file, "%s    %.2f\n", valor[z].marca, valor[z].valor_total);
        if (valor[z].valor_total>maior_valor_total){
            strcpy(marca_maior_valor_total, valor[z].marca);
            maior_valor_total = valor[z].valor_total;
        }
        if (valor[z].valor_total<menor_valor_total){
            strcpy(marca_menor_valor_total, valor[z].marca);
            menor_valor_total = valor[z].valor_total;
        }
    }
    fprintf(file,"\n\nMAIOR TOTAL EM ESTOQUE : %s  %.2f \n\n", marca_maior_valor_total, maior_valor_total);
    fprintf(file,"\n\nMENOR TOTAL EM ESTOQUE : %s  %.2f \n\n", marca_menor_valor_total, menor_valor_total);

    fclose(file);
}

int main(){
    int quantidade;
    struct t_produto t_tab_produto[100];
    struct valor_total_por_marca valor[100];
    load_tabela("tabti.txt", t_tab_produto,&quantidade);
    faz_relatorio("relat1.txt", t_tab_produto, valor, quantidade);

    return 0;
}