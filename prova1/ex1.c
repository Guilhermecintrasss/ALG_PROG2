#include <stdio.h>
#define MAX 100

/* Recebe um vetor com n números inteiros e remove o elemento na posição k */
void troca(int *a, int *b) {
  int aux;
  aux = *a;
  *a = *b;
  *b = aux;
}
int remove_R(int n, int v[], int k) // [2,1,3] , k == 2
{
    int i;
  if(k == n){
    return n;
  }
  else if(k == n-1){

  } else{
    i = remove_R(n-1,v,k);
    i = n;
  }
  troca(&v[n-1],&v[n]);
  return i;
}
    
/* Lê um inteiro n, um vetor com n inteiros e um inteiro k,
   remove o elemento de índice k de v, escrevendo o vetor */
int main (void)
{
  int n, i, k;
  
  scanf("%d", &n);
  int v[n];
  
  for (i = 0; i < n; i++)
    scanf("%d", &v[i]);
  scanf("%d", &k);

  n = remove_R(n-1, v, k);

  for (i = 0; i < n; i++)
    printf("%d ", v[i]);
  printf("\n");

  return 0;
}