#include "Tauler.h"
#include <iostream>
#include <fstream>

Tauler::Tauler() {
    caselles.resize(MAX_FILA, std::vector<char>(MAX_COL, ' '));
}

void Tauler::mostrar() {
    for (int i = 0; i < MAX_FILA; ++i) {
        for (int j = 0; j < MAX_COL; ++j) {
            std::cout << caselles[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

void Tauler::setCasella(int fila, int columna, char valor) {
    caselles[fila][columna] = valor;
}

bool Tauler::casellaOcupada(int fila, int columna) const {
    return caselles[fila][columna] != ' ';
}

void Tauler::escriuTauler(const std::string& nomFitxer) {
    std::ofstream fitxer(nomFitxer);

    if (fitxer.is_open()) {
        for (int i = 0; i < MAX_FILA; ++i) {
            for (int j = 0; j < MAX_COL; ++j) {
                fitxer << caselles[i][j] << " ";
            }
            fitxer << std::endl;
        }
        fitxer.close();
    } else {
        std::cout << "No s'ha pogut obrir el fitxer per escriure." << std::endl;
    }
}

int Tauler::eliminarFilesCompletades() {
    int lineasCompletadas = 0;
    for (int fila = MAX_FILA - 1; fila >= 0; --fila) {
        bool filaCompleta = true;
        for (int columna = 0; columna < MAX_COL; ++columna) {
            if (!casellaOcupada(fila, columna)) {
                filaCompleta = false;
                break;
            }
        }
        if (filaCompleta) {
            eliminarFila(fila); // Eliminar la fila completada
            ++lineasCompletadas;
            // Desplazar hacia abajo las filas superiores
            desplazarFilasSuperiores(fila);
            // Reiniciar el ciclo para revisar la fila actual nuevamente
            ++fila;
        }
    }
    return lineasCompletadas;
}
