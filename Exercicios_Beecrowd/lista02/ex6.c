#include <stdio.h>

int main() {
    int n,l,c=0,mesma = 0, c2 = 0;
    char anterior[20],lingua[20];
    scanf("%d",&n);
    for(int i = 0; i < n ; i++){
       scanf("%d",&l);
       for(int j = 0; j < l ; j++){
            if(j!= 0){
                 scanf("%s",lingua);
                 while(lingua[c2] != '\0'){
                    if(lingua[c2] != anterior[c2])
                         mesma = 1;
                    c2++;
                    }   
            } else{
                scanf("%s",lingua);
            }
            while(lingua[c] != '\0'){
                anterior[c] = lingua[c];
                c++;
            }
            anterior[c] = '\0';
            c = 0;
       }
       if(mesma == 1){
            printf("ingles\n"); 
       }
       else{
            printf("%s\n",lingua);
       }
       mesma = 0;

    }
}