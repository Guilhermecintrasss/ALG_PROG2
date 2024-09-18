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
        short valor;
        t_naipe naipe;
    } t_carta;

int main() {
   
    t_carta cartas1[5],cartas2[5];
    int k;
    char letra_naipe;

    scanf("%d",&k);
    for(int i = 0;i<k; i++){
        for(int c = 0; c<5; c++){
            scanf("%hu %c", &cartas1[c].valor , &letra_naipe); // hu porque o tipo d nao ta dando certo
            cartas1[c].naipe = letra_naipe;
        }
    }
    for(int c = 0; c<5; c++){
            printf("%hu %c", cartas1[c].valor , cartas1[c].naipe);
        }

    return 0;
}