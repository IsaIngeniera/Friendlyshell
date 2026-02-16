# 🔌 API Reference — EAFITos Shell

**Proyecto Académico — Sistemas Operativos**  
**Universidad EAFIT**  
**Versión:** 1.0  
**Año:** 2026  

---

## 📌 1. Propósito del Documento

Este documento define la interfaz interna (API) de la shell educativa **FriendlyShell**, desarrollada en lenguaje C como proyecto académico en la asignatura de Sistemas Operativos de la Universidad EAFIT.

Está dirigido exclusivamente a desarrolladores y mantenedores del sistema que necesiten:

- Comprender la arquitectura interna
- Extender el sistema con nuevos comandos
- Mantener o refactorizar el código
- Generar documentación automática
- Analizar el diseño modular
- Entender el flujo interno de ejecución

> ⚠ **Este documento NO está orientado a usuarios finales.**

---

## 🏗 2. Arquitectura del Sistema

EAFITos implementa una **arquitectura modular**, organizada por capas funcionales con separación clara de responsabilidades.

### 2.1 Principios de Diseño

La arquitectura se basa en los siguientes principios:

- ✔ Modularidad
- ✔ Bajo acoplamiento
- ✔ Alta cohesión
- ✔ Firma estándar para comandos
- ✔ Separación entre parsing y ejecución
- ✔ Escalabilidad
- ✔ Claridad estructural
- ✔ Organización por responsabilidad funcional

---

## 📁 3. Estructura del Proyecto

```
eafitos/
├── src/
│   ├── core/                    # Núcleo del shell
│   │   ├── main.c              # Punto de entrada
│   │   ├── shell_loop.c        # Bucle REPL
│   │   └── parser.c            # Parseo de comandos
│   ├── commands/               # Comandos por categoría
│   │   ├── basic_commands.c    # 6 comandos básicos
│   │   ├── file_commands.c     # Comandos de archivos
│   │   ├── system_commands.c   # Comandos del sistema
│   │   └── advanced_commands.c # Comandos avanzados
│   └── utils/                  # Utilidades
│       ├── memory_manager.c    # Gestión de memoria
│       ├── error_handler.c     # Manejo de errores
│       └── helpers.c           # Funciones auxiliares
├── include/                    # Headers
│   ├── shell.h
│   ├── commands.h
│   ├── parser.h
│   └── utils.h
├── tests/                      # Pruebas
│   ├── unit_tests.c
│   ├── integration_tests.c
│   └── test_runner.sh
├── docs/                       # Documentación
│   ├── API.md
│   ├── DESIGN.md
│   └── USER_GUIDE.md
├── scripts/                    # Scripts auxiliares
│   ├── build.sh
│   └── format.sh
├── Makefile                    # Build system
├── README.md                   # Documentación principal
├── CONTRIBUTORS.md            # Colaboradores y roles
├── CHANGELOG.md               # Historial de cambios
└── LICENSE                    # Licencia del proyecto
```

---

## 🔄 4. Flujo de Ejecución Interno

```
main()
   ↓
shell_loop()
   ↓
parse_input()
   ↓
execute_command()
   ↓
cmd_xxx()
```

### 4.1 Descripción del Flujo

#### 🔹 `main()`

Responsable de:

- Inicializar el entorno del programa
- Mostrar mensaje de bienvenida
- Invocar `shell_loop()`
- Finalizar ejecución

#### 🔹 `shell_loop()`

Responsable de:

- Mostrar el prompt interactivo
- Leer la entrada del usuario
- Invocar `parse_input()`
- Invocar `execute_command()`
- Repetir el ciclo hasta ejecutar `salir`

#### 🔹 `parse_input()`

Responsable de:

- Tokenizar la cadena ingresada
- Separar por espacios
- Llenar el arreglo `argv`
- Retornar `argc`

#### 🔹 `execute_command()`

Responsable de:

- Evaluar `argv[0]`
- Comparar usando `strcmp`
- Llamar al comando correspondiente
- Manejar comandos inválidos

---

## 🧠 5. Documentación de Módulos

### 5.1 `main.c`

**Firma**

```c
int main(void);
```

**Responsabilidades**

- Mostrar mensaje inicial
- Configurar entorno base
- Invocar el loop principal

---

### 5.2 `shell.c`

**Firma**

```c
void shell_loop(void);
```

**Responsabilidades**

- Control del ciclo interactivo
- Gestión de entrada estándar
- Manejo de condición de salida

---

### 5.3 `parser.c`

**Firma**

```c
int parse_input(char *input, char **args);
```

**Parámetros**

| Parámetro | Descripción |
|-----------|-------------|
| `input`   | Cadena original ingresada |
| `args`    | Arreglo de argumentos |

**Retorno**

Número de argumentos detectados (`argc`)

**Limitaciones**

- No maneja comillas
- No soporta redirecciones (`>`, `<`)
- No soporta pipes (`|`)
- No permite múltiples comandos en una línea
- No procesa variables de entorno

---

### 5.4 `dispatcher.c`

**Firma**

```c
void execute_command(int argc, char **argv);
```

**Función**

- Comparación mediante `strcmp`
- Llamado a función específica
- Manejo de comando inválido

---

## 📦 6. API de Comandos

### 6.1 Firma Estándar

Todos los comandos implementados en EAFITos deben respetar la siguiente firma:

```c
void cmd_nombre(int argc, char **argv);
```

**Convenciones**

| Parámetro    | Descripción                    |
|--------------|--------------------------------|
| `argc`       | Número de argumentos           |
| `argv`       | Arreglo de cadenas             |
| `argv[0]`    | Nombre del comando             |
| `argv[1...]` | Argumentos del usuario         |

---

## 📂 7. Comandos Implementados

### 7.1 Comandos de Archivos

#### 🔹 `cmd_listar`

```c
void cmd_listar(int argc, char **argv);
```

Lista archivos del directorio actual utilizando `dirent.h`.

---

#### 🔹 `cmd_leer`

```c
void cmd_leer(int argc, char **argv);
```

Lee el contenido de un archivo.

**Validaciones:**

- `argc >= 2`
- Archivo existente
- Permisos de lectura

---

#### 🔹 `cmd_crear`

```c
void cmd_crear(int argc, char **argv);
```

Crea un archivo vacío.

---

#### 🔹 `cmd_renombrar`

```c
void cmd_renombrar(int argc, char **argv);
```

Renombra archivo existente.

**Requiere:** `argc == 3`

---

#### 🔹 `cmd_eliminar`

```c
void cmd_eliminar(int argc, char **argv);
```

Elimina archivo con confirmación previa.

---

#### 🔹 `cmd_wc`

```c
void cmd_wc(int argc, char **argv);
```

Cuenta:

- Líneas
- Palabras
- Caracteres

---

### 7.2 Comandos del Sistema

#### 🔹 `cmd_directorio`

```c
void cmd_directorio(int argc, char **argv);
```

Imprime directorio actual usando `getcwd()`.

---

#### 🔹 `cmd_userinfo`

```c
void cmd_userinfo(int argc, char **argv);
```

Muestra información del usuario:

- UID
- GID
- Nombre
- Directorio home

Utiliza `pwd.h`.

---

#### 🔹 `cmd_tiempo`

```c
void cmd_tiempo(int argc, char **argv);
```

Muestra fecha y hora del sistema usando `time.h`.

---

### 7.3 Comandos Utilitarios

#### 🔹 `cmd_calc`

```c
void cmd_calc(int argc, char **argv);
```

Calculadora básica. Soporta:

- Suma
- Resta
- Multiplicación
- División

**Validaciones:** `argc == 4`, división por cero.

---

#### 🔹 `cmd_limpiar`

```c
void cmd_limpiar(int argc, char **argv);
```

Limpia la pantalla:

- Linux / macOS → `clear`
- Windows → `cls`

---

#### 🔹 `cmd_ayuda`

```c
void cmd_ayuda(int argc, char **argv);
```

Lista todos los comandos disponibles.

---

#### 🔹 `cmd_menu`

```c
void cmd_menu(int argc, char **argv);
```

Imprime menú formateado interactivo.

---

#### 🔹 `cmd_salir`

```c
void cmd_salir(int argc, char **argv);
```

Finaliza la ejecución del programa.

---

## 🧩 8. Constantes Globales

```c
#define MAX_INPUT 1024
#define MAX_ARGS  64
```

| Constante   | Descripción                        |
|-------------|------------------------------------|
| `MAX_INPUT` | Tamaño máximo de línea de entrada  |
| `MAX_ARGS`  | Número máximo de argumentos        |

---

## ⚙ 9. Dependencias del Sistema

El proyecto utiliza las siguientes librerías estándar de C:

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <pwd.h>
```

---

## 🛠 10. Manejo de Errores

El sistema implementa:

- Validación de argumentos
- Validación de existencia de archivos
- Mensajes para comandos desconocidos
- Protección contra división por cero
- Manejo básico de errores de archivo
- Control de punteros nulos

---

## 🔒 11. Seguridad y Limitaciones

EAFITos **NO** implementa:

- Pipes (`|`)
- Redirecciones (`>`, `<`)
- Procesos en segundo plano (`&`)
- Manejo de señales
- Ejecución de comandos externos
- Variables de entorno dinámicas
- Expansión de comodines (`*`)

> Es una shell **educativa**, no de producción.

---

## 🚀 12. Extensión del Sistema

### 12.1 Paso 1 — Declarar en `commands.h`

```c
void cmd_nuevo(int argc, char **argv);
```

### 12.2 Paso 2 — Implementar en archivo correspondiente

Agregar la implementación en el archivo adecuado dentro de `commands/`.

### 12.3 Paso 3 — Registrar en `dispatcher.c`

```c
else if (strcmp(argv[0], "nuevo") == 0) {
    cmd_nuevo(argc, argv);
}
```

### 12.4 Paso 4 — Recompilar

```bash
make
```

---

## 🧪 13. Buenas Prácticas

- Mantener firma estándar
- Validar argumentos siempre
- Separar lógica de presentación
- Documentar con Doxygen
- Evitar duplicación de código
- Manejar errores explícitamente
- Mantener coherencia modular

---

## 📌 14. Alcance Académico

EAFITos refuerza conceptos fundamentales de Sistemas Operativos:

- Parsing de comandos
- Modularidad en C
- Organización de proyectos
- Manejo de archivos
- Diseño de APIs internas
- Arquitectura por capas

> No reemplaza una terminal real del sistema.

---

## 📄 15. Licencia

Proyecto académico con fines exclusivamente educativos.  
Desarrollado en la **Universidad EAFIT** — 2026.