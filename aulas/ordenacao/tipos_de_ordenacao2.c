#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void troca(int *a, int *b);
void copia_tmp(int n, int v[], int tmp[]);
void bubblesort(int n, int v[]);
void selectionsort(int n, int v[]);
void insertionsort(int n, int v[]);
void intercala(int p, int q, int r, int v[]);
void mergesort(int p, int r, int v[]);


int main(void)
{
    int i;
    int MIN = 1000, MAX = 100000;
    char tipos[][12] = {"ALEATORIO", "CRESCENTE", "DECRESCENTE"};
    clock_t inicio, fim;

    /* initialize random seed: */
    srand (time(NULL));

    for (int n = MIN; n <= MAX; n *= 10)
    {
        printf("N: %d\n", n);
        int v[n], tmp[n];

        for (int tipo = 0; tipo < 3; tipo++) // 0 = aleatório, 1 = crescente, 2 = decrescente
        {
            for (i = 0; i < n; i++)
                if (tipo == 0)
                    v[i] = rand(); // vetor aleatório
                else if (tipo == 1)
                    v[i] = i; // vetor crescente
                else
                    v[i] = n - i; // vetor decrescente

            printf("\t%s\n", tipos[tipo]);

            copia_tmp(n, v,tmp);
            inicio = clock();
            bubblesort(n, tmp);
            fim = clock();
            printf("\t\tBUBBLE: %g segundos\n", (fim - inicio) / (float) CLOCKS_PER_SEC);

            copia_tmp(n, v,tmp);
            inicio = clock();
            selectionsort(n, tmp);
            fim = clock();
            printf("\t\tSELECTION: %g segundos\n", (fim - inicio) / (float) CLOCKS_PER_SEC);

            copia_tmp(n, v,tmp);
            inicio = clock();
            insertionsort(n, tmp);
            fim = clock();
            printf("\t\tINSERTION: %g segundos\n", (fim - inicio) / (float) CLOCKS_PER_SEC);

            copia_tmp(n, v,tmp);
            inicio = clock();
            mergesort(0, n, tmp);
            fim = clock();
            printf("\t\tMERGE: %g segundos\n", (fim - inicio) / (float) CLOCKS_PER_SEC);

            copia_tmp(n, v,tmp);
            inicio = clock();
            separa_aleatorio(0, n, tmp);
            fim = clock();
            printf("\t\tQUICKSORT_ALEATÓRIO: %g segundos\n", (fim - inicio) / (float) CLOCKS_PER_SEC);

            copia_tmp(n, v,tmp);
            inicio = clock();
            separa(0, n, tmp);
            fim = clock();
            printf("\t\tQUICKSORT: %g segundos\n", (fim - inicio) / (float) CLOCKS_PER_SEC);
        }
    }

    return 0;
}

void troca(int *a, int *b)
{
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

void copia_tmp(int n, int v[], int tmp[])
{
    for (int i = 0; i < n; i++)
    tmp[i] = v[i];
}

void bubblesort(int n, int v[])
{
    int i, j;
    for (i = n - 1; i > 0; i--)
        for (j = 0; j < i; j++)
            if (v[j] > v[j+1])
    troca(&v[j], &v[j+1]);
}

void selectionsort(int n, int v[])
{
    int i, j, min;
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i+1; j < n; j++)
            if (v[j] < v[min])
        min = j;
        troca(&v[i], &v[min]);
    }
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

/* Recebe os vetores crescentes v[p..q-1] e v[q..r-1]
e rearranja v[p..r-1] em ordem crescente */
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

/* Recebe um vetor v[p..r-1] e o rearranja em ordem crescente */
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

int separa_aleatorio(int p, int r, int v[])
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
return j;
}

int separa(int p, int r, int v[])
{
int x, i, j;
x = v[p];
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