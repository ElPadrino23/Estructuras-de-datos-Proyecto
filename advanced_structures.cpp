/*
Luis Fernando Martinez Barragan - A01613426
Programacion de estructura de datos y algoritmos fundamentales
Avance entrega 2
advanced_structures.cpp
fecha de inicio: 15/11/2025
*/




#include "advanced_structures.h"

LinkedList::~LinkedList() {
    Node* current = head;
    while (current) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}

void LinkedList::insert(Player p) {
    Node* newNode = new Node(p);
    newNode->next = head;
    head = newNode;
}

bool LinkedList::remove(string nombre) {
    Node* current = head;
    Node* prev = nullptr;
    while (current) {
        if (current->data.nombre == nombre) {
            if (prev) prev->next = current->next;
            else head = current->next;
            delete current;
            return true;
        }
        prev = current;
        current = current->next;
    }
    return false;
}

Player* LinkedList::search(string nombre) {
    Node* current = head;
    while (current) {
        if (current->data.nombre == nombre) return &current->data;
        current = current->next;
    }
    return nullptr;
}

void LinkedList::display() {
    Node* current = head;
    int posicion = 1;
    while (current) {
        cout << posicion << ". " << current->data.nombre << " - " << current->data.puntaje << endl;
        current = current->next;
        posicion++;
    }
}

void LinkedList::saveToFile(const string& filename) {
    ofstream file(filename);
    Node* current = head;
    while (current) {
        file << current->data.nombre << " - " << current->data.puntaje << endl;
        current = current->next;
    }
    file.close();
    cout << "Datos guardados en " << filename << endl;
}

// DLL   
DoublyLinkedList::~DoublyLinkedList() {
    Node* current = head;
    while (current) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}

void DoublyLinkedList::insert(Player p) {
    Node* newNode = new Node(p);
    
    if (!head) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

bool DoublyLinkedList::remove(string nombre) {
    Node* current = head;
    
    while (current) {
        if (current->data.nombre == nombre) {
            if (current->prev) {
                current->prev->next = current->next;
            } else {
                head = current->next;
            }
            
            if (current->next) {
                current->next->prev = current->prev;
            } else {
                tail = current->prev;
            }
            
            delete current;
            return true;
        }
        current = current->next;
    }
    return false;
}

Player* DoublyLinkedList::search(string nombre) {
    Node* current = head;
    while (current) {
        if (current->data.nombre == nombre) return &current->data;
        current = current->next;
    }
    return nullptr;
}

void DoublyLinkedList::display() {
    Node* current = head;
    int posicion = 1;
    while (current) {
        cout << posicion << ". " << current->data.nombre << " - " << current->data.puntaje << endl;
        current = current->next;
        posicion++;
    }
}

void DoublyLinkedList::saveToFile(const string& filename) {
    ofstream file(filename);
    Node* current = head;
    while (current) {
        file << current->data.nombre << " - " << current->data.puntaje << endl;
        current = current->next;
    }
    file.close();
    cout << "Datos guardados en " << filename << endl;
}

// implementacion de BST
void BinarySearchTree::insert(Player p) {
    insertRecursive(root, p);
}

void BinarySearchTree::insertRecursive(TreeNode*& node, Player p) {
    if (!node) {
        node = new TreeNode(p);
        return;
    }
    if (p.puntaje > node->data.puntaje) {  
        insertRecursive(node->left, p);
    } else {
        insertRecursive(node->right, p);
    }
}

Player* BinarySearchTree::search(string nombre) {
    TreeNode* result = searchRecursive(root, nombre);
    return result ? &result->data : nullptr;
}

TreeNode* BinarySearchTree::searchRecursive(TreeNode* node, string nombre) {
    if (!node || node->data.nombre == nombre) return node;
    

    TreeNode* left = searchRecursive(node->left, nombre);
    if (left) return left;
    return searchRecursive(node->right, nombre);
}

void BinarySearchTree::display() {
    if (!root) {
        cout << "No hay jugadores." << endl;
        return;
    }
    int posicion = 1;
    inOrderTraversal(root, cout, posicion);
}

void BinarySearchTree::inOrderTraversal(TreeNode* node, ostream& output, int& posicion) {
    if (node) {
        inOrderTraversal(node->left, output, posicion);
        
       
        if (&output == &cout) {
            output << posicion << ". ";
            posicion++;
        }
        
        output << node->data.nombre << " - " << node->data.puntaje << endl;
        inOrderTraversal(node->right, output, posicion);
    }
}

void BinarySearchTree::saveToFile(const string& filename) {
    ofstream file(filename);
    int posicion = 1;  
    inOrderTraversal(root, file, posicion);
    file.close();
    cout << "Datos guardados en " << filename << endl;
}

TreeNode* BinarySearchTree::findMin(TreeNode* node) {
    while (node && node->left) {
        node = node->left;
    }
    return node;
}

bool BinarySearchTree::remove(string nombre) {
    bool success = false;
    root = removeRecursive(root, nombre, success);
    return success;
}

TreeNode* BinarySearchTree::removeRecursive(TreeNode* node, string nombre, bool& success) {
    if (!node) return nullptr;
    
    if (node->data.nombre == nombre) {
        success = true;
        
        // sin hijos
        if (!node->left && !node->right) {
            delete node;
            return nullptr;
        }
        
        // un hijo
        if (!node->left) {
            TreeNode* temp = node->right;
            delete node;
            return temp;
        }
        if (!node->right) {
            TreeNode* temp = node->left;
            delete node;
            return temp;
        }
        
        // dos hijos
        TreeNode* minRight = findMin(node->right);
        node->data = minRight->data;
        node->right = removeRecursive(node->right, minRight->data.nombre, success);
        return node;
    }
    
    // Busqueda en ambos
    node->left = removeRecursive(node->left, nombre, success);
    if (!success) {
        node->right = removeRecursive(node->right, nombre, success);
    }
    
    return node;
}

void BinarySearchTree::destroy(TreeNode* node) {
    if (node) {
        destroy(node->left);
        destroy(node->right);
        delete node;
    }
}
