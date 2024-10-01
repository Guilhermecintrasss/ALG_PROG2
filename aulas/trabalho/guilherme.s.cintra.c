/*

essa versão simplificada, há menos possibilidades de mãos, e mãos iguais resultam em empate.
Considere que as cartas J, Q, K e A valem 11, 12, 13
e 14, respectivamente (o A não vale 1). Temos as
seguintes mãos, do maior valor para o menor valor:
• Royal Flush: 5 cartas do mesmo naipe exatamente na sequência 10, J, Q, K e A
• Straight Flush: 5 cartas do mesmo naipe com valores em sequência (p. ex. 4, 5, 6, 7 e 8)
• Quadra: 4 cartas de mesmo valor
• Full House: 3 cartas de mesmo valor e outras 2 cartas de mesmo valor (p. ex. 5, 5, 5, 3 e 3)
• Flush: 5 cartas de quaisquer valores com o mesmo naipe
• Sequência: 5 cartas de quaisquer naipes com valores em sequência
• Trinca: 3 cartas de mesmo valor
• 2 pares: 2 cartas de mesmo valor e outras 2 cartas de mesmo valor
• Par: 2 cartas com o mesmo valor
• Carta mais alta: se nenhuma das mãos acima ocorre, é considerada a carta de maior valor

    Entrada e saída
Como entrada, seu programa deve receber uma linha com um inteiro k > 0 que representa
a quantidade de casos de teste. Cada caso de teste consiste em duas linhas, contendo a primeira
linha as 5 cartas da primeira capivara, e a segunda linha as 5 cartas da segunda. Cada carta
é apresentada no formato valor naipe. O campo valor pode ser um número entre 2 e 10
ou uma letra entre J, Q, K e A. O campo naipe é uma letra entre P (Paus ♣), O (Ouros ♢),
C (Copas ♡) e E (Espadas ♠). Considere que as cartas não necessariamente serão dadas em
ordem crescente de valor, e que podem haver espaços extras entre os dados de entrada.
Para cada um dos casos de teste, seu programa deve gerar uma saída em uma linha escrevendo 1 caso a primeira capivara vença, 2 caso a segunda vença, e E caso haja empate.
Adicionalmente, caso não haja empate você deve escrever após 1 ou 2 as cartas da capivara
ganhadora, ordenadas de acordo com os seguintes critérios:

1º Menor valor;
2º Naipe, na ordem paus (P ♣) (menor), ouros (O ♢), copas (C ♡) e espadas (E ♠) (maior).

Por fim, ao escrever a mão deve haver um espaço entre cada valor ou naipe, mas
não após o último naipe.


Deve usar as seguintes estruturas:

typedef enum {
COPAS = 'C',
ESPADAS = 'E',
OUROS = 'O',
PAUS = 'P'
} t_naipe;
typedef struct {
short valor;
t_naipe naipe;
} t_carta;

Além disso, você DEVE implementar algum método visto em sala para ordenar as cartas
dadas como entrada, a fim de escrever na saída as cartas do ganhador ordenadas de acordo
com os critérios apresentados anteriormente. Observe que ordenar as cartas pode facilitar a
verificação das mãos das capivaras para decidir a mão ganhadora

sugestão de estrutura(nao obrigatoria):

typedef enum {
PAR = 15,
DOISPARES,
TRINCA,
SEQUENCIA,
FLUSH,
FULL,
QUADRA,
SFLUSH,
RFLUSH
} t_valor_m;
typedef struct {
t_carta cartas[5];
t_valor_m valor;
} t_mao;

*/
/*

essa versão simplificada, há menos possibilidades de mãos, e mãos iguais resultam em empate.
Considere que as cartas J, Q, K e A valem 11, 12, 13
e 14, respectivamente (o A não vale 1). Temos as
seguintes mãos, do maior valor para o menor valor:
• Royal Flush: 5 cartas do mesmo naipe exatamente na sequência 10, J, Q, K e A
• Straight Flush: 5 cartas do mesmo naipe com valores em sequência (p. ex. 4, 5, 6, 7 e 8)
• Quadra: 4 cartas de mesmo valor
• Full House: 3 cartas de mesmo valor e outras 2 cartas de mesmo valor (p. ex. 5, 5, 5, 3 e 3)
• Flush: 5 cartas de quaisquer valores com o mesmo naipe
• Sequência: 5 cartas de quaisquer naipes com valores em sequência
• Trinca: 3 cartas de mesmo valor
• 2 pares: 2 cartas de mesmo valor e outras 2 cartas de mesmo valor
• Par: 2 cartas com o mesmo valor
• Carta mais alta: se nenhuma das mãos acima ocorre, é considerada a carta de maior valor

    Entrada e saída
Como entrada, seu programa deve receber uma linha com um inteiro k > 0 que representa
a quantidade de casos de teste. Cada caso de teste consiste em duas linhas, contendo a primeira
linha as 5 cartas da primeira capivara, e a segunda linha as 5 cartas da segunda. Cada carta
é apresentada no formato valor naipe. O campo valor pode ser um número entre 2 e 10
ou uma letra entre J, Q, K e A. O campo naipe é uma letra entre P (Paus ♣), O (Ouros ♢),
C (Copas ♡) e E (Espadas ♠). Considere que as cartas não necessariamente serão dadas em
ordem crescente de valor, e que podem haver espaços extras entre os dados de entrada.
Para cada um dos casos de teste, seu programa deve gerar uma saída em uma linha escrevendo 1 caso a primeira capivara vença, 2 caso a segunda vença, e E caso haja empate.
Adicionalmente, caso não haja empate você deve escrever após 1 ou 2 as cartas da capivara
ganhadora, ordenadas de acordo com os seguintes critérios:

1º Menor valor;
2º Naipe, na ordem paus (P ♣) (menor), ouros (O ♢), copas (C ♡) e espadas (E ♠) (maior).

Por fim, ao escrever a mão deve haver um espaço entre cada valor ou naipe, mas
não após o último naipe.


Deve usar as seguintes estruturas:

typedef enum {
COPAS = 'C',
ESPADAS = 'E',
OUROS = 'O',
PAUS = 'P'
} t_naipe;
typedef struct {
short valor;
t_naipe naipe;
} t_carta;

Além disso, você DEVE implementar algum método visto em sala para ordenar as cartas
dadas como entrada, a fim de escrever na saída as cartas do ganhador ordenadas de acordo
com os critérios apresentados anteriormente. Observe que ordenar as cartas pode facilitar a
verificação das mãos das capivaras para decidir a mão ganhadora

sugestão de estrutura(nao obrigatoria):

typedef enum {
PAR = 15,
DOISPARES,
TRINCA,
SEQUENCIA,
FLUSH,
FULL,
QUADRA,
SFLUSH,
RFLUSH
} t_valor_m;
typedef struct {
t_carta cartas[5];
t_valor_m valor;
} t_mao;

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
    if(naipe == OUROS)
        return 1;
    if(naipe == ESPADAS)
        return 2;
    if(naipe == COPAS)
        return 3;
    if(naipe == PAUS)
        return 4;
 };


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
            if(c != 0 || c != 3){
                return -1; // Para nao dar conflito com o full_house, ja que o resultado de comparações certas é o mesmo
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
            if(c != 1 || c != 2){
                return -1; // Para nao dar conflito com a quadra
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
 int trinca(t_carta v[]){ // tenho que achar um jeito de nao dar conflito com os pares
    int c = 0, aux = 0;
    for(int i = 1; i<5; i++){
        if(v[i].valor == v[i-1].valor){
            c++;
        } else{
            if(aux<c){
                aux = c; // essa logica ajuda a definir a trinca
            }
            c = 0;
        }
    }

    if(aux == 2){
        return 1;
    } else {
        return -1;
    }
 }
 int pares(t_carta v[]){ // dando conflito com trinca, porém nao altera o resultado pela ordem de chamada das funcoes.
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
 int carta_alta(t_carta v[]){ // vai retornar o valor da carta mais alta
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

        if(mao1>mao2){ // 
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
            }
            else{
                 printf("%c %c ", carta_print , cartas2[c].naipe); 
            }
            }
        } else{
            printf("E");
        }
    }


    return 0;
}