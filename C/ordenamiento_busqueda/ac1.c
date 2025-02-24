/*Realizar un programa que permita, a través de una función ordenar un arreglo
 * de LONG elementos. Esta función recibirá dos parámetros : el primero indicará
 * arreglo a ordenar, y el segundo indicará si el orden será “A” - Ascendente
 * (de menor a mayor) o “D” Descendente (de mayor a menor)
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LONG 20

void ordenar(int arr[], char orden);

int main() {
  int arr[LONG];
  srand(time(NULL));
  for (int i = 0; i < LONG; i++) {
    arr[i] = rand() % 101;
  }

  char orden;
  printf("\ningrese el orden (A) o (D): ");
  scanf("%c", &orden);

  printf("\n array sin ordenar:\n|");
  for (int i =0; i< LONG; i++) {
    printf("%i|", arr[i]);
  }

  ordenar(arr, orden);

  printf("\n array ordenado:\n|");
  for (int i =0; i< LONG; i++) {
    printf("%i|", arr[i]);
  }

  return 0;
}

void ordenar(int arr[], char orden) {
  int aux;
  if (orden == 'A') {
    for (int i = 0; i < LONG; i++) {
      for (int j = 0; j < LONG - i - 1; j++) {
        if (arr[j] > arr[j + 1]) {
          aux = arr[j];
          arr[j] = arr[j + 1];
          arr[j + 1] = aux;
        }
      }
    }
  } else if (orden == 'D') {
    for (int i = 0; i < LONG; i++) {
        for (int j = 0; j < LONG - i - 1; j++) {
            if (arr[j] < arr[j+1]){
                aux = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = aux;
            }
        }
    }
  } else {
    printf("el orden debe ser 'A' o 'D'");
  }
}