#include <stdio.h>

void troca(int *a, int *b)
{
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}
void insertionsort(int p, int n, int v[]) // [4,6,5,3,7]
{
    int i, j, x;
    for (i = p+1; i <= n; i++) {
        x = v[i]; //[3]
        for (j = i - 1; j >= 0 && v[j] < x; j--) //[5,5,7] [3,5,7]
            v[j+1] = v[j];
        v[j+1] = x;
    }
}
int separa_par(int p, int r, int v[]) // 0 e 5 [3,4,5,6,7]
{
    int i, j;
    i = p - 1;  // -1
    j = r + 1; // 6
    while (i < j) {
    do {
    j--;
    } while (v[j]%2 != 0);
    do {
    i++;
    } while (v[i]%2 == 0);
    if (i < j)
    troca(&v[i], &v[j]); //[6,4,5,3,7] e [6,5,4,3,7]
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
    j = separa_par(0,n-1,numeros); // vai até a posição n, logo tem que ser até n-1

    mergesort(0,j+1,numeros); // vai até a posição final-1, logo tem que ser até j+1, para ir até j
    insertionsort(j+1,n,numeros); // aqui vai de j+1 até n-1 (ele sempre vai até a posição final-1)

    for(int i = 0; i<n ; i++){
        printf("%d\n",numeros[i]);
    }
    // ta dando errado
}