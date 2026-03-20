#include "pieza.h"
#include "tablero.h"
#include <cstdlib>

void marcarPiezaO(unsigned char* tab, int bytesFila, int filaPieza, int colPieza, bool valor) {
    cambiarCelda(tab, bytesFila, filaPieza, colPieza, valor);
    cambiarCelda(tab, bytesFila, filaPieza, colPieza + 1, valor);
    cambiarCelda(tab, bytesFila, filaPieza + 1, colPieza, valor);
    cambiarCelda(tab, bytesFila, filaPieza + 1, colPieza + 1, valor);
}

// la I puede estar vertical u horizontal
void marcarPiezaI(unsigned char* tab, int bytesFila, int filaPieza, int colPieza, int giroI, bool valor) {
    if (giroI == 0) {
        cambiarCelda(tab, bytesFila, filaPieza, colPieza, valor);
        cambiarCelda(tab, bytesFila, filaPieza + 1, colPieza, valor);
        cambiarCelda(tab, bytesFila, filaPieza + 2, colPieza, valor);
        cambiarCelda(tab, bytesFila, filaPieza + 3, colPieza, valor);
    } else {
        cambiarCelda(tab, bytesFila, filaPieza, colPieza, valor);
        cambiarCelda(tab, bytesFila, filaPieza, colPieza + 1, valor);
        cambiarCelda(tab, bytesFila, filaPieza, colPieza + 2, valor);
        cambiarCelda(tab, bytesFila, filaPieza, colPieza + 3, valor);
    }
}

void marcarPiezaT(unsigned char* tab, int bytesFila, int filaPieza, int colPieza, bool valor) {
    cambiarCelda(tab, bytesFila, filaPieza, colPieza, valor);
    cambiarCelda(tab, bytesFila, filaPieza, colPieza + 1, valor);
    cambiarCelda(tab, bytesFila, filaPieza, colPieza + 2, valor);
    cambiarCelda(tab, bytesFila, filaPieza + 1, colPieza + 1, valor);
}

void marcarPiezaL(unsigned char* tab, int bytesFila, int filaPieza, int colPieza, bool valor) {
    cambiarCelda(tab, bytesFila, filaPieza, colPieza, valor);
    cambiarCelda(tab, bytesFila, filaPieza + 1, colPieza, valor);
    cambiarCelda(tab, bytesFila, filaPieza + 2, colPieza, valor);
    cambiarCelda(tab, bytesFila, filaPieza + 2, colPieza + 1, valor);
}

bool cabePiezaO(const unsigned char* tab, int ancho, int alto, int bytesFila, int filaPieza, int colPieza) {
    int f = filaPieza;
    int c = colPieza;
    if (f < 0 || c < 0) return false;
    if (f + 1 >= alto || c + 1 >= ancho) return false;
    if (leerCelda(tab, bytesFila, f, c)) return false;
    if (leerCelda(tab, bytesFila, f, c + 1)) return false;
    if (leerCelda(tab, bytesFila, f + 1, c)) return false;
    if (leerCelda(tab, bytesFila, f + 1, c + 1)) return false;
    return true;
}

bool cabePiezaI(const unsigned char* tab, int ancho, int alto, int bytesFila, int filaPieza, int colPieza, int giroI) {
    int f = filaPieza;
    int c = colPieza;
    if (f < 0 || c < 0) return false;
    if (giroI == 0) {
        if (f + 3 >= alto || c >= ancho) return false;
        if (leerCelda(tab, bytesFila, f, c)) return false;
        if (leerCelda(tab, bytesFila, f + 1, c)) return false;
        if (leerCelda(tab, bytesFila, f + 2, c)) return false;
        if (leerCelda(tab, bytesFila, f + 3, c)) return false;
    } else {
        if (f >= alto || c + 3 >= ancho) return false;
        if (leerCelda(tab, bytesFila, f, c)) return false;
        if (leerCelda(tab, bytesFila, f, c + 1)) return false;
        if (leerCelda(tab, bytesFila, f, c + 2)) return false;
        if (leerCelda(tab, bytesFila, f, c + 3)) return false;
    }
    return true;
}

bool cabePiezaT(const unsigned char* tab, int ancho, int alto, int bytesFila, int filaPieza, int colPieza) {
    int f = filaPieza;
    int c = colPieza;
    if (f < 0 || c < 0) return false;
    if (f + 1 >= alto || c + 2 >= ancho) return false;
    if (leerCelda(tab, bytesFila, f, c)) return false;
    if (leerCelda(tab, bytesFila, f, c + 1)) return false;
    if (leerCelda(tab, bytesFila, f, c + 2)) return false;
    if (leerCelda(tab, bytesFila, f + 1, c + 1)) return false;
    return true;
}

bool cabePiezaL(const unsigned char* tab, int ancho, int alto, int bytesFila, int filaPieza, int colPieza) {
    int f = filaPieza;
    int c = colPieza;
    if (f < 0 || c < 0) return false;
    if (f + 2 >= alto || c + 1 >= ancho) return false;
    if (leerCelda(tab, bytesFila, f, c)) return false;
    if (leerCelda(tab, bytesFila, f + 1, c)) return false;
    if (leerCelda(tab, bytesFila, f + 2, c)) return false;
    if (leerCelda(tab, bytesFila, f + 2, c + 1)) return false;
    return true;
}

bool ponerPiezaO(unsigned char* tab, int ancho, int alto, int bytesFila, int& filaPieza, int& colPieza) {
    filaPieza = 0;
    colPieza = ancho / 2 - 1;
    if (colPieza < 0) colPieza = 0;
    if (!cabePiezaO(tab, ancho, alto, bytesFila, filaPieza, colPieza)) return false;
    marcarPiezaO(tab, bytesFila, filaPieza, colPieza, true);
    return true;
}

bool ponerPiezaI(unsigned char* tab, int ancho, int alto, int bytesFila, int& filaPieza, int& colPieza, int& giroI) {
    filaPieza = 0;
    colPieza = ancho / 2;
    giroI = 0;
    if (!cabePiezaI(tab, ancho, alto, bytesFila, filaPieza, colPieza, giroI)) return false;
    marcarPiezaI(tab, bytesFila, filaPieza, colPieza, giroI, true);
    return true;
}

bool ponerPiezaT(unsigned char* tab, int ancho, int alto, int bytesFila, int& filaPieza, int& colPieza) {
    filaPieza = 0;
    colPieza = ancho / 2 - 1;
    if (colPieza < 0) colPieza = 0;
    if (!cabePiezaT(tab, ancho, alto, bytesFila, filaPieza, colPieza)) return false;
    marcarPiezaT(tab, bytesFila, filaPieza, colPieza, true);
    return true;
}

bool ponerPiezaL(unsigned char* tab, int ancho, int alto, int bytesFila, int& filaPieza, int& colPieza) {
    filaPieza = 0;
    colPieza = ancho / 2 - 1;
    if (colPieza < 0) colPieza = 0;
    if (!cabePiezaL(tab, ancho, alto, bytesFila, filaPieza, colPieza)) return false;
    marcarPiezaL(tab, bytesFila, filaPieza, colPieza, true);
    return true;
}

bool ponerPiezaAleatoria(unsigned char* tab, int ancho, int alto, int bytesFila, int& tipoPieza, int& filaPieza, int& colPieza, int& giroI) {
    tipoPieza = rand() % 4; // 0 O, 1 I, 2 T, 3 L
    if (tipoPieza == 0) {
        giroI = 0;
        return ponerPiezaO(tab, ancho, alto, bytesFila, filaPieza, colPieza);
    }
    if (tipoPieza == 1) {
        return ponerPiezaI(tab, ancho, alto, bytesFila, filaPieza, colPieza, giroI);
    }
    giroI = 0;
    if (tipoPieza == 2) return ponerPiezaT(tab, ancho, alto, bytesFila, filaPieza, colPieza);
    return ponerPiezaL(tab, ancho, alto, bytesFila, filaPieza, colPieza);
}

bool moverPiezaOIzq(unsigned char* tab, int ancho, int alto, int bytesFila, int& filaPieza, int& colPieza) {
    if (colPieza <= 0) return false; // ya llego al borde
    marcarPiezaO(tab, bytesFila, filaPieza, colPieza, false); // borro donde estaba
    if (!cabePiezaO(tab, ancho, alto, bytesFila, filaPieza, colPieza - 1)) {
        marcarPiezaO(tab, bytesFila, filaPieza, colPieza, true); // la dejo donde estaba
        return false;
    }
    colPieza = colPieza - 1;
    marcarPiezaO(tab, bytesFila, filaPieza, colPieza, true);
    return true;
}

bool moverPiezaODer(unsigned char* tab, int ancho, int alto, int bytesFila, int& filaPieza, int& colPieza) {
    if (colPieza + 2 >= ancho) return false; // ya llego al borde
    marcarPiezaO(tab, bytesFila, filaPieza, colPieza, false);
    if (!cabePiezaO(tab, ancho, alto, bytesFila, filaPieza, colPieza + 1)) {
        marcarPiezaO(tab, bytesFila, filaPieza, colPieza, true);
        return false;
    }
    colPieza = colPieza + 1;
    marcarPiezaO(tab, bytesFila, filaPieza, colPieza, true);
    return true;
}

bool moverPiezaOAbajo(unsigned char* tab, int ancho, int alto, int bytesFila, int& filaPieza, int& colPieza) {
    if (filaPieza + 2 >= alto) return false; // ya llego al fondo
    marcarPiezaO(tab, bytesFila, filaPieza, colPieza, false);
    if (!cabePiezaO(tab, ancho, alto, bytesFila, filaPieza + 1, colPieza)) {
        marcarPiezaO(tab, bytesFila, filaPieza, colPieza, true);
        return false;
    }
    filaPieza = filaPieza + 1;
    marcarPiezaO(tab, bytesFila, filaPieza, colPieza, true);
    return true;
}

bool moverPiezaTIzq(unsigned char* tab, int ancho, int alto, int bytesFila, int& filaPieza, int& colPieza) {
    if (colPieza <= 0) return false;
    marcarPiezaT(tab, bytesFila, filaPieza, colPieza, false);
    if (!cabePiezaT(tab, ancho, alto, bytesFila, filaPieza, colPieza - 1)) {
        marcarPiezaT(tab, bytesFila, filaPieza, colPieza, true);
        return false;
    }
    colPieza = colPieza - 1;
    marcarPiezaT(tab, bytesFila, filaPieza, colPieza, true);
    return true;
}

bool moverPiezaTDer(unsigned char* tab, int ancho, int alto, int bytesFila, int& filaPieza, int& colPieza) {
    if (colPieza + 3 >= ancho) return false;
    marcarPiezaT(tab, bytesFila, filaPieza, colPieza, false);
    if (!cabePiezaT(tab, ancho, alto, bytesFila, filaPieza, colPieza + 1)) {
        marcarPiezaT(tab, bytesFila, filaPieza, colPieza, true);
        return false;
    }
    colPieza = colPieza + 1;
    marcarPiezaT(tab, bytesFila, filaPieza, colPieza, true);
    return true;
}

bool moverPiezaTAbajo(unsigned char* tab, int ancho, int alto, int bytesFila, int& filaPieza, int& colPieza) {
    marcarPiezaT(tab, bytesFila, filaPieza, colPieza, false);
    if (!cabePiezaT(tab, ancho, alto, bytesFila, filaPieza + 1, colPieza)) {
        marcarPiezaT(tab, bytesFila, filaPieza, colPieza, true);
        return false;
    }
    filaPieza = filaPieza + 1;
    marcarPiezaT(tab, bytesFila, filaPieza, colPieza, true);
    return true;
}

bool moverPiezaLIzq(unsigned char* tab, int ancho, int alto, int bytesFila, int& filaPieza, int& colPieza) {
    if (colPieza <= 0) return false;
    marcarPiezaL(tab, bytesFila, filaPieza, colPieza, false);
    if (!cabePiezaL(tab, ancho, alto, bytesFila, filaPieza, colPieza - 1)) {
        marcarPiezaL(tab, bytesFila, filaPieza, colPieza, true);
        return false;
    }
    colPieza = colPieza - 1;
    marcarPiezaL(tab, bytesFila, filaPieza, colPieza, true);
    return true;
}

bool moverPiezaLDer(unsigned char* tab, int ancho, int alto, int bytesFila, int& filaPieza, int& colPieza) {
    if (colPieza + 2 >= ancho) return false;
    marcarPiezaL(tab, bytesFila, filaPieza, colPieza, false);
    if (!cabePiezaL(tab, ancho, alto, bytesFila, filaPieza, colPieza + 1)) {
        marcarPiezaL(tab, bytesFila, filaPieza, colPieza, true);
        return false;
    }
    colPieza = colPieza + 1;
    marcarPiezaL(tab, bytesFila, filaPieza, colPieza, true);
    return true;
}

bool moverPiezaLAbajo(unsigned char* tab, int ancho, int alto, int bytesFila, int& filaPieza, int& colPieza) {
    marcarPiezaL(tab, bytesFila, filaPieza, colPieza, false);
    if (!cabePiezaL(tab, ancho, alto, bytesFila, filaPieza + 1, colPieza)) {
        marcarPiezaL(tab, bytesFila, filaPieza, colPieza, true);
        return false;
    }
    filaPieza = filaPieza + 1;
    marcarPiezaL(tab, bytesFila, filaPieza, colPieza, true);
    return true;
}

bool moverPiezaIAbajo(unsigned char* tab, int ancho, int alto, int bytesFila, int& filaPieza, int& colPieza, int giroI) {
    marcarPiezaI(tab, bytesFila, filaPieza, colPieza, giroI, false);
    if (!cabePiezaI(tab, ancho, alto, bytesFila, filaPieza + 1, colPieza, giroI)) {
        marcarPiezaI(tab, bytesFila, filaPieza, colPieza, giroI, true);
        return false;
    }
    filaPieza = filaPieza + 1;
    marcarPiezaI(tab, bytesFila, filaPieza, colPieza, giroI, true);
    return true;
}

bool moverPiezaIIzq(unsigned char* tab, int ancho, int alto, int bytesFila, int& filaPieza, int& colPieza, int giroI) {
    if (colPieza <= 0) return false;
    marcarPiezaI(tab, bytesFila, filaPieza, colPieza, giroI, false);
    if (!cabePiezaI(tab, ancho, alto, bytesFila, filaPieza, colPieza - 1, giroI)) {
        marcarPiezaI(tab, bytesFila, filaPieza, colPieza, giroI, true);
        return false;
    }
    colPieza = colPieza - 1;
    marcarPiezaI(tab, bytesFila, filaPieza, colPieza, giroI, true);
    return true;
}

bool moverPiezaIDer(unsigned char* tab, int ancho, int alto, int bytesFila, int& filaPieza, int& colPieza, int giroI) {
    if (giroI == 0 && colPieza + 1 >= ancho) return false;
    if (giroI == 1 && colPieza + 4 >= ancho) return false;
    marcarPiezaI(tab, bytesFila, filaPieza, colPieza, giroI, false);
    if (!cabePiezaI(tab, ancho, alto, bytesFila, filaPieza, colPieza + 1, giroI)) {
        marcarPiezaI(tab, bytesFila, filaPieza, colPieza, giroI, true);
        return false;
    }
    colPieza = colPieza + 1;
    marcarPiezaI(tab, bytesFila, filaPieza, colPieza, giroI, true);
    return true;
}

bool rotarPiezaI(unsigned char* tab, int ancho, int alto, int bytesFila, int& filaPieza, int& colPieza, int& giroI) {
    int nuevoGiro = 0;
    if (giroI == 0) nuevoGiro = 1;
    marcarPiezaI(tab, bytesFila, filaPieza, colPieza, giroI, false);
    if (!cabePiezaI(tab, ancho, alto, bytesFila, filaPieza, colPieza, nuevoGiro)) {
        marcarPiezaI(tab, bytesFila, filaPieza, colPieza, giroI, true);
        return false;
    }
    giroI = nuevoGiro;
    marcarPiezaI(tab, bytesFila, filaPieza, colPieza, giroI, true);
    return true;
}