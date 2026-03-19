#include <iostream>
#include <ctime>
#include "tablero.h"
#include "pieza.h"

using namespace std;

bool fijarYSeguir(unsigned char* tab, int ancho, int alto, int bytesFila,
                 int& tipoPieza, int& filaPieza, int& colPieza) {
    cout << "la pieza quedo fija\n";

    int filas = limpiarFilas(tab, ancho, alto, bytesFila);
    if (filas > 0) {
        cout << "filas borradas: " << filas << "\n";
    }

    // si no cabe una nueva pieza, termina
    if (!ponerPiezaAleatoria(tab, ancho, alto, bytesFila, tipoPieza, filaPieza, colPieza)) {
        cout << "game over\n";
        return false;
    }

    return true;
}

int main() {
    int ancho = 0;
    int alto = 0;
    int bytesFila = 0;  // bytes por fila
    int tamTotal = 0;  // tamano total del tablero
    int tipoPieza = 0;
    int filaPieza = 0;
    int colPieza = 0;
    char op = ' ';
    unsigned char* tab = 0; // puntero al tablero

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

    if (!ponerPiezaAleatoria(tab, ancho, alto, bytesFila, tipoPieza, filaPieza, colPieza)) {
        cout << "error: no se pudo poner la pieza\n";
        liberarTablero(tab);
        return 0;
    }

    cout << "\npieza inicial puesta arriba:\n";
    imprimirTablero(tab, ancho, alto, bytesFila);

    // aqui probamos mover con teclado
    while (true) {
        bool bajoManual = false;

        cout << "\naccion: a izq, d der, s abajo, q salir: ";
        cin >> op;

        if (!cin) {
            cout << "entrada invalida\n";
            break;
        }

        if (op == 'q' || op == 'Q') {
            break;
        }

        if (op == 'a' || op == 'A') {
            if (tipoPieza == 0 && !moverPiezaOIzq(tab, ancho, alto, bytesFila, filaPieza, colPieza)) {
                cout << "no se puede mover a la izquierda\n";
            }
        } else if (op == 'd' || op == 'D') {
            if (tipoPieza == 0 && !moverPiezaODer(tab, ancho, alto, bytesFila, filaPieza, colPieza)) {
                cout << "no se puede mover a la derecha\n";
            }
        } else if (op == 's' || op == 'S') {
            bajoManual = true;
            bool bajo = false;

            if (tipoPieza == 0) {
                bajo = moverPiezaOAbajo(tab, ancho, alto, bytesFila, filaPieza, colPieza);
            } else {
                bajo = moverPiezaIAbajo(tab, ancho, alto, bytesFila, filaPieza, colPieza);
            }

            if (!bajo) {
                if (!fijarYSeguir(tab, ancho, alto, bytesFila, tipoPieza, filaPieza, colPieza)) {
                    break;
                }
            }
        } else {
            cout << "tecla no valida\n";
            continue;
        }

        // si no fue s, igual baja una por turno
        if (!bajoManual) {
            bool bajo = false;

            if (tipoPieza == 0) {
                bajo = moverPiezaOAbajo(tab, ancho, alto, bytesFila, filaPieza, colPieza);
            } else {
                bajo = moverPiezaIAbajo(tab, ancho, alto, bytesFila, filaPieza, colPieza);
            }

            if (!bajo) {
                if (!fijarYSeguir(tab, ancho, alto, bytesFila, tipoPieza, filaPieza, colPieza)) {
                    break;
                }
            }
        }

        cout << "\ntablero:\n";
        imprimirTablero(tab, ancho, alto, bytesFila);
    }

    // libero la memoria antes de salir
    liberarTablero(tab);
    return 0;
}

