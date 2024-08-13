#include <stdio.h>

int main() {
    int S=0,R=0,C=0,total=0,qtd,n;
    char animal;
    float pcts,pctr,pctc;
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        scanf("%c %d",&animal,&qtd);
        if(animal == 'S'){
            S = S + qtd;}
        if(animal == 'R'){
            R = R + qtd;}
        if (animal == 'C'){
            C = C + qtd;}
        total = total + qtd;
    }

    pcts = S/total*100;
    pctr = R/total*100;
    pctc = C/total*100;
    printf("Total: %d cobaias\n",total);
    printf("Total de coelhos: %d\n",C);
    printf("Total de ratos: %d\n",R);
    printf("Total de sapos: %d\n",S);
    printf("Percentual de coelhos: %.2f %%\n",pctc);
    printf("Percentual de ratos: %.2f %%\n",pctr);
    printf("Percentual de sapos: %.2f %%\n",pcts);
}