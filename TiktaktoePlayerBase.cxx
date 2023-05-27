#include "TiktaktoePlayerBase.h"

TikTakToePlayerBase::TikTakToePlayerBase(){
}

void TikTakToePlayerBase::configure(unsigned int size, unsigned char symbol){
    this->size = size;
    this->symbol = symbol;
}

void TikTakToePlayerBase::play(unsigned int &x, unsigned int &y, unsigned int &z){
}

void TikTakToePlayerBase::report(const unsigned char &c){
}
