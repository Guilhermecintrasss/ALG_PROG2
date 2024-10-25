#include <stdio.h>

struct cel
{
    int valor;
    struct cel *prox;
};

typedef struct cel celula;

celula *busca_fim(celula *lst)
{
celula *p;
p = lst;

while (p->prox != NULL)
    p = p->prox;
return p;
}

void imprime_lista(celula *lst)
{
celula *p;
for (p = lst; p != NULL; p = p->prox)
printf("%d\n", p->valor);
}

void busca_insere_fim(int y, celula *lst) 
{
celula *p;
p = busca_fim(lst);
celula *nova;
nova = (celula *) malloc(sizeof (celula));
nova->valor = y;
nova->prox = p->prox;
p->prox = nova;
}


int main() {
    celula c, *lista;
    int valor,n,i=0;
    c.prox = NULL;
    lista = &c;

    printf("Digite o numero de elementos da primeira lista: ");
    scanf("%d",&n);

    while(i<n){
            scanf("%d",&valor);
            busca_insere_fim(valor,lista);
            i++;
        }
    imprime_lista(lista->prox);
}
