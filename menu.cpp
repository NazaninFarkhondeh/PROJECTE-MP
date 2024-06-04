#include <iostream>
#include <string>
#include "Joc.h"

void menu() {
    Joc joc;
    std::string nomFitxer;
    int opcio;
    bool exit = false;

    while (!exit) {
        std::cout << "Menu del Joc de Tetris" << std::endl;
        std::cout << "1. Iniciar el joc" << std::endl;
        std::cout << "2. Girar figura" << std::endl;
        std::cout << "3. Moure figura a l'esquerra" << std::endl;
        std::cout << "4. Moure figura a la dreta" << std::endl;
        std::cout << "5. Baixar figura" << std::endl;
        std::cout << "6. Escriure tauler a fitxer" << std::endl;
        std::cout << "7. Sortir" << std::endl;
        std::cout << "Tria una opcio: ";
        std::cin >> opcio;

        switch (opcio) {
            case 1:
                std::cout << "Introdueix el nom del fitxer per inicialitzar el joc: ";
                std::cin >> nomFitxer;
                joc.inicialitza(nomFitxer);
                std::cout << "Joc inicialitzat." << std::endl;
                break;
            case 2:
                std::cout << "Girar figura (0: Horari, 1: Antihorari): ";
                int direccio;
                std::cin >> direccio;
                if (joc.giraFigura(static_cast<DireccioGir>(direccio))) {
                    std::cout << "Figura girada correctament." << std::endl;
                } else {
                    std::cout << "No s'ha pogut girar la figura." << std::endl;
                }
                break;
            case 3:
                if (joc.mouFigura(-1)) {
                    std::cout << "Figura moguda a l'esquerra correctament." << std::endl;
                } else {
                    std::cout << "No s'ha pogut moure la figura a l'esquerra." << std::endl;
                }
                break;
            case 4:
                if (joc.mouFigura(1)) {
                    std::cout << "Figura moguda a la dreta correctament." << std::endl;
                } else {
                    std::cout << "No s'ha pogut moure la figura a la dreta." << std::endl;
                }
                break;
            case 5:
                int lineasCompletades;
                lineasCompletades = joc.baixaFigura();
                std::cout << "Figura baixada. " << lineasCompletades << " files completades." << std::endl;
                break;
            case 6:
                std::cout << "Introdueix el nom del fitxer per escriure el tauler: ";
                std::cin >> nomFitxer;
                joc.escriuTauler(nomFitxer);
                std::cout << "Tauler escrit a fitxer." << std::endl;
                break;
            case 7:
                exit = true;
                std::cout << "Sortint del joc..." << std::endl;
                break;
            default:
                std::cout << "Opcio invalida. Si us plau, tria una opcio valida." << std::endl;
                break;
        }
    }
}
