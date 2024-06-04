#include "Tetris.h"
#include <iostream>
#include <fstream>
#include <algorithm> // Para std::sort

Tetris::Tetris() {
    // Leer la lista de puntuaciones históricas del archivo al inicio del programa
    std::ifstream inputFile("puntuacions.txt");
    if (inputFile.is_open()) {
        int score;
        while (inputFile >> score) {
            puntuacions.push_front(score);
        }
        inputFile.close();
    }
}

void Tetris::juga() {
    // Implementar la lógica del menú y la ejecución del juego
}

void Tetris::mostraPuntuacions() {
    // Mostrar la lista de puntuaciones históricas
    std::cout << "Puntuaciones históricas:\n";
    for (int score : puntuacions) {
        std::cout << score << std::endl;
    }
}
