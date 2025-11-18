/*
Luis Fernando Martinez Barragan - A01613426
Programacion de estructura de datos y algoritmos fundamentales
Avance entrega 2
advanced_structures.h
fecha de inicio: 13/11/2025

*/





#ifndef ADVANCED_STRUCTURES_H
#define ADVANCED_STRUCTURES_H

#include "players.h"
#include <iostream>
#include <fstream>

using namespace std;

// Nodo
struct Node {
    Player data;
    Node* next;
    Node* prev;  // Solo para DoublyLinkedList
    Node(Player p) : data(p), next(nullptr), prev(nullptr) {}
};

// LinkedList 
class LinkedList {
private:
    Node* head;
public:
    LinkedList() : head(nullptr) {}
    ~LinkedList();
    void insert(Player p);  // O(1) al inicio
    bool remove(string nombre);  // O(n) búsqueda
    Player* search(string nombre);  // O(n)
    void display();  // O(n)
    void saveToFile(const string& filename);  // O(n)
};

// DoublyLinkedList
class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}
    ~DoublyLinkedList();
    void insert(Player p);  // O(1) al inicio/fin
    bool remove(string nombre);  // O(n)
    Player* search(string nombre);  // O(n)
    void display();  // O(n)
    void saveToFile(const string& filename);  // O(n)
};

// Nodo BST
struct TreeNode {
    Player data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(Player p) : data(p), left(nullptr), right(nullptr) {}
};

// Binary Search Tree arribaabajo
class BinarySearchTree {
private:
    TreeNode* root;
    void insertRecursive(TreeNode*& node, Player p);
    TreeNode* searchRecursive(TreeNode* node, string nombre);
    void inOrderTraversal(TreeNode* node, ostream& output, int& posicion);
    void destroy(TreeNode* node);
    TreeNode* findMin(TreeNode* node);
    TreeNode* removeRecursive(TreeNode* node, string nombre, bool& success);
public:
    BinarySearchTree() : root(nullptr) {}
    ~BinarySearchTree() { destroy(root); }
    void insert(Player p);  // O(log n)
    bool remove(string nombre);  // O(log n) promedio
    Player* search(string nombre);  // O(log n)
    void display();  // O(n) in-order
    void saveToFile(const string& filename);  // O(n) in-order
};

#endif
