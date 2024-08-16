#include <stdio.h>

int potR(int x, int n){
    int pot;
    if(n == 0){
        pot = 1;
    }
    else{
        pot = potR(x, n-1);
        pot = pot * x;
    }

    return pot;

}
int main(){
    int x,n,res;
    scanf("%d %d",&x,&n);
    res = potR(x,n);
    printf("%d", res);
}