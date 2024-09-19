#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void troca(int *a, int *b)
{
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

void separa_aleatorio(int p, int r, int v[])
{
int x, i, j,t;
t = r-p+1; // tamanho do vetor
x = v[p+rand()%t];
i = p - 1;
j = r + 1;
while (i < j) {
do {
j--;
} while (v[j] > x);
do {
i++;
} while (v[i] < x);
if (i < j)
troca(&v[i], &v[j]);
}

}

int main() {
    int codigos[1000],n,j;
    scanf("%d",&n);

    
    for(int i = 0; i<n ; i++){
        scanf("%d",&codigos[i]);
    }
    
    separa_aleatorio(0,1000,codigos);

    for(int i = 0; i<n ; i++){
        printf("%d\n",codigos[i]);
    }
}