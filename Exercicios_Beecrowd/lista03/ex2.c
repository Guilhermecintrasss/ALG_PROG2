#include <stdio.h>
#include <math.h>

int main() {
    int v[10],n;
    scanf("%d",&n);
    v[0] = n;
    for(int i = 1; i<10; i++){
        v[i] = v[i-1] * 2;
    }
    for(int i = 0; i<10; i++){
        printf("N[%d] = %d\n",i,v[i]);
    }
    
}