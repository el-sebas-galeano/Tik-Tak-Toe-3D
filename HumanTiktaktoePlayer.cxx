#include "HumanTiktaktoePlayer.h"
#include <cstring>
#include <cstdlib>
#include <iostream>

HumanTiktaktoePlayer::HumanTiktaktoePlayer() : TiktaktoePlayerBase(){
}

void HumanTiktaktoePlayer::play(unsigned int &x, unsigned int &y, unsigned int &z, std::vector <unsigned char> boxes){
    char* input = new char[100];
    char posicionX;
    char* anchoTemporal = new char[2];
    do{
        std::cout << "Jugador " << this->symbol << ": Elige una casilla: ";
        std::cin >> input;
        if(strlen(input) > 4){
            std::cout << "Las coordenadas ingresadas se encuentran en el formato erroneo." << std::endl;
        }else {
            posicionX = *(input);
            switch (posicionX) {
                case 'a':
                    z = 0;
                    break;
                case 'A':
                    z = 0;
                    break;
                case 'b':
                    z = 1;
                    break;
                case 'B':
                    z = 1;
                    break;
                case 'c':
                    z = 2;
                    break;
                case 'C':
                    z = 2;
                    break;
                case 'd':
                    z = 3;
                    break;
                case 'D':
                    z = 3;
                    break;
                case 'e':
                    z = 4;
                    break;
                case 'E':
                    z = 4;
                    break;
                case 'f':
                    z = 5;
                    break;
                case 'F':
                    z = 5;
                    break;
            }
            strcpy(anchoTemporal, (input + 1));
            *(anchoTemporal + 1) = '\0';
            y = atoi((const char *) (anchoTemporal)) - 1;
            x = atoi((const char *) (input + 2)) - 1;
            if (!this->verify(input)) {
                std::cout << "Las coordenadas ingresadas se encuentran en el formato erroneo." << std::endl;
            }
        }
    } while (!this->verify(input));
    delete[] anchoTemporal;
}

bool HumanTiktaktoePlayer::verify(char* entry){
    bool x = false, y = false, z = false;
    char letrasMayusculas[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    char letrasMinusculas[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    for(int iterador = 0; iterador < this->size; iterador++){
        if((*(entry) == *(letrasMayusculas + iterador)) || (*(entry) == *(letrasMinusculas + iterador))){
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