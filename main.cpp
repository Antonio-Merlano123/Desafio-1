#include <iostream>
#include <ctime>
#include "tablero.h"
#include "pieza.h"

using namespace std;

bool fijarYSeguir(unsigned char* tab, int ancho, int alto, int bytesFila, int& tipoPieza, int& filaPieza, int& colPieza, int& giro) {
    cout << "pieza fija\n";
    int filas = limpiarFilas(tab, ancho, alto, bytesFila);
    if (filas > 0) cout << "borre " << filas << " filas\n";
    if (!ponerPiezaAleatoria(tab, ancho, alto, bytesFila, tipoPieza, filaPieza, colPieza, giro)) {
        cout << "game over\n";
        return false;
    }
    return true;
}

int main() {
    int ancho = 0;
    int alto = 0;
    int bytesFila = 0;
    int tamTotal = 0;
    int tipoPieza = 0; // 0=O 1=I 2=T 3=L 4=S
    int filaPieza = 0;
    int colPieza = 0;
    int giro = 0;
    char op = ' ';
    unsigned char* tab = 0;

    cout << "Ancho del tablero (minimo 8, multiplo de 8): ";
    cin >> ancho;
    cout << "Alto del tablero (minimo 8): ";
    cin >> alto;

    if (!cin) {
        cout << "entrada invalida\n";
        return 0;
    }

    if (!validarDatos(ancho, alto)) {
        cout << "error: dimensiones invalidas\n";
        return 0;
    }

    if (!crearTablero(ancho, alto, bytesFila, tamTotal, tab)) {
        cout << "error: no se pudo crear tablero\n";
        return 0;
    }

    cout << "bytes por fila: " << bytesFila << "\n";
    cout << "tamano total: " << tamTotal << "\n";
    cout << "\ntablero vacio:\n";
    imprimirTablero(tab, ancho, alto, bytesFila);

    srand((unsigned int)time(0));

    if (!ponerPiezaAleatoria(tab, ancho, alto, bytesFila, tipoPieza, filaPieza, colPieza, giro)) {
        cout << "error: no se pudo poner la pieza\n";
        liberarTablero(tab);
        return 0;
    }

    cout << "\npieza inicial puesta arriba:\n";
    imprimirTablero(tab, ancho, alto, bytesFila);

    while (true) {
        bool bajoManual = false;

        cout << "\na=izq d=der s=baja w=gira q=salir: ";
        cin >> op;

        if (!cin) {
            cout << "entrada invalida\n";
            break;
        }

        if (op == 'q' || op == 'Q') {
            break;
        }

        if (op == 'a' || op == 'A') {
            bool seMovio = false;

            switch (tipoPieza) {
            case 0:
                seMovio = moverPiezaOIzq(tab, ancho, alto, bytesFila, filaPieza, colPieza);
                break;
            case 1:
                seMovio = moverPiezaIIzq(tab, ancho, alto, bytesFila, filaPieza, colPieza, giro);
                break;
            case 2:
                seMovio = moverPiezaTIzq(tab, ancho, alto, bytesFila, filaPieza, colPieza);
                break;
            case 3:
                seMovio = moverPiezaLIzq(tab, ancho, alto, bytesFila, filaPieza, colPieza);
                break;
            default:
                seMovio = moverPiezaSIzq(tab, ancho, alto, bytesFila, filaPieza, colPieza, giro);
                break;
            }

            if (!seMovio) cout << "ya no puede ir mas a la izquierda\n";
        } else if (op == 'd' || op == 'D') {
            bool seMovio = false;

            if (tipoPieza == 0) seMovio = moverPiezaODer(tab, ancho, alto, bytesFila, filaPieza, colPieza);
            else if (tipoPieza == 1) seMovio = moverPiezaIDer(tab, ancho, alto, bytesFila, filaPieza, colPieza, giro);
            else if (tipoPieza == 2) seMovio = moverPiezaTDer(tab, ancho, alto, bytesFila, filaPieza, colPieza);
            else if (tipoPieza == 3) seMovio = moverPiezaLDer(tab, ancho, alto, bytesFila, filaPieza, colPieza);
            else seMovio = moverPiezaSDer(tab, ancho, alto, bytesFila, filaPieza, colPieza, giro);

            if (!seMovio) cout << "ya no puede ir mas a la derecha\n";
        } else if (op == 's' || op == 'S') {
            bajoManual = true;
            bool bajo = false;

            switch (tipoPieza) {
            case 0:
                bajo = moverPiezaOAbajo(tab, ancho, alto, bytesFila, filaPieza, colPieza);
                break;
            case 1:
                bajo = moverPiezaIAbajo(tab, ancho, alto, bytesFila, filaPieza, colPieza, giro);
                break;
            case 2:
                bajo = moverPiezaTAbajo(tab, ancho, alto, bytesFila, filaPieza, colPieza);
                break;
            case 3:
                bajo = moverPiezaLAbajo(tab, ancho, alto, bytesFila, filaPieza, colPieza);
                break;
            default:
                bajo = moverPiezaSAbajo(tab, ancho, alto, bytesFila, filaPieza, colPieza, giro);
                break;
            }

            if (!bajo) {
                if (!fijarYSeguir(tab, ancho, alto, bytesFila, tipoPieza, filaPieza, colPieza, giro)) break;
            }
        } else if (op == 'w' || op == 'W') {
            if (tipoPieza == 1 || tipoPieza == 4) {
                bool giroBien = false;
                if (tipoPieza == 1) giroBien = rotarPiezaI(tab, ancho, alto, bytesFila, filaPieza, colPieza, giro);
                else giroBien = rotarPiezaS(tab, ancho, alto, bytesFila, filaPieza, colPieza, giro);
                if (!giroBien) cout << "no se puede rotar\n";
            } else {
                cout << "esa pieza no rota por ahora\n";
            }
        } else {
            cout << "tecla no valida\n";
            continue;
        }

        if (!bajoManual) {
            bool bajo = false;

            if (tipoPieza == 0) bajo = moverPiezaOAbajo(tab, ancho, alto, bytesFila, filaPieza, colPieza);
            else if (tipoPieza == 1) bajo = moverPiezaIAbajo(tab, ancho, alto, bytesFila, filaPieza, colPieza, giro);
            else if (tipoPieza == 2) bajo = moverPiezaTAbajo(tab, ancho, alto, bytesFila, filaPieza, colPieza);
            else if (tipoPieza == 3) bajo = moverPiezaLAbajo(tab, ancho, alto, bytesFila, filaPieza, colPieza);
            else bajo = moverPiezaSAbajo(tab, ancho, alto, bytesFila, filaPieza, colPieza, giro);

            if (!bajo) {
                if (!fijarYSeguir(tab, ancho, alto, bytesFila, tipoPieza, filaPieza, colPieza, giro)) break;
            }
        }

        cout << "\ntablero:\n";
        imprimirTablero(tab, ancho, alto, bytesFila);
    }

    liberarTablero(tab);
    return 0;
}

