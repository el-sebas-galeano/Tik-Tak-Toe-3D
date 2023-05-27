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

void TiktaktoeBoard::setPlayers(TiktaktoePlayerBase *playerX, TiktaktoePlayerBase *playerO){
    this->playerX = playerX;
    this->playerX->configure(this->size, 'X');
    this->playerO = playerO;
    this->playerO->configure(this->size, 'O');
}

const unsigned int& TiktaktoeBoard::getSize(){
    return this->size;
};

bool TiktaktoeBoard::have_won() const{
    return false;
}

bool TiktaktoeBoard::have_lose() const{
    return false;
}

unsigned char TiktaktoeBoard::click(){

}

void TiktaktoeBoard::step(TiktaktoePlayerBase *player){

}

void TiktaktoeBoard::toStream(std::ostream &out) const{

}
