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

/**
 * @brief Flujo principal del juego, en el cual el jugador elige la posicion que desea en el tablero
 * donde se verifica si esta es correcta y se procede a su asignación.
 * 
 * @see comprobarTurnoJugador comprueba que la posicion ingresada por el jugador para el turno actual
 * se encuentra en el formato correcto.
 * 
 * @see verificarTablero verifica si el jugador ha completado la cantidad necesaria de casillas para 
 * darse por terminado el juego.
 * 
 * @param simboloJugador caracter que pertenece al jugador del turno utilizado para marcar las posiciones
 * que este elige en el tablero.
 * 
 * @param tablero Tablero de juego.
 * 
 * @param tamTablero Tamaño del tablero de juego.
 * 
 * @return verificarTablero bandera que indica si el jugador se ha convertido en ganador del juego.
*/
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
    return verificarTablero(simboloJugador, tablero, tamTablero);
    delete[] anchoTemporal;
    delete[] posicion;
}

/**
 * @brief Comprueba que la posicion ingresada por el jugador en el turno se encuentra en el formato correcto.
 * 
 * @param turnoJugador Posicion ingresada por el jugador en el turno dispuesta para ser verificada.
 * 
 * @param letras Arreglo de caracteres utilizados en la verificación de la posicoón ingresada.
 * 
 * @param tamTablero Tamaño del tablero de juego.
 * 
 * @return Bandera que indica si fue exitosa la comprobación de los caracteres ingresados por el jugador en el turno.
*/
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

/**
 * @brief Modifica el tablero de juego teniendo en cuenta la posición elegida por el jugador en el turno actual.
 * 
 * @param posicionX Caracter que indica la posición en el eje X ingresada por el jugador.
 * 
 * @param posicionY Numero que indica la posición en el eje Y ingresada por el jugador.
 * 
 * @param posicionZ Numero que indica la posición en el eje Z ingresada por el jugador.
 * 
 * @param tablero Tablero de juego
 * 
 * @param tamTablero Tamaño del tablero de juego.
 * 
 * @param simbolo Simbolo del jugador en el turno actual utilizado para modificar el tablero.
*/
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

bool verificarTablero(char simbolo, char*** tablero, int tamTablero){
    bool comprobante = false;
    for(int iteradorX = 0; iteradorX < tamTablero; iteradorX++){
        for(int iteradorY = 0; iteradorY < tamTablero; iteradorY++){
            for(int iteradorZ = 0; iteradorZ < tamTablero; iteradorZ++){
                if((iteradorX == 0 || iteradorY == 0 || iteradorZ == 0)){

                }
            }
        }
    }
    return comprobante;
}

bool verificarFilas(char*** tablero, int tamTablero, char simbolo, int x, int y, int z){

}

bool verificarColumnas(char*** tablero, int tamTablero, char simbolo, int x, int y, int z){

}

