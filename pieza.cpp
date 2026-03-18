#include "pieza.h"
#include "tablero.h"

// funcion interna: prende o apaga la pieza O
void marcarPiezaO(unsigned char* tab, int bytesFila,
                 int filaPieza, int colPieza, bool valor) {
    cambiarCelda(tab, bytesFila, filaPieza, colPieza, valor);
    cambiarCelda(tab, bytesFila, filaPieza, colPieza + 1, valor);
    cambiarCelda(tab, bytesFila, filaPieza + 1, colPieza, valor);
    cambiarCelda(tab, bytesFila, filaPieza + 1, colPieza + 1, valor);
}

bool ponerPiezaO(unsigned char* tab, int ancho, int alto, int bytesFila,
                 int& filaPieza, int& colPieza) {
    filaPieza = 0;
    colPieza = ancho / 2 - 1;

    if (colPieza < 0) {
        colPieza = 0;
    }

    if (alto < 2 || colPieza + 1 >= ancho) {
        return false;
    }

    marcarPiezaO(tab, bytesFila, filaPieza, colPieza, true);

    return true;
}

bool moverPiezaOIzq(unsigned char* tab, int bytesFila,
                    int& filaPieza, int& colPieza) {
    if (colPieza <= 0) {
        return false; // ya llego al borde
    }

    marcarPiezaO(tab, bytesFila, filaPieza, colPieza, false); // borro donde estaba
    colPieza = colPieza - 1;
    marcarPiezaO(tab, bytesFila, filaPieza, colPieza, true);  // dibujo en la nueva

    return true;
}

bool moverPiezaODer(unsigned char* tab, int ancho, int bytesFila,
                    int& filaPieza, int& colPieza) {
    if (colPieza + 2 >= ancho) {
        return false; // ya llego al borde
    }

    marcarPiezaO(tab, bytesFila, filaPieza, colPieza, false);
    colPieza = colPieza + 1;
    marcarPiezaO(tab, bytesFila, filaPieza, colPieza, true);

    return true;
}

bool moverPiezaOAbajo(unsigned char* tab, int alto, int bytesFila,
                      int& filaPieza, int& colPieza) {
    if (filaPieza + 2 >= alto) {
        return false; // ya llego al fondo
    }

    marcarPiezaO(tab, bytesFila, filaPieza, colPieza, false);
    filaPieza = filaPieza + 1;
    marcarPiezaO(tab, bytesFila, filaPieza, colPieza, true);

    return true;
}