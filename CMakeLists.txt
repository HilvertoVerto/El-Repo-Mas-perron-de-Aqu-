cmake_minimum_required(VERSION 3.10)

# Información del proyecto
project(SistemaGestionBiblioteca
    VERSION 1.0.0
    DESCRIPTION "Sistema de gestión de libros y categorías con SQLite"
    LANGUAGES CXX)

# Configurar C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Habilitar advertencias
if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Buscar SQLite3
find_package(SQLite3 QUIET)

# Si find_package no funciona, buscar manualmente
if(NOT SQLite3_FOUND)
    find_path(SQLite3_INCLUDE_DIR NAMES sqlite3.h)
    find_library(SQLite3_LIBRARY NAMES sqlite3)

    if(SQLite3_INCLUDE_DIR AND SQLite3_LIBRARY)
        set(SQLite3_FOUND TRUE)
        set(SQLite3_INCLUDE_DIRS ${SQLite3_INCLUDE_DIR})
        set(SQLite3_LIBRARIES ${SQLite3_LIBRARY})
        message(STATUS "SQLite3 encontrado manualmente: ${SQLite3_LIBRARY}")
    else()
        message(FATAL_ERROR "SQLite3 no encontrado. Instala: sudo pacman -S sqlite")
    endif()
endif()

# Buscar SQLite ORM (header-only library)
# Buscar en /usr/include, /usr/local/include, o en external/
find_path(SQLITE_ORM_INCLUDE_DIR
    NAMES sqlite_orm/sqlite_orm.h
    PATHS
        /usr/include
        /usr/local/include
        ${CMAKE_CURRENT_SOURCE_DIR}/external
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

if(NOT SQLITE_ORM_INCLUDE_DIR)
    message(FATAL_ERROR
        "\nSQLite ORM no encontrado.\n"
        "Instálalo con:\n"
        "  cd /tmp\n"
        "  git clone https://github.com/fnc12/sqlite_orm.git\n"
        "  sudo cp -r sqlite_orm/include/sqlite_orm /usr/include/\n"
        "\nO copia los headers al proyecto:\n"
        "  mkdir -p external\n"
        "  cp -r sqlite_orm/include/sqlite_orm external/\n")
else()
    message(STATUS "SQLite ORM encontrado: ${SQLITE_ORM_INCLUDE_DIR}")
endif()

# Archivos fuente - Modelos
set(MODEL_SOURCES
    m/Libro.cpp
    m/Categoria.cpp
)

# Archivos fuente - Controladores
set(CONTROLLER_SOURCES
    c/ControladorPrincipal.cpp
    c/ControladorMenu.cpp
    c/MenuFactory.cpp
)

# Archivos fuente - Vistas (Menús)
set(VIEW_SOURCES
    v/MenuPrincipal.cpp
    v/MenuAgregarLibro-I_Menu.cpp
    v/MenuAgregarCategoria-I_Menu.cpp
    v/MenuEliminarLibro-I_Menu.cpp
    v/MenuEditar-I_Menu.cpp
)

# Archivos fuente - Base de datos
set(DB_SOURCES
    db/RepositorioLibros.cpp
)

# Archivos fuente - Utilidades
set(UTILS_SOURCES
    utils/LimpiarPantalla.cpp
)

# Archivo principal
set(MAIN_SOURCE
    main.cpp
)

# Crear ejecutable
add_executable(biblioteca
    ${MAIN_SOURCE}
    ${MODEL_SOURCES}
    ${CONTROLLER_SOURCES}
    ${VIEW_SOURCES}
    ${DB_SOURCES}
    ${UTILS_SOURCES}
)

# Directorios de includes
target_include_directories(biblioteca PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${SQLite3_INCLUDE_DIRS}
    ${SQLITE_ORM_INCLUDE_DIR}
)

# Linkear SQLite3
target_link_libraries(biblioteca PRIVATE
    ${SQLite3_LIBRARIES}
)

# Organizar archivos en el IDE (Visual Studio, Xcode, etc.)
source_group("Source Files\\Models" FILES ${MODEL_SOURCES})
source_group("Source Files\\Controllers" FILES ${CONTROLLER_SOURCES})
source_group("Source Files\\Views" FILES ${VIEW_SOURCES})
source_group("Source Files\\Database" FILES ${DB_SOURCES})
source_group("Source Files\\Utils" FILES ${UTILS_SOURCES})
source_group("Source Files" FILES ${MAIN_SOURCE})

# Crear directorio db/ en tiempo de compilación si no existe
add_custom_command(TARGET biblioteca POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_CURRENT_SOURCE_DIR}/db
    COMMENT "Creando directorio db/ para la base de datos"
)

# Configuración de instalación (opcional)
install(TARGETS biblioteca
    RUNTIME DESTINATION bin
)

# Mostrar información de configuración
message(STATUS "===========================================")
message(STATUS "Sistema de Gestión de Biblioteca")
message(STATUS "===========================================")
message(STATUS "Versión: ${PROJECT_VERSION}")
message(STATUS "Compilador: ${CMAKE_CXX_COMPILER_ID} ${CMAKE_CXX_COMPILER_VERSION}")
message(STATUS "C++ Standard: C++${CMAKE_CXX_STANDARD}")
message(STATUS "SQLite3: ${SQLite3_VERSION}")
message(STATUS "Build Type: ${CMAKE_BUILD_TYPE}")
message(STATUS "===========================================")
