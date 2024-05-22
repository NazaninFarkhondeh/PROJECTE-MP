#include <string>
#include "Joc.h"
#include "InfoJoc.h"
using namespace std;

class Partida {
public:
    Partida();
    void inicialitza(int mode, const string& fitxerInicial, const string& fitxerFigures, const string& fitxerMoviments);
    void actualitza(double deltaTime);

private:
    Joc m_joc;
    int m_puntuacio;
    int m_nivell;
    int m_mode;
    double m_temps;
    list<Figura> m_figures;
    list<TipusMoviment> m_moviments;
};
