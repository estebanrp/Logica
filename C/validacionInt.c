#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int leer_entero(const char* mensaje) {
    char buffer[100];
    char* endptr;
    int numero;

    while (1) {
        printf("%s", mensaje);

        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            printf("Error al leer entrada.\n");
            continue;
        }
        
        buffer[strcspn(buffer, "\n")] = 0;
        numero = (int)strtol(buffer, &endptr, 10);

        if (endptr != buffer && *endptr == '\0') {
            return numero;
        }

        printf("Entrada inválida. Intente de nuevo.\n");
    }
}

int main(){
    int numero = leer_entero("que ejercicio desea usar [2-6]: ");
}