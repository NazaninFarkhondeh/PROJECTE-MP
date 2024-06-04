#ifndef TETRIS_H
#define TETRIS_H

#include "Partida.h"
#include <forward_list>

class Tetris {
public:
    Tetris();

    void juga();
    void mostraPuntuacions();

private:
    Partida partida;
    std::forward_list<int> puntuacions;
};

#endif
