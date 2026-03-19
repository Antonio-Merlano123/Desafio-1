#ifndef TABLERO_H
#define TABLERO_H

// valida reglas del tablero
bool validarDatos(int ancho, int alto);

// crea el tablero dinamico y lo deja vacio
bool crearTablero(int ancho, int alto, int& bytesFila, int& tamTotal, unsigned char*& tab);

// libera la memoria del tablero
void liberarTablero(unsigned char*& tab);

// devuelve true si la celda esta prendida
bool leerCelda(const unsigned char* tab, int bytesFila, int fila, int col);

// prende o apaga una celda
void cambiarCelda(unsigned char* tab, int bytesFila, int fila, int col, bool valor);

// imprime el tablero con # y .
void imprimirTablero(const unsigned char* tab, int ancho, int alto, int bytesFila);

// revisa si una fila esta llena
bool filaLlena(const unsigned char* tab, int ancho, int bytesFila, int fila);

// borra una fila y baja las de arriba
void borrarFila(unsigned char* tab, int ancho, int alto, int bytesFila, int fila);

// limpia todas las filas llenas y devuelve cuantas borro
int limpiarFilas(unsigned char* tab, int ancho, int alto, int bytesFila);

#endif
