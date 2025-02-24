/*Escriba una función que reciba dos arreglos de n elementos, Legajo (n) y
 * Calificación (n), retorna los arreglos ordenados en forma ascendente
 * conservando la relación, y muestra por pantalla el listado ordenado.
 */

#include <stdio.h>
#define LONG 5

void ordenar_enlazados(int legajo[], int nota[]);

int main() {
  int legajos[LONG] = {564, 1545, 685, 1236, 301};
  int notas[LONG] = {4, 10, 9, 5, 7};

  printf("\nlegajos: {");
  for (int i = 0; i < LONG - 1; i++) {
    printf("%d, ", legajos[i]);
  }
  printf("%d}", legajos[LONG - 1]);

  printf("\n  notas: {");
  for (int i = 0; i < LONG - 1; i++) {
    printf("%d, ", notas[i]);
  }
  printf("%d}", notas[LONG - 1]);

  ordenar_enlazados(legajos, notas);
  printf("\n----- Ordenando ----\n");

  printf("legajos: {");
  for (int i = 0; i < LONG - 1; i++) {
    printf("%d, ", legajos[i]);
  }
  printf("%d}", legajos[LONG - 1]);

  printf("\n  notas: {");
  for (int i = 0; i < LONG - 1; i++) {
    printf("%d, ", notas[i]);
  }
  printf("%d}\n", notas[LONG - 1]);

  return 0;
}

void ordenar_enlazados(int legajo[], int nota[]) {
  int aux;
  for (int i = 0; i < LONG - 1; i++) {
    for (int j = 0; j < LONG - 1 - i; j++) {
      if (legajo[j] > legajo[j + 1]) {
        aux = legajo[j];
        legajo[j] = legajo[j + 1];
        legajo[j + 1] = aux;
        aux = nota[j];
        nota[j] = nota[j + 1];
        nota[j + 1] = aux;
      }
    }
  }
}