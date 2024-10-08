#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000

void troca(int *a, int *b);
void copia_tmp(int n, int v[], int tmp[]);
void bubblesort(int n, int v[]);
void selectionsort(int n, int v[]);
void insertionsort(int n, int v[]);

int separa_aleatorio(int p, int r, int v[MAX])
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

int separa(int p, int r, int v[MAX])
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

int main(void)
{
  int i, v[MAX], tmp[MAX];
  int n = MAX;
  clock_t inicio, fim;

  /* initialize random seed: */
  srand (time(NULL));

  for (i = 0; i < n; i++)
    v[i] = rand();  // vetor aleatório
    //100000 elementos
    //BUBBLE: 30.3501 segundos
    //SELECTION: 9.95902 segundos
    //INSERTION: 5.64629 segundos
    //v[i] = i;     // vetor ordenado
    //100000 elementos
    //BUBBLE: 10.3639 segundos
    //SELECTION: 9.8959 segundos
    //INSERTION: 0.000326 segundos
    //v[i] = n - i; // vetor decrescente
    //100000 elementos
    //BUBBLE: 21.7612 segundos
    //SELECTION: 9.59479 segundos
    //INSERTION: 11.2112 segundos

  printf("%d elementos\n", n);

  
  copia_tmp(n, v,tmp);
  inicio = clock();
  bubblesort(n, tmp);
  fim = clock();
  printf("BUBBLE: %g segundos\n", (fim - inicio) / (float) CLOCKS_PER_SEC);

  copia_tmp(n, v,tmp);
  inicio = clock();
  selectionsort(n, tmp);
  fim = clock();
  printf("SELECTION: %g segundos\n", (fim - inicio) / (float) CLOCKS_PER_SEC);
  
  copia_tmp(n, v,tmp);
  inicio = clock();
  insertionsort(n, tmp);
  fim = clock();
  printf("INSERTION: %g segundos\n", (fim - inicio) / (float) CLOCKS_PER_SEC);
  

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
