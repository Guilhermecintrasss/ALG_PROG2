#include <stdio.h>
#include <string.h>

#define MAX 100
#define MAX_NOME 100

/* Recebe dois números inteiros esq e dir, um vetor de strings crescente
   v[esq..dir] e uma string x tal que v[esq] < x <= v[dir] e devolve
   um índice k em [esq+1, dir] tal que v[k-1] < x <= v[k] */
int busca_binaria_str_R(int esq, int dir, char v[MAX][MAX_NOME+1], char x[MAX_NOME+1])
{
  /*** Implemente ***/
    int depois,meio;
    while (esq < dir - 1) {
        meio = (esq + dir) / 2;
        depois = strcmp(x,v[meio]);
        if (depois > 0)
            esq = meio;
        else
            dir = meio;
        }
    return dir;
}


/* Recebe um número inteiro n > 0, um vetor de números inteiros crescente v[0..n-1] e um número inteiro x e devolve um índice k em [0, n] tal que v[k-1] < x <= v[k] 
int busca_binaria(int n, int v[MAX], int x)
{
int esq, dir, meio;
esq = -1;
dir = n;
while (esq < dir - 1) {
meio = (esq + dir) / 2;
if (v[meio] < x)
esq = meio;
else
dir = meio;
}
return dir;
}
*/

/* Recebe um inteiro c > 0, e c linhas com um inteiro n, uma string x,
   e mais n strings crescentes, e escreve o índice k onde x = v[k] ou
   -1 caso contrário */
int main(void)
{
  int c, n, k, i;
  char v[MAX][MAX_NOME+1], x[MAX_NOME+1];
  
  scanf("%d", &c);
  while(c-- > 0) {
    scanf("%d", &n);
    for(i= 0; i < n; i++)
      scanf("%s", v[i]);
    scanf("%s", x);
    
    k = busca_binaria_str_R(0,n,v,x);
    if(k<n){
        if(strcmp(v[k],x) == 0){
            printf("%d\n",k);
        }
    } else{
        printf("-1");
    }
    /*** Utilize a busca binária e escreva a saída ***/
  }
  return 0;
}