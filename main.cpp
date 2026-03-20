#include <iostream>
#include <ctime>
#include "tablero.h"
#include "pieza.h"

using namespace std;

bool fijarYSeguir(unsigned char* tab, int ancho, int alto, int bytesFila, int& tipoPieza, int& filaPieza, int& colPieza, int& giroI) {
    cout << "pieza fija\n";
    int filas = limpiarFilas(tab, ancho, alto, bytesFila);
    if (filas > 0) cout << "borre " << filas << " filas\n";
    if (!ponerPiezaAleatoria(tab, ancho, alto, bytesFila, tipoPieza, filaPieza, colPieza, giroI)) {
        cout << "game over\n";
        return false;
    }
    return true;
}

int main() {
    int ancho = 0;
    int alto = 0;
    int bytesFila = 0;
    int tamTotal = 0;
    int tipoPieza = 0; // 0=O 1=I 2=T 3=L 4=S
    int filaPieza = 0;
    int colPieza = 0;
    int giroI = 0;
    char op = ' ';
    unsigned char* tab = 0;

    cout << "Ancho del tablero (minimo 8, multiplo de 8): ";
    cin >> ancho;
    cout << "Alto del tablero (minimo 8): ";
    cin >> alto;

    // si no entro un numero, salgo
    if (!cin) {
        cout << "entrada invalida\n";
        return 0;
    }

    // reviso que el tamano sea valido
    if (!validarDatos(ancho, alto)) {
        cout << "error: dimensiones invalidas\n";
        return 0;
    }

    // pido memoria para el tablero
    if (!crearTablero(ancho, alto, bytesFila, tamTotal, tab)) {
        cout << "error: no se pudo crear tablero\n";
        return 0;
    }

    cout << "bytes por fila: " << bytesFila << "\n";
    cout << "tamano total: " << tamTotal << "\n";
    cout << "\ntablero vacio:\n";
    imprimirTablero(tab, ancho, alto, bytesFila);

    srand((unsigned int)time(0));

    if (!ponerPiezaAleatoria(tab, ancho, alto, bytesFila, tipoPieza, filaPieza, colPieza, giroI)) {
        cout << "error: no se pudo poner la pieza\n";
        liberarTablero(tab);
        return 0;
    }

    cout << "\npieza inicial puesta arriba:\n";
    imprimirTablero(tab, ancho, alto, bytesFila);

    // aqui juego por turnos
    while (true) {
        bool bajoManual = false;

        cout << "\na=izq d=der s=baja w=gira q=salir: ";
        cin >> op;

        if (!cin) {
            cout << "entrada invalida\n";
            break;
        }

        if (op == 'q' || op == 'Q') {
            break;
        }

        if (op == 'a' || op == 'A') {
            bool pudoIzq = false;
            if (tipoPieza == 0) pudoIzq = moverPiezaOIzq(tab, ancho, alto, bytesFila, filaPieza, colPieza);
            else if (tipoPieza == 1) pudoIzq = moverPiezaIIzq(tab, ancho, alto, bytesFila, filaPieza, colPieza, giroI);
            else if (tipoPieza == 2) pudoIzq = moverPiezaTIzq(tab, ancho, alto, bytesFila, filaPieza, colPieza);
            else if (tipoPieza == 3) pudoIzq = moverPiezaLIzq(tab, ancho, alto, bytesFila, filaPieza, colPieza);
            else pudoIzq = moverPiezaSIzq(tab, ancho, alto, bytesFila, filaPieza, colPieza);
            if (!pudoIzq) cout << "ya no puede ir mas a la izquierda\n";
        } else if (op == 'd' || op == 'D') {
            bool pudoDer = false;
            if (tipoPieza == 0) pudoDer = moverPiezaODer(tab, ancho, alto, bytesFila, filaPieza, colPieza);
            else if (tipoPieza == 1) pudoDer = moverPiezaIDer(tab, ancho, alto, bytesFila, filaPieza, colPieza, giroI);
            else if (tipoPieza == 2) pudoDer = moverPiezaTDer(tab, ancho, alto, bytesFila, filaPieza, colPieza);
            else if (tipoPieza == 3) pudoDer = moverPiezaLDer(tab, ancho, alto, bytesFila, filaPieza, colPieza);
            else pudoDer = moverPiezaSDer(tab, ancho, alto, bytesFila, filaPieza, colPieza);
            if (!pudoDer) cout << "ya no puede ir mas a la derecha\n";
        } else if (op == 's' || op == 'S') {
            bajoManual = true;
            bool pudoBajar = false;
            if (tipoPieza == 0) pudoBajar = moverPiezaOAbajo(tab, ancho, alto, bytesFila, filaPieza, colPieza);
            else if (tipoPieza == 1) pudoBajar = moverPiezaIAbajo(tab, ancho, alto, bytesFila, filaPieza, colPieza, giroI);
            else if (tipoPieza == 2) pudoBajar = moverPiezaTAbajo(tab, ancho, alto, bytesFila, filaPieza, colPieza);
            else if (tipoPieza == 3) pudoBajar = moverPiezaLAbajo(tab, ancho, alto, bytesFila, filaPieza, colPieza);
            else pudoBajar = moverPiezaSAbajo(tab, ancho, alto, bytesFila, filaPieza, colPieza);
            if (!pudoBajar) {
                if (!fijarYSeguir(tab, ancho, alto, bytesFila, tipoPieza, filaPieza, colPieza, giroI)) break;
            }
        } else if (op == 'w' || op == 'W') {
            if (tipoPieza == 1) {
                if (!rotarPiezaI(tab, ancho, alto, bytesFila, filaPieza, colPieza, giroI))
                    cout << "no se puede rotar\n";
            } else {
                cout << "esa pieza no rota por ahora\n";
            }
        } else {
            cout << "tecla no valida\n";
            continue;
        }

        // aunque no baje manual, igual toca bajar una fila por turno
        if (!bajoManual) {
            bool pudoBajar = false;
            if (tipoPieza == 0) pudoBajar = moverPiezaOAbajo(tab, ancho, alto, bytesFila, filaPieza, colPieza);
            else if (tipoPieza == 1) pudoBajar = moverPiezaIAbajo(tab, ancho, alto, bytesFila, filaPieza, colPieza, giroI);
            else if (tipoPieza == 2) pudoBajar = moverPiezaTAbajo(tab, ancho, alto, bytesFila, filaPieza, colPieza);
            else if (tipoPieza == 3) pudoBajar = moverPiezaLAbajo(tab, ancho, alto, bytesFila, filaPieza, colPieza);
            else pudoBajar = moverPiezaSAbajo(tab, ancho, alto, bytesFila, filaPieza, colPieza);
            if (!pudoBajar) {
                if (!fijarYSeguir(tab, ancho, alto, bytesFila, tipoPieza, filaPieza, colPieza, giroI)) break;
            }
        }

        cout << "\ntablero:\n";
        imprimirTablero(tab, ancho, alto, bytesFila);
    }

    // libero la memoria antes de salir
    liberarTablero(tab);
    return 0;
}

