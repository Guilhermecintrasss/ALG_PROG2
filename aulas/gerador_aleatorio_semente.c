#include <stdio.h>

int main(){
    int semente;
    semente = time(NULL); /*Resulta em quanto tempo se passou desde alguma data especifica(nunca vai dar o mesmo resultado, pois retorna em segundos, e o tempo sempre esta passando)*/
    srand(semente); /*Gera uma sequencia de numeros aleatorios a partir de uma semente especifica(Semente igual gera a mesma sequencia)*/

}
    