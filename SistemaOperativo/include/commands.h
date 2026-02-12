/**
 * @file commands.h
 * @brief Interfaz para los comandos del sistema.
 * 
 * Define las funciones que implementan la lógica de cada comando disponible
 * en la shell. Todas siguen la firma `void cmd_nombre(char **args)`.
 */

#ifndef COMMANDS_H
#define COMMANDS_H

// ======================================================
// === Comandos Básicos de la Shell =====================
// ======================================================

/**
 * @brief Muestra el menú principal con los comandos disponibles.
 */
void cmd_menu(char **args);

/**
 * @brief Muestra la lista de ayuda detallada.
 */
void cmd_ayuda(char **args);

/**
 * @brief Termina la ejecución de la shell.
 */
void cmd_salir(char **args);

/**
 * @brief Muestra la fecha y hora del sistema.
 */
void cmd_tiempo(char **args);

// ======================================================
// === Comandos de Archivos =============================
// ======================================================

/**
 * @brief Lista los archivos del directorio actual.
 */
void cmd_listar(char **args);

/**
 * @brief Lee y muestra el contenido de un archivo.
 */
void cmd_leer(char **args);

// ======================================================
// === Otros Comandos ===================================
// ======================================================

/**
 * @brief Realiza operaciones matemáticas simples.
 */
void cmd_calc(char **args);

// ======================================================
// === Comandos Avanzados ===============================
// ======================================================

/**
 * @brief Limpia la pantalla del terminal.
 */
void cmd_limpiar(char **args);

// ======================================================
// === Utilidades del Registro de Comandos ==============
// ======================================================

/**
 * @brief Retorna el número total de comandos registrados.
 * @return int Cantidad de comandos.
 */
int num_comandos();

void cmd_crear(char **args);

void cmd_renombrar(char **args);

#endif /* COMMANDS_H */