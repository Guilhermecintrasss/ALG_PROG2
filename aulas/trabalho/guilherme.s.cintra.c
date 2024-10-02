/**************************************************
*
* Guilherme de Souza Cintra
* Trabalho 1
* Professor(a): Diego Padilha
*
*/
#include <stdio.h>
typedef enum 
   {
        COPAS = 'C',
        ESPADAS = 'E',
        OUROS = 'O',
        PAUS = 'P'
    } t_naipe;

    typedef struct 
    {
        int valor;
        t_naipe naipe;
    } t_carta;

 int converte_naipe(char naipe){
    if(naipe == PAUS)
        return 1;
    if(naipe == OUROS)

        return 2;
    if(naipe == COPAS)
        return 3;
    else
        return 4;
 }


 int royal_flush(t_carta v[]){
    for(int i = 10; i<15; i++){
        if(v[i-10].valor != i || v[i-10].naipe != v[0].naipe){
            return -1;
        }
    }
    return 1;
 }

 void troca(t_carta *a, t_carta *b)
{
  t_carta aux;
  aux = *a;
  *a = *b;
  *b = aux;
}
 void bubblesort(int n, t_carta v[])
{
    int i, j;
    for (i = n - 1; i > 0; i--)
        for (j = 0; j < i; j++)
            if (v[j].valor > v[j+1].valor)
    troca(&v[j], &v[j+1]);
}

void bubblesort_naipe(int n, t_carta v[])
{
    int i, j;
    for (i = n - 1; i > 0; i--)
        for (j = 0; j < i; j++)
            if (converte_naipe(v[j].naipe) > converte_naipe(v[j+1].naipe) && v[j].valor == v[j+1].valor)
    troca(&v[j], &v[j+1]);
}

 int straight_flush(t_carta v[]){
    for(int i = 1; i<5; i++){
        if(v[i].valor != v[i-1].valor+1 || v[i].naipe != v[0].naipe){
            return -1;
        }
    }
    return 1;
 }
 int quadra(t_carta v[]){
    int c = 0;
    for(int i = 1; i<5; i++){
        if(v[i].valor == v[i-1].valor){
            c++;
        } else{
            if(c != 0 && c != 3){
                return -1;
            }
        }
    }
    if(c == 3){
        return 1;
    } else {
        return -1;
    }
 }
 int full_house(t_carta v[]){
    int c = 0;
    for(int i = 1; i<5; i++){
        if(v[i].valor == v[i-1].valor){
            c++;
        } else{
            if(c != 1 && c != 2){
                return -1;
            }
        }
    }
    if(c == 3){
        return 1;
    } else {
        return -1;
    }
 }
 int flush(t_carta v[]){
     for(int i = 1; i<5; i++){
        if(v[i].naipe != v[0].naipe){
            return -1;
        }
    }
    return 1;
 }
 int sequencia(t_carta v[]){
     for(int i = 1; i<5; i++){
        if(v[i].valor != v[i-1].valor+1){
            return -1;
        }
    }
    return 1;
 }
 int trinca(t_carta v[]){
    int c = 0, aux = 0;
    for(int i = 1; i<5; i++){
        if(v[i].valor == v[i-1].valor){
            c++;
        } else{
            if(aux<c){
                aux = c;
            }
            c = 0;
        }
    }
    if(aux<c){
        aux = c;
    }

    if(aux == 2){
        return 1;
    } else {
        return -1;
    }
 }
 int pares(t_carta v[]){
     int c = 0;
    for(int i = 1; i<5; i++){
        if(v[i].valor == v[i-1].valor){
            c++;
        }
    }
    if(c == 2){
        return 1;
    } else {
        return -1;
    }
 }
 int par(t_carta v[]){
     int c = 0;
    for(int i = 1; i<5; i++){
        if(v[i].valor == v[i-1].valor){
            c++;
        }
    }
    if(c == 1){
        return 1;
    } else {
        return -1;
    }
 }
 int carta_alta(t_carta v[]){
    return v[4].valor;
 }
 void le_mao(char carta_letras[], t_carta v[],int c){
    if(carta_letras[0] == 'J'){
        v[c].valor = 11;
    } else if(carta_letras[0] == 'Q' && carta_letras[1] == '\0'){
        v[c].valor = 12;
    } else if(carta_letras[0] == 'K' && carta_letras[1] == '\0'){
        v[c].valor = 13;
    } else if(carta_letras[0] == 'A' && carta_letras[1] == '\0'){
        v[c].valor = 14;
    } else if(carta_letras[0] == '1' && carta_letras[1] == '0'){
        v[c].valor = 10;
    } else{
        v[c].valor = carta_letras[0] - '0';
    }
 }
 void converte_letra(char *carta_letras, int valor){
    if(valor == 11){
        *carta_letras = 'J'; 
    } else if(valor == 12){
        *carta_letras = 'Q'; 
    } else if(valor == 13){
        *carta_letras = 'K'; 
    } else if(valor == 14){
        *carta_letras = 'A'; 
    }
 }

 int encontra_mao(t_carta v[]){ 
    int mao = -1;
    if(royal_flush(v) == 1)
        mao = 23;
    else if(straight_flush(v) == 1)
        mao = 22;
    else if(quadra(v) == 1)
        mao = 21;
    else if(full_house(v) == 1)
        mao = 20;
    else if(flush(v) == 1)
        mao = 19;
    else if(sequencia(v) == 1)
        mao = 18;
    else if(trinca(v) == 1)
        mao = 17;
    else if(pares(v) == 1)
        mao = 16;
    else if(par(v) == 1)
        mao = 15;
    else
        mao = carta_alta(v);
    return mao; 
 }

int main() {
   
    char carta_letras[2];
    t_carta cartas1[5],cartas2[5];
    int k;
    char letra_naipe;
    int mao1,mao2;

    scanf("%d",&k);
    for(int i = 0;i<k; i++){
        for(int c = 0; c<5; c++){

            scanf("%s %c", carta_letras , &letra_naipe);
            cartas1[c].naipe = letra_naipe;
            le_mao(carta_letras,cartas1,c);

        }

        for(int c = 0; c<5; c++){

            scanf("%s %c", carta_letras , &letra_naipe);
            cartas2[c].naipe = letra_naipe;
            le_mao(carta_letras,cartas2,c);
        }

        bubblesort(5,cartas1);
        bubblesort_naipe(5,cartas1);
        bubblesort(5,cartas2);
        bubblesort_naipe(5,cartas2);

        mao1 = encontra_mao(cartas1);
        mao2 = encontra_mao(cartas2);

        if(mao1>mao2){
            printf("1 ");
            for(int c = 0; c<5; c++){
            char carta_print = '*';
            converte_letra(&carta_print,cartas1[c].valor);
            if(carta_print == '*'){
                 printf("%d %c ", cartas1[c].valor , cartas1[c].naipe); 
            }
            else{
                 printf("%c %c ", carta_print , cartas1[c].naipe); 
            }

            }
        } else if(mao1<mao2){
            printf("2 ");
            for(int c = 0; c<5; c++){
            char carta_print = '*';
            converte_letra(&carta_print,cartas2[c].valor);
            if(carta_print == '*'){
                 printf("%d %c ", cartas2[c].valor , cartas2[c].naipe); 
                 if(c == 5)
                    printf("%d %c", cartas2[c].valor , cartas2[c].naipe); 
            }
            else{
                 printf("%c %c ", carta_print , cartas2[c].naipe); 
                 if(c == 5)
                    printf("%c %c", carta_print , cartas2[c].naipe);
            }
            }
        } else{
            printf("E");
        }
    }
    return 0;
}