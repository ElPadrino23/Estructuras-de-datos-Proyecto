#include "players.h"
#include <iostream>

using namespace std;

int main() {
    string archivoEntrada = "jugadores.txt";
    string archivoSalida = "jugadores_ordenados.txt";
    int opcion;

    do {
        cout << "1 Agregar jugador" << endl;
        cout << "2 Mostrar lista ordenada" << endl;
        cout << "3 Ordenar jugadores" << endl;
        cout << "4 Salir" << endl;
        cout << "Selecciona una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                agregarJugador(archivoEntrada);
                break;

            case 2:
                mostrarListaOrdenada(archivoSalida);
                break;

            case 3: {
                vector<Player> jugadores = leerJugadores(archivoEntrada);

                if (jugadores.empty()) {                  //En caso de que la lista de jugadores este vacia, se lanza la advertencia
                    cout << "No se encontraron jugadores en el archivo" << endl;
                } else {
                    cout << "Ordenando jugadores" << endl;
                    quickSort(jugadores, 0, jugadores.size() - 1);
                    guardarJugadores(jugadores, archivoSalida);
                }
                break;
            }

            case 4:
                cout << "\nGracias por usar el programa!" << endl;
                break;

            default:
                cout << "\nOpcion invalida. Por favor selecciona una opcion del 1 al 4." << endl;
        }

    } while (opcion != 4);

    return 0;
}
