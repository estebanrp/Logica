#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    int valor;
    struct nodo *izq;
    struct nodo *dcho;
    struct nodo *padre;
} Nodo;

typedef Nodo Arbol;

Nodo *crear_nodo(int valor)
{
    Nodo *nuevo_nodo = (Nodo *)malloc(sizeof(Nodo));
    nuevo_nodo->valor = valor;
    nuevo_nodo->dcho = nuevo_nodo->izq = NULL;
    return nuevo_nodo;
}

void destruir_nodo(Nodo *nodo)
{
    if (nodo->izq == NULL && nodo->dcho == NULL)
    {
        if (nodo->padre->valor > nodo->valor)
        {
            nodo->padre->izq == NULL;
        }
        else
        {
            nodo->padre->dcho == NULL;
        }
        free(nodo);
    }
    else if (nodo->izq != NULL && nodo->dcho != NULL)
    {
    }
    else
    {
        if (nodo->izq != NULL)
        {
            nodo->padre->izq = nodo->izq;
            free(nodo);
        }
        else
        {
            nodo->padre->dcho = nodo->dcho;
            free(nodo);
        }
    }
}
