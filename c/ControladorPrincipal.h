#ifndef CONTROLADOR_PRINCIPAL_H
#define CONTROLADOR_PRINCIPAL_H

#include <string>
#include "../db/RepositorioLibros.h"
#include "ControladorMenu.h"

class ControladorPrincipal {
private:
    std::string rutaBD;
    RepositorioLibros* repositorio;
    ControladorMenu* controladorMenu;

public:
    // Constructor: recibe opcionalmente la ruta de la base de datos
    ControladorPrincipal(const std::string& rutaBD = "db/biblioteca.db");

    // Destructor
    ~ControladorPrincipal();

    // Iniciar la aplicacion
    void iniciar();

    // Ejecutar el ciclo principal de la aplicacion
    void ejecutar();
};

#endif
