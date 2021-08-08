#include "funciones.h"

using namespace std;

int main() {
    char tablero[27];
    srand(time(NULL));
    saludarEInstruir();
    cout << endl;
    while (true) {
        movimientoJugadorUno(tablero);
        if (verificarGanador(tablero)) {
            mostrarTablero(tablero);
            cout << endl << "Jugador1 gana.";
            break;
        }
        movimientoJugadorDos(tablero);
        if (verificarGanador(tablero)) {
            mostrarTablero(tablero);
            cout << endl << "Jugador2 gana(computadora).";
            break;
        }
        mostrarTablero(tablero);
        cout << endl << endl;
    }
    return 0;
}
