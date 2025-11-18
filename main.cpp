/*
Luis Fernando Martinez Barragan - A01613426
Programacion de estructura de datos y algoritmos fundamentales
Avance entrega 2

main.cpp
fecha de conclusion: 18/11/2025
*/



#include "players.h"
#include "advanced_structures.h"
#include <iostream>
#include <limits>

using namespace std;

enum Estructura { VECTOR, LINKEDLIST, DOUBLYLINKEDLIST, BST };
Estructura estructuraActual = VECTOR;
vector<Player> jugadoresVector;
LinkedList* listaLigada = nullptr;
DoublyLinkedList* listaDoble = nullptr;
BinarySearchTree* bst = nullptr;

// cargar datos en la estructura act  
void cargarDatos(const string& archivo) {
    vector<Player> temp = leerJugadores(archivo);
    if (estructuraActual == VECTOR) {
        jugadoresVector = temp;
    } else if (estructuraActual == LINKEDLIST) {
        if (!listaLigada) listaLigada = new LinkedList();
        for (auto& p : temp) listaLigada->insert(p);
    } else if (estructuraActual == DOUBLYLINKEDLIST) {
        if (!listaDoble) listaDoble = new DoublyLinkedList();
        for (auto& p : temp) listaDoble->insert(p);
    } else if (estructuraActual == BST) {
        if (!bst) bst = new BinarySearchTree();
        for (auto& p : temp) bst->insert(p);
    }
}

int main() {
    string archivoEntrada = "jugadores.txt";
    string archivoSalida = "jugadores_ordenados.txt";
    int opcion;
    
    // Cargar datos iniciales
    cargarDatos(archivoEntrada);
    
    do {
        cout << "\n========================================" << endl;
        cout << "   GESTION DE JUGADORES DE AMERICANO" << endl;
        cout << "========================================" << endl;
        cout << "0. Elegir estructura de datos" << endl;
        cout << "1. Agregar jugador" << endl;
        cout << "2. Mostrar lista" << endl;
        cout << "3. Ordenar jugadores (solo Vector)" << endl;
        cout << "4. Buscar jugador" << endl;
        cout << "5. Eliminar jugador" << endl;
        cout << "6. Guardar datos" << endl;
        cout << "7. Salir" << endl;
        cout << "========================================" << endl;
        
        // Mostrar estructura actual
        cout << "Estructura actual: ";
        if (estructuraActual == VECTOR) cout << "Vector";
        else if (estructuraActual == LINKEDLIST) cout << "LinkedList";
        else if (estructuraActual == DOUBLYLINKEDLIST) cout << "DoublyLinkedList";
        else if (estructuraActual == BST) cout << "Binary Search Tree";
        cout << endl;
        
        cout << "Selecciona una opcion: ";
        cin >> opcion;
        
        switch (opcion) {
            case 0: {
                cout << "\nElige estructura de datos:" << endl;
                cout << "1. Vector" << endl;
                cout << "2. LinkedList" << endl;
                cout << "3. DoublyLinkedList" << endl;
                cout << "4. Binary Search Tree" << endl;
                cout << "Opcion: ";
                int subOpcion;
                cin >> subOpcion;
                
                if (subOpcion >= 1 && subOpcion <= 4) {
                    estructuraActual = static_cast<Estructura>(subOpcion - 1);
                    
                    // vacial la estructura pasada
                    jugadoresVector.clear();
                    if (listaLigada) { delete listaLigada; listaLigada = nullptr; }
                    if (listaDoble) { delete listaDoble; listaDoble = nullptr; }
                    if (bst) { delete bst; bst = nullptr; }
                    
                    cargarDatos(archivoEntrada);
                    cout << "Estructura cambiada exitosamente." << endl;
                } else {
                    cout << "Opcion invalida." << endl;
                }
                break;
            }
            
            case 1: {
                string nombre;
                int puntaje;
                
                cout << "\n Agregar Nuevojugador " << endl;
                cout << "Nombre del jugador: ";
                cin.ignore();
                getline(cin, nombre);
                
                cout << "Puntaje (1-50): ";
                while (!(cin >> puntaje) || puntaje < 1 || puntaje > 50) {
                    cout << "Puntaje invalidodebe ser un numero entre 1 y 50." << endl;
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "Puntaje (1-50): ";
                }
                
                Player p = {nombre, puntaje};
                
                if (estructuraActual == VECTOR) {
                    jugadoresVector.push_back(p);
                } else if (estructuraActual == LINKEDLIST) {
                    if (!listaLigada) listaLigada = new LinkedList();
                    listaLigada->insert(p);
                } else if (estructuraActual == DOUBLYLINKEDLIST) {
                    if (!listaDoble) listaDoble = new DoublyLinkedList();
                    listaDoble->insert(p);
                } else if (estructuraActual == BST) {
                    if (!bst) bst = new BinarySearchTree();
                    bst->insert(p);
                }
                
                cout << "\nJugador agregado exitosamente!" << endl;
                break;
            }
            
            case 2: {
                cout << "\n Lista de jjugadores " << endl;
                if (estructuraActual == VECTOR) {
                    if (jugadoresVector.empty()) {
                        cout << "No hay jugadores" << endl;
                    } else {
                        for (size_t i = 0; i < jugadoresVector.size(); i++) {
                            cout << (i+1) << ". " << jugadoresVector[i].nombre 
                                 << " - " << jugadoresVector[i].puntaje << endl;
                        }
                    }
                } else if (estructuraActual == LINKEDLIST) {
                    if (listaLigada) listaLigada->display();
                    else cout << "No hay jugadores" << endl;
                } else if (estructuraActual == DOUBLYLINKEDLIST) {
                    if (listaDoble) listaDoble->display();
                    else cout << "No hay jugadores" << endl;
                } else if (estructuraActual == BST) {
                    if (bst) bst->display();
                    else cout << "No hay jugadores" << endl;
                }
                break;
            }
            
            case 3: {
                if (estructuraActual == VECTOR) {
                    if (jugadoresVector.empty()) {
                        cout << "\nNo hay jugadores para ordenar." << endl;
                    } else {
                        cout << "\nOrdenando jugadores..." << endl;
                        quickSort(jugadoresVector, 0, jugadoresVector.size() - 1);
                        cout << "Jugadores ordenados exitosamente!" << endl;
                    }
                } else {
                    cout << "\nordena con el vector" << endl;
                    cout << "Las otras estructuras mantienen su propio orden" << endl;
                }
                break;
            }
            
            case 4: {
                string nombre;
                cout << "\nNombre a buscar: ";
                cin.ignore();
                getline(cin, nombre);
                
                Player* encontrado = nullptr;
                
                if (estructuraActual == VECTOR) {
                    for (auto& p : jugadoresVector) {
                        if (p.nombre == nombre) {
                            encontrado = &p;
                            break;
                        }
                    }
                } else if (estructuraActual == LINKEDLIST) {
                    if (listaLigada) encontrado = listaLigada->search(nombre);
                } else if (estructuraActual == DOUBLYLINKEDLIST) {
                    if (listaDoble) encontrado = listaDoble->search(nombre);
                } else if (estructuraActual == BST) {
                    if (bst) encontrado = bst->search(nombre);
                }
                
                if (encontrado) {
                    cout << "Jugador encontrado: " << encontrado->nombre 
                         << " - " << encontrado->puntaje << endl;
                } else {
                    cout << "Jugador no encontrado." << endl;
                }
                break;
            }
            
            case 5: {
                string nombre;
                cout << "\nNombre a eliminar: ";
                cin.ignore();
                getline(cin, nombre);
                
                bool eliminado = false;
                
                if (estructuraActual == VECTOR) {
                    for (auto it = jugadoresVector.begin(); it != jugadoresVector.end(); ++it) {
                        if (it->nombre == nombre) {
                            jugadoresVector.erase(it);
                            eliminado = true;
                            break;
                        }
                    }
                } else if (estructuraActual == LINKEDLIST) {
                    if (listaLigada) eliminado = listaLigada->remove(nombre);
                } else if (estructuraActual == DOUBLYLINKEDLIST) {
                    if (listaDoble) eliminado = listaDoble->remove(nombre);
                } else if (estructuraActual == BST) {
                    if (bst) eliminado = bst->remove(nombre);
                }
                
                if (eliminado) {
                    cout << "Jugador eliminado exitosamente!" << endl;
                } else {
                    cout << "Jugador no encontrado." << endl;
                }
                break;
            }
            
            case 6: {
                cout << "\nGuardando datos en " << archivoSalida << "..." << endl;
                
                if (estructuraActual == VECTOR) {
                    guardarJugadores(jugadoresVector, archivoSalida);
                } else if (estructuraActual == LINKEDLIST) {
                    if (listaLigada) listaLigada->saveToFile(archivoSalida);
                } else if (estructuraActual == DOUBLYLINKEDLIST) {
                    if (listaDoble) listaDoble->saveToFile(archivoSalida);
                } else if (estructuraActual == BST) {
                    if (bst) bst->saveToFile(archivoSalida);
                }
                
                cout << "Datos guardados exitosamente!" << endl;
                break;
            }
            
            case 7:
                cout << "\nGracias por usar el programa!" << endl;
                break;
                
            default:
                cout << "\nOpcion invalida. Por favor selecciona una opcion del 0 al 7." << endl;
        }
        
    } while (opcion != 7);
    
    // Liberar memoria
    delete listaLigada;
    delete listaDoble;
    delete bst;
    
    return 0;
}
