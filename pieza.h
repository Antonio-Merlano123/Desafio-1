#ifndef PIEZA_H
#define PIEZA_H

// pone una pieza O sencilla arriba en el centro
bool ponerPiezaO(unsigned char* tab, int ancho, int alto, int bytesFila, int& filaPieza, int& colPieza);

// pone una pieza I vertical arriba
bool ponerPiezaI(unsigned char* tab, int ancho, int alto, int bytesFila, int& filaPieza, int& colPieza, int& giroI);

// pone una pieza T fija (sin rotar)
bool ponerPiezaT(unsigned char* tab, int ancho, int alto, int bytesFila, int& filaPieza, int& colPieza);

// pone una pieza L fija (sin rotar)
bool ponerPiezaL(unsigned char* tab, int ancho, int alto, int bytesFila, int& filaPieza, int& colPieza);

// pone una pieza S fija (sin rotar)
bool ponerPiezaS(unsigned char* tab, int ancho, int alto, int bytesFila, int& filaPieza, int& colPieza);

// pone una pieza aleatoria (0=O 1=I 2=T 3=L 4=S)
bool ponerPiezaAleatoria(unsigned char* tab, int ancho, int alto, int bytesFila, int& tipoPieza, int& filaPieza, int& colPieza, int& giroI);

// mueve la pieza O una posicion a la izquierda
bool moverPiezaOIzq(unsigned char* tab, int ancho, int alto, int bytesFila, int& filaPieza, int& colPieza);

// mueve la pieza O una posicion a la derecha
bool moverPiezaODer(unsigned char* tab, int ancho, int alto, int bytesFila, int& filaPieza, int& colPieza);

// mueve la pieza O una posicion hacia abajo
bool moverPiezaOAbajo(unsigned char* tab, int ancho, int alto, int bytesFila, int& filaPieza, int& colPieza);

// mueve una pieza T
bool moverPiezaTIzq(unsigned char* tab, int ancho, int alto, int bytesFila, int& filaPieza, int& colPieza);
bool moverPiezaTDer(unsigned char* tab, int ancho, int alto, int bytesFila, int& filaPieza, int& colPieza);
bool moverPiezaTAbajo(unsigned char* tab, int ancho, int alto, int bytesFila, int& filaPieza, int& colPieza);

// mueve una pieza L
bool moverPiezaLIzq(unsigned char* tab, int ancho, int alto, int bytesFila, int& filaPieza, int& colPieza);
bool moverPiezaLDer(unsigned char* tab, int ancho, int alto, int bytesFila, int& filaPieza, int& colPieza);
bool moverPiezaLAbajo(unsigned char* tab, int ancho, int alto, int bytesFila, int& filaPieza, int& colPieza);

// mueve una pieza S
bool moverPiezaSIzq(unsigned char* tab, int ancho, int alto, int bytesFila, int& filaPieza, int& colPieza);
bool moverPiezaSDer(unsigned char* tab, int ancho, int alto, int bytesFila, int& filaPieza, int& colPieza);
bool moverPiezaSAbajo(unsigned char* tab, int ancho, int alto, int bytesFila, int& filaPieza, int& colPieza);

// mueve una pieza I hacia abajo
bool moverPiezaIAbajo(unsigned char* tab, int ancho, int alto, int bytesFila, int& filaPieza, int& colPieza, int giroI);

// mueve una pieza I a la izquierda
bool moverPiezaIIzq(unsigned char* tab, int ancho, int alto, int bytesFila, int& filaPieza, int& colPieza, int giroI);

// mueve una pieza I a la derecha
bool moverPiezaIDer(unsigned char* tab, int ancho, int alto, int bytesFila, int& filaPieza, int& colPieza, int giroI);

// rota la pieza I (vertical y horizontal)
bool rotarPiezaI(unsigned char* tab, int ancho, int alto, int bytesFila, int& filaPieza, int& colPieza, int& giroI);

#endif