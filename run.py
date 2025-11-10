#!/usr/bin/env python3
"""
Script para compilar y ejecutar el Sistema de Gestión de Biblioteca.
Este script asegura que el programa se ejecute desde la raíz del proyecto
para que los archivos de base de datos se creen en la ubicación correcta.
"""

import os
import sys
import subprocess
from pathlib import Path


def print_info(message):
    """Imprime un mensaje informativo."""
    print(f"[INFO] {message}")


def print_error(message):
    """Imprime un mensaje de error."""
    print(f"[ERROR] {message}", file=sys.stderr)


def print_success(message):
    """Imprime un mensaje de éxito."""
    print(f"[OK] {message}")


def check_build_directory():
    """Verifica si existe el directorio build."""
    build_dir = Path("build")
    if not build_dir.exists():
        print_info("Directorio 'build' no existe. Creándolo...")
        build_dir.mkdir()
        return False
    return True


def check_executable():
    """Verifica si el ejecutable existe."""
    executable = Path("build/biblioteca")
    return executable.exists()


def run_cmake():
    """Ejecuta CMake para configurar el proyecto."""
    print_info("Configurando proyecto con CMake...")
    try:
        result = subprocess.run(
            ["cmake", "-S", ".", "-B", "build"],
            check=True,
            capture_output=False
        )
        print_success("Configuración completada.")
        return True
    except subprocess.CalledProcessError as e:
        print_error(f"Error al ejecutar CMake: {e}")
        return False
    except FileNotFoundError:
        print_error("CMake no está instalado. Instala con: sudo pacman -S cmake")
        return False


def run_make():
    """Compila el proyecto usando make."""
    print_info("Compilando proyecto...")
    try:
        result = subprocess.run(
            ["cmake", "--build", "build", "--", "-j"],
            check=True,
            capture_output=False
        )
        print_success("Compilación completada.")
        return True
    except subprocess.CalledProcessError as e:
        print_error(f"Error al compilar: {e}")
        return False


def run_program():
    """Ejecuta el programa desde la raíz del proyecto."""
    print_info("Ejecutando programa...\n")
    print("=" * 50)
    try:
        # Ejecutar el programa desde la raíz del proyecto
        # Esto asegura que las rutas relativas se creen correctamente
        result = subprocess.run(
            ["./build/biblioteca"],
            cwd=os.getcwd(),  # Ejecutar desde el directorio actual (raíz)
            check=False  # No lanzar excepción si el programa retorna código != 0
        )
        print("=" * 50)
        return result.returncode
    except FileNotFoundError:
        print_error("No se pudo encontrar el ejecutable './build/biblioteca'")
        return 1
    except KeyboardInterrupt:
        print("\n[INFO] Programa interrumpido por el usuario.")
        return 130


def main():
    """Función principal."""
    # Verificar que estamos en el directorio del proyecto
    if not Path("CMakeLists.txt").exists():
        print_error("No se encuentra CMakeLists.txt")
        print_error("Asegúrate de ejecutar este script desde la raíz del proyecto.")
        return 1

    print("=" * 50)
    print("Sistema de Gestión de Biblioteca")
    print("=" * 50)

    # Verificar si necesitamos compilar
    needs_compile = False

    if not check_build_directory():
        needs_compile = True

    if not check_executable():
        print_info("Ejecutable no encontrado.")
        needs_compile = True

    # Compilar si es necesario
    if needs_compile:
        print_info("Se requiere compilación.")

        # Configurar con CMake
        if not run_cmake():
            return 1

        # Compilar con make
        if not run_make():
            return 1
    else:
        print_success("Ejecutable encontrado. No se requiere compilación.")

    # Ejecutar el programa
    return run_program()


if __name__ == "__main__":
    sys.exit(main())
