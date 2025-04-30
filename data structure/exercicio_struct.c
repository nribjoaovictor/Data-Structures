#include <stdio.h>
#include <string.h>
/*
void intersec (int conjunto_1[50],int sizeA, int conjunto_2[50], int sizeB, int conj_intersec[50], int *size_intersec){
    for (int i=0;i<sizeB;i++){
        for (int j=0;j<sizeB;j++){
            if (conjunto_1[i] == conjunto_2[j]) {
                conj_intersec[*size_intersec] = conjunto_1[i];
                (*size_intersec)++;
            }
        }
    }
} 

void print_conjunto (const char *m, int c[50], int tamC){
    printf("%s",m);
    for (int i=0; i<tamC -1; i++){
        printf("%d,", c[i]);
    }
    printf("%d\n", c[tamC-1]);
    printf("\n");
}

int main(){
    int conj_1 [50] = {3,6,9,12,15,18,21,24};
    int sizeA=8;
    int conj_2 [50] = {6,12,18,24,30,36,42,48};
    int sizeB=8;
    int conj_intersec[50];
    int size_intersec=0;

    intersec(conj_1, sizeA, conj_2, sizeB, conj_intersec, &size_intersec);

    print_conjunto("conjunto A: ", conj_1, sizeA);
    print_conjunto("conjunto b: ", conj_2, sizeB);
    print_conjunto("conjunto Inters: ", conj_intersec, size_intersec);


    return 0;
}
*/



/*
void intersec (int conjunto_1[50],int sizeA, int conjunto_2[50], int sizeB, int conj_uniao[50], int *size_uniao){
    for (int i=0;i<sizeA;i++){
        conj_uniao[*size_uniao]= conjunto_1[i];
        (*size_uniao)++;
    }
    for (int j=0; j<sizeB; j++){
        for (int k=0; k<sizeA; k++){
            if (conjunto_2[j] != conj_uniao[k])
            {
                conj_uniao[*size_uniao]=conjunto_2[j];
                (*size_uniao)++;        
            }
            
            
        }
    }
} 

void print_conjunto (const char *m, int c[50], int tamC){
    printf("%s",m);
    for (int i=0; i<tamC -1; i++){
        printf("%d,", c[i]);
    }
    printf("%d\n", c[tamC-1]);
    printf("\n");
}

int main(){
    int conj_1 [50] = {3,6,9,12,15,18,21,24};
    int sizeA=8;
    int conj_2 [50] = {6,12,18,24,30,36,42,48};
    int sizeB=8;
    int conj_intersec[50];
    int size_intersec=0;

    intersec(conj_1, sizeA, conj_2, sizeB, conj_intersec, &size_intersec);

    print_conjunto("conjunto A: ", conj_1, sizeA);
    print_conjunto("conjunto b: ", conj_2, sizeB);
    print_conjunto("conjunto União: ", conj_intersec, size_intersec);


    return 0;
}
*/

/*
struct produto {
    int id;
    char nome[100];
    char fabricante[100];
    float preco;
    int quantidade;
};


void print_table(int id, char nome[100], char fabricante[100], float preco, int quantidade){
    printf("%d %s %s %.2f %d \n", id, nome, fabricante, preco, quantidade);
}

void quantidade (struct produto tabela1, struct produto tabela2, struct produto *maior_quantidade){
    if (tabela1.quantidade > tabela2.quantidade){
        *maior_quantidade = tabela1;
    } else {
        *maior_quantidade = tabela2;
    }
}

int main () {

    struct produto tabelas [10];

    struct produto maior_quantidade;
    

    for (int i=0;i<10;i++){
        scanf("%d", &tabelas[i].id);
        scanf("%s", tabelas[i].nome);
        scanf("%s", tabelas[i].fabricante);
        scanf("%f", &tabelas[i].preco);
        scanf("%d", &tabelas[i].quantidade);
    }
    
    for (int j=0; j<10; j++){
        print_table(tabelas[j].id,tabelas[j].nome,tabelas[j].fabricante,tabelas[j].preco,tabelas[j].quantidade);
    }

    maior_quantidade = tabelas[0];
    for (int i = 1; i < 10; i++) {
        quantidade(maior_quantidade, tabelas[i], &maior_quantidade);
    }

    print_table(maior_quantidade.id,maior_quantidade.nome,maior_quantidade.fabricante, maior_quantidade.preco, maior_quantidade.quantidade);


    return 0;
}
*/

struct pessoas {
    int rg;
    char nome[50];
    int idade;
    char profissao[50];
};

struct residencia {
    int numero;
    int quartos;
    int garagem;
    struct pessoas pessoa[5];
};

void print_struct (struct residencia casa[]){
    for (int i=0; i<12; i++){
        printf("\n");
        printf("casa:%d\n", casa[i].numero);
        printf("quartos:%d\n", casa[i].quartos);
        printf("garagem:%d\n", casa[i].garagem);
        for (int j=0; j<5; j++){
            printf("%d\n", casa[i].pessoa[j].rg);
            printf("%s\n", casa[i].pessoa[j].nome);
            printf("%d\n", casa[i].pessoa[j].idade);
            printf("%s\n", casa[i].pessoa[j].profissao);
            printf("\n");
        }
    }
}

int main(){
    struct residencia casas [12];
    
    for (int i=0; i<12; i++){
        scanf("%d", &casas[i].numero);
        scanf("%d", &casas[i].quartos);
        scanf("%d", &casas[i].garagem);
        for (int j=0; j<5; j++){
            scanf("%d", &casas[i].pessoa[j].rg);
            scanf("%s", casas[i].pessoa[j].nome);
            scanf("%d", &casas[i].pessoa[j].idade);
            scanf("%s", casas[i].pessoa[j].profissao);
        }    
    }
    print_struct(casas);
    return 0;
}