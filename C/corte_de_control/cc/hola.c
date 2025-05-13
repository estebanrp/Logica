// 1)muestre por pantalla la cantidad de alumnos que se reciben este año por
// carrera y la cantidad total de alumnos que se reciben en este año en general
// 2)actualice el archivo historico carreras.dat con la cantidad de alumnos que
// se reciven (cantidad_total_graduados)
// 3)actualce la cantidad de graduados por mes de todas las carreras juntas
// (can_graduados)

#include <stdio.h>
#include <string.h>

// Estructuras de datos
typedef struct {
    int cod_carrera;
    char nombre_carrera[50];
    int cantidad_total_graduados;
} Carrera;

typedef struct {
    int cod_carrera;
    int mes;
    int anio;
    char nombre_alumno[50];
} Graduado;

// Prototipos de funciones
void mostrar_graduados_por_carrera(FILE *archivo);
void actualizar_historico_carreras(FILE *archivo_graduados, FILE *archivo_carreras);
void actualizar_graduados_mes(FILE *archivo_graduados);

int main() {
    // Abrir archivos
    FILE *archivo_graduados = fopen("graduados.dat", "rb");
    FILE *archivo_carreras = fopen("carreras.dat", "rb+");

    if (!archivo_graduados || !archivo_carreras) {
        printf("Error al abrir archivos\n");
        return 1;
    }

    // Procesar datos
    printf("=== Reporte de graduados ===\n");
    mostrar_graduados_por_carrera(archivo_graduados);

    actualizar_historico_carreras(archivo_graduados, archivo_carreras);
    actualizar_graduados_mes(archivo_graduados);

    // Cerrar archivos
    fclose(archivo_graduados);
    fclose(archivo_carreras);

    return 0;
}

// 1. Mostrar graduados por carrera y total general
void mostrar_graduados_por_carrera(FILE *archivo) {
    rewind(archivo);
    Graduado grad;
    int carrera_actual, contador_carrera = 0, total_general = 0;

    if (fread(&grad, sizeof(Graduado), 1, archivo) != 1) {
        printf("No hay registros de graduados.\n");
        return;
    }

    carrera_actual = grad.cod_carrera;
    contador_carrera = 1;

    while (fread(&grad, sizeof(Graduado), 1, archivo) == 1) {
        if (grad.cod_carrera != carrera_actual) {
            printf("Carrera %d: %d graduados\n", carrera_actual, contador_carrera);
            total_general += contador_carrera;
            carrera_actual = grad.cod_carrera;
            contador_carrera = 1;
        } else {
            contador_carrera++;
        }
    }

    // Última carrera
    printf("Carrera %d: %d graduados\n", carrera_actual, contador_carrera);
    total_general += contador_carrera;
    printf("TOTAL GENERAL: %d graduados\n\n", total_general);
}

// 2. Actualizar archivo histórico de carreras
void actualizar_historico_carreras(FILE *archivo_graduados, FILE *archivo_carreras) {
    rewind(archivo_graduados);
    rewind(archivo_carreras);

    Graduado grad;
    Carrera carrera;
    int carrera_actual, contador = 0;

    if (fread(&grad, sizeof(Graduado), 1, archivo_graduados) != 1) return;

    carrera_actual = grad.cod_carrera;
    contador = 1;

    while (fread(&grad, sizeof(Graduado), 1, archivo_graduados) == 1) {
        if (grad.cod_carrera != carrera_actual) {
            // Buscar y actualizar carrera en histórico
            rewind(archivo_carreras);
            while (fread(&carrera, sizeof(Carrera), 1, archivo_carreras) == 1) {
                if (carrera.cod_carrera == carrera_actual) {
                    carrera.cantidad_total_graduados += contador;
                    fseek(archivo_carreras, -sizeof(Carrera), SEEK_CUR);
                    fwrite(&carrera, sizeof(Carrera), 1, archivo_carreras);
                    break;
                }
            }
            carrera_actual = grad.cod_carrera;
            contador = 1;
        } else {
            contador++;
        }
    }

    // Actualizar última carrera
    rewind(archivo_carreras);
    while (fread(&carrera, sizeof(Carrera), 1, archivo_carreras) == 1) {
        if (carrera.cod_carrera == carrera_actual) {
            carrera.cantidad_total_graduados += contador;
            fseek(archivo_carreras, -sizeof(Carrera), SEEK_CUR);
            fwrite(&carrera, sizeof(Carrera), 1, archivo_carreras);
            break;
        }
    }
}

// 3. Actualizar graduados por mes
void actualizar_graduados_mes(FILE *archivo_graduados) {
    rewind(archivo_graduados);
    Graduado grad;
    int meses[12] = {0}; // Inicializar todos en 0

    while (fread(&grad, sizeof(Graduado), 1, archivo_graduados) == 1) {
        meses[grad.mes - 1]++; // -1 porque enero es mes 1 (índice 0)
    }

    printf("=== Graduados por mes ===\n");
    for (int i = 0; i < 12; i++) {
        printf("Mes %d: %d graduados\n", i + 1, meses[i]);
    }
}