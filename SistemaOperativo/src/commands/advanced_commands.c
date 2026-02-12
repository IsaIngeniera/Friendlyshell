/**
 * @file advanced_commands.c
 * @brief Implementación de comandos avanzados del sistema.
 */

#include <stdio.h>
#include <stdlib.h>
#include "commands.h"

/**
 * @brief Comando LIMPIAR
 *
 * Limpia la pantalla del terminal usando el comando
 * propio del sistema operativo y muestra el mensaje inicial.
 *
 * - Linux / WSL / macOS → clear
 * - Windows → cls
 */
void cmd_limpiar(char **args) {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif

    printf("Iniciando EAFITos v1.0...\n");
    printf("Escribe 'menu' para comenzar.\n\n");

    (void)args; // Evita warning de parámetro no usado
}
