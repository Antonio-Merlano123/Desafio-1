#ifndef PIEZA_H
#define PIEZA_H

// pone una pieza O sencilla arriba en el centro
bool ponerPiezaO(unsigned char* tab, int ancho, int alto, int bytesFila,
                 int& filaPieza, int& colPieza);

// mueve la pieza O una posicion a la izquierda
bool moverPiezaOIzq(unsigned char* tab, int ancho, int alto, int bytesFila,
                    int& filaPieza, int& colPieza);

// mueve la pieza O una posicion a la derecha
bool moverPiezaODer(unsigned char* tab, int ancho, int alto, int bytesFila,
                    int& filaPieza, int& colPieza);

// mueve la pieza O una posicion hacia abajo
bool moverPiezaOAbajo(unsigned char* tab, int ancho, int alto, int bytesFila,
                      int& filaPieza, int& colPieza);

#endif