#include "RandomTiktaktoePlayer.h"
#include <cstdlib>
#include <ctime>

RandomTiktaktoePlayer::RandomTiktaktoePlayer() : TiktaktoePlayerBase(){
}

void RandomTiktaktoePlayer::configure(
        unsigned int size,
        unsigned char symbol
        ) {
    this->size = size;
    this->symbol = symbol;
}

void RandomTiktaktoePlayer::play(unsigned int &x,
                                 unsigned int &y,
                                 unsigned int &z,
                                 std::vector <unsigned char> boxes
                                 ){
    std::srand(std::time(0));
    int randomNumber;
    do{
        randomNumber = std::rand() % (this->size * this->size * this->size);
    }while(boxes[randomNumber] == 'X' || boxes[randomNumber] == 'O');
    this->_idx(x, y, z, randomNumber);
}

unsigned long long RandomTiktaktoePlayer::_idx(
        unsigned int &x,
        unsigned int &y,
        unsigned int &z,
        unsigned int number
) const {
    unsigned int n = this->size;
    z = number / (n * n);
    number -= z * (n * n);

    y = number / n;
    number -= y * n;

    x = number;
}