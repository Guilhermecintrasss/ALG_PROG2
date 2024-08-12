#include <stdio.h>

#define MAX_PALAVRA 20

void copiar_cebolinha(char original[], char nova[]) {
    int i = 0,Rduplo = 0, c = 0;
    char novat[MAX_PALAVRA];
  while(original[i] != '\0'){
    if(original[i] == 'R'){
        if(Rduplo == 0){
            novat[c] = 'L';
            Rduplo = 1;
            c++;
        }       
    } else {
        novat[c] = original[i];
        Rduplo = 0;
        c++;
    }
    i++;
  }
  i = 0;
  while(i<c){
    nova[i] = novat[i];
    i = i+1;
  }
  nova[i] = '\0';
}

int main() {
  char palavra[MAX_PALAVRA];
  char palavra_modificada[MAX_PALAVRA];

  scanf("%s", palavra);
  copiar_cebolinha(palavra, palavra_modificada);
  printf("%s", palavra_modificada);

}