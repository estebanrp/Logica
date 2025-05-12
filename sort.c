#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 20

void burbuja(int arr[])
{
    int aux;
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                aux = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = aux;
            }
        }
    }
}

void seleccion(int arr[])
{
    int min;
    int aux;
    for (int j = 0; j < MAX; j++)
    {
        min = j;
        for (int i = j + 1; i < MAX; i++)
        {
            if (arr[i] < arr[min])
            {
                min = i;
            }
        }
        aux = arr[j];
        arr[j] = arr[min];
        arr[min] = aux;
    }
}

void insercion(int arr[])
{
    int elem, aux;
    for (int i = 1; i < MAX; i++)
    {
        elem = arr[i];
        for (int j = i; j > 0; j--)
        {
            if (arr[j] < arr[j - 1])
            {
                aux = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = aux;
            } else {
                break;
            }
        }
    }
}

int main()
{
    srand(time(NULL));
    int arr[MAX];
    for (int i = 0; i < MAX; i++)
    {
        arr[i] = rand() % 100;
    }
    printf("Arregle original:");
    for (int j = 0; j < MAX; j++)
    {
        printf("\n%d", arr[j]);
    }
    printf("\nArreglo ordenado");
    // burbuja(arr);
    // printf("\n--> burbuja");
    // seleccion(arr);
    // printf("\n--> seleccion");
    insercion(arr);
    printf("\n--> insercion");
    for (int j = 0; j < MAX; j++)
    {
        printf("\n%d", arr[j]);
    }
    printf("\n");
    return 0;
}