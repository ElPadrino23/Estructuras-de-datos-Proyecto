#ifndef PLAYERS_H
#define PLAYERS_H

#include <string>
#include <vector>

using namespace std;

struct Player {
    string nombre;
    int puntaje;
};

vector<Player> leerJugadores(const string& nombreArchivo);
void quickSort(vector<Player>& jugadores, int inicio, int fin);
int partition(vector<Player>& jugadores, int inicio, int fin);
void guardarJugadores(const vector<Player>& jugadores, const string& nombreArchivo);
void agregarJugador(const string& nombreArchivo);
void mostrarListaOrdenada(const string& nombreArchivo);

#endif
