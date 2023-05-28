#include "TiktaktoePlayerBase.h"

/**
 * @brief Constructor del jugador base.
**/
TiktaktoePlayerBase::TiktaktoePlayerBase(){
}

/**
 * @brief Reporta el estado del jugador.
 *
 * @return Estado del jugador. Retorna si este ha ganado.
**/
bool TiktaktoePlayerBase::getWon(){
    return this->won;
}

/**
 * @brief Configuracion inicial del jugador base.
 *
 * @param size Tamaño del tablero de Tiktaktoe3D.
 * @param symbol Símbolo asignado al jugador.
 * **/
void TiktaktoePlayerBase::configure(unsigned int size, unsigned char symbol){
    this->size = size;
    this->symbol = symbol;
    this->won = false;
}

/**
 * @brief El jugador decide cual será su próxima casilla elegida.
 *
 * @param x Coordenada de la casilla elegida en el eje x.
 * @param y Coordenada de la casilla elegida en el eje y.
 * @param z Coordenada de la casilla elegida en el eje z.
**/
void TiktaktoePlayerBase::play(unsigned int &x, unsigned int &y, unsigned int &z){

}


/**
 * @brief Actualiza las probabilidades de las opciones cuando un jugador realiza un movimiento.
 *
 * @param c Reporte.
**/
void TiktaktoePlayerBase::report(const unsigned char &c){
    //  Actualiza las probabilidades de las opciones cuando un jugador realiza un movimiento
}
