#include <stdio.h>

int main() {
    int cod1,qtd1,cod2,qtd2;
    double v1,v2,total;
    scanf("%d %d %lf",&cod1,&qtd1,&v1);
    scanf("%d %d %lf",&cod2,&qtd2,&v2);
    total = qtd1*v1 + qtd2*v2;
    printf("VALOR A PAGAR: R$ %.2lf\n",total);
}