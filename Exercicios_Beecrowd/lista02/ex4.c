#include <stdio.h>

int main() {
    int a,b,c=0;
    scanf("%d %d",&a,&b);
    for(int i=1; i<=b;i++){
        printf("%d",i);
        if(i%a == 0){
            printf("\n");
        }
        else{
            printf(" ");
        }
    }
}