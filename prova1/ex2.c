#include <stdio.h>
#include <string.h>

#define MAX 100
#define MAX_NOME 100

int busca_binaria_str_R(int esq, int dir, char v[MAX][MAX_NOME+1], char x[MAX_NOME+1])
{
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
  }
  return 0;
}