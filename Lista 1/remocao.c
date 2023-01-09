#include <stdio.h>
#include <stdlib.h>

typedef struct celula
{
    int dado;
    struct celula *prox;
} celula;

void remove_depois(celula *p)
{
    if (p->prox != NULL)
    {
        celula *tmp = p->prox;
        p->prox = tmp->prox;
        free(tmp);
    }
}

void remove_elemento(celula *le, int x)
{
    celula *p;
    if (le != NULL)
    {
        if (le->dado == x)
        {
            p = le;
            le = le->prox;
            free(p);
        }
        else
        {
            for (p = le; p->prox != NULL && p->prox->dado != x; p = p->prox)
                ;
            if (p->prox != NULL)
            {
                celula *tmp = p->prox;
                p->prox = tmp->prox;
                free(tmp);
            }
        }
    }
}

void remove_todos_elementos(celula *le, int x)
{
    celula *p = le;
    while (p->prox != NULL)
    {
        if (p->prox->dado == x)
        {
            celula *tmp;
            tmp = p->prox;
            p->prox = tmp->prox;
            free(tmp);
        }
        else
        {
            p = p->prox;
        }
    }
}