#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 5

void p_arr(int *arr);

int b_secuencial(int *arr, int buscado)
{
    int encontrado = -1;
    for (int i = 0; i < MAX; i++)
    {
        if (arr[i] == buscado)
        {
            encontrado = i;
            break;
        }
    }
    return encontrado;
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
    printf("\nIngrese el elemento a buscar: ");
    int elem;
    int flag = 1;
    scanf("%d", &elem);
    int encontrado = b_secuencial(arr, elem);
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
