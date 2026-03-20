#ifndef TABLERO_H
#define TABLERO_H

bool validarDatos(int ancho, int alto);
bool crearTablero(int ancho, int alto, int& bytesFila, int& tamTotal, unsigned char*& tab);
void liberarTablero(unsigned char*& tab);

bool leerCelda(const unsigned char* tab, int bytesFila, int fila, int col);
void cambiarCelda(unsigned char* tab, int bytesFila, int fila, int col, bool valor);
void imprimirTablero(const unsigned char* tab, int ancho, int alto, int bytesFila);

bool filaLlena(const unsigned char* tab, int ancho, int bytesFila, int fila);
void borrarFila(unsigned char* tab, int ancho, int alto, int bytesFila, int fila);
int limpiarFilas(unsigned char* tab, int ancho, int alto, int bytesFila);

#endif
