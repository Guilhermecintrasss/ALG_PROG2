#include <stdio.h>

struct cel
{
    int valor;
    struct cel *prox;
};
typedef struct cel celula;

celula *busca_C(int x, celula *lst)
{
celula *p;
p = lst->prox;
while (p != NULL && p->valor != x)
p = p->prox;
return p;
}
void insere_C(int y, celula *p)
{
celula *nova;
nova = (celula *) malloc(sizeof (celula));
nova->valor = y;
nova->prox = p->prox;
p->prox = nova;
}

void imprime_lista(celula *lst)
{
celula *p;
for (p = lst; p != NULL; p = p->prox)
printf("%d\n", p->valor);
}

int compara_listas(celula *lst1, celula *lst2){
    celula *p,*busca;
    int resul = 1;
    p = lst1->prox;
    while(p != NULL){
        busca = busca_C(p->valor , lst2);
        p = p->prox;
        if(busca == NULL){
            resul = -1;
        }
    }
    return resul;
}


int main() {
    int result,n1,n2,i = 0,valor;
    celula c, *lista1;
    c.prox = NULL;
    lista1 = &c;

    celula c2, *lista2;
    c.prox = NULL;
    lista2 = &c2;
    
    printf("Digite o numero de elementos da primeira lista: ");
    scanf("%d",&n1);
    printf("Digite o numero de elementos da segunda lista: ");
    scanf("%d",&n2);
    if(n1 == n2){
        while(i<n1){
            scanf("%d",&valor);
            insere_C(valor,lista1);
            i++;
        }
        i = 0;
        while(i<n2){
            scanf("%d",&valor);
            insere_C(valor,lista2);
            i++;
        }


        result = compara_listas(lista1,lista2);
        if(result < 0){
            printf("Diferentes\n");
        } else{
            printf("Iguais\n");
        }
    }
    else{
        printf("Diferentes\n");
    }
    imprime_lista(lista1->prox);
}
