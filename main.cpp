#include <iostream>
#include "funciones.h"
using namespace std;


int main(int argc, char* argv[]){
    int tamTablero;
    bool banderaGanador = false;
    tamTablero = atoi(argv[1]);
    if(argc > 2){
        cerr << "La cantidad de parametros ingresada es erronea." << endl;
        exit(1);
    }
    if(tamTablero > 6 || tamTablero < 3){
            cerr << "El tamano de tablero ingresado se encuentra fuera de rango." << endl;
            cerr << "Tamano minimo: 3. \t Tamano maximo: 6." << endl;
            exit(1);
    }
    char*** tablero = crearTableroJuego(tamTablero);
    do{
        system("cls");
        turnoJugador('X', tablero, tamTablero);
        system("cls");
        turnoJugador('O', tablero, tamTablero);
    }while (!banderaGanador);
    eliminarTableroJuego(tablero, tamTablero);
}