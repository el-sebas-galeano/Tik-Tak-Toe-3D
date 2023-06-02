#include "TiktaktoeBoard.h"
#include <iostream>
/**
 * @brief Constructor del tablero de juego
 * 
 * @param size Tamaño del tablero de juego
**/
TiktaktoeBoard::TiktaktoeBoard(
        unsigned int size
        ){
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
void TiktaktoeBoard::setPlayers(
        TiktaktoePlayerBase *playerX,
        TiktaktoePlayerBase *playerO
        ){
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

TiktaktoePlayerBase* TiktaktoeBoard::getPlayerX() {
    return this->playerX;
}

TiktaktoePlayerBase* TiktaktoeBoard::getPlayerO() {
    return this->playerO;
}

unsigned long long TiktaktoeBoard::getCheck(){
    return this->check;
}

void TiktaktoeBoard::setCheck(long long check) {
    this->check = check;
}
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
bool TiktaktoeBoard::have_tie(){
    if(this->check == (this->size * this->size * this->size)){
        this->tie = true;
    }
    return this->tie;
}

unsigned char TiktaktoeBoard::click(
        unsigned int x,
        unsigned int y,
        unsigned int z,
        char symbol
        ){
    /*system("PAUSE");
    system("cls");*/
    char letra;
    switch (z) {
        case 0:
            letra = 'A';
            break;
        case 1:
            letra = 'B';
            break;
        case 2:
            letra = 'C';
            break;
        case 3:
            letra = 'D';
            break;
        case 4:
            letra = 'E';
            break;
        case 5:
            letra = 'F';
            break;
        case 6:
            letra = 'G';
            break;
        default:
            // Manejar caso de índice inválido o agregar más casos según sea necesario
            break;
    }
    std::cout << "Jugador " << symbol << " juega " << letra << "'" << y + 1  << "'" << x + 1 << std::endl;
    this->boxes[this->_idx(x, y, z)] = symbol;
    this->setCheck(this->getCheck() + 1);
}

bool TiktaktoeBoard::verify(
        unsigned int x,
        unsigned int y,
        unsigned int z,
        char symbol
        ) {

    bool winner = true;

    // Comprobar X
    unsigned int i = 0;
    while (i < this->size) {
        if (this->boxes[this->_idx(i, y, z)] != symbol) {
            winner = false;
        }
        ++i;
    }
    if (winner) return true;

    // Comprobar Y
    i = 0;
    winner = true;
    while (i < this->size) {
        if (this->boxes[this->_idx(x, i, z)] != symbol) {
            winner = false;
        }
        ++i;
    }
    if (winner) return true;

    // Comprobar Z
    i = 0;
    winner = true;
    while (i < this->size) {
        if (this->boxes[this->_idx(x, y, i)] != symbol) {
            winner = false;
        }
        ++i;
    }
    if (winner) return true;

    //Comprobar diagonal Z constante
    i = 0;
    winner = true;
    while (i < this->size) {
        if (this->boxes[this->_idx(i, i, z)] != symbol) {
            winner = false;
        }
        ++i;
    }
    if (winner) return true;

    i = this->size - 1;
    winner = true;
    unsigned int j = 0;
    while (j < this->size) {
        if (this->boxes[this->_idx(i, j, z)] != symbol) {
            winner = false;
        }
        --i;
        ++j;
    }
    if(winner) return true;

    i = this->size - 1;
    winner = true;
    j = 0;
    while (j < this->size) {
        if (this->boxes[this->_idx(j, i, z)] != symbol) {
            winner = false;
        }
        --i;
        ++j;
    }
    if(winner) return true;

    //Comprobar diagonal X constante
    i = 0;
    winner = true;
    while(i < this->size){
        if (this->boxes[this->_idx(x,i,i)] != symbol) {
            winner = false;
        }
        ++i;
    }
    if(winner) return true;

    i = this->size - 1;
    j = 0;
    winner = true;
    while(j < this->size){
        if (this->boxes[this->_idx(x,i,j)] != symbol) {
            winner = false;
        }
        --i;
        ++j;
    }
    if(winner) return true;

    i = this->size - 1;
    j = 0;
    winner = true;
    while(j < this->size){
        if (this->boxes[this->_idx(x,j,i)] != symbol) {
            winner = false;
        }
        --i;
        ++j;
    }
    if(winner) return true;

    //Comprobar diagonal Y Constante
    i = 0;
    winner = true;
    while(i < this->size){
        if (this->boxes[this->_idx(i,y,i)] != symbol) {
            winner = false;
        }
        ++i;
    }
    if(winner) return true;

    i = this->size - 1;
    j = 0;
    winner = true;
    while(j < this->size){
        if (this->boxes[this->_idx(i,y,j)] != symbol) {
            winner = false;
        }
        --i;
        ++j;
    }
    if(winner) return true;

    i = this->size - 1;
    j = 0;
    winner = true;
    while(j < this->size){
        if (this->boxes[this->_idx(j,y,i)] != symbol) {
            winner = false;
        }
        --i;
        ++j;
    }
    if(winner) return true;

    //Comprobar diagonal +++
    i = 0;
    winner = true;
    while(i < this->size){
        if (this->boxes[this->_idx(i,i,i)] != symbol) {
            winner = false;
        }
        ++i;
    }
    if(winner) return true;

    //Comprobar diagonal ++-
    i = 0;
    j = this->size - 1;
    winner = true;
    while(i < this->size){
        if (this->boxes[this->_idx(i,i,j)] != symbol) {
            winner = false;
        }
        ++i;
        --j;
    }
    if(winner) return true;

    //Comprobar diagonal +-+
    i = 0;
    j = this->size - 1;
    winner = true;
    while(i < this->size){
        if (this->boxes[this->_idx(i,j,i)] != symbol) {
            winner = false;
        }
        ++i;
        --j;
    }
    if(winner) return true;

    //Comprobar diagonal +--
    i = 0;
    j = this->size - 1;
    winner = true;
    while(i < this->size){
        if (this->boxes[this->_idx(i,j,j)] != symbol) {
            winner = false;
        }
        ++i;
        --j;
    }
    if(winner) return true;

    //Comprobar diagonal -++
    i = 0;
    j = this->size - 1;
    winner = true;
    while(i < this->size){
        if (this->boxes[this->_idx(j,i,i)] != symbol) {
            winner = false;
        }
        ++i;
        --j;
    }
    if(winner) return true;

    //Comprobar diagonal -+-
    i = 0;
    j = this->size - 1;
    winner = true;
    while(i < this->size){
        if (this->boxes[this->_idx(j,i,j)] != symbol) {
            winner = false;
        }
        ++i;
        --j;
    }
    std::cout << 17 << std::endl;
    if(winner) return true;

    //Comprobar diagonal --+
    i = 0;
    j = this->size - 1;
    winner = true;
    while(i < this->size){
        if (this->boxes[this->_idx(j,j,i)] != symbol) {
            winner = false;
        }
        ++i;
        --j;
    }
    if(winner) return true;

    //Comprobar diagonal ---
    i = 0;
    j = this->size - 1;
    winner = true;
    while(i < this->size){
        if (this->boxes[this->_idx(j,j,j)] != symbol) {
            winner = false;
        }
        ++i;
        --j;
    }
    if(winner) return true;

    return winner;
}

void TiktaktoeBoard::step(TiktaktoePlayerBase& player){
    unsigned int x, y, z;
    player.play(x,y,z, this->boxes);
    player.report(this->click(x, y, z, player.getSymbol()));
    if(this->verify(x, y, z, player.getSymbol())){
        player.setWon(true);
    }
}

void TiktaktoeBoard::toStream(
        std::ostream &out
        ) const{
    char letras[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    for(unsigned int i = 0; i < this->size; ++i){
        out << "Tablero # " << i + 1;
        out << std::endl;
        out << std::endl;
        out << "+===+";
        for(unsigned int k = 0; k < this->size; ++k){
            out << "===+";
        }
        out << std::endl;
        out << "| / |";
        for(unsigned int j = 0; j < this->size; ++j){
            out << " " << letras[j] << " |";
        }
        out << std::endl;
        for(unsigned int j = 0; j < this->size; ++j){
            out << "+===+";
            for(unsigned int k = 0; k < this->size; ++k){
                out << "===+";
            }
            out << std::endl;
            out << "| " << j + 1 << " |";
            for(unsigned int k = 0; k < this->size; ++k){
                out << " " << this->boxes[this->_idx(i, j, k)] << " |";
            }
            out << std::endl;
        }
        out << "+===+";
        for(unsigned int k = 0; k < this->size; ++k){
            out << "===+";
        }
        out << std::endl;
        out << std::endl;
    }
}

unsigned long long TiktaktoeBoard::_idx(
        unsigned int &x,
        unsigned int &y,
        unsigned int &z
        ) const {
    return x + this->size *( y + this->size * z);
}

