#include "funciones.h"
#include <iostream>
using namespace std;

/**
 * @brief Crea el tablero de juego teniendo en cuenta el tamaño ingresado
 * como argumento inicialmente por el usuario
 * 
 * @param tamTablero Tamaño del tablero ingresado para el usuario
 * 
 * @return Tablero con memoria reservada según el tamaño ingresado por el usuario
**/
char*** crearTableroJuego(int tamTablero){
    char*** tableroTemp;
    tableroTemp = new char**[tamTablero];
    for(int iterador = 0; iterador < tamTablero; iterador++){
        *(tableroTemp + iterador) = new char*[tamTablero];
        for(int iteradorProfundidad = 0; iteradorProfundidad < tamTablero; iteradorProfundidad++){
            *(*(tableroTemp + iterador) + iteradorProfundidad) = new char[tamTablero];
        }
    }
    for(int iteradorX = 0; iteradorX < tamTablero; iteradorX++){
        for(int iteradorY = 0; iteradorY < tamTablero; iteradorY++){
            for(int iteradorZ = 0; iteradorZ < tamTablero; iteradorZ++){
                *(*(*(tableroTemp + iteradorX) + iteradorY) + iteradorZ) = '-';
            }        
        }
    }
    return tableroTemp;
}

/**
 * @brief Imprime el tablero de juego
 * 
 * @param tablero Tablero de juego
 * @param tamTablero Tamaño del tablero de juego
*/
void imprimirTableroJuego(char*** tablero, int tamTablero){
    for(int iteradorX = 0; iteradorX < tamTablero; iteradorX++){
        for(int iteradorY = 0; iteradorY < tamTablero; iteradorY++){
            for(int iteradorZ = 0; iteradorZ < tamTablero; iteradorZ++){
                cout << *(*(*(tablero + iteradorX) + iteradorY) + iteradorZ) << " ";
            }        
            cout << endl;
        }
        cout << endl;
    }
}