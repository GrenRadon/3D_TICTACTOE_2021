#ifndef FUNCIONES_H
#define FUNCIONES_H


#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <cstring>

#endif //TICTACTOE_FUNCTIONS_H

bool verificarSiLegal (int cellNbre, char tablero[]);
bool verificarGanador (char tablero[]);
void movimientoJugadorUno(char tablero[]);
void mostrarTablero (char tablero[]);
void saludarEInstruir();
void movimientoJugadorDos(char tablero[]);
