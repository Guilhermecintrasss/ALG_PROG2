#include <stdio.h>

float somar(int n, float v[]){
    float soma;
    if(n == 0){
        soma = v[n-1];
    }
    else{
        soma = somar(n-1,v);
        soma += v[n-1];
    }
    return soma;
}
int main(){
    int n,i;
    scanf("%d",&n);
    i = n;
    float v[n],soma;
    while(i>0){
        scanf("%f",&v[i-1]);
        i = i-1;
    }
    soma = somar(n,v);
    printf("%f",soma);
}
    