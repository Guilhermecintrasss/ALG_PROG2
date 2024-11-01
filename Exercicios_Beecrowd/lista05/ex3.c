#include <stdio.h>

void troca(int *a, int *b)
{
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}
int compara(int v1[] , int v2[], int n){
    int contador = 0;
    for(int i = 0; i<n ; i++){
        if(v1[i] == v2[i]){
            contador++;
        }
    }
    return contador;
}
void printa_vetor(int v[], int n){
    for(int i = 0; i<n ; i++){
        printf("%d ",v[i]);
    }
    printf("\n");
}
int separa(int p, int r, int v[])
{
    int x, i, j;
    x = v[p];
    i = p - 1;
    j = r + 1;
    while (i < j) {
    do {
    j--;
    } while (v[j] < x);
    do {
    i++;
    } while (v[i] > x);
    if (i < j)
    troca(&v[i], &v[j]);
    }
    return j;
}

void quicksort(int p, int r, int v[])
{
    int q;
    if (p < r) {
    q = separa(p, r, v);
    quicksort(p, q, v);
    quicksort(q+1, r, v);
    }
}

int main() {
   int n;
   scanf("%d",&n);
   for(int i = 0; i<n ; i++){
    int alunos,alunos_certos;
    int notas[1000],notas_ordenadas[1000];
    scanf("%d",&alunos);
    for(int c = 0; c<alunos; c++){
        scanf("%d",&notas[c]);
        notas_ordenadas[c] = notas[c];
    }
    quicksort(0,alunos-1,notas_ordenadas); // porque o quicksort esta ordenando ambos os vetores quando eu crio um vetor com o tamanho "alunos"?
    alunos_certos = compara(notas,notas_ordenadas,alunos);
    printf("%d\n",alunos_certos);
   }
}
