#include <stdio.h>

void troca(int *a, int *b)
{
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}
int selecao(int n, int v[])
{
    int i, j, min,c = 0;
    for (i = 0; i < n - 1; i++) {
    min = i;
    for (j = i+1; j < n; j++){
        if (v[j] < v[min]){
            min = j;
            c = c+1;
            }
        troca(&v[i], &v[min]);
    }
    }
    return c;
}
int main() {
    int n=1;
    while(n!= 0){
        scanf("%d",&n);
        if(n!= 0){
            int v[n],total;
            for(int i = 0; i < n ; i++){
                scanf("%d",&v[i]);
            }
            total = selecao(n,v);
            if(total%2 == 0){
                printf("Marcelo\n"); // ta dando problema, queria usar o bubblesort e n da, tenho que descobrir quantas vezes meche nos outros
            }
            else{
                printf("Carlos\n");
            }
        }
    }
    return 0;
}
