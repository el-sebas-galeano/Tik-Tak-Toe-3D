/*
 * Integrantes:
 *
 *  + Juan Sebastian Galeano Gonzalez
 *  + Daniel Florido Saez
 *
 **/
#include "TiktaktoeBoard.h"
#include <iostream>
#include <string>


int main(int argc, char** argv){
    unsigned int size = 3;
    std::string pType1 = "HUMAN";
    std::string pType2 = "HUMAN";

    if(argc >= 2)
        pType1 = argv[1];
    if(argc >= 3)
        pType2 = argv[2];
    if(argc >= 4)
        size = std::atoi( argv[3] );


    TiktaktoeBoard* tiktaktoeBoard = new TiktaktoeBoard(size);
    std::cout << *tiktaktoeBoard << std::endl;


}