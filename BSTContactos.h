#ifndef BST_CONTACTOS_H
#define BST_CONTACTOS_H

#include "Contacto.h"

// Nodo del arbol BST. Cada nodo guarda un contacto y los enlaces a la izquierda y derecha
struct NodoBST {
    Contacto* contacto;
    NodoBST* left;
    NodoBST* right;

    NodoBST(Contacto* c) {
        contacto = c;
        left = right = nullptr;
    }
};

// Arbol BST que uso solo como indice para ordenar y buscar por nombre (no afecta la lista ligada, solo sirve como extra)
class BSTContactos {
private:
    NodoBST* root;

    // Insertar un contacto en el arbol (recursivo)
    NodoBST* insertarRec(NodoBST* nodo, Contacto* c) {
        if (!nodo) return new NodoBST(c);

        string a = toLowerStr(c->nombre);
        string b = toLowerStr(nodo->contacto->nombre);

        if (a < b)
            nodo->left = insertarRec(nodo->left, c);
        else if (a > b)
            nodo->right = insertarRec(nodo->right, c);

        return nodo;
    }

    // Mostrar el arbol en orden (left - root - right)
    void inorder(NodoBST* nodo) {
        if (!nodo) return;
        inorder(nodo->left);
        cout << nodo->contacto->nombre << " - "
             << nodo->contacto->telefono << " - "
             << nodo->contacto->correo << endl;
        inorder(nodo->right);
    }

    // Buscar en el arbol de forma recursiva
    Contacto* buscarRec(NodoBST* nodo, string nombre) {
        if (!nodo) return nullptr;

        string a = toLowerStr(nombre);
        string b = toLowerStr(nodo->contacto->nombre);

        if (a == b) return nodo->contacto;
        if (a < b) return buscarRec(nodo->left, nombre);
        return buscarRec(nodo->right, nombre);
    }

public:
    BSTContactos() { root = nullptr; }

    // Funcion publica para insertar
    void insertar(Contacto* c) {
        root = insertarRec(root, c);
    }

    // Buscar por nombre
    Contacto* buscar(string nombre) {
        return buscarRec(root, nombre);
    }

    // Mostrar en orden alfabetico
    void mostrarOrdenados() {
        inorder(root);
    }
};

#endif