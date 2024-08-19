#include <stdio.h>

int main() {
    int a,b,total=0,aux;
    scanf("%d %d",&a,&b);
    if(a>b){
        aux = b;
        b = a;
        a = aux;
    }
    while(a<=b){
        if(a%13 != 0){
            total = total + a;
        }
        a = a+1;
    }
        printf("%d\n",total);
}