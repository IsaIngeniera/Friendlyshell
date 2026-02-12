/**
 * @file shell_loop.c
 * @brief Corazón operativo de la shell (Lógica de control).
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"
#include "commands.h"

/* ===== Registro de Comandos ===== */

char *nombres_comandos[] = {
    "menu",
    "listar",
    "leer",
    "tiempo",
    "calc",
    "ayuda",
    "limpiar",
    "salir",
    "crear",
    "renombrar",
    "eliminar",
    "userinfo"
};

void (*func_comandos[]) (char **) = {
    &cmd_menu,
    &cmd_listar,
    &cmd_leer,
    &cmd_tiempo,
    &cmd_calc,
    &cmd_ayuda,
    &cmd_limpiar,
    &cmd_salir,
    &cmd_crear,
    &cmd_renombrar,
    &cmd_eliminar,
    &cmd_userinfo,
};

int num_comandos() {
    return sizeof(nombres_comandos) / sizeof(char *);
}

/* ===== Ejecutor de comandos ===== */

void ejecutar(char **args) {
    if (args[0] == NULL) {
        return;
    }

    for (int i = 0; i < num_comandos(); i++) {
        if (strcmp(args[0], nombres_comandos[i]) == 0) {
            (*func_comandos[i])(args);
            return;
        }
    }

    printf("Comando desconocido: %s\nEscribe 'ayuda' para ver los comandos.\n", args[0]);
}

/* ===== Loop principal ===== */

void loop_shell() {
    char *linea;
    char **args;

    while (1) {
        printf("EAFITos> ");

        // 1. Leer
        linea = leer_linea();

        // 2. Parsear
        args = parsear_linea(linea);

        // 3. Ejecutar
        ejecutar(args);

        if (args[0] != NULL) {
            if (strcmp(args[0], "menu") != 0 &&
                strcmp(args[0], "salir") != 0 &&
                strcmp(args[0], "limpiar") != 0) {

                printf("\n[Presiona ENTER para continuar...]");
                getchar();
                printf("\n");
                cmd_menu(NULL);
                printf("\n");
            }
        }

        // 4. Liberar memoria
        free(linea);
        free(args);
    }
}
