#include "players.h"
#include <fstream>
#include <sstream>
#include <iostream>

vector<Player> leerJugadores(const string& nombreArchivo) {   //Crear lista de jugadores con el vector
    vector<Player> jugadores;
    ifstream archivo(nombreArchivo);

    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo " << nombreArchivo << endl;  //Error si el archivo no se puede abrir
        return jugadores;
    }

    string linea;
    while (getline(archivo, linea)) {
        size_t pos = linea.find(" - ");
        if (pos != string::npos) {
            Player jugador;
            jugador.nombre = linea.substr(0, pos);
            jugador.puntaje = stoi(linea.substr(pos + 3));
            jugadores.push_back(jugador);
        }
    }

    archivo.close();
    return jugadores;
}

int partition(vector<Player>& jugadores, int inicio, int fin) {
    int pivot = jugadores[fin].puntaje;
    int i = inicio - 1;

    for (int j = inicio; j < fin; j++) {
        if (jugadores[j].puntaje > pivot) {
            i++;
            Player temp = jugadores[i];
            jugadores[i] = jugadores[j];
            jugadores[j] = temp;
        }
    }

    Player temp = jugadores[i + 1];
    jugadores[i + 1] = jugadores[fin];
    jugadores[fin] = temp;

    return i + 1;
}

void quickSort(vector<Player>& jugadores, int inicio, int fin) {   //FUncion para implementar el metodo de ordenamiento quicksort
    if (inicio < fin) {
        int pi = partition(jugadores, inicio, fin);
        quickSort(jugadores, inicio, pi - 1);
        quickSort(jugadores, pi + 1, fin);
    }
}

void guardarJugadores(const vector<Player>& jugadores, const string& nombreArchivo) {
    ofstream archivo(nombreArchivo);

    if (!archivo.is_open()) {
        cout << "No se pudo crear el archivo " << nombreArchivo << endl;
        return;
    }

    for (const Player& jugador : jugadores) {
        archivo << jugador.nombre << " - " << jugador.puntaje << endl;
    }

    archivo.close();
    cout << "Jugadores ordenados guardados en" << nombreArchivo << endl;  //opcion 4, close
}

void agregarJugador(const string& nombreArchivo) {  //agregar jugador manual
    string nombre;
    int puntaje;

    cout << "Agregar Nuevo Jugador" << endl;
    cout << "Nombre del jugador: ";
    cin.ignore();
    getline(cin, nombre);

    cout << "Puntaje (1-50): ";
    while (!(cin >> puntaje) || puntaje < 1 || puntaje > 50) {
        cout << "Puntaje invalido. Debe ser un numero entre 1 y 50." << endl;  //Evitar un inputs incorrectos
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Puntaje (1-50): ";
    }

    ofstream archivo(nombreArchivo, ios::app);

    if (!archivo.is_open()) {
        cout << "no se pudo abrir el archivo " << nombreArchivo << endl;
        return;
    }

    archivo << nombre << " - " << puntaje << endl;
    archivo.close();

    cout << "\nJugador agregado exitosamente!" << endl;
}

void mostrarListaOrdenada(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);

    if (!archivo.is_open()) {
        cout << "\nError: No se pudo abrir el archivo " << nombreArchivo << endl;
        cout << "Asegurate de haber ordenado la lista primero (opcion 3)." << endl;
        return;
    }

    cout << "\n--- Lista de Jugadores Ordenados ---" << endl;
    string linea;
    int posicion = 1;

    while (getline(archivo, linea)) {
        cout << posicion << ". " << linea << endl;
        posicion++;
    }

    archivo.close();
}
