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
                                 unsigned int &z
                                 ){
    std::srand(std::time(0));
    int randomNumber = std::rand() % this->size;
    x = randomNumber;
    randomNumber = std::rand() % this->size;
    y = randomNumber;
    randomNumber = std::rand() % this->size;
    z = randomNumber;
}

unsigned long long RandomTiktaktoePlayer::_idx(
        unsigned int &x,
        unsigned int &y,
        unsigned int &z
) const {
    return x + this->size *( y + this->size * z);
}