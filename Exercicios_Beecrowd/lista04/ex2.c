#include <stdio.h>

void insertionsort(int n, int v[])
{
    int i, j, x;
    for (i = 1; i < n; i++) {
        x = v[i];
        for (j = i - 1; j >= 0 && v[j] > x; j--)
            v[j+1] = v[j];
        v[j+1] = x;
    }
}

int main() {
    int n;
    while(scanf("%d",&n) == 1){
        int codigos[n];
        
        for(int i = 0; i<n ; i++){
            scanf("%d",&codigos[i]);
        }
        
        insertionsort(n,codigos);

        for(int i = 0; i<n ; i++){
            printf("%04d\n",codigos[i]);
        }
    }
}