#include <stdio.h>

void troca(int *a, int *b)
{
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}
void insertionsort(int n, int v[])
{
    int i, j, x;
    for (i = 1; i < n; i++) {
        x = v[i];
        for (j = i - 1; j >= 0 && v[j] > x; j--)
            v[j+1] = v[j];
        v[j+1] = x;
    }
}
int separa_par(int p, int r, int v[])
{
    int i, j;
    i = p - 1;
    j = r + 1;
    while (i < j) {
    do {
    j--;
    } while (v[j]%2 != 0);
    do {
    i++;
    } while (v[i]%2 == 0);
    if (i < j)
    troca(&v[i], &v[j]);
    }
    return j;
}

void intercala(int p, int q, int r, int v[])
{
    int i, j, k, w[r-p];
    i = p;
    j = q;
    k = 0;
    while (i < q && j < r) {
        if (v[i] < v[j]) {
            w[k] = v[i];
        i++;
        }
        else {
            w[k] = v[j];
            j++;
        }
        k++;
    }
    while (i < q) {
        w[k] = v[i];
        i++;
        k++;
    }
    while (j < r) {
        w[k] = v[j];
        j++;
        k++;
    }
    for (i = p; i < r; i++)
        v[i] = w[i-p];
}

void mergesort(int p, int r, int v[])
{
    int q;
    if (p < r - 1) {
        q = (p + r) / 2;
        mergesort(p, q, v);
        mergesort(q, r, v);
        intercala(p, q, r, v);
    }
}

int main() {
    int n;
    scanf("%d",&n);
    int numeros[n],j;
        
    for(int i = 0; i<n ; i++){
        scanf("%d",&numeros[i]);
    }
    j = separa_par(0,n,numeros);
    
    mergesort(0,j,numeros);
    mergesort(j+1,n,numeros);

    for(int i = 0; i<n ; i++){
        printf("%d\n",numeros[i]);
    }
    
}