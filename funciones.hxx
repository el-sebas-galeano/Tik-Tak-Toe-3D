#include "funciones.h"
#include <iostream>
#include <string.h>
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
    char letras[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    for(int iteradorX = 0; iteradorX < tamTablero; iteradorX++){
        cout << iteradorX + 1;
        for(int iterador = 0; iterador < tamTablero; iterador++){
            cout <<"--"; 
        }
        cout << "\n\n  ";
        for(int iterador = 0; iterador < tamTablero; iterador++){
            cout << letras[iterador] << " "; 
        }
        cout << endl;    
        for(int iteradorY = 0; iteradorY < tamTablero; iteradorY++){
            cout << iteradorY + 1 << " ";    
            for(int iteradorZ = 0; iteradorZ < tamTablero; iteradorZ++){
                cout << *(*(*(tablero + iteradorX) + iteradorY) + iteradorZ) << " ";
            }        
            cout << endl;
        }
        cout << endl;
    }
}

/**
 * @brief Libera la memoria asignada al tablero de juego al inicio del programa
 * 
 * @param tablero Tablero de Juego
 * @param tamTablero Tamaño del tablero de Juego
*/
void eliminarTableroJuego(char*** tablero, int tamTablero){
    for(int iterador = 0; iterador < tamTablero; iterador++){
        for(int iteradorProfundidad = 0; iteradorProfundidad < tamTablero; iteradorProfundidad++){
               delete[] tablero[iterador][iteradorProfundidad];
        }
        delete[] tablero[iterador];
    }
    delete[] tablero;
}

bool turnoJugador(char simboloJugador, char*** tablero, int tamTablero){
    char* posicion = new char[4];
    char letras[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    bool turnoExitoso = false;
    char posicionX;
    int posicionY, posicionZ;
    char* anchoTemporal = new char[2];
    cout << "Inicia turno del jugador " << simboloJugador << endl;
    imprimirTableroJuego(tablero, tamTablero);

    while(!turnoExitoso){
        do{
            cout << "Elija las cordenadas de su eleccion en orden [ANCHO][ALTO][PROFUNDO]" << endl;
            cin >> posicion;
            if(!comprobarTurnoJugador(posicion, letras, tamTablero)){
                cout << "Formato Incorrecto.\n" << endl;    
            }
        }while(!comprobarTurnoJugador(posicion, letras, tamTablero));
        posicionX = *(posicion);
    
        strcpy(anchoTemporal, (posicion + 1));
        *(anchoTemporal + 1) = '\0';
        posicionY = atoi((const char *)(anchoTemporal));
        posicionZ = atoi((const char *)(posicion + 2));
        turnoExitoso = modificarTableroJuego(posicionX, posicionY, posicionZ, tablero, tamTablero, simboloJugador);
    }
    system("cls");
    cout << "La posicion que eligio es: " << posicionX << " ANCHO, " << posicionY <<
    " ALTO, " << posicionZ << " PROFUNDO." << endl;
    imprimirTableroJuego(tablero, tamTablero);
    system("pause");
    delete[] anchoTemporal;
    delete[] posicion;
}

bool comprobarTurnoJugador(char* turnoJugador, char* letras, int tamTablero){
    bool x = false, y = false, z = false;
    for(int iterador = 0; iterador < tamTablero; iterador++){
        if(*(turnoJugador) == *(letras + iterador)){
            x = true;
        }
    }
    char* anchoTemporal = new char[2];
    strcpy(anchoTemporal, (turnoJugador + 1));
    *(anchoTemporal + 1) = '\0';
    if(atoi((const char *)(anchoTemporal)) < tamTablero + 1 && atoi((const char *)(anchoTemporal)) > 0){
        y = true;
    }
    if(atoi((const char *)(turnoJugador + 2)) < tamTablero + 1 && atoi((const char *)(turnoJugador + 2)) > 0){
        z = true;
    }
    delete[] anchoTemporal;
    return x && y && z;
}

bool modificarTableroJuego(char posicionX, int posicionY, int posicionZ, char*** tablero, int tamTablero, char simbolo){
    bool comprobante = false;
    char letras[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    int conversionX = 0;
    for(int iterador = 0; iterador < tamTablero; iterador++){
        if(posicionX == letras[iterador]){
            conversionX = iterador + 1;
        }
    }  
    if(*(*(*(tablero + posicionZ - 1) + posicionY - 1) + conversionX - 1) == '-'){
        *(*(*(tablero + posicionZ - 1) + posicionY - 1) + conversionX - 1) = simbolo;
        comprobante = true;
    }else{
        cout << "No se puede elegir una posicion que ya haya sido elegida por otro jugador.\n" << endl;
    }
    return comprobante;
}