#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Figura {
private:
    // Definir els atributs necessaris per a la figura
public:
    // Mètodes necessaris per a la figura
    // Constructor, mètodes per rotar, desplaçar, etc.
};

class Tauler {
private:
    int files;
    int columnes;
    vector<vector<int>> celles;

public:
    Tauler(int f, int c) : files(f), columnes(c), celles(f, vector<int>(c, 0)) {}
    }

    // Modificar el contingut del tauler
    // Afegir i eliminar files
    // Eliminar files completes i incrementar la puntuació
    // Tauler en un fitxer

    void escriuTauler(const string& nomFitxer) {
        ofstream fitxer(nomFitxer);

        if (fitxer.is_open()) {
            for (int i = 0; i < files; ++i) {
                for (int j = 0; j < columnes; ++j) {
                    fitxer << celles[i][j] << " ";
                }
                fitxer << endl;
            }
            fitxer.close();
        } else {
            cout << "No s'ha pogut obrir el fitxer." << endl;
        }
    }
};

class Joc {
private:
    Tauler tauler;
    // Altres mètodes necessaris per al joc

public:
    Joc(int f, int c) : tauler(f, c) {
    }

    // Mètodes per jugar el joc

    void escriuTauler(const string& nomFitxer) {
        tauler.escriuTauler(nomFitxer);
    }
};
