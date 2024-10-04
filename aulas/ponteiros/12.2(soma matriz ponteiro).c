#include <stdio.h>

#define MAX 3
int soma_matriz(int A[MAX][MAX])
        {
        int *p , soma = 0;
        for (p = &A[0][0] ; p <= &A[MAX-1][MAX-1]; p++)
            soma = soma + *p;
        return soma;
        }

int main(){
    int matriz[MAX][MAX];
    int *p;
    for(p = &matriz[0][0] ; p<=&matriz[MAX-1][MAX-1] ; p++){
        scanf("%d",p);
    }

    printf("%d",soma_matriz(matriz));
    
}