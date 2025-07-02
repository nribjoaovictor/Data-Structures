#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int hash_simple(char *s){
    int soma = 0;
    for (int i =0; i< strlen(s);i++){
        soma+=s[i];
    }
    return soma;
}

int main(){
    char *palavra = "ifes campus serra";
    printf("Hash de %s %d", palavra, hash_simple(palavra));
    return 0;
}