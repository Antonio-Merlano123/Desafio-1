#ifndef PIEZA_H
#define PIEZA_H

bool ponerPiezaO(unsigned char* tab, int ancho, int alto, int bytesFila, int& filaPieza, int& colPieza);
bool moverPiezaOIzq(unsigned char* tab, int ancho, int alto, int bytesFila, int& filaPieza, int& colPieza);
bool moverPiezaODer(unsigned char* tab, int ancho, int alto, int bytesFila, int& filaPieza, int& colPieza);
bool moverPiezaOAbajo(unsigned char* tab, int ancho, int alto, int bytesFila, int& filaPieza, int& colPieza);

bool ponerPiezaT(unsigned char* tab, int ancho, int alto, int bytesFila, int& filaPieza, int& colPieza);
bool moverPiezaTAbajo(unsigned char* tab, int ancho, int alto, int bytesFila, int& filaPieza, int& colPieza);
bool moverPiezaTIzq(unsigned char* tab, int ancho, int alto, int bytesFila, int& filaPieza, int& colPieza);
bool moverPiezaTDer(unsigned char* tab, int ancho, int alto, int bytesFila, int& filaPieza, int& colPieza);
bool ponerPiezaL(unsigned char* tab, int ancho, int alto, int bytesFila, int& filaPieza, int& colPieza);
bool moverPiezaLDer(unsigned char* tab, int ancho, int alto, int bytesFila, int& filaPieza, int& colPieza);
bool moverPiezaLIzq(unsigned char* tab, int ancho, int alto, int bytesFila, int& filaPieza, int& colPieza);
bool moverPiezaLAbajo(unsigned char* tab, int ancho, int alto, int bytesFila, int& filaPieza, int& colPieza);

bool ponerPiezaI(unsigned char* tab, int ancho, int alto, int bytesFila, int& filaPieza, int& colPieza, int& giro);
bool moverPiezaIAbajo(unsigned char* tab, int ancho, int alto, int bytesFila, int& filaPieza, int& colPieza, int giro);
bool moverPiezaIIzq(unsigned char* tab, int ancho, int alto, int bytesFila, int& filaPieza, int& colPieza, int giro);
bool moverPiezaIDer(unsigned char* tab, int ancho, int alto, int bytesFila, int& filaPieza, int& colPieza, int giro);
bool rotarPiezaI(unsigned char* tab, int ancho, int alto, int bytesFila, int& filaPieza, int& colPieza, int& giro);
bool ponerPiezaS(unsigned char* tab, int ancho, int alto, int bytesFila, int& filaPieza, int& colPieza, int& giro);
bool moverPiezaSIzq(unsigned char* tab, int ancho, int alto, int bytesFila, int& filaPieza, int& colPieza, int giro);
bool moverPiezaSDer(unsigned char* tab, int ancho, int alto, int bytesFila, int& filaPieza, int& colPieza, int giro);
bool moverPiezaSAbajo(unsigned char* tab, int ancho, int alto, int bytesFila, int& filaPieza, int& colPieza, int giro);
bool rotarPiezaS(unsigned char* tab, int ancho, int alto, int bytesFila, int& filaPieza, int& colPieza, int& giro);

bool ponerPiezaAleatoria(unsigned char* tab, int ancho, int alto, int bytesFila, int& tipoPieza, int& filaPieza, int& colPieza, int& giro);

#endif
