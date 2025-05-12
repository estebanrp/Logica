#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 5

void p_arr(int *arr);
void burbuja(int *arr);

int b_binaria(int *arr, int buscado) {
    int inf = 0;
    int sup = MAX - 1;

    while (inf <= sup) {  // Usamos <= para incluir el caso inf == sup.
        int med = (inf + sup) / 2;  // Siempre calculamos med aquí.

        if (buscado == arr[med]) {
            return med;  // Elemento encontrado.
        } else if (buscado > arr[med]) {
            inf = med + 1;  // Buscamos en la mitad superior.
        } else {
            sup = med - 1;  // Buscamos en la mitad inferior.
        }
    }

    return -1;  // Elemento no encontrado.
}

int main()
{
    srand(time(NULL));
    int arr[MAX];
    for (int i = 0; i < MAX; i++)
    {
        arr[i] = 1 + rand() % 100;
    }
    printf("Arreglo original");
    p_arr(arr);
    printf("\nArreglo ordenado");
    burbuja(arr);
    p_arr(arr);
    int elem;
    printf("\nIngrese el elemento a buscar: ");
    scanf("%d", &elem);
    int encontrado = b_binaria(arr, elem);
    if (encontrado != -1)
    {
        printf("el elemento %d se encuentra en la posicion %d\n", arr[encontrado], encontrado);
    }
    else
    {
        printf("el elemento no fue encontrado\n");
    }
    return 0;
}

void p_arr(int *arr)
{
    printf("[");
    for (int i = 0; i < MAX - 1; i++)
    {
        printf("%d, ", arr[i]);
    }
    printf("%d]", arr[MAX - 1]);
}

void burbuja(int *arr)
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
