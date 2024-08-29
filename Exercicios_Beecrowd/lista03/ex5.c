#include <stdio.h>

int main() {
    int fib[61],p,c;
    fib[0] = 0;
    fib[1] = 1;
    for(int i = 2; i<61 ; i++){
        fib[i] = fib[i-1] + fib[i-2];
    }
    scanf("%d",&c);
    for(int i = 0; i<c ; i++){
        scanf("%d",&p);
        printf("Fib(%d) = %d\n",p,fib[p]);
    }

}