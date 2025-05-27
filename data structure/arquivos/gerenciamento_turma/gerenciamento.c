#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct turma {
    char matricula[100];
    char nome[100];
    float nota_1;
    float nota_2;
    float nota_3;
};

struct media {
    float media;
};

void leitura (const char *filename, struct turma *alunos, int *quantidade){
    FILE *file = fopen(filename,"rt");
    char buffer[256];
    *quantidade = 0;
    fgets(buffer, sizeof(buffer),file);
    while (fgets(buffer,sizeof(buffer),file)){
        char *token = strtok(buffer,";");
        if (token!=NULL) strcpy (alunos[*quantidade].matricula, token);
        token = strtok(NULL,";");
        if (token!=NULL) strcpy (alunos[*quantidade].nome,token);
        token = strtok(NULL,";");
        if (token!=NULL) alunos[*quantidade].nota_1 = atof(token);
        token = strtok(NULL,";");
        if (token!=NULL) alunos[*quantidade].nota_2 = atof(token);
        token = strtok(NULL,";");
        if (token!=NULL) alunos[*quantidade].nota_3 = atof(token);
        (*quantidade)++;
    }
    fclose(file);
}

void calculo_media(struct turma *alunos,struct media *media_alunos, int quantidade, float *media_total, int quant){

    for (int i=0; i<quantidade; i++){
        media_alunos[i].media = (alunos[i].nota_1 + alunos[i].nota_2 + alunos[i].nota_3)/3;
        *media_total += media_alunos[i].media;
    }
    *media_total = *media_total/quant;
}

void print(const char *filename, struct turma *alunos,int quantidade, float *media_total, struct media *media_alunos){
    float maior_media = 0;
    char aluno_maior_media[100];

    FILE *file = fopen(filename,"a+");
    for (int i=0; i<quantidade; i++){
        fprintf(file,"%s %s %.2f %.2f %.2f \n\n", alunos[i].matricula,alunos[i].nome,alunos[i].nota_1,alunos[i].nota_2,alunos[i].nota_3);
    }
    fprintf(file,"\n\n Média Total : %.2f\n\n", *media_total);
    for (int j=0; j<quantidade; j++){
       if (media_alunos[j].media >= 7){
            fprintf(file,"aprovado: %s %s %.2f\n", alunos[j].matricula,alunos[j].nome, media_alunos[j].media);
       }
    }
    for (int z=0; z<quantidade; z++){
       if (media_alunos[z].media < 7){
            fprintf(file,"reprovado: %s %s %.2f\n", alunos[z].matricula,alunos[z].nome, media_alunos[z].media);
       }
    }

    for (int p=0; p<quantidade; p++){
       if (media_alunos[p].media > maior_media){
        maior_media = media_alunos[p].media;
        strcpy(aluno_maior_media, alunos[p].nome);
        }
    }
    fprintf(file,"maior media : %.2f do %s", maior_media, aluno_maior_media);
    fclose(file);
    
}

int main(){
    int quantidade = 0;
    float media_total = 0;
    

    FILE *file = fopen("turma.txt","rt");
    int quant = 0;
    char buffer[256];
    quant = atoi(fgets(buffer,sizeof(buffer),file));
    fclose(file);
    
    struct turma alunos[quant];
    struct media media_alunos[quant];

    leitura("turma.txt",alunos,&quantidade);
    calculo_media(alunos, media_alunos, quantidade, &media_total, quant);
    print("relatorio.txt", alunos, quantidade, &media_total, media_alunos);

    return 0;
}