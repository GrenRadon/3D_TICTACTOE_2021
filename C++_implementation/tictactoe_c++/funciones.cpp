#include "funciones.h"

using namespace std;

bool verificarSiLegal (int cellNbre, char tablero[]) {
    return (cellNbre > 0 && cellNbre < 28 && tablero[cellNbre-1]!='X' && tablero[cellNbre-1]!='O');
}

void mostrarEspacios (int a, int b, char tablero[]) {
    //Mostrar X o O, En caso contrario, el número de celda
    for (int i = a; i <= b; i++) {
        switch (tablero[i - 1]) {
            case 'X':
                cout << "\033[1;31mX\033[0m";
                break;
            case 'O':
                cout << "\033[1;34mO\033[0m";
                break;
            default:
                cout << i;
        }
        if (i==b)
            break;
        cout << " | ";
    }
}

char verificarFila (char tablero[]) {
    //Verificar las filas como e.g 1-2-3
    for (int i = 0; i <=24; i+=3) {

        int jugadoruno = 0;
        int cpu = 0;
        for (int j=i; j<i+3; j++) {

            switch (tablero[j]) {
                case 'X':
                    jugadoruno++;
                    break;
                case 'O':
                    cpu++;
            }
        }
        if (jugadoruno==3)
            return 'p';
        if (cpu==3)
            return 'c';
    }
    return 'n';
}

char verificarColumna (char tablero[]) {
    //Verificar las columnas e.g 1-4-7
    for (int i=0; i<=18; i+=9) {
        for (int j = i; j < i + 3; j++) {
            int jugadoruno = 0;
            int cpu = 0;
            for (int k=j; k<=j+6; k+=3) {
                switch (tablero[k]) {
                    case 'X':
                        jugadoruno++;
                        break;
                    case 'O':
                        cpu++;
                }
            }
            if (jugadoruno == 3)
                return 'p';
            if (cpu == 3)
                return 'c';
        }
    }
    return 'n';
}

char verificarDiagonal (char tablero[]) {
    //Verificar las diagonales hacia la derecha, e.g. 1-5-9
    for (int i = 0; i <= 18; i += 9) {
        int jugadoruno = 0;
        int cpu = 0;
        for (int j = i; j <= i + 8; j += 4) {
            switch (tablero[j]) {
                case 'X':
                    jugadoruno++;
                    break;
                case 'O':
                    cpu++;
            }
        }
        if (jugadoruno == 3)
            return 'p';
        if (cpu == 3)
            return 'c';
    }
    //Verificar las diagonales hacia la izquierda, e.g. 3-5-7
    for (int i=2; i<=20; i+=9) {
        int jugadoruno = 0;
        int cpu = 0;
        for (int j = i; j <= i + 4; j += 2) {
            switch (tablero[j]) {
                case 'X':
                    jugadoruno++;
                    break;
                case 'O':
                    cpu++;
            }
        }
        if (jugadoruno == 3)
            return 'p';
        if (cpu == 3)
            return 'c';
    }
    return 'n';
}

char verificarAdyacente (char tablero[]) {
    //Verificar patrones como 1-9-19 (igual celda en cada tablero)
    for (int i = 0; i < 9; i++) {
        int jugadoruno = 0;
        int cpu = 0;
        for (int j = i; j <= i + 18; j += 9) {
            switch (tablero[j]) {
                case 'X':
                    jugadoruno++;
                    break;
                case 'O':
                    cpu++;
            }
        }
        if (jugadoruno == 3)
            return 'p';
        if (cpu == 3)
            return 'c';
    }
    return 'n';
}

char verificarLineasOblicuas (char tablero[]) {
    //Verificar patrones como 1-11-21 (fila en las 3 tablas)
    for (int i=0; i<=6; i+=3) {
        int jugadoruno=0;
        int cpu=0;
        for (int j=i; j<=i+20; j+=10) {
            switch (tablero[j]) {
                case 'X':
                    jugadoruno++;
                    break;
                case 'O':
                    cpu++;
            }
        }
        if (jugadoruno==3)
            return 'p';
        if (cpu==3)
            return 'c';
    }
    //Verificar patrones como 1-13-25 (columna en las 3 tablas)
    for (int i=0; i<3; i++) {
        int jugadoruno=0;
        int cpu=0;
        for (int j=i; j<=i+24; j+=12) {
            switch (tablero[j]) {
                case 'X':
                    jugadoruno++;
                    break;
                case 'O':
                    cpu++;
            }
        }
        if (jugadoruno==3)
            return 'p';
        if (cpu==3)
            return 'c';
    }
    //Verificar patrones 1-14-27 y 3-14-25
    if (tablero[0]=='X' && tablero[13]=='X' && tablero[26]=='X')
        return 'p';
    if (tablero[0]=='O' && tablero[13]=='O' && tablero[26]=='O')
        return 'c';
    if (tablero[2]=='X' && tablero[13]=='X' && tablero[24]=='X')
        return 'p';
    if (tablero[2]=='O' && tablero[13]=='O' && tablero[24]=='O')
        return 'c';
    return 'n';
}

bool verificarGanador (char tablero[]) {
    //Verificar cada fila
    switch (verificarFila(tablero)) {
        case 'p':
            return true;
        case 'c':
            return true;
    }
    //Verificar cada columna
    switch (verificarColumna(tablero)) {
        case 'p':
            return true;
        case 'c':
            return true;
    }
    //Verificar cada diagonal
    switch (verificarDiagonal(tablero)) {
        case 'p':
            return true;
        case 'c':
            return true;
    }
    //Verificar cada patron adyacente e.g. 1-10-19
    switch (verificarAdyacente(tablero)) {
        case 'p':
            return true;
        case 'c':
            return true;
    }
    //Verificar cada línea oblicua e.g. 1-11-21, 1-13-25, 1-14-27, 3-14-25
    switch (verificarLineasOblicuas(tablero)) {
        case 'p':
            return true;
        case 'c':
            return true;
    }
    return false;
}

void movimientoJugadorUno(char tablero[]) {
    int m=1;
    while(true) {
        cout << "Jugador1, digite un numero de celda: ";
        cin >> m;
        if (verificarSiLegal(m, tablero))
            break;
        cout << "Movimiento Ilegal." << endl;
    }
        tablero[m - 1] = 'X';
}

void mostrarTablero (char tablero[]) {
    mostrarEspacios(1, 3, tablero);
    cout << "      ";
    mostrarEspacios(10, 12, tablero);
    cout << "      ";
    mostrarEspacios(19, 21, tablero);
    cout << endl << "----------------------------------------------" << endl;
    mostrarEspacios(4, 6, tablero);
    cout << "      ";
    mostrarEspacios(13, 15, tablero);
    cout << "      ";
    mostrarEspacios(22, 24, tablero);
    cout << "      ";
    cout << endl << "----------------------------------------------" << endl;
    mostrarEspacios(7, 9, tablero);
    cout << "      ";
    mostrarEspacios(16, 18, tablero);
    cout << "      ";
    mostrarEspacios(25, 27, tablero);
    cout << "      ";
}


void saludarEInstruir() {
    cout << "Buenos dias, bienvenido al reto Tres en linea: Jugador 1 vs Jugador 2" << endl;
    cout << "El tablero está enumerado desde 1 hasta 27 como se puede observar a continuacion:" << endl;
    cout << "1 | 2 | 3      10 | 11 | 12      19 | 20 | 21" << endl;
    cout << "---------      ------------      ------------" << endl;
    cout << "4 | 5 | 6      13 | 14 | 15      22 | 23 | 24" << endl;
    cout << "---------      ------------      ------------" << endl;
    cout << "7 | 8 | 9      16 | 17 | 19      25 | 26 | 27" << endl;
    cout<< "\nJugador 1 va primero, luego el jugador dos hasta que haya un ganador." <<endl;
    cout<<"Simplemente debe ingresar el número de la celda la cual desea ocupar. Movimientos del jugaodr uno son marcados con 'X'. Movimientos del jugador dos son marcados con 'O'."<< endl;
    cout << "Desea iniciar? (s/n):";
    char ans;
    cin >> ans;
    char tablero[27];
    if (ans == 's')
        mostrarTablero(tablero);
    else
        exit(0);
}

void movimientoJugadorDos(char tablero[]) {
    int m=1;
    while(true) {
        cout << "Jugador2, digite un numero de celda: ";
        cin >> m;
        if (verificarSiLegal(m, tablero))
            break;
        cout << "Movimiento Ilegal." << endl;
    }
        tablero[m - 1] = 'O';
}
