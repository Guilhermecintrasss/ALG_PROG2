#include <stdio.h>

typedef struct cel {
    char chave;
    struct cel *prox;
} celula;

void empilha_enc_C(char y, celula *t)
{
    celula *nova;
    nova = (celula *) malloc(sizeof (celula));
    nova->chave = y;
    nova->prox = t->prox;
    t->prox = nova;
}

int desempilha_enc_C(celula *t,char x)
{
    celula *p;
    if (t->prox != NULL) {
        p = t->prox;
        t->prox = p->prox;
        if(p->chave == x-1 || p->chave == x-2){
            return 1;
        }
        else{
            return -1;
        }
    free(p);
    
}
else {
return -2;
}
}



int main(){
    celula *t;
    t = (celula *) malloc(sizeof (celula));
    t->prox = NULL;
    char sequencia[50];
    int i = 0,result;
    scanf("%s",sequencia);
    while(sequencia[i] != '\0'){
        if(sequencia[i] == '(' || sequencia[i] == '{')
        {
            empilha_enc_C(sequencia[i],t);
        }
        else if(sequencia[i] == ')' || sequencia[i] == '}')
        {
            result = desempilha_enc_C(t,sequencia[i]);
            if(result == -1)
            {
                break;
            }
            else if(result == -2)
            {
                break;
            }
        }
        i++;
    }
    if(t->prox != NULL || result < 0){
        printf("Uso indevido de parenteses ou chaves\n");
    } else{
        printf("Parenteses ou chaves usados corretamente!\n");
    }

}