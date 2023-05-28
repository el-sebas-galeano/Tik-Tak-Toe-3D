#include "HumanTiktaktoePlayer.h"
#include <cstring>
#include <cstdlib>
#include <iostream>

HumanTiktaktoePlayer::HumanTiktaktoePlayer() : TiktaktoePlayerBase(){
}

void HumanTiktaktoePlayer::play(unsigned int &x, unsigned int &y, unsigned int &z){
    char* input = new char[4];
    char posicionX;
    char* anchoTemporal = new char[2];
    std::cout << "Jugador " << this->symbol << ": Elige una casilla: ";
    std::cin >> input;
    if(this->verify(input)){
        posicionX = *(input);
        switch (posicionX) {
            case 'A':
                z = 0;
                break;
            case 'B':
                z = 1;
                break;
            case 'C':
                z = 2;
                break;
            case 'D':
                z = 3;
                break;
            case 'E':
                z = 4;
                break;
            case 'F':
                z = 5;
                break;
        }
        strcpy(anchoTemporal, (input + 1));
        *(anchoTemporal + 1) = '\0';
        y = atoi((const char *)(anchoTemporal)) - 1;
        x = atoi((const char *)(input + 2)) - 1;
    }
    delete[] anchoTemporal;
}

bool HumanTiktaktoePlayer::verify(char* entry){
    bool x = false, y = false, z = false;
    char letras[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    for(int iterador = 0; iterador < this->size; iterador++){
        if(*(entry) == *(letras + iterador)){
            x = true;
        }
    }
    char* anchoTemporal = new char[2];
    strcpy(anchoTemporal, (entry + 1));
    *(anchoTemporal + 1) = '\0';
    if(std::atoi((const char *)(anchoTemporal)) < this->size + 1 && std::atoi((const char *)(anchoTemporal)) > 0){
        y = true;
    }
    if(std::atoi((const char *)(entry + 2)) < this->size + 1 && std::atoi((const char *)(entry + 2)) > 0){
        z = true;
    }
    delete[] anchoTemporal;
    return x && y && z;
}