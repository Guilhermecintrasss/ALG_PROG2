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
    j = separa_aleatorio(0,3,v);
    
    for(int i = 0; i<4 ; i++){
        printf("%d ",v[i]);
    }

}