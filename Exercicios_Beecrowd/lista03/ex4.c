#include <stdio.h>

int main() {
    int v[20],j = 19,aux;
    for(int i = 0; i<20; i++){
        scanf("%d",&v[i]);
    }
    for(int i = 0; i<10; i++){
        aux = v[i];
        v[i] = v[j];
        v[j] = aux;
        j--;
    }
    for(int i = 0; i<20; i++){
        printf("N[%d] = %d\n",i,v[i]);
    }
}