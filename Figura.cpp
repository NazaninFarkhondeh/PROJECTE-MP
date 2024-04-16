#include "Figura.h"

// Constructor de Figura
Figura::Figura(TipusFigura _tipus, ColorFigura _color, vector<vector<char>> _forma, int _fila, int _columna)
    : tipus(_tipus), color(_color), forma(_forma), fila(_fila), columna(_columna) {}
// Método para mostrar la figura en el tauler
void Figura::mostrarAlTauler(Tauler& tauler) {
    // Aquí deberías implementar la lógica para mostrar la figura en el tauler
    // Esto implica colocar los caracteres correspondientes en las posiciones adecuadas del tauler
    // Por ejemplo:
    for (int i = 0; i < forma.size(); ++i) {
        for (int j = 0; j < forma[i].size(); ++j) {
            if (forma[i][j] != ' ') {
                // Si el carácter en la forma de la figura no es un espacio, lo colocamos en el tauler
                // El cálculo de las posiciones reales en el tauler dependerá de la fila y columna actual de la figura
                tauler.setCasella(fila + i, columna + j, forma[i][j]);
            }
        }
    }
}

// Método para mover la figura horizontalmente
void Figura::moure(int desplacament) {
    // Aquí deberías implementar la lógica para mover la figura horizontalmente
    // Esto implica actualizar la columna de la figura según el desplazamiento recibido
    columna += desplacament;
}

// Método para girar la figura en sentido horario o antihorario
bool Figura::girar(DireccioGir direccio) {
    // Aquí deberías implementar la lógica para girar la figura en sentido horario o antihorario
    // Esto implica modificar la forma de la figura según la dirección de giro
    // Devuelve true si el giro fue exitoso, false en caso contrario
    // Implementación de ejemplo:
    if (direccio == GIR_HORARI) {
        // Implementar el giro en sentido horario
    } else {
        // Implementar el giro en sentido antihorario
    }
    // Devolver false si el giro no se pudo realizar (por ejemplo, si la figura colisiona con otra figura o los límites del tauler)
    return true; // Modifica este valor según sea necesario
}
