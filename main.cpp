#include <iostream>
#include "tablero.h"
#include "pieza.h"

using namespace std;

int main() {
    // variables de control del tablero
    int ancho = 0;
    int alto = 0;
    int bytesFila = 0;      // cuantos bytes caben en cada fila
    int tamTotal = 0;       // memoria total que necesitao
    int filaPieza = 0;
    int colPieza = 0;
    unsigned char* tab = 0; // punteroal tablero dinamico

    cout << "Ancho del tablero (minimo 8, multiplo de 8): ";
    cin >> ancho;
    cout << "Alto del tablero (minimo 8): ";
    cin >> alto;

    // verificamos que el usuario haya ingresado numeros validos
    if (!cin) {
        cout << "entrada invalida\n";
        return 0;
    }

    // validamos que cumplan reglas (minimo 8x8, ancho multiplo de 8)
    if (!validarDatos(ancho, alto)) {
        cout << "error: dimensiones invalidas\n";
        return 0;
    }

    // allocamos memoria dinamica para el tablero
    if (!crearTablero(ancho, alto, bytesFila, tamTotal, tab)) {
        cout << "error: no se pudo crear tablero\n";
        return 0;
    }

    // mostramos informacion: cuanta memoria usamos
    cout << "bytes por fila: " << bytesFila << "\n";
    cout << "tamano total: " << tamTotal << "\n";
    cout << "\ntablero vacio:\n";
    imprimirTablero(tab, ancho, alto, bytesFila);

    if (!ponerPiezaO(tab, ancho, alto, bytesFila, filaPieza, colPieza)) {
        cout << "error: no se pudo poner la pieza\n";
        liberarTablero(tab);
        return 0;
    }

    cout << "\npieza O puesta arriba:\n";
    imprimirTablero(tab, ancho, alto, bytesFila);

    // liberamos la memoria que allocamos con new[] para evitar memory leak
    liberarTablero(tab);
    return 0;
}

