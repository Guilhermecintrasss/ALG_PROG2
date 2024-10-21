#include <stdio.h>

typedef struct 
{
    int valor;
    celula *prox;
} celula;

void imprime_lista(celula *lst, celula *p, celula *p2, int valor)
{
celula *nova;
p2 = lst;
nova = (celula *) malloc(sizeof (celula));
nova->chave = valor;

for (p = lst; p->prox != NULL; p = p->prox){}

nova->prox = p->prox;
p->prox = nova;

}
void insere_C(int y, celula *p) // y é o valor anterior aonde sera inserido um valor
{
celula *nova;
nova = (celula *) malloc(sizeof (celula));
nova->chave = y;
nova->prox = p->prox;
p->prox = nova;
}


int main() {
    celula c, *lista;
    c.prox = NULL;
    lista = &c;


}
