#include <iostream>
#include "tablero.h"

using namespace std;

int main() {
    // variables de control del tablero
    int ancho = 0;
    int alto = 0;
    int bytesFila = 0;      // cuantos bytes caben en cada fila
    int tamTotal = 0;       // memoria total que necesitamos
    unsigned char* tab = 0; // puntero al tablero dinamico

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

    // liberamos la memoria que allocamos con new[] para evitar memory leak
    liberarTablero(tab);
    return 0;
}

