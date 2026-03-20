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
void marcarPiezaI(unsigned char* tab, int bytesFila, int filaPieza, int colPieza, int giro, bool valor) {
    if (giro == 0) {
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

void marcarPiezaS(unsigned char* tab, int bytesFila, int filaPieza, int colPieza, int giro, bool valor) {
    if (giro == 0) {
        cambiarCelda(tab, bytesFila, filaPieza, colPieza + 1, valor);
        cambiarCelda(tab, bytesFila, filaPieza, colPieza + 2, valor);
        cambiarCelda(tab, bytesFila, filaPieza + 1, colPieza, valor);
        cambiarCelda(tab, bytesFila, filaPieza + 1, colPieza + 1, valor);
    } else {
        cambiarCelda(tab, bytesFila, filaPieza, colPieza, valor);
        cambiarCelda(tab, bytesFila, filaPieza + 1, colPieza, valor);
        cambiarCelda(tab, bytesFila, filaPieza + 1, colPieza + 1, valor);
        cambiarCelda(tab, bytesFila, filaPieza + 2, colPieza + 1, valor);
    }
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

bool cabePiezaI(const unsigned char* tab, int ancho, int alto, int bytesFila, int filaPieza, int colPieza, int giro) {
    int f = filaPieza;
    int c = colPieza;
    if (f < 0 || c < 0) return false;
    if (giro == 0) {
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

bool cabePiezaS(const unsigned char* tab, int ancho, int alto, int bytesFila, int filaPieza, int colPieza, int giro) {
    int f = filaPieza;
    int c = colPieza;
    if (f < 0 || c < 0) return false;
    if (giro == 0) {
        if (f + 1 >= alto || c + 2 >= ancho) return false;
        if (leerCelda(tab, bytesFila, f, c + 1)) return false;
        if (leerCelda(tab, bytesFila, f, c + 2)) return false;
        if (leerCelda(tab, bytesFila, f + 1, c)) return false;
        if (leerCelda(tab, bytesFila, f + 1, c + 1)) return false;
    } else {
        if (f + 2 >= alto || c + 1 >= ancho) return false;
        if (leerCelda(tab, bytesFila, f, c)) return false;
        if (leerCelda(tab, bytesFila, f + 1, c)) return false;
        if (leerCelda(tab, bytesFila, f + 1, c + 1)) return false;
        if (leerCelda(tab, bytesFila, f + 2, c + 1)) return false;
    }
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

bool ponerPiezaI(unsigned char* tab, int ancho, int alto, int bytesFila, int& filaPieza, int& colPieza, int& giro) {
    filaPieza = 0;
    colPieza = ancho / 2;
    giro = 0;
    if (!cabePiezaI(tab, ancho, alto, bytesFila, filaPieza, colPieza, giro)) return false;
    marcarPiezaI(tab, bytesFila, filaPieza, colPieza, giro, true);
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

bool ponerPiezaS(unsigned char* tab, int ancho, int alto, int bytesFila, int& filaPieza, int& colPieza, int& giro) {
    filaPieza = 0;
    colPieza = ancho / 2 - 1;
    if (colPieza < 0) colPieza = 0;
    giro = 0;
    if (!cabePiezaS(tab, ancho, alto, bytesFila, filaPieza, colPieza, giro)) return false;
    marcarPiezaS(tab, bytesFila, filaPieza, colPieza, giro, true);
    return true;
}

bool ponerPiezaAleatoria(unsigned char* tab, int ancho, int alto, int bytesFila, int& tipoPieza, int& filaPieza, int& colPieza, int& giro) {
    tipoPieza = rand() % 5; // 0 O, 1 I, 2 T, 3 L, 4 S
    if (tipoPieza == 0) {
        giro = 0;
        return ponerPiezaO(tab, ancho, alto, bytesFila, filaPieza, colPieza);
    }
    if (tipoPieza == 1) {
        return ponerPiezaI(tab, ancho, alto, bytesFila, filaPieza, colPieza, giro);
    }
    giro = 0;
    if (tipoPieza == 2) return ponerPiezaT(tab, ancho, alto, bytesFila, filaPieza, colPieza);
    if (tipoPieza == 3) return ponerPiezaL(tab, ancho, alto, bytesFila, filaPieza, colPieza);
    return ponerPiezaS(tab, ancho, alto, bytesFila, filaPieza, colPieza, giro);
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

bool moverPiezaSIzq(unsigned char* tab, int ancho, int alto, int bytesFila, int& filaPieza, int& colPieza, int giro) {
    if (colPieza <= 0) return false;
    marcarPiezaS(tab, bytesFila, filaPieza, colPieza, giro, false);
    if (!cabePiezaS(tab, ancho, alto, bytesFila, filaPieza, colPieza - 1, giro)) {
        marcarPiezaS(tab, bytesFila, filaPieza, colPieza, giro, true);
        return false;
    }
    colPieza = colPieza - 1;
    marcarPiezaS(tab, bytesFila, filaPieza, colPieza, giro, true);
    return true;
}

bool moverPiezaSDer(unsigned char* tab, int ancho, int alto, int bytesFila, int& filaPieza, int& colPieza, int giro) {
    if (giro == 0 && colPieza + 3 >= ancho) return false;
    if (giro == 1 && colPieza + 2 >= ancho) return false;
    marcarPiezaS(tab, bytesFila, filaPieza, colPieza, giro, false);
    if (!cabePiezaS(tab, ancho, alto, bytesFila, filaPieza, colPieza + 1, giro)) {
        marcarPiezaS(tab, bytesFila, filaPieza, colPieza, giro, true);
        return false;
    }
    colPieza = colPieza + 1;
    marcarPiezaS(tab, bytesFila, filaPieza, colPieza, giro, true);
    return true;
}

bool moverPiezaSAbajo(unsigned char* tab, int ancho, int alto, int bytesFila, int& filaPieza, int& colPieza, int giro) {
    marcarPiezaS(tab, bytesFila, filaPieza, colPieza, giro, false);
    if (!cabePiezaS(tab, ancho, alto, bytesFila, filaPieza + 1, colPieza, giro)) {
        marcarPiezaS(tab, bytesFila, filaPieza, colPieza, giro, true);
        return false;
    }
    filaPieza = filaPieza + 1;
    marcarPiezaS(tab, bytesFila, filaPieza, colPieza, giro, true);
    return true;
}

bool moverPiezaIAbajo(unsigned char* tab, int ancho, int alto, int bytesFila, int& filaPieza, int& colPieza, int giro) {
    marcarPiezaI(tab, bytesFila, filaPieza, colPieza, giro, false);
    if (!cabePiezaI(tab, ancho, alto, bytesFila, filaPieza + 1, colPieza, giro)) {
        marcarPiezaI(tab, bytesFila, filaPieza, colPieza, giro, true);
        return false;
    }
    filaPieza = filaPieza + 1;
    marcarPiezaI(tab, bytesFila, filaPieza, colPieza, giro, true);
    return true;
}

bool moverPiezaIIzq(unsigned char* tab, int ancho, int alto, int bytesFila, int& filaPieza, int& colPieza, int giro) {
    if (colPieza <= 0) return false;
    marcarPiezaI(tab, bytesFila, filaPieza, colPieza, giro, false);
    if (!cabePiezaI(tab, ancho, alto, bytesFila, filaPieza, colPieza - 1, giro)) {
        marcarPiezaI(tab, bytesFila, filaPieza, colPieza, giro, true);
        return false;
    }
    colPieza = colPieza - 1;
    marcarPiezaI(tab, bytesFila, filaPieza, colPieza, giro, true);
    return true;
}

bool moverPiezaIDer(unsigned char* tab, int ancho, int alto, int bytesFila, int& filaPieza, int& colPieza, int giro) {
    if (giro == 0 && colPieza + 1 >= ancho) return false;
    if (giro == 1 && colPieza + 4 >= ancho) return false;
    marcarPiezaI(tab, bytesFila, filaPieza, colPieza, giro, false);
    if (!cabePiezaI(tab, ancho, alto, bytesFila, filaPieza, colPieza + 1, giro)) {
        marcarPiezaI(tab, bytesFila, filaPieza, colPieza, giro, true);
        return false;
    }
    colPieza = colPieza + 1;
    marcarPiezaI(tab, bytesFila, filaPieza, colPieza, giro, true);
    return true;
}

bool rotarPiezaI(unsigned char* tab, int ancho, int alto, int bytesFila, int& filaPieza, int& colPieza, int& giro) {
    int nuevoGiro = 0;
    if (giro == 0) nuevoGiro = 1;
    marcarPiezaI(tab, bytesFila, filaPieza, colPieza, giro, false);
    if (!cabePiezaI(tab, ancho, alto, bytesFila, filaPieza, colPieza, nuevoGiro)) {
        marcarPiezaI(tab, bytesFila, filaPieza, colPieza, giro, true);
        return false;
    }
    giro = nuevoGiro;
    marcarPiezaI(tab, bytesFila, filaPieza, colPieza, giro, true);
    return true;
}

bool rotarPiezaS(unsigned char* tab, int ancho, int alto, int bytesFila, int& filaPieza, int& colPieza, int& giro) {
    int nuevoGiro = 0;
    if (giro == 0) nuevoGiro = 1;
    marcarPiezaS(tab, bytesFila, filaPieza, colPieza, giro, false);
    if (!cabePiezaS(tab, ancho, alto, bytesFila, filaPieza, colPieza, nuevoGiro)) {
        marcarPiezaS(tab, bytesFila, filaPieza, colPieza, giro, true);
        return false;
    }
    giro = nuevoGiro;
    marcarPiezaS(tab, bytesFila, filaPieza, colPieza, giro, true);
    return true;
}