#include <iostream>
#include "tablero.h"

using namespace std;

bool validarDatos(int ancho, int alto) {
    // tablero debe ser al menos 8x8
    if (ancho < 8 || alto < 8) {
        return false;
    }

    // ancho debe ser multiplo de 8 porque cada byte guarda 8 celdas
    if (ancho % 8 != 0) {
        return false;
    }

    return true;
}

bool crearTablero(int ancho, int alto,
                   int& bytesFila, int& tamTotal,
                   unsigned char*& tab) {
    // calculamos cuantos bytes necesitamos por fila
    // si ancho=16, necesitamos 16/8 = 2 bytes
    bytesFila = ancho / 8;
    tamTotal = alto * bytesFila;

    // allocamos memoria dinamica del tamaño calculado
    tab = new unsigned char[tamTotal];
    if (tab == 0) {
        return false; // si malloc falla, retornamos error
    }

    // inicializamos todo en 0: tablero vacio (todos los bits en 0)
    for (int i = 0; i < tamTotal; i++) {
        tab[i] = 0;
    }

    return true;
}

void liberarTablero(unsigned char*& tab) {
    // liberamos la memoria que allocamos con new[]
    delete[] tab;
    // seteamos a null para evitar usar puntero invalido
    tab = 0;
}

void imprimirTablero(const unsigned char* tab,
                     int ancho, int alto, int bytesFila) {
    for (int fila = 0; fila < alto; fila++) {
        for (int col = 0; col < ancho; col++) {
            // calculamos en que byte del array esta esta celda
            int byteFila = col / 8;
            // calculamos que bit dentro del byte (0-7)
            int bit = 7 - (col % 8);
            // posicion en el array: fila * bytesXfila + byte de la celda
            int pos = fila * bytesFila + byteFila;

            // extraemos el bit con shift y AND
            // si el bit es 1, celda ocupada; si es 0, vacia
            if ((tab[pos] >> bit) & 1) {
                cout << "#";
            } else {
                cout << ".";
            }
        }
        cout << '\n';
    }
}
