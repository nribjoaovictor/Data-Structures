#include <stdio.h>
#include <string.h>

struct megasena {
    char dezena[10];
    int quantidade;
};
void contador(struct megasena *megasenas,int *quantidade, const char *dezena){
    for (int j=0; j<*quantidade; j++){
        if (strcmp(megasenas[j].dezena, dezena) ==0){
            megasenas[j].quantidade++;
            return; //quebrar, se não vai ir no strcpy abaixo
        }
    }
    //se não entrar no if, irá adicionar aqui
    strcpy(megasenas[*quantidade].dezena,dezena);
    megasenas[*quantidade].quantidade=1;
    (*quantidade)++;
}

void leitura_arquivo(const char *filename, struct megasena *megasena_dezena, int *quantidade){
    FILE *file = fopen(filename,"rt");
    char buffer[256];
    *quantidade = 0;
    while (fgets(buffer,sizeof(buffer),file)!=NULL){
        buffer[strcspn(buffer,"\n")]= '\0';
        char *token = strtok(buffer," \t\r\n");
        while (token!=NULL){
            contador(megasena_dezena, quantidade, token);
            token = strtok(NULL," \t\r\n");   
        }
    }
    fclose(file);
}


void escrita_arquivo(const char *filename, struct megasena dbmegasena[],int *quantidade){
    FILE *file = fopen(filename,"a+");
    for (int i=0;i<*quantidade;i++){
        fprintf(file,"%s - %d\n\n", dbmegasena[i].dezena, dbmegasena[i].quantidade);
    }
    fclose(file);
}

int main(){
    struct megasena dbmegasena[100];
    int quantidade = 0;

    leitura_arquivo("bdmegasena.txt",dbmegasena,&quantidade);
    escrita_arquivo("relatorios.txt",dbmegasena, &quantidade);

    return 0;
}