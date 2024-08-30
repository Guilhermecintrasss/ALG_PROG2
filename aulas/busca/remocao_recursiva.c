#include <stdio.h>

float somar( float v[],int k,int n){
    int aux;
    if(k == n){
    
    } else{
        aux = v[n];
        v[n] = somar(v,k,n-1);
        v[n-1] = v[n];
    }

  return v[n];
}
int main(){
    int v[4], k=1,n = 3,num;
    v[0] = 1;
    v[1] = 2;
    v[2] = 3;
    v[3] = 4;
    num = somar(v,k,n);

}
    