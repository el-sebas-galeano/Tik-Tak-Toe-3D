/*
 * Integrantes:
 *
 *  + Juan Sebastian Galeano Gonzalez
 *  + Daniel Florido Saez
 *
 **/
#include "TiktaktoeBoard.h"
#include "TiktaktoePlayerBase.h"
#include "HumanTiktaktoePlayer.h"
#include "RandomTiktaktoePlayer.h"
#include "CPUTiktaktoePlayer.h"
#include <iostream>
#include <string>


int main(int argc, char** argv){
    unsigned int size = 3;
    std::string pTypeX = "HUMAN";
    std::string pTypeO = "HUMAN";

    if(argc >= 2)
        pTypeX = argv[1];
    if(argc >= 3)
        pTypeO = argv[2];
    if(argc >= 4)
        size = std::atoi( argv[3] );
    if(!(size >= 3 && size <= 6)){
        size = 3;
        std::cout << "La dimension ingresada se encuentra fuera de rango.";
        std::cout << std::endl;
        std::cout << "Dimension por defecto:\t" << size;
        std::cout << std::endl;
    }

    TiktaktoeBoard* tiktaktoeBoard = new TiktaktoeBoard(size);

    TiktaktoePlayerBase* playerX = nullptr;
    TiktaktoePlayerBase* playerO = nullptr;

    if(pTypeX == "HUMAN" || pTypeX == "human" || pTypeX == "Human" || pTypeX == "H" || pTypeX == "h"){
        playerX = new HumanTiktaktoePlayer();
    } else if(pTypeX == "RANDOM" || pTypeX == "random" || pTypeX == "Random" || pTypeX == "R" || pTypeX == "r"){
        playerX = new RandomTiktaktoePlayer();
    } else if(pTypeX == "CPU" || pTypeX == "cpu" || pTypeX == "Cpu" || pTypeX == "C" || pTypeX == "c"){
        playerX = new CPUTiktaktoePlayer();
    }

    if(pTypeO == "HUMAN" || pTypeO == "human" || pTypeO == "Human" || pTypeO == "H" || pTypeO == "h"){
        playerO = new HumanTiktaktoePlayer();
    } else if(pTypeO == "RANDOM" || pTypeO == "random" || pTypeO == "Random" || pTypeO == "R" || pTypeO == "r"){
        playerO = new RandomTiktaktoePlayer();
    } else if(pTypeO == "CPU" || pTypeO == "cpu" || pTypeO == "Cpu" || pTypeO == "C" || pTypeO == "c"){
        playerO = new CPUTiktaktoePlayer();
    }

    tiktaktoeBoard->setPlayers(playerX, playerO);
    while((!tiktaktoeBoard->have_tie()) || !(tiktaktoeBoard->getPlayerX()->getWon() || tiktaktoeBoard->getPlayerO()->getWon())){
        std::cout << *tiktaktoeBoard << std::endl;
        tiktaktoeBoard->step(*playerX);
        std::cout << *tiktaktoeBoard << std::endl;
        tiktaktoeBoard->step(*playerO);
    }

    std::cout << *tiktaktoeBoard << std::endl;
    if(tiktaktoeBoard->getPlayerX()->getWon()){
        std::cout << "Player X gana.";
        std::cout << std::endl;
    }else if(tiktaktoeBoard->getPlayerO()->getWon()){
        std::cout << "Player O gana.";
        std::cout << std::endl;
    }
}