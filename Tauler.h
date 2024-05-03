#ifndef TAULER_H
#define TAULER_H
#include "Figura.h"
#include <vector>
#include <string> // Asegúrate de incluir <string> para usar std::string

const int MAX_FILA = 8;
const int MAX_COL = 8;

class Tauler
{
    
    private:
    std::vector<std::vector<char>> caselles; // Matriz para representar el tauler

public:
    Tauler(); // Constructor inicializa el tauler con casillas vacías
    void mostrar(); // Método para mostrar el tauler en la consola
    void setCasella(int fila, int columna, char valor); // Método para establecer el valor de una casilla
    bool casellaOcupada(int fila, int columna) const; // Verificar si una casilla está ocupada
    void escriuTauler(const std::string& nomFitxer); // Declaración de la función escriuTauler
    int eliminarFilesCompletades();
    void eliminarFila(int fila);
    void desplazarFilasSuperiores(int fila);
  
};
#endif
