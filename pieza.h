#ifndef PIEZA_H
#define PIEZA_H

// pone una pieza O sencilla arriba en el centro
bool ponerPiezaO(unsigned char* tab, int ancho, int alto, int bytesFila,
                 int& filaPieza, int& colPieza);

// pone una pieza I vertical arriba
bool ponerPiezaI(unsigned char* tab, int ancho, int alto, int bytesFila,
                 int& filaPieza, int& colPieza);

// pone una pieza aleatoria (0 = O, 1 = I)
bool ponerPiezaAleatoria(unsigned char* tab, int ancho, int alto, int bytesFila,
                         int& tipoPieza, int& filaPieza, int& colPieza);

// mueve la pieza O una posicion a la izquierda
bool moverPiezaOIzq(unsigned char* tab, int ancho, int alto, int bytesFila,
                    int& filaPieza, int& colPieza);

// mueve la pieza O una posicion a la derecha
bool moverPiezaODer(unsigned char* tab, int ancho, int alto, int bytesFila,
                    int& filaPieza, int& colPieza);

// mueve la pieza O una posicion hacia abajo
bool moverPiezaOAbajo(unsigned char* tab, int ancho, int alto, int bytesFila,
                      int& filaPieza, int& colPieza);

// mueve una pieza I hacia abajo
bool moverPiezaIAbajo(unsigned char* tab, int ancho, int alto, int bytesFila,
                      int& filaPieza, int& colPieza);

// mueve una pieza I a la izquierda
bool moverPiezaIIzq(unsigned char* tab, int ancho, int alto, int bytesFila,
                    int& filaPieza, int& colPieza);

// mueve una pieza I a la derecha
bool moverPiezaIDer(unsigned char* tab, int ancho, int alto, int bytesFila,
                    int& filaPieza, int& colPieza);

#endif