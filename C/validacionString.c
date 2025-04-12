#include <stdio.h>
#include <string.h>
#include <ctype.h>

void leer_string(const char* mensaje, char* buffer, int max_len) {
    while (1) {
        printf("%s", mensaje);

        if (fgets(buffer, max_len, stdin) == NULL) {
            printf("Error al leer entrada.\n");
            continue;
        }

        // Eliminar el salto de línea final, si está presente
        buffer[strcspn(buffer, "\n")] = '\0';

        // Validación: que no esté vacío
        if (strlen(buffer) == 0) {
            printf("La entrada no puede estar vacía. Intente de nuevo.\n");
            continue;
        }

        //validar que no haya numeros 
        int esSoloLetras = 1;
        for (int i = 0; buffer[i] != '\0'; i++) {
            if (!isalpha(buffer[i]) && buffer[i] != ' ') {
                esSoloLetras = 0; 
            }
        }
    
        if (esSoloLetras == 0) {
            printf("Solo se permiten letras. Intente de nuevo.\n");
            continue;
        }        

        // Si todo está bien, salir del bucle
        break;
    }
}

int main() {
    char nombre[100];
    leer_string("Ingrese su nombre: ", nombre, sizeof(nombre));
    printf("Nombre ingresado: %s\n", nombre);
    return 0;
}
