#include "funciones.h"
using namespace std;

bool verificarSiLegal (int cellNbre, char tablero[]) {
    return (cellNbre > 0 && cellNbre < 28 && tablero[cellNbre-1]!='X' && tablero[cellNbre-1]!='O');
}

void mostrarEspacios (int a, int b, char tablero[]) {
    //Display X or O, otherwise cell number
    for (int i = a; i <= b; i++) {
        switch (tablero[i - 1]) {
            case 'X':
                cout << 'X';
                break;
            case 'O':
                cout << 'O';
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
    //Check rows like 1-2-3
    for (int i = 0; i <=24; i+=3) {
        int player = 0;
        int cpu = 0;
        for (int j=i; j<i+3; j++) {
            switch (tablero[j]) {
                case 'X':
                    player++;
                    break;
                case 'O':
                    cpu++;
            }
        }
        if (player==3)
            return 'p';
        if (cpu==3)
            return 'c';
    }
    return 'n';
}

char verificarColumna (char tablero[]) {
    //Check columns like 1-4-7
    for (int i=0; i<=18; i+=9) {
        for (int j = i; j < i + 3; j++) {
            int player = 0;
            int cpu = 0;
            for (int k=j; k<=j+6; k+=3) {
                switch (tablero[k]) {
                    case 'X':
                        player++;
                        break;
                    case 'O':
                        cpu++;
                }
            }
            if (player == 3)
                return 'p';
            if (cpu == 3)
                return 'c';
        }
    }
    return 'n';
}

char verificarDiagonal (char tablero[]) {
    //Check rightward diagonals, e.g. 1-5-9
    for (int i = 0; i <= 18; i += 9) {
        int player = 0;
        int cpu = 0;
        for (int j = i; j <= i + 8; j += 4) {
            switch (tablero[j]) {
                case 'X':
                    player++;
                    break;
                case 'O':
                    cpu++;
            }
        }
        if (player == 3)
            return 'p';
        if (cpu == 3)
            return 'c';
    }
    //Check leftward diagonals, e.g. 3-5-7
    for (int i=2; i<=20; i+=9) {
        int player = 0;
        int cpu = 0;
        for (int j = i; j <= i + 4; j += 2) {
            switch (tablero[j]) {
                case 'X':
                    player++;
                    break;
                case 'O':
                    cpu++;
            }
        }
        if (player == 3)
            return 'p';
        if (cpu == 3)
            return 'c';
    }
    return 'n';
}

char verificarAdyacente (char tablero[]) {
    //Check for patterns like 1-9-19 (same cell on each board)
    for (int i = 0; i < 9; i++) {
        int player = 0;
        int cpu = 0;
        for (int j = i; j <= i + 18; j += 9) {
            switch (tablero[j]) {
                case 'X':
                    player++;
                    break;
                case 'O':
                    cpu++;
            }
        }
        if (player == 3)
            return 'p';
        if (cpu == 3)
            return 'c';
    }
    return 'n';
}

char verificarLineasOblicuas (char tablero[]) {
    //Check for patterns like 1-11-21 (row across all 3 boards)
    for (int i=0; i<=6; i+=3) {
        int player=0;
        int cpu=0;
        for (int j=i; j<=i+20; j+=10) {
            switch (tablero[j]) {
                case 'X':
                    player++;
                    break;
                case 'O':
                    cpu++;
            }
        }
        if (player==3)
            return 'p';
        if (cpu==3)
            return 'c';
    }
    //Check for patterns like 1-13-25 (column across all 3 boards)
    for (int i=0; i<3; i++) {
        int player=0;
        int cpu=0;
        for (int j=i; j<=i+24; j+=12) {
            switch (tablero[j]) {
                case 'X':
                    player++;
                    break;
                case 'O':
                    cpu++;
            }
        }
        if (player==3)
            return 'p';
        if (cpu==3)
            return 'c';
    }
    //Check for patterns 1-14-27 and 3-14-25
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
    //Check each row
    switch (verificarFila(tablero)) {
        case 'p':
            return true;
        case 'c':
            return true;
    }
    //Check each column
    switch (verificarColumna(tablero)) {
        case 'p':
            return true;
        case 'c':
            return true;
    }
    //Check each diagonal
    switch (verificarDiagonal(tablero)) {
        case 'p':
            return true;
        case 'c':
            return true;
    }
    //Check each adjacent pattern e.g. 1-10-19
    switch (verificarAdyacente(tablero)) {
        case 'p':
            return true;
        case 'c':
            return true;
    }
    //Check each skew line e.g. 1-11-21, 1-13-25, 1-14-27, 3-14-25
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
        cout << "Type a cell number: ";
        cin >> m;
        if (verificarSiLegal(m, tablero))
            break;
        cout << "Illegal move." << endl;
    }
        tablero[m - 1] = 'X';
}

void mostrarTablero (char tablero[]) {
    mostrarEspacios(1, 3, tablero);
    cout << "      ";
    mostrarEspacios(10, 12, tablero);
    cout << "      ";
    mostrarEspacios(19, 21, tablero);
    cout << endl << "---------------------------------------" << endl;
    mostrarEspacios(4, 6, tablero);
    cout << "      ";
    mostrarEspacios(13, 15, tablero);
    cout << "      ";
    mostrarEspacios(22, 24, tablero);
    cout << "      ";
    cout << endl << "---------------------------------------" << endl;
    mostrarEspacios(7, 9, tablero);
    cout << "      ";
    mostrarEspacios(16, 18, tablero);
    cout << "      ";
    mostrarEspacios(25, 27, tablero);
    cout << "      ";
}


void saludarEInstruir() {
    cout << "Buenos dias, bienvenido al reto Tic-Tac-Toe: Jugador 1 vs Jugador 2" << endl;
    cout << "El tablero está enumerado desde 1 hasta 27 como se puede observar a continuacion:" << endl;
    cout << "1 | 2 | 3      10 | 11 | 12      19 | 20 | 21" << endl;
    cout << "---------      ------------      ------------" << endl;
    cout << "4 | 5 | 6      13 | 14 | 15      22 | 23 | 24" << endl;
    cout << "---------      ------------      ------------" << endl;
    cout << "7 | 8 | 9      16 | 17 | 19      25 | 26 | 27" << endl;
    cout<< "\nJugador 1 va primero, luego el jugador dos hasta que haya un ganador." <<endl;
    cout<<"Simply input the number of the cell you want to occupy. Player’s move is marked with X. Computer’s move is marked with O."<< endl;
    cout << "Start? (y/n):";
    char ans;
    cin >> ans;
    char tablero[27];
    if (ans == 'y')
        mostrarTablero(tablero);
    else
        exit(0);
}

void movimientoJugadorDos(char tablero[]) {
    char test[27];
    for (int i = 0; i < 27; i++) {
        //Protect original board by copying it into another array
        copy(tablero, tablero+27, test);
        //Check if each move is legal using the test array, then commit if that cell is a win condition
        if (verificarSiLegal(i+1, test)) {
            //Check for computer's win condition
            test[i]='O';
            if (verificarGanador(test)) {
                tablero[i] = 'O';
                return;
            }
            //Check for player's win condition
            test[i]='X';
            if (verificarGanador(test)) {
                tablero[i]='O';
                return;
            }
        }
    }
    //If no cell is a win condition, make a random move
    for (int i=0; i<27; i++) {
        if (verificarSiLegal(i+1, tablero)) {
            tablero[i] = 'O';
            return;
        }
    }
}
