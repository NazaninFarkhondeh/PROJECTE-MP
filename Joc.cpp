#include "Joc.h"
#include <fstream>

void Joc::inicialitza(const std::string& nomFitxer) {
    // Cargar tablero
    tauler = Tauler();
    tauler.escriuTauler(nomFitxer);
}

bool Joc::giraFigura(DireccioGir direccio) {

    // Girar la figura (si se puede)
    if (figura.esMovimentValid(tauler)) {
        if (direccio == GIR_HORARI) {
            figura.girarHorari();
        }
        else if (direccio == GIR_ANTI_HORARI) {
            figura.girarAntihorari();
        }
        return true;
    }
    else {
        return false;
    }
}

bool Joc::mouFigura(int dirX) {

    // Mover lateralmente (si se puede)

    figura.moureEsquerra();
    if (dirX > 0) {
        figura.moureDreta();
    }
    return figura.esMovimentValid(tauler);
}

int Joc::baixaFigura() {

    // Mover hacia abajo (si valido) + lineas completadas

    int lineasCompletadas = 0;
    if (figura.esMovimentValid(tauler)) {
        figura.moureAvall();
    }
    else {
        figura.mostrarEnTablero(tauler);
        lineasCompletadas = tauler.eliminarFilesCompletades();
        // Colocar una nueva figura en la parte superior del tablero
        // Si no es posible, indicar fin de juego
    }
    return lineasCompletadas;
}

void Joc::escriuTauler(const std::string& nomFitxer) {
    // Escribir el estado del tablero
    tauler.escriuTauler(nomFitxer);
}
