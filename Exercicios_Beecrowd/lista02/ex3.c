#include <stdio.h>

int main() {
    int a,b,aux;
    scanf("%d %d",&a,&b);
    if(a>b){
        aux = b;
        b = a;
        a = aux;
    }
    a++;
    while(a<b){
        if(a%5 == 2 || a%5 == 3){
            printf("%d\n",a);
        }
        a = a+1;
    }
}