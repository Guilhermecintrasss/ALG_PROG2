#include <stdio.h>
#include <string.h>

#define MAX_PALAVRA  15

#define MAX_ALTURA  15
#define MAX_LARGURA 10


void ler_matriz(char matriz[MAX_ALTURA][MAX_LARGURA], int m, int n) {
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      scanf(" %c", &matriz[i][j]);
}

void imprimir_matriz(char A[MAX_ALTURA][MAX_LARGURA], int m, int n) {
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++)
      printf("%c ", A[i][j]);
    printf("\n");
  }
}

void criar_matriz_ponto(char matriz[MAX_ALTURA][MAX_LARGURA], int m, int n) {
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      matriz[i][j] = '.';
}

int comprimento_str(char string[]) {
  int comprimento = 0;
  while (string[comprimento] != '\0')
    comprimento++;
  return comprimento;
}

void copiar_inverso(char palavra[], char inverso[]) {
  int i, j;
  i = comprimento_str(palavra) - 1;  /* índice da última letra de palavra */
  j = 0;                             /* índice da primeira posição de inverso */
  while (i >= 0)
    /* copia a i-ésima letra de palavra para a j-ésima posição de inverso */
    inverso[j++] = palavra[i--];
  /* adicionamos o '\0' para indicar que a string inverso terminou */
  inverso[j] = '\0';
}

void marcar_ocorrencia_horizontal(char palavra[],
        char A[MAX_ALTURA][MAX_LARGURA],
        char B[MAX_ALTURA][MAX_LARGURA],
        int m, int n, int i, int j) {
  int k = 0;
  while (j+k < n && A[i][j+k] == palavra[k] && palavra[k] != '\0')
    k++;
  if (palavra[k] == '\0') /* achamos a palavra */
    for (k--; k >= 0; k--)
      B[i][j+k] = palavra[k];
}

void marcar_ocorrencia_vertical(char palavra[],
        char A[MAX_ALTURA][MAX_LARGURA],
        char B[MAX_ALTURA][MAX_LARGURA],
        int m, int n, int i, int j) {
  /* Fazer */
}

void marcar_ocorrencia_diagonal(char palavra[],
        char A[MAX_ALTURA][MAX_LARGURA],
        char B[MAX_ALTURA][MAX_LARGURA],
        int m, int n, int i, int j) {
  /* Fazer: */
  /* Diagonal para direita e para baixo */
  /* Diagonal para esquerda e para baixo */
}

void marcar_ocorrencias(char palavra[],
        char A[MAX_ALTURA][MAX_LARGURA],
        char B[MAX_ALTURA][MAX_LARGURA],
        int m, int n) {
  int i, j;
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      marcar_ocorrencia_horizontal(palavra, A, B, m, n, i, j);
      marcar_ocorrencia_vertical(palavra, A, B, m, n, i, j);
      marcar_ocorrencia_diagonal(palavra, A, B, m, n, i, j);
    }
  }
}

int main() {
  int i;
  int m, n, p;
  char A[MAX_ALTURA][MAX_LARGURA];
  char B[MAX_ALTURA][MAX_LARGURA];
  char palavra[MAX_PALAVRA], inverso[MAX_PALAVRA];
  
  /* lê e cria matrizes */
  scanf("%d %d", &m, &n);
  ler_matriz(A, m, n);
  criar_matriz_ponto(B, m, n);
  
  /* lê e marca cada palavra */
  scanf("%d", &p);
  for (i = 0; i < p; i++) {
    scanf("%s", palavra);
    marcar_ocorrencias(palavra, A, B, m, n);
    copiar_inverso(palavra, inverso);
    marcar_ocorrencias(inverso, A, B, m, n);
  }
  
  /* imprime matriz resultante */
  imprimir_matriz(B, m, n);
}
