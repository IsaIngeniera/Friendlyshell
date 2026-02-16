# FriendlyShell 🎓

**FriendlyShell** es un sistema operativo educativo diseñado para aprender los fundamentos de la programación de sistemas y la operación interna de una shell utilizando el lenguaje C.

## 🚀 Objetivos

- Entender la **gestión de procesos** y memoria.
- Aprender sobre **hilos (threads)** y concurrencia.
- Explorar el **sistema de archivos** y llamadas al sistema (syscalls).
- Implementar **estructuras de datos básicas** usadas en kernels.

## 🏆 Desarrolladores Principales

| Nombre | Rol |
|--------|-----|
| **Isabella Cadavid Posada** | Desarrollo y documentación del sistema |
| **Isabella Ocampo Sanchez** | Desarrollo y lider del sistema |
| **Juan Manuel Hernandez Martelo** | Desarrollo, tester y documentador del sistema |
| **Wendy Vanessa Atehortua Chaverra** | Desarrollo y arquitectura del sistema |


---

## ⚡ Compilación y Ejecución

### ✅ Requisitos

- Sistema **Linux**, **macOS** o **Windows con WSL**
- Compilador **GCC** instalado
- **`make`** instalado

Puedes verificarlos con:
```bash
gcc --version
make --version
```

### 🔧 Compilar

Ubícate en la carpeta raíz del proyecto y ejecuta:
```bash
make
```

### ▶️ Ejecutar
```bash
make run
# O directamente:
./build/sistema_os
```

Al iniciar, verás el mensaje de bienvenida:
```
Iniciando FriendlyShell v1.0...
Escribe 'menu' para comenzar.
```

El prompt se verá así:
```
FriendlyShell>
```

---

## 🐚 La Shell de EAFITos (FriendlyShell)

El sistema inicia con una interfaz de línea de comandos básica que permite interactuar con el sistema. Si escribes `menu`, aparecerá el listado completo de comandos disponibles.

### ¿Qué son los Argumentos (`args`)?

En una shell, cuando escribes un comando, a menudo necesitas enviarle información adicional. Esta información se divide en "argumentos".

Internamente en C, esto se maneja mediante un arreglo de cadenas (`char **args`):
- **`args[0]`**: Es siempre el nombre del comando (ej. `calc`).
- **`args[1]`, `args[2]`, etc.**: Son los parámetros que le pasas al comando.

**Ejemplo con `calc 10 + 5`:**
- `args[0]` → `"calc"`
- `args[1]` → `"10"`
- `args[2]` → `"+"`
- `args[3]` → `"5"`

---

## 📋 Comandos Disponibles

| Comando | Argumentos | Descripción | Ejemplo |
| :--- | :--- | :--- | :--- |
| `listar` | Ninguno | Muestra los archivos y carpetas del directorio actual. | `listar` |
| `leer` | `<archivo>` | Muestra el contenido completo de un archivo de texto. | `leer README.md` |
| `tiempo` | Ninguno | Muestra la fecha y hora actual del sistema. | `tiempo` |
| `calc` | `<n1> <op> <n2>` | Realiza operaciones aritméticas (`+`, `-`, `*`, `/`). | `calc 10 * 2.5` |
| `crear` | `<archivo>` | Crea un nuevo archivo vacío (sobrescribe si ya existe). | `crear notas.txt` |
| `renombrar` | `<viejo> <nuevo>` | Cambia el nombre de un archivo existente. | `renombrar a.txt b.txt` |
| `eliminar` | `<archivo>` | Elimina un archivo con confirmación (acción irreversible). | `eliminar notas.txt` |
| `directorio` | Ninguno | Muestra la ruta completa del directorio actual (`pwd`). | `directorio` |
| `userinfo` | Ninguno | Muestra nombre de usuario, UID, GID y directorio home. | `userinfo` |
| `wc` | `<archivo>` | Cuenta líneas, palabras y caracteres de un archivo. | `wc archivo.txt` |
| `limpiar` | Ninguno | Limpia completamente la pantalla del terminal. | `limpiar` |
| `ayuda` | Ninguno | Muestra información detallada de todos los comandos. | `ayuda` |
| `menu` | Ninguno | Muestra nuevamente el menú principal. | `menu` |
| `salir` | Ninguno | Cierra la shell y finaliza la sesión. | `salir` |

---

## ⚠️ Mensajes de Error

Si un comando no existe o está mal escrito, el sistema mostrará:
```
Comando desconocido.
Escribe 'ayuda' para ver los comandos disponibles.
```

---

## 🛠️ Estructura del Proyecto
```
SistemaOperativo/
├── src/          # Código fuente (main.c contiene el loop principal)
├── build/        # Ejecutables generados por make
├── docs/         # Documentación generada por Doxygen
├── Makefile      # Script para automatizar la compilación
└── Doxyfile      # Configuración de Doxygen
```

---

## 📚 Documentación Técnica (Doxygen)

El proyecto incluye autodocumentación basada en **Doxygen**, que genera un sitio web técnico a partir de los comentarios del código fuente.

### ¿Qué es el `Doxyfile`?

El archivo `Doxyfile` contiene la configuración para que Doxygen analice el código en C, encuentre los archivos fuente y genere la salida en formato HTML.

### Generar la documentación

Si tienes Doxygen instalado:

1. Asegúrate de estar en la raíz del proyecto.
2. Ejecuta:
```bash
doxygen Doxyfile
```

3. Abre `docs/html/index.html` en tu navegador para navegar por la documentación interactiva.

---

## 🧠 Recomendaciones

- Escribe los comandos exactamente como aparecen en el menú.
- Verifica que el archivo exista antes de usar `leer`, `renombrar` o `eliminar`.
- Usa `menu` o `ayuda` si necesitas orientación dentro de la shell.

---

> © 2026 — Proyecto Académico Sistemas Operativos · EAFIT