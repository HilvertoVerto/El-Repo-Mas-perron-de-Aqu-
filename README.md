# 📚 Sistema de Gestión de Biblioteca

Sistema completo de gestión de libros y categorías desarrollado en C++ con arquitectura MVC, patrones de diseño y persistencia en SQLite.

## 🚀 Inicio Rápido

Para compilar y ejecutar el proyecto fácilmente, usa el script Python:

```bash
./run.py
```

Este script automáticamente:
- ✅ Detecta si el proyecto necesita compilación
- ✅ Compila el proyecto con CMake si es necesario
- ✅ Ejecuta el programa desde la raíz del proyecto
- ✅ Asegura que la base de datos se cree en la ubicación correcta (`db/biblioteca.db`)

## ✨ Características

- ✅ **CRUD completo** de libros y categorías
- ✅ **Persistencia con SQLite ORM** (base de datos profesional)
- ✅ **Validación robusta de entrada** (no explota con datos inválidos)
- ✅ **Arquitectura MVC** + Repository Pattern + Factory Pattern
- ✅ **Interfaz de consola intuitiva**
- ✅ **Manejo de errores y excepciones**
- ✅ **Código modular y escalable**

## 🎯 Funcionalidades

### Gestión de Libros
- Agregar libros (nombre, autor, año, categoría)
- Editar libros existentes
- Eliminar libros con confirmación
- Listar todos los libros

### Gestión de Categorías
- Agregar categorías (nombre, descripción)
- Listar todas las categorías
- Validación de duplicados

### Características Técnicas
- IDs autoincrementales generados por SQLite
- Transacciones atómicas (todo se guarda o nada)
- Validación de tipos (int, string) con retry automático
- Base de datos organizada en `db/biblioteca.db`

## 🏗️ Arquitectura

```
┌─────────────────────────────────────────────────────┐
│                    main.cpp                         │
│                 (Punto de entrada)                  │
└────────────────────┬────────────────────────────────┘
                     │
         ┌───────────▼──────────────┐
         │  ControladorPrincipal    │  ← Coordinador general
         │  - Inicializa sistema    │
         │  - Gestiona flujo        │
         └───────┬──────────┬───────┘
                 │          │
        ┌────────▼─────┐   ┌▼──────────────────┐
        │ControladorMenu│   │ RepositorioLibros │
        │ - UI/Navegación│   │ - Persistencia    │
        │ - Validación   │   │ - CRUD DB         │
        └────────┬─────┘   └┬──────────────────┘
                 │           │
        ┌────────▼─────┐   ┌▼──────────────┐
        │ MenuFactory  │   │  SQLite ORM   │
        │ - Crea menús │   │ (biblioteca.db)│
        └────┬─────────┘   └───────────────┘
             │
    ┌────────▼────────┐
    │ Menús (I_Menu)  │
    │ - MenuAgregarLibro
    │ - MenuAgregarCategoria
    │ - MenuEditar
    │ - MenuEliminarLibro
    └─────────────────┘
```

### Patrones de Diseño Utilizados

1. **MVC (Model-View-Controller)**
   - **Model**: `Libro`, `Categoria` (m/)
   - **View**: Menús de interfaz (v/)
   - **Controller**: Controladores de lógica (c/)

2. **Repository Pattern**
   - `RepositorioLibros`: Abstrae el acceso a datos

3. **Factory Pattern**
   - `MenuFactory`: Crea instancias de menús según el tipo

4. **Strategy Pattern**
   - `I_Menu`: Interfaz común para todos los menús

## 📁 Estructura del Proyecto

```
El-Repo-Mas-perron-de-Aqu-/
├── c/                              # Controladores
│   ├── ControladorPrincipal.h/cpp  # Coordinador general
│   ├── ControladorMenu.h/cpp       # Gestión de menús y UI
│   └── MenuFactory.h/cpp           # Factory de menús
│
├── db/                             # Base de datos y repositorio
│   ├── RepositorioLibros.h/cpp     # Acceso a datos con SQLite ORM
│   └── biblioteca.db               # Base de datos SQLite (generada)
│
├── m/                              # Modelos (Entidades)
│   ├── Libro.h/cpp                 # Clase Libro
│   └── Categoria.h/cpp             # Clase Categoria
│
├── v/                              # Vistas (Menús)
│   ├── I_Menu.h                    # Interfaz base
│   ├── MenuAgregarLibro-I_Menu.h/cpp
│   ├── MenuAgregarCategoria-I_Menu.h/cpp
│   ├── MenuEditar-I_Menu.h/cpp
│   └── MenuEliminarLibro-I_Menu.h/cpp
│
├── utils/                          # Utilidades
│   ├── LimpiarPantalla.h/cpp       # Función para limpiar pantalla
│
├── build/                          # Archivos de compilación (generado)
│   └── biblioteca                  # Ejecutable
│
├── main.cpp                        # Punto de entrada
├── CMakeLists.txt                  # Configuración de CMake
├── run.py                          # Script para compilar y ejecutar
└── README.md                       # Este archivo
```

## 🔧 Requisitos

### Software Necesario

- **g++** con soporte para C++17 o superior
- **CMake** 3.10 o superior
- **SQLite3** (biblioteca)
- **SQLite ORM** (header-only library)
- **Python 3** (para el script run.py)
- **Git** (opcional, para clonar)

### Sistemas Operativos

- ✅ Linux (probado en Arch Linux)
- ✅ macOS
- ✅ Windows (con MinGW/MSYS2)

## 📦 Instalación

### 1. Instalar Dependencias

#### En Arch Linux:
```bash
# Instalar todas las dependencias necesarias
sudo pacman -S gcc cmake sqlite python

# Verificar instalación
cmake --version
python --version
sqlite3 --version
```

#### En Ubuntu/Debian:
```bash
# Instalar todas las dependencias necesarias
sudo apt update
sudo apt install build-essential cmake libsqlite3-dev python3

# Verificar instalación
cmake --version
python3 --version
sqlite3 --version
```

#### En macOS:
```bash
# Instalar dependencias con Homebrew
brew install cmake sqlite3 python3

# Verificar instalación
cmake --version
python3 --version
sqlite3 --version
```

### 2. Instalar SQLite ORM

SQLite ORM es una biblioteca **header-only** (solo headers):

```bash
# Clonar el repositorio
cd /tmp
git clone https://github.com/fnc12/sqlite_orm.git

# Copiar headers al sistema
sudo cp -r sqlite_orm/include/sqlite_orm /usr/include/

# O copiar al proyecto (alternativa)
# mkdir -p external
# cp -r sqlite_orm/include/sqlite_orm external/
```

### 3. Clonar el Proyecto

```bash
git clone <url-del-repositorio>
cd El-Repo-Mas-perron-de-Aqu-
```

## 🚀 Compilación y Ejecución

### Método Recomendado: Script Python (run.py)

El método más simple y recomendado es usar el script `run.py`:

```bash
# Dar permisos de ejecución (solo la primera vez)
chmod +x run.py

# Compilar y ejecutar automáticamente
./run.py
```

**Ventajas del script:**
- ✅ Compila automáticamente si es necesario
- ✅ Ejecuta el programa desde la raíz (base de datos en `db/biblioteca.db`)
- ✅ Detecta si el proyecto ya está compilado
- ✅ Muestra mensajes informativos claros

### Método Manual: CMake

Si prefieres compilar manualmente:

```bash
# Configurar el proyecto con CMake
cmake -S . -B build

# Compilar
cmake --build build

# Ejecutar (desde la raíz del proyecto)
./build/biblioteca
```

### Limpiar archivos compilados

```bash
# Eliminar la carpeta build
rm -rf build

# Eliminar la base de datos
rm -rf db
```

## 📖 Uso del Sistema

### Menú Principal

Al ejecutar el programa verás:

```
========================================
       SISTEMA DE GESTION DE LIBROS
========================================

1. Agregar Libro
2. Agregar Categoria
3. Editar Libro
4. Eliminar Libro
5. Ver Libros
6. Ver Categorias
0. Salir

========================================
```

### Flujo Típico

1. **Primera vez**: Agregar categorías primero (Novela, Terror, etc.)
2. **Agregar libros**: Seleccionar categoría de la lista
3. **Editar**: Modificar datos existentes
4. **Eliminar**: Confirmar escribiendo "eliminar"
5. **Salir**: Los datos se guardan automáticamente

### Validación de Entrada

El sistema **NO EXPLOTA** si introduces datos incorrectos:

```
Seleccione una opcion: abc
Error: Debe ingresar un numero entero.
Seleccione una opcion: 10
Error: El numero debe estar entre 0 y 6.
Seleccione una opcion: 1
✓ Opción válida
```

## 🗄️ Base de Datos

### Esquema SQLite

**Tabla `libros`:**
```sql
CREATE TABLE libros (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    nombre TEXT,
    autor TEXT,
    anio INTEGER,
    categoria TEXT
);
```

**Tabla `categorias`:**
```sql
CREATE TABLE categorias (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    nombre TEXT,
    descripcion TEXT
);
```

### Ubicación

- **Archivo**: `db/biblioteca.db`
- Se crea automáticamente al ejecutar el programa
- Formato SQLite3 estándar (puedes abrirlo con cualquier cliente SQLite)

### Ver la Base de Datos

```bash
# Abrir con cliente SQLite
sqlite3 db/biblioteca.db

# Comandos útiles dentro de sqlite3
.tables              # Ver tablas
SELECT * FROM libros;       # Ver libros
SELECT * FROM categorias;   # Ver categorías
.exit                # Salir
```

## 🛠️ Tecnologías Utilizadas

- **Lenguaje**: C++17
- **Base de Datos**: SQLite3
- **ORM**: [SQLite ORM](https://github.com/fnc12/sqlite_orm)
- **Compilador**: GCC/Clang
- **Build System**: CMake
- **Script de Automatización**: Python 3

## 📚 Conceptos Aplicados

- Programación Orientada a Objetos (POO)
- Patrones de Diseño (MVC, Factory, Repository, Strategy)
- Manejo de excepciones
- Validación de entrada robusta
- Persistencia de datos
- Arquitectura por capas
- Separación de responsabilidades (SRP)
- Gestión de memoria (RAII)

## 🔮 Posibles Mejoras Futuras

- [ ] Búsqueda y filtrado de libros
- [ ] Relaciones entre Libro y Categoria con foreign keys
- [ ] Exportar/Importar datos (CSV, JSON)
- [ ] Interfaz gráfica (Qt/GTK)
- [ ] Sistema de usuarios y permisos
- [ ] Préstamos y devoluciones
- [ ] Estadísticas y reportes
- [ ] Tests unitarios

## 🤝 Contribuciones

Las contribuciones son bienvenidas. Por favor:

1. Fork el proyecto
2. Crea una rama para tu feature (`git checkout -b feature/AmazingFeature`)
3. Commit tus cambios (`git commit -m 'Add some AmazingFeature'`)
4. Push a la rama (`git push origin feature/AmazingFeature`)
5. Abre un Pull Request

## 📝 Licencia

Este proyecto es código abierto y está disponible bajo la licencia MIT.

## 👨‍💻 Autor

Desarrollado por HilvertoVerto

---

⭐ Si te gustó el proyecto, dale una estrella en GitHub!
