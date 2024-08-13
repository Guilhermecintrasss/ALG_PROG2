#include <stdio.h>

int main() {
    int cod1,qtd1,cod2,qtd2;
    float v1,v2,total;
    scanf("%d %d %f",&cod1,&qtd1,&v1);
    scanf("%d %d %f",&cod2,&qtd2,&v2);
    total = qtd1*v1 + qtd2*v2;
    printf("VALOR A PAGAR: R$ %.2f\n",total);
}