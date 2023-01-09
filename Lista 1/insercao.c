#include <stdio.h>
#include <stdlib.h>

typedef struct celula
{
    int dado;
    struct celula *prox;
} celula;

void insere_inicio(celula *p, int x)
{
    celula *novo = malloc(sizeof(celula));
    if (novo == NULL)
        exit(EXIT_FAILURE);
    novo->dado = x;
    novo->prox = p->prox;
    p->prox = novo;
}

void insere_antes(celula *p, int x, int y)
{
    celula *novo = malloc(sizeof(celula));
    celula *percor;
    if (novo == NULL)
        exit(EXIT_FAILURE);
    novo->dado = x;
    for (percor = p; percor->prox != NULL && percor->prox->dado != y; percor = percor->prox)
        ;
    novo->prox = percor->prox;
    percor->prox = novo;
}