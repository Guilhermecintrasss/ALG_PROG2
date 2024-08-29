#include <stdio.h>

int cria_fibo(int v[], int n){
    int num = 0;
    if(n = 1){
        v[0] = 0;
        v[n] = 1;
    }
    else{
        num = cria_fibo(v,n-1);
        num += v[n-2];
        v[n] = num;
    }

    return v[n];

}
int main(){
    int v[61],n = 61;
    v[61] = cria_fibo(v,n);
    for(int i = 0; i<61 ; i++){
        printf("%d",v[i]);
    }
}