#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char marca[100];
    float valor_total;
}valor_total_por_marca;

typedef valor_total_por_marca valor[100];

typedef struct {
    char id[100];
    char nome[100];
    char categoria[100];
    char marca[100];
    float preco;
    int garantia;
    int quantidade;
}t_produto;

typedef t_produto t_tab_produto[100];


void load_tabela(const char *filename, t_produto *tab, int *ptam){
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


void verifica_marca(t_produto *tab,valor_total_por_marca *valortotal,int tam,int *marcas){
    *marcas= 0;
    for (int i=0; i<tam;i++){  
        int ja_existe = 0;  
        for (int j=0;j<*marcas;j++){
           if (strcmp(tab[i].marca, valortotal[j].marca)==0){
                valortotal[j].valor_total+=(tab[i].preco * tab[i].quantidade);
                ja_existe=1;
                break;
            } 
        }    
        if (!ja_existe){
            strcpy(valortotal[*marcas].marca,tab[i].marca);
            valortotal[*marcas].valor_total=(tab[i].preco * tab[i].quantidade);
            (*marcas)++;
        }    
    }
}



void faz_relatorio(const char *filename, t_produto *tab,valor_total_por_marca *valor,int quantidade_marcas){

    float maior_valor_total = 0;
    char marca_maior_valor_total[100];
    float menor_valor_total = 100000000;
    char marca_menor_valor_total[100];


    FILE *file = fopen(filename,"a+");
    fprintf(file,"RELATÓRIO TOTAL EM ESTOQUE (R$) \n\n");
    
    for (int i=0;i<quantidade_marcas;i++){
        fprintf(file, "%s    %.2f\n", valor[i].marca, valor[i].valor_total);
    }

    for (int z=0; z<quantidade_marcas; z++){
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
    int tam;
    int quantidade_marcas;
    
    t_tab_produto tabelaprod;
    valor valorTotal;

    load_tabela("tabti.txt", tabelaprod,&tam);
    verifica_marca(tabelaprod, valorTotal, tam, &quantidade_marcas);
    faz_relatorio("relat1.txt", tabelaprod, valorTotal, quantidade_marcas);

    return 0;
}