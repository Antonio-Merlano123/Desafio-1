#include "pieza.h"
#include "tablero.h"

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

    cambiarCelda(tab, bytesFila, filaPieza, colPieza, true);
    cambiarCelda(tab, bytesFila, filaPieza, colPieza + 1, true);
    cambiarCelda(tab, bytesFila, filaPieza + 1, colPieza, true);
    cambiarCelda(tab, bytesFila, filaPieza + 1, colPieza + 1, true);

    return true;
}