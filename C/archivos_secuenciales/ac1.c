#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARCHIVO "encuesta.txt"
#define MAX_PERSONAS 100 // Ajusta el tamaño según la cantidad de encuestados

typedef struct {
    int sexo;
    int edad;
    int civil;
    int trabaja;
    int estudia;
} t_persona;

void generarArchivo();
void generarReporte();

int main() {
    generarArchivo();
    generarReporte();
    return 0;
}

void generarArchivo() {
    srand(time(NULL));
    FILE *arch = fopen(ARCHIVO, "w");
    if (!arch) {
        perror("Error al abrir el archivo");
        exit(1);
    }

    for (int i = 0; i < MAX_PERSONAS; i++) {
        t_persona persona;
        persona.sexo = (rand() % 2) + 1;
        persona.edad = (rand() % 126); // 0 - 125
        persona.civil = (rand() % 3) + 1;
        persona.trabaja = rand() % 2;
        persona.estudia = rand() % 2;

        fprintf(arch, "%d,%d,%d,%d,%d\n", persona.sexo, persona.edad, persona.civil, persona.trabaja, persona.estudia);
    }

    fclose(arch);
    printf("Archivo generado exitosamente.\n");
}

void generarReporte() {
    FILE *arch = fopen(ARCHIVO, "r");
    if (!arch) {
        perror("Error al abrir el archivo");
        exit(1);
    }

    int total = 0, hombres = 0, mujeres = 0, menores_trabajan = 0;
    int solteros = 0, casados = 0, trabajan_estudian = 0, mujeres_trabajan = 0;
    t_persona persona;

    while (fscanf(arch, "%d,%d,%d,%d,%d", &persona.sexo, &persona.edad, &persona.civil, &persona.trabaja, &persona.estudia) == 5) {
        total++;

        if (persona.sexo == 1) hombres++;
        if (persona.sexo == 2) mujeres++;
        if (persona.edad < 18 && persona.trabaja == 1) menores_trabajan++;
        if (persona.civil == 1) solteros++;
        if (persona.civil == 2) casados++;
        if (persona.trabaja == 1 && persona.estudia == 1) trabajan_estudian++;
        if (persona.sexo == 2 && persona.trabaja == 1) mujeres_trabajan++;
    }

    fclose(arch);

    if (total == 0) {
        printf("No hay datos en el archivo.\n");
        return;
    }

    printf("\n===== PORCENTAJES =====\n");
    printf("• Varones: %.2f%%\n", (hombres * 100.0) / total);
    printf("• Mujeres: %.2f%%\n", (mujeres * 100.0) / total);
    printf("• Menores de 18 años que trabajan: %.2f%%\n", (menores_trabajan * 100.0) / total);
    printf("• Solteros: %.2f%%\n", (solteros * 100.0) / total);
    printf("• Casados: %.2f%%\n", (casados * 100.0) / total);
    printf("• Encuestados que trabajan y estudian: %.2f%%\n", (trabajan_estudian * 100.0) / total);
    printf("• Mujeres que trabajan: %.2f%%\n", (mujeres_trabajan * 100.0) / total);
}
