#include "Tauler.h"
#include <iostream>

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
