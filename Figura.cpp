#include "Figura.h"
#include "Tauler.h"

Figura::Figura() : fila(0), columna(0) {
    // Inicializar la forma de la figura
}

void Figura::moureDreta() {
    columna++;
}

void Figura::moureEsquerra() {
    columna--;
}

void Figura::moureAvall() {
    fila++;
}

void Figura::girarHorari() {
    // Algoritmo para girar la figura en sentido horario
    std::vector<std::vector<char>> novaForma(forma[0].size(), std::vector<char>(forma.size()));
    for (size_t i = 0; i < forma.size(); ++i) {
        for (size_t j = 0; j < forma[i].size(); ++j) {
            novaForma[j][forma.size() - 1 - i] = forma[i][j];
        }
    }
    forma = novaForma;
}

void Figura::girarAntihorari() {
    // Algoritmo para girar la figura en sentido antihorario
    std::vector<std::vector<char>> novaForma(forma[0].size(), std::vector<char>(forma.size()));
    for (size_t i = 0; i < forma.size(); ++i) {
        for (size_t j = 0; j < forma[i].size(); ++j) {
            novaForma[forma[i].size() - 1 - j][i] = forma[i][j];
        }
    }
    forma = novaForma;
}

void Figura::mostrarEnTablero(Tauler& tauler) {
    for (size_t i = 0; i < forma.size(); ++i) {
        for (size_t j = 0; j < forma[i].size(); ++j) {
            if (forma[i][j] != ' ') {
                tauler.setCasella(fila + i, columna + j, forma[i][j]);
            }
        }
    }
}

bool Figura::esMovimentValid(Tauler& tauler) {
    for (size_t i = 0; i < forma.size(); ++i) {
        for (size_t j = 0; j < forma[i].size(); ++j) {
            if (forma[i][j] != ' ') {
                if (tauler.casellaOcupada(fila + i, columna + j)) {
                    return false; // Colisión con una casilla ocupada
                }
            }
        }
    }
    return true; // Movimiento válido
}
