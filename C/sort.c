#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 20

void burbuja(int arr[])
{
    int swapped; // Bandera para detectar intercambios
    for (int i = 0; i < MAX - 1; i++)
    {
        swapped = 0;
        for (int j = 0; j < MAX - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                swapped = 1; // Hubo un intercambio
            }
        }
        if (swapped == 0)
            break; // Si no hubo intercambios, el arreglo ya está ordenado
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
            }
            else
            {
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