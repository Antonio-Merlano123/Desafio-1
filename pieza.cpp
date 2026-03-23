#include "pieza.h"
#include "tablero.h"
#include <cstdlib>

void marcarPiezaO(unsigned char* tab, int bytesFila, int filaPieza, int colPieza, bool valor) {
    cambiarCelda(tab, bytesFila, filaPieza, colPieza, valor);
    cambiarCelda(tab, bytesFila, filaPieza, colPieza + 1, valor);
    cambiarCelda(tab, bytesFila, filaPieza + 1, colPieza, valor);
    cambiarCelda(tab, bytesFila, filaPieza + 1, colPieza + 1, valor);
}

bool cabePiezaO(const unsigned char* tab, int ancho, int alto, int bytesFila, int filaPieza, int colPieza) {
    if (filaPieza < 0 || colPieza < 0) return false;
    if (filaPieza + 1 >= alto || colPieza + 1 >= ancho) return false;
    if (leerCelda(tab, bytesFila, filaPieza, colPieza)) return false;
    if (leerCelda(tab, bytesFila, filaPieza, colPieza + 1)) return false;
    if (leerCelda(tab, bytesFila, filaPieza + 1, colPieza)) return false;
    if (leerCelda(tab, bytesFila, filaPieza + 1, colPieza + 1)) return false;
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

bool moverPiezaOIzq(unsigned char* tab, int ancho, int alto, int bytesFila, int& filaPieza, int& colPieza) {
    if (colPieza <= 0) return false;

    marcarPiezaO(tab, bytesFila, filaPieza, colPieza, false);
    if (!cabePiezaO(tab, ancho, alto, bytesFila, filaPieza, colPieza - 1)) {
        marcarPiezaO(tab, bytesFila, filaPieza, colPieza, true);
        return false;
    }

    colPieza = colPieza - 1;
    marcarPiezaO(tab, bytesFila, filaPieza, colPieza, true);
    return true;
}

bool moverPiezaODer(unsigned char* tab, int ancho, int alto, int bytesFila, int& filaPieza, int& colPieza) {
    if (colPieza + 2 >= ancho) return false;
    int nuevaCol = colPieza + 1;

    marcarPiezaO(tab, bytesFila, filaPieza, colPieza, false);
    if (!cabePiezaO(tab, ancho, alto, bytesFila, filaPieza, nuevaCol)) {
        marcarPiezaO(tab, bytesFila, filaPieza, colPieza, true);
        return false;
    }

    colPieza = nuevaCol;
    marcarPiezaO(tab, bytesFila, filaPieza, colPieza, true);
    return true;
}

bool moverPiezaOAbajo(unsigned char* tab, int ancho, int alto, int bytesFila, int& filaPieza, int& colPieza) {
    if (filaPieza + 2 >= alto) return false;

    marcarPiezaO(tab, bytesFila, filaPieza, colPieza, false);
    if (!cabePiezaO(tab, ancho, alto, bytesFila, filaPieza + 1, colPieza)) {
        marcarPiezaO(tab, bytesFila, filaPieza, colPieza, true);
        return false;
    }

    filaPieza++;
    marcarPiezaO(tab, bytesFila, filaPieza, colPieza, true);
    return true;
}

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

bool cabePiezaI(const unsigned char* tab, int ancho, int alto, int bytesFila, int filaPieza, int colPieza, int giro) {
    if (filaPieza < 0 || colPieza < 0) return false;

    if (giro == 0) {
        if (filaPieza + 3 >= alto || colPieza >= ancho) return false;
        if (leerCelda(tab, bytesFila, filaPieza, colPieza)) return false;
        if (leerCelda(tab, bytesFila, filaPieza + 1, colPieza)) return false;
        if (leerCelda(tab, bytesFila, filaPieza + 2, colPieza)) return false;
        if (leerCelda(tab, bytesFila, filaPieza + 3, colPieza)) return false;
    } else {
        if (filaPieza >= alto || colPieza + 3 >= ancho) return false;
        if (leerCelda(tab, bytesFila, filaPieza, colPieza)) return false;
        if (leerCelda(tab, bytesFila, filaPieza, colPieza + 1)) return false;
        if (leerCelda(tab, bytesFila, filaPieza, colPieza + 2)) return false;
        if (leerCelda(tab, bytesFila, filaPieza, colPieza + 3)) return false;
    }

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

bool moverPiezaIAbajo(unsigned char* tab, int ancho, int alto, int bytesFila, int& filaPieza, int& colPieza, int giro) {
    int nuevaFila = filaPieza + 1;
    marcarPiezaI(tab, bytesFila, filaPieza, colPieza, giro, false);

    if (!cabePiezaI(tab, ancho, alto, bytesFila, nuevaFila, colPieza, giro)) {
        marcarPiezaI(tab, bytesFila, filaPieza, colPieza, giro, true);
        return false;
    }

    filaPieza = nuevaFila;
    marcarPiezaI(tab, bytesFila, filaPieza, colPieza, giro, true);
    return true;
}

bool moverPiezaIIzq(unsigned char* tab, int ancho, int alto, int bytesFila, int& filaPieza, int& colPieza, int giro) {
    if (colPieza == 0) return false;
    int nuevaCol = colPieza - 1;

    marcarPiezaI(tab, bytesFila, filaPieza, colPieza, giro, false);
    if (!cabePiezaI(tab, ancho, alto, bytesFila, filaPieza, nuevaCol, giro)) {
        marcarPiezaI(tab, bytesFila, filaPieza, colPieza, giro, true);
        return false;
    }

    colPieza = nuevaCol;
    marcarPiezaI(tab, bytesFila, filaPieza, colPieza, giro, true);
    return true;
}

bool moverPiezaIDer(unsigned char* tab, int ancho, int alto, int bytesFila, int& filaPieza, int& colPieza, int giro) {
    if ((giro == 0 && colPieza + 1 >= ancho) || (giro == 1 && colPieza + 4 >= ancho)) return false;

    marcarPiezaI(tab, bytesFila, filaPieza, colPieza, giro, false);
    if (!cabePiezaI(tab, ancho, alto, bytesFila, filaPieza, colPieza + 1, giro)) {
        marcarPiezaI(tab, bytesFila, filaPieza, colPieza, giro, true);
        return false;
    }

    colPieza++;
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

void marcarPiezaT(unsigned char* tab, int bytesFila, int filaPieza, int colPieza, bool valor) {
    cambiarCelda(tab, bytesFila, filaPieza, colPieza, valor);
    cambiarCelda(tab, bytesFila, filaPieza, colPieza + 1, valor);
    cambiarCelda(tab, bytesFila, filaPieza, colPieza + 2, valor);
    cambiarCelda(tab, bytesFila, filaPieza + 1, colPieza + 1, valor);
}

bool cabePiezaT(const unsigned char* tab, int ancho, int alto, int bytesFila, int filaPieza, int colPieza) {
    if (filaPieza < 0 || colPieza < 0) return false;
    if (filaPieza + 1 >= alto) return false;
    if (colPieza + 2 >= ancho) return false;

    bool libre = true;
    if (leerCelda(tab, bytesFila, filaPieza, colPieza)) libre = false;
    if (leerCelda(tab, bytesFila, filaPieza, colPieza + 1)) libre = false;
    if (leerCelda(tab, bytesFila, filaPieza, colPieza + 2)) libre = false;
    if (leerCelda(tab, bytesFila, filaPieza + 1, colPieza + 1)) libre = false;
    return libre;
}

bool ponerPiezaT(unsigned char* tab, int ancho, int alto, int bytesFila, int& filaPieza, int& colPieza) {
    filaPieza = 0;
    colPieza = ancho / 2 - 1;

    if (colPieza < 0) {
        colPieza = 0;
    }
    if (!cabePiezaT(tab, ancho, alto, bytesFila, filaPieza, colPieza)) return false;

    marcarPiezaT(tab, bytesFila, filaPieza, colPieza, true);
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
    int nuevaFila = filaPieza + 1;
    marcarPiezaT(tab, bytesFila, filaPieza, colPieza, false);

    if (!cabePiezaT(tab, ancho, alto, bytesFila, nuevaFila, colPieza)) {
        marcarPiezaT(tab, bytesFila, filaPieza, colPieza, true);
        return false;
    }

    filaPieza = nuevaFila;
    marcarPiezaT(tab, bytesFila, filaPieza, colPieza, true);
    return true;
}

void marcarPiezaL(unsigned char* tab, int bytesFila, int filaPieza, int colPieza, bool valor) {
    cambiarCelda(tab, bytesFila, filaPieza, colPieza, valor);
    cambiarCelda(tab, bytesFila, filaPieza + 1, colPieza, valor);
    cambiarCelda(tab, bytesFila, filaPieza + 2, colPieza, valor);
    cambiarCelda(tab, bytesFila, filaPieza + 2, colPieza + 1, valor);
}

bool cabePiezaL(const unsigned char* tab, int ancho, int alto, int bytesFila, int filaPieza, int colPieza) {
    if (filaPieza < 0 || colPieza < 0) return false;
    if (filaPieza + 2 >= alto) return false;
    if (colPieza + 1 >= ancho) return false;
    if (leerCelda(tab, bytesFila, filaPieza, colPieza)) return false;
    if (leerCelda(tab, bytesFila, filaPieza + 1, colPieza)) return false;
    if (leerCelda(tab, bytesFila, filaPieza + 2, colPieza)) return false;
    if (leerCelda(tab, bytesFila, filaPieza + 2, colPieza + 1)) return false;
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

bool moverPiezaLIzq(unsigned char* tab, int ancho, int alto, int bytesFila, int& filaPieza, int& colPieza) {
    if (colPieza == 0) return false;

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

bool cabePiezaS(const unsigned char* tab, int ancho, int alto, int bytesFila, int filaPieza, int colPieza, int giro) {
    if (filaPieza < 0 || colPieza < 0) return false;

    if (giro == 0) {
        if (filaPieza + 1 >= alto || colPieza + 2 >= ancho) return false;
        if (leerCelda(tab, bytesFila, filaPieza, colPieza + 1)) return false;
        if (leerCelda(tab, bytesFila, filaPieza, colPieza + 2)) return false;
        if (leerCelda(tab, bytesFila, filaPieza + 1, colPieza)) return false;
        if (leerCelda(tab, bytesFila, filaPieza + 1, colPieza + 1)) return false;
    } else {
        if (filaPieza + 2 >= alto || colPieza + 1 >= ancho) return false;
        if (leerCelda(tab, bytesFila, filaPieza, colPieza)) return false;
        if (leerCelda(tab, bytesFila, filaPieza + 1, colPieza)) return false;
        if (leerCelda(tab, bytesFila, filaPieza + 1, colPieza + 1)) return false;
        if (leerCelda(tab, bytesFila, filaPieza + 2, colPieza + 1)) return false;
    }

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

bool moverPiezaSIzq(unsigned char* tab, int ancho, int alto, int bytesFila, int& filaPieza, int& colPieza, int giro) {
    if (colPieza <= 0) return false;

    marcarPiezaS(tab, bytesFila, filaPieza, colPieza, giro, false);
    if (!cabePiezaS(tab, ancho, alto, bytesFila, filaPieza, colPieza - 1, giro)) {
        marcarPiezaS(tab, bytesFila, filaPieza, colPieza, giro, true);
        return false;
    }

    colPieza--;
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

bool ponerPiezaAleatoria(unsigned char* tab, int ancho, int alto, int bytesFila, int& tipoPieza, int& filaPieza, int& colPieza, int& giro) {
    tipoPieza = rand() % 5;

    switch (tipoPieza) {
    case 0:
        giro = 0;
        return ponerPiezaO(tab, ancho, alto, bytesFila, filaPieza, colPieza);
    case 1:
        return ponerPiezaI(tab, ancho, alto, bytesFila, filaPieza, colPieza, giro);
    case 2:
        giro = 0;
        return ponerPiezaT(tab, ancho, alto, bytesFila, filaPieza, colPieza);
    case 3:
        giro = 0;
        return ponerPiezaL(tab, ancho, alto, bytesFila, filaPieza, colPieza);
    default:
        giro = 0;
        return ponerPiezaS(tab, ancho, alto, bytesFila, filaPieza, colPieza, giro);
    }
}