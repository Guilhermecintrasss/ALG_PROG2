#include <stdio.h>
int fibo(int n, int v[], int *c){ // dessa forma, a função usa o valor original na variavel, e altera ele na função

        if(n == 0){
            v[n] = 0;
            (*c)++;
            return v[n];

        } else if(n == 1){
            (*c)++;
            v[n] = 1;
            return v[n];

        } else{
            (*c)++;
            v[n] = fibo(n-1,v,c) + fibo(n-2,v,c);
            return v[n];
        }
    }
int main() {
    int n,v[1000],c,res,qtd;
    c = 0;
    scanf("%d",&qtd);
    for(int i = 0; i<qtd; i++){
        scanf("%d",&n);
        res = fibo(n,v,&c);
        printf("fib(%d) = %d calls = %d\n",n,c-1,res);
        c = 0;
    }
}