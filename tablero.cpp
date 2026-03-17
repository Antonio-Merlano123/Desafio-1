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

bool leerCelda(const unsigned char* tab, int bytesFila, int fila, int col) {
    int byteFila = col / 8;
    int bit = 7 - (col % 8);
    int pos = fila * bytesFila + byteFila;

    return ((tab[pos] >> bit) & 1) == 1;
}

void cambiarCelda(unsigned char* tab, int bytesFila, int fila, int col, bool valor) {
    int byteFila = col / 8;
    int bit = 7 - (col % 8);
    int pos = fila * bytesFila + byteFila;

    if (valor) {
        // prendo el bit
        tab[pos] = tab[pos] | (1 << bit);
    } else {
        // apago el bit
        tab[pos] = tab[pos] & ~(1 << bit);
    }
}

void imprimirTablero(const unsigned char* tab,
                     int ancho, int alto, int bytesFila) {
    for (int fila = 0; fila < alto; fila++) {
        for (int col = 0; col < ancho; col++) {
            if (leerCelda(tab, bytesFila, fila, col)) {
                cout << "#";
            } else {
                cout << ".";
            }
        }
        cout << '\n';
    }
}
