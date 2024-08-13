#include <stdio.h>

int main() {
    char nome[30];
    float salarioi,vendas,salariof;
    scanf("%s %f %f",nome,&salarioi,&vendas);
    salariof = salarioi + vendas*0.15;
    
    printf("TOTAL = R$ %.2f\n",salariof);
}