#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int leer_entero(const char* mensaje, int min, int max) {
    char buffer[100];
    char* endptr;
    int numero;

    while (1) {
        // impreime el mensaje de la funcino
        printf("%s", mensaje);
        // copia en buffer la entrada del teclado (stdin) con le tamanio "sizepf(buffer)"
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            printf("Error al leer entrada.\n");
            continue;
        }
        // Eliminar el salto de línea. 
        // strcspn: Cuenta caracteres de (str1 -> buffer) hasta encontrar cualquier carácter de (str2 -> "\n")
        // strcspn devuelve el indice en donde se encuentra "\n"
        // entonces reemplaza el salto ed line con fin de string "\0"
        buffer[strcspn(buffer, "\n")] = 0;

        // Convertir a entero. strol prototipo -> long int strtol(const char *nptr, char **endptr, int base).
        // str to long convierte buffer en long y lo guarda en la var numero. 
        // Luego guarda un puntero a el primer caracter no numerico
        numero = (int)strtol(buffer, &endptr, 10);

        // Verificar si la conversión fue válida y está en el rango
        // si endptr == buffer significa que el primer caracter fue no numerico (puede ser entrada vacio)
        // si *endptr == '\0' asegura que todo fue convertido hasta el enter del usuario 
        // (no hay cosas raras que hayan roto la conversion antes de tiempo ej: "30 fa", "40xx", etc).
        if (endptr != buffer && *endptr == '\0') {
            // verifica el rango
            if (numero >= min && numero <= max) {
                return numero;
            } else {
                printf("Número fuera de rango [%d - %d].\n", min, max);
            }
        } else {
            printf("Entrada inválida. Ingrese un número entero.\n");
        }
    }
}


int main(){
    int numero = leer_entero("que ejercicio desea usar [2-6]: ", 2, 6);
}