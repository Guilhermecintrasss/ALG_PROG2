#include <stdio.h>

int main() {
    int c=0,total=0;
    scanf("%d",&c);
    if(c != 0){
        while(c != 0){
            if(c%2 == 0){
                for(int i=0;i<5;i++){
                    total = total + c + 2*i;
                }
            }
            else{
                for(int i=0;i<5;i++){
                    total = total + c+1 + 2*i;
                }
            }
            printf("%d\n",total);
            scanf("%d",&c);
            total = 0;
        }
    }
}