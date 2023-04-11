#include <iostream>
#include "funciones.h"
using namespace std;


int main(int argc, char* argv[]){
    int tamTablero;
    tamTablero = atoi(argv[1]);
    
    char*** tablero = crearTableroJuego(tamTablero);
    imprimirTableroJuego(tablero, tamTablero);
    return 1;
}