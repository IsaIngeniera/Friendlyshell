# 📖 Guía de Usuario --- EAFITos

## 🎯 Objetivo

Esta guía explica cómo instalar, ejecutar y utilizar **FriendlyShell**, una
shell educativa desarrollada con fines académicos.

Está dirigida a usuarios finales que desean usar el sistema sin
necesidad de conocer detalles internos del código.

------------------------------------------------------------------------

# 1️⃣ Primer Paso: Instalación

## ✅ Requisitos

-   Sistema Linux, macOS o Windows con WSL\
-   Compilador GCC instalado\
-   `make` instalado

Puedes verificar que tienes GCC con:

``` bash
gcc --version
```

Y `make` con:

``` bash
make --version
```

------------------------------------------------------------------------

## 🔧 Compilación del Proyecto

Ubícate en la carpeta raíz del proyecto:

``` bash
cd SistemaOperativo
```

Luego ejecuta:

``` bash
make
```

Si todo está correcto, el sistema compilará automáticamente los archivos
fuente y generará el ejecutable.

------------------------------------------------------------------------

# 2️⃣ Segundo Paso: Ejecución

## ▶️ Ejecutar la Shell


Después de compilar, ejecuta:

``` bash
./build/sistema_os
```

(Si tu ejecutable tiene otro nombre, usa ese nombre.)

Al iniciar, verás el mensaje:

``` bash
Iniciando FriendlyShell v1.0...
Escribe 'menu' para comenzar.
```

Si escribes `menu`, aparecerá el menú principal con los comandos
disponibles:


El prompt se verá así:

FriendlyShell>

``` bash
╔════════════════════════════════════════╗
║     MENÚ PRINCIPAL - Shell Educativa   ║
╚════════════════════════════════════════╝
  Comandos disponibles:
  • listar    - Mostrar archivos
  • leer      - Ver contenido de archivo
  • tiempo    - Fecha y hora actual
  • calc      - Calculadora simple
  • limpiar   - Limpiar la pantalla
  • ayuda     - Ayuda detallada de comandos
  • crear     - Crear archivo vacío
  • renombrar - Renombrar archivo existente
  • eliminar  - Elimina archivo con confirmación.
  • directorio- Muestra el directorio actual
  • userinfo  - Muestra información del usuario.
  • menu      - Mostrar este menú
  • wc        - Contador de líneas/palabras/caracteres.
  • salir     - Terminar sesión
════════════════════════════════════════
```

------------------------------------------------------------------------

# 3️⃣ Tercer Paso: Manual de Comandos

A continuación se describen todos los comandos disponibles en la shell.

------------------------------------------------------------------------

## 📂 listar

Nombre completo: Listar Directorio 
Función: Muestra los archivos y carpetas del directorio actual.

FriendlyShell> listar
docs
src
Makefile
README.md

------------------------------------------------------------------------

## 📖 leer

Nombre completo: Leer archivo
Función: Muestra el contenido completo de un archivo de texto.

Sintaxis:

leer docs/DOCUMENTATION.md

FriendlyShell> leer docs/DOCUMENTATION.md

Si el archivo no existe, aparecerá un mensaje de error.

------------------------------------------------------------------------

## 🕒 tiempo

Nombre completo: Date/Time  
Función: Muestra la fecha y hora actual del sistema.

FriendlyShell> tiempo
Fecha y hora actual: 12/02/2026 14:32:10

------------------------------------------------------------------------

## 🧮 calc

Nombre completo: Calculator  
Función: Realiza operaciones matemáticas básicas (suma, resta, multiplicación y división).

Sintaxis:

calc <numero1> <operador> <numero2>

Operadores disponibles:

+ suma
- resta
* multiplicación
/ división

Ejemplo:

FriendlyShell> calc 15 + 7

------------------------------------------------------------------------

## 🧹 limpiar

Nombre completo: Clear Screen  
Función: Limpia completamente la pantalla del terminal.

FriendlyShell> limpiar

------------------------------------------------------------------------

## 📄 crear

Nombre completo: Create File  
Función: Crea un nuevo archivo vacío.  
Si el archivo ya existe, sobrescribe su contenido.

FriendlyShell> crear notas.txt

------------------------------------------------------------------------

## ✏️ renombrar

Nombre completo: Rename File  
Función: Cambia el nombre de un archivo existente.

FriendlyShell> renombrar viejo.txt nuevo.txt

------------------------------------------------------------------------

## 🗑 eliminar

Nombre completo: Remove File  
Función: Elimina permanentemente un archivo del sistema.  
Esta acción no se puede deshacer.

FriendlyShell> eliminar archivo.txt

------------------------------------------------------------------------

## 📁 directorio

Nombre completo: Print Working Directory  
Función: Muestra la ruta completa del directorio actual (equivalente a pwd).

FriendlyShell> directorio

------------------------------------------------------------------------

## 👤 userinfo

Nombre completo: User Information  
Función: Muestra información técnica del usuario actual:

Nombre de usuario
UID
GID
Directorio Home

FriendlyShell> userinfo

------------------------------------------------------------------------

## 📊 wc

Nombre completo: Word Count  
Función: Cuenta líneas, palabras y caracteres de un archivo.

FriendlyShell> wc archivo.txt

------------------------------------------------------------------------

## ❓ ayuda

Nombre completo: Help  
Función: Muestra información detallada de todos los comandos disponibles.

FriendlyShell> ayuda

------------------------------------------------------------------------

## 📋 menu

Nombre completo: Main Menu  
Función: Muestra nuevamente el menú principal.

FriendlyShell> menu

------------------------------------------------------------------------

## 🚪 salir

Nombre completo: Exit  
Función: Cierra la shell y finaliza la sesión.

FriendlyShell> salir
Saliendo de la shell...

------------------------------------------------------------------------

# ⚠️ Mensajes de Error

Si un comando no existe o está mal escrito, el sistema mostrará:

Comando desconocido.
Escribe 'ayuda' para ver los comandos disponibles.

------------------------------------------------------------------------

# 🧠 Recomendaciones

- Escribe los comandos exactamente como aparecen en el menú.
- Verifica que el archivo exista antes de usar leer, renombrar o eliminar.
- Usa menu o ayuda si necesitas orientación.

------------------------------------------------------------------------

© 2026 --- Proyecto Académico Sistemas Operativos