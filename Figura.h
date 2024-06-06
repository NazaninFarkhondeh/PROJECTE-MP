#ifndef FIGURA_H
#define FIGURA_H
#include <vector>
using namespace std;

#include "Tauler.h"

typedef enum
{
    COLOR_NEGRE = 0,
    COLOR_GROC,
    COLOR_BLAUCEL,
    COLOR_MAGENTA,
    COLOR_TARONJA,
    COLOR_BLAUFOSC,
    COLOR_VERMELL,
    COLOR_VERD,
    NO_COLOR
} ColorFigura;


typedef enum
{
    NO_FIGURA = 0,
    FIGURA_O,
    FIGURA_I,
    FIGURA_T,
    FIGURA_L,
    FIGURA_J,
    FIGURA_Z,
    FIGURA_S,
} TipusFigura;

const int MAX_ALCADA = 4;
const int MAX_AMPLADA = 4;

typedef enum
{
    GIR_HORARI = 0,
    GIR_ANTI_HORARI
} DireccioGir;

class Tauler; // Declaración anticipada de la clase Tauler

class Figura
{
public:
    Figura(); // Constructor por defecto

    // Métodos para mover la figura
    void moureDreta();
    void moureEsquerra();
    void moureAvall();
    void girarHorari();
    void girarAntihorari();

    // Método para mostrar la figura en el tablero
    void mostrarEnTablero(Tauler& tauler);

    // Método para comprobar si el movimiento es válido
    bool esMovimentValid(Tauler& tauler);

private:
    int fila;
    int columna;
    std::vector<std::vector<char>> forma;
    Tauler* tauler; // Usamos un puntero a Tauler en lugar de una instancia
};


#endif
