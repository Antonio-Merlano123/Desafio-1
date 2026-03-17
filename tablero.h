#ifndef TABLERO_H
#define TABLERO_H

// valida reglas del tablero
bool validarDatos(int ancho, int alto);

// crea tablero dinamico y lo deja vacio
bool crearTablero(int ancho, int alto,
                   int& bytesFila, int& tamTotal,
                   unsigned char*& tab);

// libera memoria
void liberarTablero(unsigned char*& tab);

// revisa si una celda esta prendida o apagada
bool leerCelda(const unsigned char* tab, int bytesFila, int fila, int col);

// prende o apaga una celda
void cambiarCelda(unsigned char* tab, int bytesFila, int fila, int col, bool valor);

// imprime tablero con # y .
void imprimirTablero(const unsigned char* tab,int ancho, int alto, int bytesFila);

#endif
