#include <stdio.h>

int potencia(int x, int n){
    int pot;
    if(n == 0){
        pot = 1;
    }
    else{
        if(n%2 == 0){
            pot = potencia(x,n/2);
            pot *= pot;
        }
        else{
            pot = potencia(x,n-1);
            pot *= x;
        }   
    }
    return pot;
}
int main(){

    int x,n,res;
    scanf("%d %d",&x,&n);
    res = potencia(x,n-1);
    printf("%d", res);

}
    