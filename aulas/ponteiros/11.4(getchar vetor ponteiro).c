#include <stdio.h>

int main(){
    char mensagem[100];
    int caractere = 'A';
    char *p;
    p = mensagem;
    while(caractere != '\n'){
        caractere = getchar();
        *p++ = (char) caractere;
    }
    *p = '\0';

    printf("%s",mensagem);
}