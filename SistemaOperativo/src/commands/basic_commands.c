/**
 * @file basic_commands.c
 * @brief Implementación de comandos básicos del sistema.
 */

#include <stdio.h>  // printf
#include <stdlib.h> // exit, malloc
#include <time.h>   // time, localtime, strftime
#include "commands.h"

/**
 * @brief Comando MENU PRINCIPAL
 * 
 * Muestra al usuario la lista básica de comandos disponibles.
 * Versión simplificada para navegación rápida.
 * 
 * @param args Argumentos del comando (no se usan aquí, por eso (void)args).
 */
void cmd_menu(char **args) {
    printf("╔════════════════════════════════════════╗\n");
    printf("║     MENÚ PRINCIPAL - Shell Educativa   ║\n");
    printf("╚════════════════════════════════════════╝\n");
    printf("  Comandos disponibles:\n");
    printf("  • listar    - Mostrar archivos\n");
    printf("  • leer      - Ver contenido de archivo\n");
    printf("  • tiempo    - Fecha y hora actual\n");
    printf("  • calc      - Calculadora simple\n");
    printf("  • limpiar   - Limpiar la pantalla\n");
    printf("  • ayuda     - Ayuda detallada de comandos\n");
    printf("  • crear     - Crear archivo vacío\n");
    printf("  • renombrar - Renombrar archivo existente\n");
    printf("  • eliminar  - Elimina archivo con confirmación.\n");
    printf("  • userinfo  - Muestra información del usuario.\n");
    printf("  • menu      - Mostrar este menú\n");
    printf("  • salir     - Terminar sesión\n");
    printf("════════════════════════════════════════\n");
    
    (void)args;
}

/**
 * @brief Comando AYUDA
 * 
 * Muestra documentación detallada de todos los comandos:
 * nombre completo, descripción de función y sintaxis de uso.
 * 
 * @param args Argumentos del comando (no se usan aquí).
 */
void cmd_ayuda(char **args) {
    printf("╔═════════════════════════════════════════════════════════════╗\n");
    printf("║              AYUDA DETALLADA - Shell Educativa              ║\n");
    printf("╚═════════════════════════════════════════════════════════════╝\n");
    
    printf("┌─ LISTAR ────────────────────────────────────────────────────┐\n");
    printf("│ Nombre completo: List Directory (listar directorio)         │\n");
    printf("│ Función: Muestra todos los archivos y carpetas del          │\n");
    printf("│          directorio actual                                  │\n");
    printf("│ Atajo: listar                                               │\n");
    printf("└─────────────────────────────────────────────────────────────┘\n\n");
    
    printf("┌─ LEER ──────────────────────────────────────────────────────┐\n");
    printf("│ Nombre completo: Read File (leer archivo)                   │\n");
    printf("│ Función: Muestra el contenido completo de un archivo        │\n");
    printf("│          de texto                                           │\n");
    printf("│ Sintaxis: leer <nombre_archivo>                             │\n");
    printf("│ Atajo: leer                                                 │\n");
    printf("│ Ejemplo: leer documento.txt                                 │\n");
    printf("└─────────────────────────────────────────────────────────────┘\n\n");
    
    printf("┌─ TIEMPO ────────────────────────────────────────────────────┐\n");
    printf("│ Nombre completo: Date/Time (fecha y hora)                   │\n");
    printf("│ Función: Muestra la fecha y hora actual del sistema         │\n");
    printf("│ Sintaxis: tiempo                                            │\n");
    printf("│ Atajo: tiempo                                               │\n");
    printf("└─────────────────────────────────────────────────────────────┘\n\n");
    
    printf("┌─ CALC ──────────────────────────────────────────────────────┐\n");
    printf("│ Nombre completo: Calculator (calculadora)                   │\n");
    printf("│ Función: Realiza operaciones matemáticas básicas            │\n");
    printf("│          (suma, resta, multiplicación, división)            │\n");
    printf("│ Sintaxis: calc <número1> <operador> <número2>               │\n");
    printf("│ Atajo: calc                                                 │\n");
    printf("│ Operadores: + (suma), - (resta), * (multiplicación),        │\n");
    printf("│             / (división)                                    │\n");
    printf("│ Ejemplo: calc 15 + 7                                        │\n");
    printf("└─────────────────────────────────────────────────────────────┘\n\n");
    
    printf("┌─ LIMPIAR ───────────────────────────────────────────────────┐\n");
    printf("│ Nombre completo: Clear Screen (limpiar pantalla)            │\n");
    printf("│ Función: Limpia completamente la pantalla del terminal      │\n");
    printf("│ Sintaxis: limpiar                                           │\n");
    printf("│ Atajos: limpiar, clear                                      │\n");
    printf("└─────────────────────────────────────────────────────────────┘\n\n");
    
    printf("┌─ AYUDA ─────────────────────────────────────────────────────┐\n");
    printf("│ Nombre completo: Help (ayuda)                               │\n");
    printf("│ Función: Muestra esta ayuda detallada con información       │\n");
    printf("│          completa de todos los comandos                     │\n");
    printf("│ Atajo: ayuda                                                │\n");
    printf("└─────────────────────────────────────────────────────────────┘\n\n");
    
    printf("┌─ MENU ──────────────────────────────────────────────────────┐\n");
    printf("│ Nombre completo: Main Menu (menú principal)                 │\n");
    printf("│ Función: Muestra el menú principal con lista resumida       │\n");
    printf("│          de comandos disponibles                            │\n");
    printf("│ Atajo: menu                                                 │\n");
    printf("└─────────────────────────────────────────────────────────────┘\n\n");
    
    printf("┌─ CREAR ─────────────────────────────────────────────────────┐\n");
    printf("│ Nombre completo: Create File (crear archivo)                │\n");
    printf("│ Función: Crea un nuevo archivo de texto vacío.              │\n");
    printf("│          Si existe, borra su contenido (sobrescribe).       │\n");
    printf("│ Sintaxis: crear <nombre_archivo>                            │\n");
    printf("│ Ejemplo: crear notas.txt                                    │\n");
    printf("└─────────────────────────────────────────────────────────────┘\n\n");

    printf("┌─ RENOMBRAR ─────────────────────────────────────────────────┐\n");
    printf("│ Nombre completo: Rename File (renombrar archivo)            │\n");
    printf("│ Función: Cambia el nombre de un archivo existente.          │\n");
    printf("│ Sintaxis: renombrar <nombre_actual> <nuevo_nombre>          │\n");
    printf("│ Ejemplo: renombrar viejo.txt nuevo.txt                      │\n");
    printf("└─────────────────────────────────────────────────────────────┘\n\n");

    
    
    printf("┌─ SALIR ─────────────────────────────────────────────────────┐\n");
    printf("│ Nombre completo: Exit (salir)                               │\n");
    printf("│ Función: Cierra la shell y finaliza la sesión               │\n");
    printf("│ Atajo: salir                                                │\n");
    printf("└─────────────────────────────────────────────────────────────┘\n\n");
    
    (void)args;
}

/**
 * @brief Comando SALIR
 * 
 * Finaliza la ejecución del programa de forma controlada.
 * Utiliza la llamada al sistema exit().
 * 
 * @param args Argumentos del comando (ignorados).
 */
void cmd_salir(char **args) {
    printf("Saliendo de la shell...\n");
    // exit(0) devuelve el código 0 al sistema operativo padre,
    // indicando que el proceso terminó sin errores.
    exit(0);
    (void)args;
}

/**
 * @brief Comando TIEMPO (date)
 * 
 * Obtiene y formatea la fecha y hora del sistema.
 * Demuestra el uso de la librería estándar <time.h>.
 * 
 * @param args Argumentos del comando (ignorados).
 */
void cmd_tiempo(char **args) {
    // 1. Obtener tiempo "crudo" (segundos desde 1970 - Epoch Unix)
    time_t t = time(NULL);
    
    // 2. Convertir a una estructura estructurada local (struct tm)
    // localtime devuelve un puntero, así que desreferenciamos con *
    struct tm tm = *localtime(&t);
    
    // 3. Imprimir con formato
    // tm_year cuenta desde 1900, por eso sumamos 1900.
    // tm_mon es 0-11, por eso sumamos 1.
    printf("Fecha y Hora del Sistema: %02d-%02d-%04d %02d:%02d:%02d\n",
           tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900,
           tm.tm_hour, tm.tm_min, tm.tm_sec);
           
    (void)args;
}