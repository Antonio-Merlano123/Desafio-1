#include <iostream>
#include "tablero.h"

using namespace std;

bool validarDatos(int ancho, int alto) {
    if (ancho < 8 || alto < 8) {
        return false;
    }

    if (ancho % 8 != 0) {
        return false;
    }

    return true;
}

bool crearTablero(int ancho, int alto, int& bytesFila, int& tamTotal, unsigned char*& tab) {
    bytesFila = ancho / 8;
    tamTotal = alto * bytesFila;
    tab = new unsigned char[tamTotal];
    if (tab == 0) return false;
    for (int i = 0; i < tamTotal; i++) tab[i] = 0; // arranco vacio
    return true;
}

void liberarTablero(unsigned char*& tab) {
    delete[] tab;
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
        tab[pos] = tab[pos] | (1 << bit);
    } else {
        tab[pos] = tab[pos] & ~(1 << bit);
    }
}

void imprimirTablero(const unsigned char* tab, int ancho, int alto, int bytesFila) {
    for (int fila = 0; fila < alto; fila++) {
        for (int col = 0; col < ancho; col++) {
            if (leerCelda(tab, bytesFila, fila, col)) cout << "#";
            else cout << ".";
        }
        cout << "\n";
    }
}

bool filaLlena(const unsigned char* tab, int ancho, int bytesFila, int fila) {
    for (int col = 0; col < ancho; col++) {
        if (!leerCelda(tab, bytesFila, fila, col)) {
            return false;
        }
    }
    return true;
}

void borrarFila(unsigned char* tab, int ancho, int alto, int bytesFila, int fila) {
    for (int f = fila; f > 0; f--) {
        for (int col = 0; col < ancho; col++) {
            bool valorArriba = leerCelda(tab, bytesFila, f - 1, col);
            cambiarCelda(tab, bytesFila, f, col, valorArriba);
        }
    }

    for (int col = 0; col < ancho; col++) {
        cambiarCelda(tab, bytesFila, 0, col, false);
    }
}

int limpiarFilas(unsigned char* tab, int ancho, int alto, int bytesFila) {
    int borradas = 0;

    for (int fila = alto - 1; fila >= 0; fila--) {
        if (filaLlena(tab, ancho, bytesFila, fila)) {
            borrarFila(tab, ancho, alto, bytesFila, fila);
            borradas = borradas + 1;
            fila = fila + 1;
        }
    }

    return borradas;
}
