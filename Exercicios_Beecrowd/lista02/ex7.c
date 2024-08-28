#include <stdio.h>

int main() {
    int A,N,i,soma=0;
    scanf("%d",&A);
    scanf("%d",&N);
    while(N<=0){
        scanf("%d",&N);
    }
    for(i = 0 ; i<= N-1 ; i++){
        soma += A + i;
    }
    printf("%d\n",soma);
}