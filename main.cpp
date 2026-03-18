#include <iostream>
#include "tablero.h"
#include "pieza.h"

using namespace std;

int main() {
    int ancho = 0;
    int alto = 0;
    int bytesFila = 0;  // bytes por fila
    int tamTotal = 0;  // tamano total del tablero
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

    if (!ponerPiezaO(tab, ancho, alto, bytesFila, filaPieza, colPieza)) {
        cout << "error: no se pudo poner la pieza\n";
        liberarTablero(tab);
        return 0;
    }

    cout << "\npieza O puesta arriba:\n";
    imprimirTablero(tab, ancho, alto, bytesFila);

    // aqui probamos mover con teclado
    while (true) {
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
            if (!moverPiezaOIzq(tab, bytesFila, filaPieza, colPieza)) {
                cout << "no se puede mover a la izquierda\n";
            }
        } else if (op == 'd' || op == 'D') {
            if (!moverPiezaODer(tab, ancho, bytesFila, filaPieza, colPieza)) {
                cout << "no se puede mover a la derecha\n";
            }
        } else if (op == 's' || op == 'S') {
            if (!moverPiezaOAbajo(tab, alto, bytesFila, filaPieza, colPieza)) {
                cout << "no se puede bajar mas\n";
            }
        } else {
            cout << "tecla no valida\n";
        }

        cout << "\ntablero:\n";
        imprimirTablero(tab, ancho, alto, bytesFila);
    }

    // libero la memoria antes de salir
    liberarTablero(tab);
    return 0;
}

