#include "Partida.h"
#include "InfoJoc.h"
#include "GraphicManager.h"

Partida::Partida()
{
    m_temps = 0;
    // Inicializar el atributo m_forma
    for (int i = 0; i < MIDA; i++)
        for (int j = 0; j < MIDA; j++)
            m_forma[i][j] = NO_COLOR;
    // Definir la forma de ejemplo
    m_forma[0][0] = COLOR_BLAUFOSC;
    m_forma[1][0] = COLOR_BLAUFOSC;
    m_forma[1][1] = COLOR_BLAUFOSC;
    m_forma[1][2] = COLOR_BLAUFOSC;
    m_fila = 1;
    m_columna = 5;
}

void Partida::actualitza(double deltaTime)
{
    // Incrementar el tiempo acumulado
    m_temps += deltaTime;
    
    // Actualizar la posición de la figura cada 0.5 segundos
    if (m_temps > 0.5) {
        if (m_fila < N_FILES_TAULER) // Verificar si no hemos llegado al fondo del tablero
            m_fila++; // Mover la figura hacia abajo
        m_temps = 0.0; // Reiniciar el tiempo
    }
    
    // Dibujar el fondo y el tablero
    GraphicManager::getInstance()->drawSprite(GRAFIC_FONS, 0, 0, false);
    GraphicManager::getInstance()->drawSprite(GRAFIC_TAULER, POS_X_TAULER, POS_Y_TAULER, false);
    
    // Dibujar la figura en su posición actual
    for (int i = 0; i < MIDA; i++) {
        for (int j = 0; j < MIDA; j++) {
            if (m_forma[i][j] != NO_COLOR) {
                // Calcular la posición en la pantalla para dibujar cada cuadrado de la figura
                float posX = POS_X_TAULER + ((m_columna + j) * MIDA_QUADRAT);
                float posY = POS_Y_TAULER + ((m_fila - 1 + i) * MIDA_QUADRAT);
                // Dibujar el cuadrado correspondiente al color de la figura
                switch (m_forma[i][j]) {
                    case COLOR_BLAUFOSC:
                        GraphicManager::getInstance()->drawSprite(GRAFIC_QUADRAT_BLAUFOSC, posX, posY, false);
                        break;
                    // Agregar casos para otros colores si es necesario
                    default:
                        break;
                }
            }
        }
    }
}
