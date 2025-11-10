#include "c/ControladorPrincipal.h"
#include <iostream>

int main() {
    try {
        // Crear el controlador principal
        // La base de datos se creara en db/biblioteca.db
        ControladorPrincipal controlador;

        // Inicializar el sistema (crear BD y tablas)
        controlador.iniciar();

        // Ejecutar el menu principal
        controlador.ejecutar();

        return 0;

    } catch (const std::exception& e) {
        std::cerr << "Error fatal: " << e.what() << std::endl;
        return 1;
    }
}
