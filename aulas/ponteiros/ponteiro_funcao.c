#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define TIPO char
#define LEITURA " %c" // esse espaço é pro char nao ler enter como um caractere
int compara(const void *a , const void *b){
   TIPO x = tolower(*(TIPO*)a); // converte o void pra inteiro, nesse caso a gente sabe que o tipo que vai ser utilizado é o inteiro
   TIPO y = tolower(*(TIPO*)b); // o tolower faz que quando eu usar CHAR ele n levar em consideração letras maiusculas
   if(x<y)
      return -1; // primeiro menor que o segundo retorna um vlaor negativo
   else if (x>y)
      return 1; // primeiro maoir que o segundo retorna valor positivo
   else
      return 0; // iguais retorna 0
}

//void qsort(void * base , size_t nitens, size_t size, int (*conpar)(const void*,const void*)) // cria o ponteiro pra função "compar" que retorna inteiro e recebe 2 ponteiros genericos void
//Essa função void criada acima qsort ja existe na biblioteca stdlib.h, aqui foi criado apenas para entender como funciona.

int main(){
   int n;
   scanf("%d" , &n);
   TIPO v[n];
   for(int i = 0; i < n ; i++){
    scanf(LEITURA,&v[i]);
   }
   qsort(v,n,sizeof(TIPO),compara);

   for(int i = 0; i < n ; i++){
    printf(LEITURA,v[i]);
    printf("\n");
   }
}