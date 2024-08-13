#include <stdio.h>

#define MAX_ALUNOS 100

float ler_media(int m) {
  float media, nota;
  media = 0;
  for (int i = 0; i < m; i++) {
    scanf("%f", &nota);
    media += nota;
  }
  media = media / m;
  return media;
}

void ler_notas_praticas(float P[], int n) {
  for (int i = 0; i < n; i++){
    P[i] = ler_media(3);}
    

}

void ler_notas_teoricas(float T[], int n) {
  for (int i = 0; i < n; i++)
    T[i] = ler_media(2);
}

float obter_maximo(float vetor[], int n) {
  float maximo = vetor[0];
  for (int i = 0; i < n; i++)
    if (maximo < vetor[i])
      maximo = vetor[i];
  return maximo;
}

float obter_media(float vetor[], int n) {
  /* Falta implementar: calcula de devolve a média dos elementos do vetor */
  float total = 0,media = 0;
  for (int i = 0; i < n; i++){
    total = total + vetor[i];
  }
    media = total/n;
  return media;
}

void mutiplicar_fator(float vetor[], int n, float fator) {
  for (int i = 0; i < n; i++)
    vetor[i] = vetor[i] * fator;
}

void imprimir_notas(float P[], float T[], int n) {
  /* Falta implementar: escreve a média de cada aluno */
  float media;
  for(int i = 0; i < n ; i++){
    media = (P[i] + T[i])/2;
    printf("%.1f \n",media);
  }
}

int main() {
  int n;
  float P[MAX_ALUNOS];
  float T[MAX_ALUNOS];
  float maximo;

  scanf("%d", &n);
  ler_notas_praticas(P, n);
  mutiplicar_fator(P, n, 1.1);
  ler_notas_teoricas(T, n);
  maximo = obter_maximo(T, n);
  mutiplicar_fator(T, n, 10/maximo);

  imprimir_notas(P, T, n);
    
  printf("Max P: %.1f\n", obter_maximo(P,n));
  printf("Max T: %.1f\n", obter_maximo(T,n));
  printf("Media P: %.1f\n", obter_media(P, n));
  printf("Media T: %.1f\n", obter_media(T, n));
}