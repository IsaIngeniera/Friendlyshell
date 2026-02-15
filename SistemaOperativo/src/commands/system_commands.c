/**
 * @file system_commands.c
 * @brief Comandos de utilería del sistema.
 * 
 * Actualmente contiene la calculadora, pero podría expandirse para incluir
 * gestión de procesos o informes de memoria.
 */

#include <stdio.h>
#include <stdlib.h> // Para atof (ASCII to Float conversion)
#include "commands.h"
#include <unistd.h> // Para getcwd (Obtener directorio actual)
#include <pwd.h>    // (Para struct passwd y getpwuid)
#include <grp.h>    // (Para struct group y getgrgid)


/**
 * @brief Comando CALC (Calculadora)
 * 
 * Realiza operaciones aritméticas básicas entre dos números.
 * Sintaxis esperada: calc <num1> <operador> <num2>
 * 
 * @param args Lista de argumentos donde:
 *             args[1]: Primer operando (cadena)
 *             args[2]: Operador (+, -, *, /)
 *             args[3]: Segundo operando (cadena)
 */
void cmd_calc(char **args) {
    // 1. Validación de argumentos. Necesitamos exáctamente 3 partes después del comando.
    if (args[1] == NULL || args[2] == NULL || args[3] == NULL) {
        printf("Uso: calc <num1> <operador> <num2>\nEjemplo: calc 5 + 3\n");
        return;
    }

    // 2. Conversión de tipos (Parsing)
    // atof(): Convierte una cadena numérica a un float (double precision).
    float n1 = atof(args[1]);
    char op = args[2][0]; // Tomamos el primer caracter del argumento operador
    float n2 = atof(args[3]);
    float res = 0;

    // 3. Lógica de selección (Switch)
    switch(op) {
        case '+': 
            res = n1 + n2; 
            break;
        case '-': 
            res = n1 - n2; 
            break;
        case '*': 
        case 'x': // Permitimos 'x' como alias de multiplicación
            res = n1 * n2; 
            break;
        case '/': 
            // Manejo de caso borde: División por cero
            if (n2 == 0) {
                printf("Error: División por cero no permitida.\n");
                return;
            }
            res = n1 / n2; 
            break;
        default:
            printf("Error: Operador '%c' no reconocido. Use +, -, * o /.\n", op);
            return;
    }

    // 4. Salida
    // %.2f formatea el float para mostrar solo 2 decimales.
    printf("Resultado: %.2f\n", res);
}

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
printf("\033[H\033[2J\033[3J");
    (void)args; // Evitamos warning de variable no usada
}

/**
 * @brief Comando DIRECTORIO (pwd)
 * Muestra la ruta absoluta del directorio actual de trabajo.
 */

void cmd_directorio(char **args) {
    char cwd[1024]; // Buffer para almacenar la ruta
    
    // getcwd llena el buffer 'cwd' con la ruta actual
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("Directorio actual: %s\n", cwd);
    } else {
        perror("Error al obtener el directorio actual");
    }
    (void)args; // Evitar advertencia de variable no usada
}


/**
 * @brief Comando USERINFO 
 * Muestra la informacion del usuario.
 */
 
 void cmd_userinfo(char **args) {
    uid_t uid = geteuid();
    struct passwd *pw = getpwuid(uid);

    if (pw) {
        // Obtenemos el nombre del grupo a partir del ID
        struct group *gr = getgrgid(pw->pw_gid);
        char *group_name = (gr) ? gr->gr_name : "Desconocido";
        
        printf(" \n");
        printf("  ** INFO DEL USUARIO (FriendlyShell)  ** \n");
        printf(" \n");
        printf("Nombre de usuario:    %s\n", pw->pw_name);
        // pw_gecos suele guardar el nombre completo y a veces info extra separada por comas
        printf("Nombre completo:      %s\n", pw->pw_gecos); 
        printf("----------------------------------------\n");
        printf("User ID (UID):        %d\n", pw->pw_uid);
        printf("Group ID (GID):       %d (%s)\n", pw->pw_gid, group_name);
        printf("----------------------------------------\n");
        printf("Directorio Home:      %s\n", pw->pw_dir);
        printf("Shell por defecto:    %s\n", pw->pw_shell);

    } else {
        perror("Error al obtener información del usuario");
    }
    (void)args;
}
