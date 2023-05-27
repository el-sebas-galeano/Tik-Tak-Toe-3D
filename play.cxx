/*
 * Integrantes:
 *
 *  + Juan Sebastian Galeano Gonzalez
 *  + Daniel Florido Saez
 *
 **/

#include <iostream>
#include <string>
#include "TiktaktoeBoard.h"
#include "TiktaktoePlayerBase.h"

int main(int argc, char** argv){
    unsigned int size = 3;
    std::string pType = "HUMAN";

    if(argc < 2)
        exit(1);
    if(argc >= 2)
        pType = argv[1];
    if(argc >= 3)
        size = std::atoi( argv[2] );

    TiktaktoeBoard* tiktaktoeBoard = new TiktaktoeBoard(size);
    std::cout << *tiktaktoeBoard << std::endl;

    TikTakToePlayerBase* playerX = nullptr;
    TikTakToePlayerBase* playerO = nullptr;
}