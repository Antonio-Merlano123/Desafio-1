#include <iostream>
#include "tablero.h"

using namespace std;

bool validarDatos(int ancho, int alto) {
    // minimo 8x8
    if (ancho < 8 || alto < 8) {
        return false;
    }

    // el ancho tiene que ser multiplo de 8 para que quepan bien en bytes
    if (ancho % 8 != 0) {
        return false;
    }

    return true;
}

bool crearTablero(int ancho, int alto,
                   int& bytesFila, int& tamTotal,
                   unsigned char*& tab) {
    // cuantos bytes necesito por fila
    bytesFila = ancho / 8;
    tamTotal = alto * bytesFila;

    // reservo la memoria
    tab = new unsigned char[tamTotal];
    if (tab == 0) {
        return false;
    }

    // arranco con todo en 0, tablero vacio
    for (int i = 0; i < tamTotal; i++) {
        tab[i] = 0;
    }

    return true;
}

void liberarTablero(unsigned char*& tab) {
    delete[] tab;
    tab = 0; // lo pongo en 0 para no usarlo por error
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
