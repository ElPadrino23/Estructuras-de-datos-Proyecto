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

// nodo
struct Node {
    Player data;
    Node* next;
    Node* prev;  // Solo para DLL
    Node(Player p) : data(p), next(nullptr), prev(nullptr) {}
};

// LL 
class LinkedList {
private:
    Node* head;
public:
    LinkedList() : head(nullptr) {}
    ~LinkedList();
    void insert(Player p);  
    bool remove(string nombre);  
    Player* search(string nombre);  
    void display();  
    void saveToFile(const string& filename);  
};

// DLL
class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}
    ~DoublyLinkedList();
    void insert(Player p);  
    bool remove(string nombre);  
    Player* search(string nombre);  
    void display();  
    void saveToFile(const string& filename);  
};

// BST
struct TreeNode {
    Player data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(Player p) : data(p), left(nullptr), right(nullptr) {}
};


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
    void insert(Player p);  
    bool remove(string nombre);  
    Player* search(string nombre);  
    void display();  /
    void saveToFile(const string& filename);  
};

#endif
