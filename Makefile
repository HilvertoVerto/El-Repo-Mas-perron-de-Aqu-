# Makefile para Sistema de Gestión de Biblioteca

# Compilador y flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -I.
LDFLAGS = -lsqlite3

# Nombre del ejecutable
TARGET = biblioteca

# Directorios
SRC_DIR = .
MODEL_DIR = m
VIEW_DIR = v
CONTROLLER_DIR = c
DB_DIR = db

# Archivos fuente
SOURCES = main.cpp \
          $(MODEL_DIR)/Libro.cpp \
          $(MODEL_DIR)/Categoria.cpp \
          $(VIEW_DIR)/MenuAgregar-I_Menu.cpp \
          $(VIEW_DIR)/MenuAgregarLibro-I_Menu.cpp \
          $(VIEW_DIR)/MenuAgregarCategoria-I_Menu.cpp \
          $(VIEW_DIR)/MenuEditar-I_Menu.cpp \
          $(VIEW_DIR)/MenuEliminarLibro-I_Menu.cpp \
          $(CONTROLLER_DIR)/MenuFactory.cpp \
          $(CONTROLLER_DIR)/ControladorMenu.cpp \
          $(CONTROLLER_DIR)/ControladorPrincipal.cpp \
          $(DB_DIR)/RepositorioLibros.cpp

# Archivos objeto
OBJECTS = $(SOURCES:.cpp=.o)

# Regla principal
all: $(TARGET)

# Linkear el ejecutable
$(TARGET): $(OBJECTS)
	@echo "Linkeando $(TARGET)..."
	$(CXX) $(OBJECTS) -o $(TARGET) $(LDFLAGS)
	@echo "Compilacion exitosa!"

# Compilar archivos objeto
%.o: %.cpp
	@echo "Compilando $<..."
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpiar archivos compilados
clean:
	@echo "Limpiando archivos compilados..."
	rm -f $(OBJECTS) $(TARGET)
	@echo "Limpieza completa!"

# Limpiar todo incluyendo la base de datos
clean-all: clean
	@echo "Eliminando base de datos..."
	rm -f db/biblioteca.db
	@echo "Todo limpio!"

# Ejecutar el programa
run: $(TARGET)
	@echo "Ejecutando $(TARGET)..."
	./$(TARGET)

# Ayuda
help:
	@echo "Makefile para Sistema de Gestion de Biblioteca"
	@echo ""
	@echo "Comandos disponibles:"
	@echo "  make          - Compila el proyecto"
	@echo "  make clean    - Elimina archivos compilados"
	@echo "  make clean-all - Elimina archivos compilados y la base de datos"
	@echo "  make run      - Compila y ejecuta el programa"
	@echo "  make help     - Muestra esta ayuda"

.PHONY: all clean clean-all run help
