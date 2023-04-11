#ifndef FUNCIONES_H
#define FUNCIONES_H

char*** crearTableroJuego(int tamTablero);
void imprimirTableroJuego(char*** tablero, int tamTablero);
void eliminarTableroJuego(char*** tablero, int tamTablero);
bool turnoJugador(char simboloJugador, char*** tablero, int tamTablero);
bool comprobarTurnoJugador(char* turnoJugador, char* letras, int tamTablero);
bool modificarTableroJuego(char posicionX, int posicionY, int posicionZ, char*** tablero, int tamTablero, char simbolo);
bool verificarTablero(char simbolo, char*** tablero, int tamTablero);

#include "funciones.hxx"
#endif