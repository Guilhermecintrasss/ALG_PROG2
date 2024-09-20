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

int separa_aleatorio(int p, int r, int v[])
{
int x, i, j;
x = p;
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
return j;
}

int main() {
    int n,j;
    scanf("%d",&n);
    int codigos[n];
    
    for(int i = 0; i<n ; i++){
        scanf("%d",&codigos[i]);
    }
    
    j = separa_aleatorio(0,n,codigos);

    for(int i = 0; i<n ; i++){
        printf("%d\n",codigos[i]);
    }
}