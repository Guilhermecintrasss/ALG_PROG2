#include <stdio.h>

#define MAX 100


/* Recebe um número inteiro n >= 0 e um vetor v de números inteiros e rearranja
   o intervalo [p..r] do vetor v de modo que fique crescente */
void insertionsort(int p, int r, int v[MAX])
{

  int i, j, x;
  for (i = p+1; i < r; i++) {
    x = v[i];
    for (j = i - 1; j >= p && v[j] > x; j--)
      v[j+1] = v[j];
    v[j+1] = x;
  }

}

/* Recebe por referência dois inteiros a e b e troca seus valores */
void troca(int *a, int *b) {
  int aux;
  aux = *a;
  *a = *b;
  *b = aux;
}

/* Recebe um par de números inteiros p e r, com p <= r e um vetor v[p..r]
   de números inteiros e rearranja seus elementos e devolve um número in-
   teiro j em p..r tal que v[p..j] <= v[j+1..r] */
int separa(int p, int r, int v[MAX])
{
  int x, i, j;
  x = v[p];
  i = p - 1;
  j = r + 1;
  while (1) {
    do {
      j--;
    } while (v[j] > x);
    do {
      i++;
    } while (v[i] < x);
    if (i < j)
      troca(&v[i], &v[j]);
    else
      return j;
  }
}

/* Recebe um vetor v[p..r] e o rearranja em ordem crescente */
void quicksort(int p, int r, int v[MAX])
{

  int q;
  if (r - p + 1 > 5) {
    q = separa(p, r, v);
    quicksort(p, q, v);
    quicksort(q+1, r, v);
  } else{
    insertionsort(p,r,v);
  }

}

/* Recebe um número inteiro k > 0 que indica o número de casos
   de teste; para cada caso de teste, recebe um número inteiro
   n, com 1 <= n <= MAX, e uma seqüência de n números inteiros
   e escreve a sequência ordenada */
int main(void)
{
  int k, n, i, v[MAX];
  scanf("%d", &k);
  while (k > 0) {
    scanf("%d", &n);
    for (i = 0; i < n; i++)
      scanf("%d", &v[i]);

    quicksort(0, n, v);

    for (i = 0; i < n; i++)
      printf("%d ", v[i]);
    printf("\n");
    k--;
  }
  return 0;
}
