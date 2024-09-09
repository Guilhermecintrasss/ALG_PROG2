#include <stdio.h>
#include <string.h>
// strcpy --> copia uma string em outro vetor (mesmo sentido da atribuição de valor)
// strcmp --> compara uma string com a outra seguindo a ordem alfabetica (-1 caso a primeira seja primeira, 1 caso a segunda seja primeira, 0 caso iguais)
#define MAX 1000

void troca(int *a, int *b);
void copia_tmp(int n, int v[], int tmp[]);
void bubblesort(int n, int v[]);


int main(void)
{
  int i, v[MAX], tmp[MAX];
  int n = MAX;

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
  bubblesort(n, tmp);

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