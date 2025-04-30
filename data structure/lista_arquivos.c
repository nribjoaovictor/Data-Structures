#include <stdio.h>
#include <string.h>

/*
    void remove_barra_n_final(char *string){
        size_t tamanho = strlen(string);
        if (tamanho>0 && string[tamanho-1]=="\n"){
            string[tamanho-1]="\0";
        }  
    }
*/

struct proprietarios
{
    char cpf_proprietario[15];
    char nome_proprietario[100];
    char email_proprietario[100];
    char telefone_proprietario[20];
};

struct veiculos
{
    char placa_veiculo[10];
    char marca_veiculo[100];
    char modelo_veiculo[100];
    char cpf_proprietario[15];
};


void leitura_veiculo(const char *filename, struct veiculos *veiculo, int *quantidade){
    FILE *file = fopen(filename,"rt");
    char buffer[256];
    *quantidade = 0;
    fgets(buffer, sizeof(buffer),file);
    while (fgets(buffer, sizeof(buffer),file)!=NULL) {
        buffer[strcspn(buffer, "\n")] = 0; /* Remove o '\n' no final da linha;  strcspn procura o primeiro sinal do caracter dado como parametro*/
        char *token = strtok(buffer,",");
        if (token!=NULL) strcpy (veiculo[*quantidade].placa_veiculo,token);
        token = strtok(NULL,",");
        if (token!=NULL) strcpy (veiculo[*quantidade].marca_veiculo,token);
        token = strtok(NULL,",");
        if (token!=NULL) strcpy (veiculo[*quantidade].modelo_veiculo,token);
        token = strtok(NULL,",");
        if (token!=NULL) strcpy (veiculo[*quantidade].cpf_proprietario,token);
        (*quantidade)++;
    }
    fclose(file);
}


void leitura_proprietario(const char *filename,struct proprietarios *proprietario, int *quantidade){
    FILE *file = fopen(filename,"rt");
    char buffer[256]; /*Essa variável receber o conteudo da linha*/
    *quantidade = 0;
    fgets(buffer,sizeof(buffer),file); /*Essa primeira leitura pula o cabeçalho*/
    while (fgets(buffer,sizeof(buffer),file)!=NULL){ /*feof verifica se é o fim do arquivo, mas pode dar problema com a ultima liha null*/
        buffer[strcspn(buffer, "\n")] = 0;
        char *token = strtok(buffer,","); /*Vai quebrar o buffer nas ,*/
        if (token!=NULL) strcpy (proprietario[*quantidade].cpf_proprietario, token); /*strcpy copia o conteúdo de uma string para outra*/
        token = strtok(NULL,","); /*Essa parte continua de onde parou até a próxima ,*/
        if (token!=NULL) strcpy (proprietario[*quantidade].nome_proprietario,token);
        token = strtok(NULL,","); 
        if (token!=NULL) strcpy (proprietario[*quantidade].email_proprietario,token);
        token = strtok(NULL,","); 
        if (token!=NULL) strcpy (proprietario[*quantidade].telefone_proprietario,token);
        (*quantidade)++;
    }
    fclose(file);
}

int main(){
    struct proprietarios proprietario [8];
    struct veiculos veiculo [24];
    
    int quantidade_prop = 0;
    int quantidade_veic = 0;

    leitura_proprietario("proprietarios.txt", proprietario, &quantidade_prop); /*& pois estou passando o endereço dela. essa variavel irá retornar com outro valor*/
    leitura_veiculo("veiculos.txt", veiculo, &quantidade_veic);
    
    for (int i=0;i<quantidade_prop;i++)
        for (int j=0;j<quantidade_veic;j++){
            if (strcmp(proprietario[i].cpf_proprietario, veiculo[j].cpf_proprietario)==0){ /*Antes eu havia usado == direto e isso dá erro em c, pois compara o endereço da memória e não o conteúdo*/
                /*strcmp compara o conteúdo das duas strings*/
                printf("%s , %s , %s , %s \n",proprietario[i].cpf_proprietario,proprietario[i].nome_proprietario,proprietario[i].email_proprietario,proprietario[i].telefone_proprietario);
                printf("%s , %s , %s , %s \n\n",veiculo[j].placa_veiculo,veiculo[j].marca_veiculo,veiculo[j].modelo_veiculo,veiculo[j].cpf_proprietario);
                printf("-------------");
            }
        }

    return 0;
}