/*Escribir una función que reciba un arreglo ordenado y un elemento x. Si el
 * elemento x se encuentra en el arreglo, debe encontrar su posición mediante
 * búsqueda binaria y devolver la posición. Si no se encuentra, debe agregar x
 * al vector en la posición correcta y devolver esa nueva posición.
 */

#include <stdio.h>

int busqueda_o_insert(int arr[], int *n, int objetivo);

int main() {
  int arr[20] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
  int n = 10; // Número actual de elementos en el array
  int objetivo;

  printf("ingrese el numero a buscar: ");
  scanf("%d", &objetivo);

  printf("Arreglo: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  int resultado = busqueda_o_insert(arr, &n, objetivo);
  printf("Elemento ubicado en la posición %d\n", resultado);

  printf("Nuevo arreglo: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}

int busqueda_o_insert(int arr[], int *n, int objetivo) {
  int izquierda = 0, derecha = *n - 1;
  while (izquierda <= derecha) {
    int medio = izquierda + (derecha - izquierda) / 2;

    if (arr[medio] == objetivo)
      return medio;

    if (arr[medio] < objetivo)
      izquierda = medio + 1;
    else
      derecha = medio - 1;
  }

  // Insertar el elemento si no se encuentra
  for (int i = *n; i > izquierda; i--) {
    arr[i] = arr[i - 1];
  }
  arr[izquierda] = objetivo;
  (*n)++;

  return izquierda;
}