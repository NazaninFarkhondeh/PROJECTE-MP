#include "Figura.h"
#include "Tauler.h"

//modificando las coordenadas de la columna y fila de la figura.

Figura::Figura() : fila(0), columna(0) {
    // Inicializar la forma de la figura
}

void Figura::moureDreta() {
    columna++;
}

//decrementa la columna de la figura, moviéndola hacia la izquierda.
void Figura::moureEsquerra() {
    columna--;
}

void Figura::moureAvall() {
    fila++;
}

//Los métodos girarHorari y girarAntihorari giran la figura en sentido horario y antihorario respectivamente, 
//ajustando la forma de la figura en consecuencia.

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

//en la posición indicada por las coordenadas de fila y columna de la figura,
//verificando si cada casilla ocupada por la figura está vacía en el tablero y si no,
//establece el valor de esa casilla en el tablero

void Figura::mostrarEnTablero(Tauler& tauler) {
    for (size_t i = 0; i < forma.size(); ++i) {
        for (size_t j = 0; j < forma[i].size(); ++j) {
            if (forma[i][j] != ' ') {
                tauler.setCasella(fila + i, columna + j, forma[i][j]);
            }
        }
    }
}


//método esMovimentValid verifica si el movimiento de la figura es válido en el tablero Tauler, 
//comprobando si cada casilla que ocuparía la figura está vacía en el tablero. Si encuentra alguna casilla ocupada, 
//devuelve false, indicando una colisión, de lo contrario devuelve true, indicando un movimiento válido.

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
