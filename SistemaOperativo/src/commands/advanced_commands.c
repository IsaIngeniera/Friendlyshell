#include <stdio.h>  // Obligatorio para printf, fopen, fgetc
#include <stdlib.h> // Obligatorio para exit, NULL
#include <ctype.h>  // <--- NUEVA E IMPORTANTE: Para isspace() (detectar espacios)
#include "commands.h" // Para conectar con el resto del sistema#include <ctype.h> // <--- IMPORTANTE: Agrega esto arriba del todo

/**
 * @brief Comando WC (Word Count)
 * Cuenta líneas, palabras y bytes de un archivo.
 */
void cmd_wc(char **args) {
    // 1. Verificar si el usuario puso el nombre del archivo
    if (args[1] == NULL) {
        printf("Uso: wc <archivo>\n");
        return;
    }

    // 2. Intentar abrir el archivo
    FILE *file = fopen(args[1], "r");
    if (file == NULL) {
        perror("Error"); // Muestra el error del sistema (ej: No such file)
        return;
    }

    // 3. Variables para contar
    int lineas = 1;
    int palabras = 0;
    int bytes = 0;
    
    int c;              // Carácter actual
    int en_palabra = 0; // Bandera (0 = fuera de palabra, 1 = dentro)

    // 4. Leer el archivo carácter por carácter
    while ((c = fgetc(file)) != EOF) {
        bytes++; // Cada carácter cuenta como un byte

        // Contar líneas
        if (c == '\n') {
            lineas++;
        }

        // Lógica para contar palabras:
        // Si el carácter actual es un espacio (espacio, tab, enter)...
        if (isspace(c)) {
            en_palabra = 0; // Ya no estamos en una palabra
        } 
        // Si NO es espacio y antes NO estábamos en una palabra...
        else if (en_palabra == 0) {
            en_palabra = 1; // ¡Entramos a una nueva palabra!
            palabras++;
        }
    }

    fclose(file);

    // 5. Mostrar resultados bonitos
    printf("\n");
        printf("  Líneas:   %d\n", lineas);
        printf("  Palabras: %d\n", palabras);
        printf("  Bytes:    %d\n", bytes);
        printf("  Archivo:  %s\n", args[1]);
    printf("\n");
}