#include <stdio.h>

void troca(int *a, int *b)
{
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

int bubblesort(int n, int v[])
{
  int i, j,c = 0;
  for (i = n - 1; i > 0; i--)
    for (j = 0; j < i; j++)
      if (v[j] > v[j+1]){
	    troca(&v[j], &v[j+1]);
        c = c+1;
        }
    return c;
}
int main() {
    int n,total;
    scanf("%d",&n);
    int v[n];
    for(int i = 0; i < n ; i++){
        scanf("%d",&v[i]);
    }
    total = bubblesort(n,v);
    if(total%2 == 0){
        printf("Carlos");
    }
    else{
        printf("Marcelo");
    }
    return 0;
}
