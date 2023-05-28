#include "TiktaktoeBoard.h"

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

/**
 * @brief Asignación de los jugadores al tablero
 *
 * @param playerX Jugador con el caracter X
 * @param playerO Jugador con el caracter Y
**/
void TiktaktoeBoard::setPlayers(TiktaktoePlayerBase *playerX, TiktaktoePlayerBase *playerO){
    this->playerX = playerX;
    this->playerX->configure(this->size, 'X');
    this->playerO = playerO;
    this->playerO->configure(this->size, 'O');
}

/**
 * @brief Accessor para el tamaño del tablero
 *
 * @return Tamaño del tablero
**/
const unsigned int& TiktaktoeBoard::getSize(){
    return this->size;
};

/**
 * @brief Reporta si alguno de los 2 jugadores ha ganado el juego
 *
 * @return Estado de los dos jugadores. Retorna si uno u otro ha ganado
**/
bool TiktaktoeBoard::have_won() const{
    return this->playerX->getWon() || this->playerO->getWon();
}

/**
 * @brief Reporta si hay empate
 *
 * @return Estado del tablero. Reporta si hay o no empate
**/
bool TiktaktoeBoard::have_tie() const{
    return this->tie;
}

unsigned char TiktaktoeBoard::click(unsigned int x, unsigned int y, unsigned int z){
    // Que es lo que hace un click de un jugador en el tablero
}

void TiktaktoeBoard::step(){
    unsigned int x, y, z;
    this->playerX->play(x,y,z);
    this->playerX->report(this->click(x, y, z));

    this->playerO->play(x,y,z);
    this->playerO->report((this->click(x, y, z)));
}

void TiktaktoeBoard::toStream(std::ostream &out) const{
    //Como deberia estarse imprimiendo el tablero
    for(unsigned int i = 0; i < this->size; ++i){
        out << "Tablero # " << i + 1;
        out << std::endl;
        for(unsigned int j = 0; j < this->size; ++j){
            out << "+";
            for(unsigned int k = 0; k < this->size; ++k){
                out << "===+";
            }
            out << std::endl;
            out << "|";
            for(unsigned int k = 0; k < this->size; ++k){
                out << " " << " " << " |";
            }
            out << std::endl;
            out << "+";
            for(unsigned int k = 0; k < this->size; ++k){
                out << "===+";
            }
            out << std::endl;
        }
    }
}
