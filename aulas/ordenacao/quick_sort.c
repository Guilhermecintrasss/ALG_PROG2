#include <stdio.h>
#include <time.h>
#include <stdlib.h>


void troca(int *a, int *b)
{
  int aux;
  aux = *a;
  *a = *b;
  *b = aux;
}
int mediana(int n1, int n2,int n3){
  if(n1 > n2){
    troca(n1,n2);
  }
  if(n2>n3){
    troca(n2,n3);
  }
  if(n1>n2){
    troca(n1,n2);
  }
  return n2;
}
int separa_aleatorio_mediana(int p, int r, int v[4])
{
int x, i, j,t,n1,n2,n3;
t = r-p+1; // tamanho do vetor
n1 = v[p+rand()%t];
n2 = v[p+rand()%t];
n3 = v[p+rand()%t];
x = mediana(n1,n2,n3);
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
int separa_aleatorio(int p, int r, int v[4])
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

int separa(int p, int r, int v[4])
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

int main()
{
    int v[4],j;
    v[0] = 5;
    v[1] = 3;
    v[2] = 4;
    v[3] = 2;
    j = separa_aleatorio_mediana(0,3,v);
    
    for(int i = 0; i<4 ; i++){
        printf("%d ",v[i]);
    }

}