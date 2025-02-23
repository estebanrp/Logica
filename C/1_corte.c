/*
1)muestre por pantalla la cantidad de alumnos que se reciben este año por
carrera y la cantidad total de alumnos que se reciben en este año en general

2)actualice el archivo historico carreras.dat con la cantidad de alumnos que
se reciven (cantidad_total_graduados)
3)actualce la cantidad de graduados por mes de todas las carreras juntas
(can_graduados)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int mes;
  int legajo;
  char nom_alumno[20];
  float promedio;
  int cod_car; // key
} t_egresado;

typedef struct {
  int mes;
  int can_graduados;
} t_gradmes;

typedef struct {
  int cod_car;
  char nombre_carrera[20];
  int total_graduados;
} t_gradcarreras;

void alum_por_carrera_print();
void actualizar_carreras(int cod_car, int cantidad);
void actualizar_graduados_mes(int mes);

int main() {
  alum_por_carrera_print();
  return 0;
}

void alum_por_carrera_print() {
  FILE *arch = fopen("Termino.txt", "r");
  if (arch == NULL) {
    printf("Error al abrir el archivo Termino.txt\n");
    return;
  }

  t_egresado eg;
  int total = 0;

  fscanf(arch, "%d,%d,%19[^,],%f,%d", &eg.mes, &eg.legajo, eg.nom_alumno, &eg.promedio, &eg.cod_car);

  while (feof(arch) == 0) {
    int carrera_actual = eg.cod_car;
    int contador_carrera = 0;
    while (feof(arch) == 0 && eg.cod_car == carrera_actual) {
	  	actualizar_graduados_mes(eg.mes);
      fscanf(arch, "%d,%d,%19[^,],%f,%d", &eg.mes, &eg.legajo, eg.nom_alumno, &eg.promedio, &eg.cod_car);
      contador_carrera++;
    }
    printf("\nla carrera %i tubo %i egresados", carrera_actual, contador_carrera);
	actualizar_carreras(carrera_actual, contador_carrera);
    total += contador_carrera;
  }

  fclose(arch);
  printf("\nlos egresados totales fueron %i\n", total);
}

void actualizar_carreras(int cod_car, int cantidad) {
  FILE *arch = fopen("carreras.dat", "r+b");
  if (arch == NULL) {
    printf("Error al abrir carreras.dat\n");
    return;
  }

  t_gradcarreras carrera;
  int encontrado = 0;

  while (fread(&carrera, sizeof(t_gradcarreras), 1, arch)) {
    if (carrera.cod_car == cod_car) {
      carrera.total_graduados += cantidad;
      fseek(arch, -sizeof(t_gradcarreras), SEEK_CUR);
      fwrite(&carrera, sizeof(t_gradcarreras), 1, arch);
	  	encontrado = 1;
      break;
    }
  }

	if (!encontrado) {
		carrera.cod_car = cod_car;
		carrera.total_graduados = cantidad;
		strcpy(carrera.nombre_carrera, "unknowed");
		fwrite(&carrera, sizeof(t_gradcarreras), 1, arch);
	}

  fclose(arch);
}

void actualizar_graduados_mes(int mes) {
  FILE *arch = fopen("graduados_mes.dat", "r+b");
  if (arch == NULL) {
    printf("Error al abrir graduados_mes.dat\n");
    return;
  }

  t_gradmes grad_mes;
  int encontrado = 0;

  while (fread(&grad_mes, sizeof(t_gradmes), 1, arch)) {
    if (grad_mes.mes == mes) {
      grad_mes.can_graduados++;
      fseek(arch, -sizeof(t_gradmes), SEEK_CUR);
      fwrite(&grad_mes, sizeof(t_gradmes), 1, arch);
      encontrado = 1;
      break;
    }
  }

  if (!encontrado) {
    grad_mes.mes = mes;
    grad_mes.can_graduados = 1;
    fwrite(&grad_mes, sizeof(t_gradmes), 1, arch);
  }

  fclose(arch);
}
