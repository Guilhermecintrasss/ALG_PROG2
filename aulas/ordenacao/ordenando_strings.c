#include <stdio.h>
#include <string.h>
// strcpy --> copia uma string em outro vetor (mesmo sentido da atribuição de valor)
// strcmp --> compara uma string com a outra seguindo a ordem alfabetica (-1 caso a primeira seja primeira, 1 caso a segunda seja primeira, 0 caso iguais)
#define MAX 4

void troca(int *a, int *b);
void bubblesort(int n, int v[]);


int main(void)
{
  char v[MAX][30];
  int n = MAX;
  for(int c = 0; c<n; c++){
    scanf("%s",v[c]);
  }
  bubblesort(n, v);

  return 0;
}

void troca(int *a, int *b)
{
  int aux;
  strcpy(aux,a);
  strcpy(a,b);
  strcpy(b,aux);
}

void bubblesort(int n, int v[])
{
  int i, j,compara;
  for (i = n - 1; i > 0; i--)
    for (j = 0; j < i; j++)
      compara = strcmp(v[j],v[j+1]);
      
      if (compara == -1){
	    troca(&v[j], &v[j+1]);
    }
}