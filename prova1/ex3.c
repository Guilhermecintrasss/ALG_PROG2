#include <stdio.h>

#define MAX 100

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

void troca(int *a, int *b) {
  int aux;
  aux = *a;
  *a = *b;
  *b = aux;
}

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
