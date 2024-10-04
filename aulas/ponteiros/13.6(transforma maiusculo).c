#include <stdio.h>
void maiuscula(char *cadeia){
    {
        while(*cadeia != '\n'){
            if(*cadeia >= 97 && *cadeia <= 122)
                *cadeia = *cadeia - 32;
            cadeia++;
        }
    }
}

int main(){
    char mensagem[100];
    char *p;
    gets(mensagem);

    p = mensagem;

    printf("%s\n\n",mensagem);
    maiuscula(p);
    printf("%s\n\n", mensagem);
}