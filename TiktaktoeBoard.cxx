#include "TiktaktoeBoard.h"
#include "TiktaktoePlayerBase.h"


/**
 * @brief Constructor del tablero de juego
 * 
 * @param size Tamaño del tablero de juego
**/
TiktaktoeBoard::TiktaktoeBoard(unsigned int size){
    this->size = size;
    this->boxes.resize(size * size * size, ' ');
    this->tie = false;
}

