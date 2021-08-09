import numpy as np


def verificarFila (tablero):
    ##Verificar las filas como e.g 1-2-3
    for i in range(0,25):
        jugadoruno = 0
        cpu = 0
        for j in range(i,i+3):
            if(tablero[j]=="X"):
                jugadoruno+=1
                break;
            elif(tablero[j]=='O'):
                cpu+=1
        if (jugadoruno==3):
            return 'p'
        if (cpu==3):
            return 'c'
        i+=3
    return 'n'

def verificarColumna (tablero):
    ##Verificar las columnas e.g 1-4-7
    for i in range(0,19):

        for j in range(i,i+3):
            jugadoruno = 0
            cpu = 0
            for k in range(j,j+7):

                if(tablero[k]=='X'):
                    jugadoruno+=1
                    break;
                elif(tablero[k]=='O'):
                    cpu+=1
                k+=3

            if(jugadoruno==3):
                return 'p'
            if(cpu == 3):
                return 'c'
        i+=9
    return 'n'

def verificarDiagonal (tablero):
    ##Verificar las diagonales hacia la derecha, e.g. 1-5-9
    for i in range(0,19):

        jugadoruno = 0
        cpu = 0
        for j in range(i,i+9):

            if(tablero[j]=='X'):
                jugadoruno+=1
                break;
            if(tablero[j]=='O'):
                cpu+=1
            j+=4
        if (jugadoruno == 3):
            return 'p'
        if (cpu == 3):
            return 'c'
        i+=9
    ##Verificar las diagonales hacia la izquierda, e.g. 3-5-7
    for i in range(2,21):

        jugadoruno = 0
        cpu = 0;
        for j in range(i,i+5):

            if(tablero[j]=='X'):
                jugadoruno+=1
                break;
            elif(tablero[j]=='O'):
                cpu+=1
            j+=2
        if (jugadoruno == 3):
            return 'p'
        if (cpu == 3):
            return 'c'
        i+=9
    return 'n'


def verificarAdyacente (tablero):
    ##Verificar patrones como 1-9-19 (igual celda en cada tablero)
    for i in range(0,9):
        jugadoruno = 0
        cpu = 0
        for j in range(i,i+19):

            if(tablero[j]=='X'):
                jugadoruno+=1
                break;
            elif(tablero[j]=='O'):
                cpu+=1
            j+=9
        if (jugadoruno == 3):
            return 'p'
        if (cpu == 3):
            return 'c'
    return 'n'


def verificarLineasOblicuas (tablero):
    ##Verificar patrones como 1-11-21 (fila en las 3 tablas)
    for i in range(0,7):

        jugadoruno=0
        cpu=0
        for j in range(i,i+21):

            if(tablero[j]=='X'):
                jugadoruno+=1
                break;
            elif(tablero[j]=='O'):
                cpu+=1
            j+=10

        if (jugadoruno==3):
            return 'p'
        if (cpu==3):
            return 'c'
        i+=3
    ##Verificar patrones como 1-13-25 (columna en las 3 tablas)

    for i in range(0,3):
        jugadoruno=0
        cpu=0
        for j in range(i,i+25):

            if(tablero[j]=='X'):
                jugadoruno+=1
                break;
            elif(tablero[j]=='O'):
                cpu+=1
            j+=12

        if (jugadoruno==3):
            return 'p'
        if (cpu==3):
            return 'c'

    ##Verificar patrones 1-14-27 y 3-14-25
    if(tablero[0]=='X' and tablero[13]=='X' and tablero[26]=='X'):
        return 'p'
    if(tablero[0]=='O' and tablero[13]=='O' and tablero[26]=='O'):
        return 'c'
    if(tablero[2]=='X' and tablero[13]=='X' and tablero[24]=='X'):
        return 'p'
    if (tablero[2]=='O' and tablero[13]=='O' and tablero[24]=='O'):
        return 'c'
    return 'n'

def verificarGanador(tablero):
    ##Verificar cada fila
    if(verificarFila(tablero)=='p'):
        return True
    elif(verificarFila(tablero)=='c'):
        return True;
    ##Verificar cada columna
    if(verificarColumna(tablero)=='p'):
        return True
    elif(verificarColumna(tablero)=='c'):
        return True
    ##Verificar cada diagonal
    if(verificarDiagonal(tablero)=='p'):
        return True
    elif(verificarDiagonal(tablero)=='c'):
        return True
    ##Verificar cada patron adyacente e.g. 1-10-19
    if(verificarAdyacente(tablero)=='p'):
        return True
    elif(verificarAdyacente(tablero)=='c'):
        return True
    ##Verificar cada línea oblicua e.g. 1-11-21, 1-13-25, 1-14-27, 3-14-25
    if(verificarLineasOblicuas(tablero)=='p'):
        return True
    elif(verificarLineasOblicuas(tablero)=='c'):
        return True
    return False


def verificarSiLegal (cellNbre, tablero):
    if(cellNbre > 0 and cellNbre < 28 and tablero[cellNbre-1]!="X" and tablero[cellNbre-1]!="O"):
        return True
    else:
        False

def movimientoJugadorUno(tablero):
    m=1
    int(m)
    while(True):
        m=int(input("Jugador1, digite un numero de celda: "))
        if (verificarSiLegal(m, tablero)):
            break;
        print("Movimiento Ilegal.")
        print(" ")
    tablero[m - 1] = 'X'

def movimientoJugadorDos(tablero):
    m=1
    while(True):
        m=int(input("Jugador2, digite un numero de celda: "))
        if(verificarSiLegal(m, tablero)):
            break;
        print("Movimiento Ilegal.")
        print(" ")

    tablero[m - 1] = 'O'


def mostrarEspacios (a, b, tablero):
    #Mostrar X o O, En caso contrario, el número de celda
    for i in range(a,b+1):
        if(tablero[i - 1]== 'X'):
            print("033[1;31mX\033[0m", end ="")
            break;
        elif(tablero[i - 1]== 'O'):
            print("\033[1;34mO\033[0m", end ="")
            break;
        else:
            print(i, end ="")
        if (i==b):
            break;
        if(i%3 != 0):
            print(" | ", end ="")
        if(i%3 == 0):
            print("")
            print("--------------")
        print(" ", end ="")


def mostrarTablero(tablero):
    mostrarEspacios(1, 9, tablero)
    print("\n\n\n",end =" ")
    mostrarEspacios(10, 18, tablero)
    print("\n\n\n",end =" ")
    mostrarEspacios(19, 27, tablero)
    print("\n\n\n",end =" ")



def saludarEInstruir():
    print("Buenos dias, bienvenido al reto Tres en linea: Jugador 1 vs Jugador 2")
    print("El tablero está enumerado desde 1 hasta 27 como se puede observar a continuacion:")
    print("1 | 2 | 3      10 | 11 | 12      19 | 20 | 21")
    print("---------      ------------      ------------")
    print("4 | 5 | 6      13 | 14 | 15      22 | 23 | 24")
    print("---------      ------------      ------------")
    print("7 | 8 | 9      16 | 17 | 19      25 | 26 | 27")
    print("\nJugador 1 va primero, luego el jugador dos hasta que haya un ganador.")
    print("Simplemente debe ingresar el número de la celda la cual desea ocupar. Movimientos del jugaodr uno son marcados con 'X'. Movimientos del jugador dos son marcados con 'O'.")
    print("Desea iniciar? (s/n):")
    ans = input ("Enter number :")
    tablero=np.chararray(shape=(27))
    if (ans == "s"):
        mostrarTablero(tablero);
    else:
        exit()




def main():
    tablero=np.chararray(shape=(27))
    saludarEInstruir()
    print(" ")
    while (True):
        movimientoJugadorUno(tablero)
        if (verificarGanador(tablero)):
            mostrarTablero(tablero)
            print(" ")
            print("Jugador1 gana.")
            break;
        mostrarTablero(tablero)
        print(" ")
        movimientoJugadorDos(tablero)
        if (verificarGanador(tablero)):
            mostrarTablero(tablero)
            print(" ")
            print("Jugador2 gana")
            break;

        mostrarTablero(tablero);
        print(" ")
        print(" ")

if __name__ == "__main__":
    main()
