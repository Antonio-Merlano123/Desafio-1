#include "pieza.h"
#include "tablero.h"
#include <cstdlib>

// esta me ayuda a dibujar o borrar la O
void marcarPiezaO(unsigned char* tab, int bytesFila,
                 int filaPieza, int colPieza, bool valor) {
    cambiarCelda(tab, bytesFila, filaPieza, colPieza, valor);
    cambiarCelda(tab, bytesFila, filaPieza, colPieza + 1, valor);
    cambiarCelda(tab, bytesFila, filaPieza + 1, colPieza, valor);
    cambiarCelda(tab, bytesFila, filaPieza + 1, colPieza + 1, valor);
}

// esta me ayuda a dibujar o borrar la I vertical
void marcarPiezaI(unsigned char* tab, int bytesFila,
                 int filaPieza, int colPieza, bool valor) {
    cambiarCelda(tab, bytesFila, filaPieza, colPieza, valor);
    cambiarCelda(tab, bytesFila, filaPieza + 1, colPieza, valor);
    cambiarCelda(tab, bytesFila, filaPieza + 2, colPieza, valor);
    cambiarCelda(tab, bytesFila, filaPieza + 3, colPieza, valor);
}

// revisa si la O cabe en esa posicion
bool cabePiezaO(const unsigned char* tab, int ancho, int alto, int bytesFila,
               int filaPieza, int colPieza) {
    if (filaPieza < 0 || colPieza < 0) {
        return false;
    }

    if (filaPieza + 1 >= alto || colPieza + 1 >= ancho) {
        return false;
    }

    if (leerCelda(tab, bytesFila, filaPieza, colPieza)) return false;
    if (leerCelda(tab, bytesFila, filaPieza, colPieza + 1)) return false;
    if (leerCelda(tab, bytesFila, filaPieza + 1, colPieza)) return false;
    if (leerCelda(tab, bytesFila, filaPieza + 1, colPieza + 1)) return false;

    return true;
}

// revisa si la I vertical cabe en esa posicion
bool cabePiezaI(const unsigned char* tab, int ancho, int alto, int bytesFila,
               int filaPieza, int colPieza) {
    if (filaPieza < 0 || colPieza < 0) {
        return false;
    }

    if (filaPieza + 3 >= alto || colPieza >= ancho) {
        return false;
    }

    if (leerCelda(tab, bytesFila, filaPieza, colPieza)) return false;
    if (leerCelda(tab, bytesFila, filaPieza + 1, colPieza)) return false;
    if (leerCelda(tab, bytesFila, filaPieza + 2, colPieza)) return false;
    if (leerCelda(tab, bytesFila, filaPieza + 3, colPieza)) return false;

    return true;
}

bool ponerPiezaO(unsigned char* tab, int ancho, int alto, int bytesFila,
                 int& filaPieza, int& colPieza) {
    filaPieza = 0;
    colPieza = ancho / 2 - 1;

    if (colPieza < 0) {
        colPieza = 0;
    }

    if (!cabePiezaO(tab, ancho, alto, bytesFila, filaPieza, colPieza)) {
        return false;
    }

    marcarPiezaO(tab, bytesFila, filaPieza, colPieza, true);

    return true;
}

bool ponerPiezaI(unsigned char* tab, int ancho, int alto, int bytesFila,
                 int& filaPieza, int& colPieza) {
    filaPieza = 0;
    colPieza = ancho / 2;

    if (!cabePiezaI(tab, ancho, alto, bytesFila, filaPieza, colPieza)) {
        return false;
    }

    marcarPiezaI(tab, bytesFila, filaPieza, colPieza, true);
    return true;
}

bool ponerPiezaAleatoria(unsigned char* tab, int ancho, int alto, int bytesFila,
                         int& tipoPieza, int& filaPieza, int& colPieza) {
    tipoPieza = rand() % 2; // 0 O, 1 I

    if (tipoPieza == 0) {
        return ponerPiezaO(tab, ancho, alto, bytesFila, filaPieza, colPieza);
    }

    return ponerPiezaI(tab, ancho, alto, bytesFila, filaPieza, colPieza);
}

bool moverPiezaOIzq(unsigned char* tab, int ancho, int alto, int bytesFila,
                    int& filaPieza, int& colPieza) {
    if (colPieza <= 0) {
        return false; // ya llego al borde
    }

    marcarPiezaO(tab, bytesFila, filaPieza, colPieza, false); // borro donde estaba

    if (!cabePiezaO(tab, ancho, alto, bytesFila, filaPieza, colPieza - 1)) {
        marcarPiezaO(tab, bytesFila, filaPieza, colPieza, true); // la dejo donde estaba
        return false;
    }

    colPieza = colPieza - 1;
    marcarPiezaO(tab, bytesFila, filaPieza, colPieza, true);  // dibujo en la nueva

    return true;
}

bool moverPiezaODer(unsigned char* tab, int ancho, int alto, int bytesFila,
                    int& filaPieza, int& colPieza) {
    if (colPieza + 2 >= ancho) {
        return false; // ya llego al borde
    }

    marcarPiezaO(tab, bytesFila, filaPieza, colPieza, false);

    if (!cabePiezaO(tab, ancho, alto, bytesFila, filaPieza, colPieza + 1)) {
        marcarPiezaO(tab, bytesFila, filaPieza, colPieza, true);
        return false;
    }

    colPieza = colPieza + 1;
    marcarPiezaO(tab, bytesFila, filaPieza, colPieza, true);

    return true;
}

bool moverPiezaOAbajo(unsigned char* tab, int ancho, int alto, int bytesFila,
                      int& filaPieza, int& colPieza) {
    if (filaPieza + 2 >= alto) {
        return false; // ya llego al fondo
    }

    marcarPiezaO(tab, bytesFila, filaPieza, colPieza, false);

    if (!cabePiezaO(tab, ancho, alto, bytesFila, filaPieza + 1, colPieza)) {
        marcarPiezaO(tab, bytesFila, filaPieza, colPieza, true);
        return false;
    }

    filaPieza = filaPieza + 1;
    marcarPiezaO(tab, bytesFila, filaPieza, colPieza, true);

    return true;
}

bool moverPiezaIAbajo(unsigned char* tab, int ancho, int alto, int bytesFila,
                      int& filaPieza, int& colPieza) {
    if (filaPieza + 4 >= alto) {
        return false;
    }

    marcarPiezaI(tab, bytesFila, filaPieza, colPieza, false);

    if (!cabePiezaI(tab, ancho, alto, bytesFila, filaPieza + 1, colPieza)) {
        marcarPiezaI(tab, bytesFila, filaPieza, colPieza, true);
        return false;
    }

    filaPieza = filaPieza + 1;
    marcarPiezaI(tab, bytesFila, filaPieza, colPieza, true);
    return true;
}