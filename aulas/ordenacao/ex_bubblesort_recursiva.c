
// #include <stdio.h>

// void troca(int *a, int *b)
// {
//   int aux;
//   aux = *a;
//   *a = *b;
//   *b = aux;
// }

// void bubblesort(int n, int v[])
// {
//   int i, j;
//   for (i = n - 1; i > 0; i--)
//     for (j = 0; j < i; j++)
//       if (v[j] > v[j+1])
// 	troca(&v[j], &v[j+1]);
// }
// int main(){
//     int v[5];
//     for(int i = 0; i<5; i++){
//         scanf("%d",&v[i]);
//     }
//     bubblesort(5,v);
//     for(int i = 0; i<5; i++){
//         printf("%d",v[i]);
//     }

// }

#include <stdio.h>
void troca(int *a, int *b)
{
   int aux;
   aux = *a;
   *a = *b;
   *b = aux;
 }

void bubblesort(int n, int v[]){

    
}
int main(){
    int v[5];
    for(int i = 0; i<5; i++){
         scanf("%d",&v[i]);
    }
    bubblesort(5,v);
    for(int i = 0; i<5; i++){
        printf("%d",v[i]);
    }
}