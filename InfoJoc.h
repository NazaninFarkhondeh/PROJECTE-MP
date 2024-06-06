#ifndef INFO_JOC_H
#define INFO_JOC_H
#include "Figura.h"

typedef enum
{
    TECLA_ESQUERRA,
    TECLA_DRETA,
    TECLA_AMUNT,
    TECLA_ABAIX,
    TECLA_ESPAI,
    TECLA_ESCAPE,
    NO_TECLA
} TipusTecla;

const int N_TIPUS_FIGURES = 7;

// Tamany de la pantalla gràfica
const int SCREEN_SIZE_X = 600;
const int SCREEN_SIZE_Y = 700;

// Mida dels quadrats que formen el tauler
const int MIDA_QUADRAT = 26;

// Tamany del tauler
const int N_FILES_TAULER = 21;
const int N_COL_TAULER = 11;

// Posició del tauler a la pantalla
const int POS_X_TAULER = 120;
const int POS_Y_TAULER = 100;

#endif
