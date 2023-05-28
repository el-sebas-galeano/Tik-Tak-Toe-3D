#include "RandomTiktaktoePlayer.h"
#include <cstdlib>
#include <ctime>

RandomTiktaktoePlayer::RandomTiktaktoePlayer() : TiktaktoePlayerBase(){
}

void RandomTiktaktoePlayer::configure(
        unsigned int size,
        unsigned char symbol
        ) {
    TiktaktoePlayerBase::configure(size, symbol);
}

void RandomTiktaktoePlayer::play(unsigned int &x,
                                 unsigned int &y,
                                 unsigned int &z
                                 ){
    std::srand(std::time(0));
    int randomNumber = std::rand() % this->size - 1;
    x = randomNumber;
    randomNumber = std::rand() % this->size - 1;
    y = randomNumber;
    randomNumber = std::rand() % this->size - 1;
    z = randomNumber;
}

unsigned long long RandomTiktaktoePlayer::_idx(
        unsigned int &x,
        unsigned int &y,
        unsigned int &z
) const {
    return x + this->size *( y + this->size * z);
}