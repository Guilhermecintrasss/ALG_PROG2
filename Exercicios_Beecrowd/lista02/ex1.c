#include <stdio.h>

int main() {
    int S=0,R=0,C=0,total=0,qtd,n;
    char animal;
    double pcts,pctr,pctc;
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        scanf("%d %c",&qtd,&animal);
        if(animal == 'S'){
            S = S + qtd;}
        if(animal == 'R'){
            R = R + qtd;}
        if (animal == 'C'){
            C = C + qtd;}
        total = total + qtd;
    }

    pcts = (double)(S*100)/total;
    pctr = (double)(R*100)/total;
    pctc = (double)(C*100)/total;
    printf("Total: %d cobaias\n",total);
    printf("Total de coelhos: %d\n",C);
    printf("Total de ratos: %d\n",R);
    printf("Total de sapos: %d\n",S);
    printf("Percentual de coelhos: %.2lf %%\n",pctc);
    printf("Percentual de ratos: %.2lf %%\n",pctr);
    printf("Percentual de sapos: %.2lf %%\n",pcts);
}