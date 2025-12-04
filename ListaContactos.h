#ifndef LISTA_CONTACTOS_H
#define LISTA_CONTACTOS_H

#include "Contacto.h"
#include "BSTContactos.h"
#include <vector>

class ListaContactos {
private:
    Contacto* head;     // inicio de la lista ligada
    BSTContactos indiceBST; // arbol extra para buscar y ordenar mas rapido

    // Convierte a minusculas para comparar sin errores
    string toLower(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        return s;
    }

public:
    ListaContactos() { head = nullptr; }

    // Funcion para insertar contactos al final de la lista
    void insertar(string nombre, string telefono, string correo) {

        if (nombre.empty()) {
            cout << "El nombre no puede estar vacio.\n";
            return;
        }

        // Creo un nuevo contacto
        Contacto* nuevo = new Contacto{nombre, telefono, correo, nullptr};

        // Si la lista esta vacia
        if (!head) {
            head = nuevo;
            indiceBST.insertar(nuevo); // tambien lo meto al arbol
            return;
        }

        // Recorro la lista para evitar duplicados y llegar al final
        Contacto* temp = head;
        while (temp) {

            if (toLower(temp->nombre) == toLower(nombre)) {
                cout << "El contacto ya existe.\n";
                delete nuevo;
                return;
            }

            if (!temp->next) break;  
            temp = temp->next;
        }

        // Inserto al final
        temp->next = nuevo;

        // Tambien lo indexo en el arbol
        indiceBST.insertar(nuevo);
    }

    // Mostrar la lista como esta guardada
    void mostrar() {
        if (!head) {
            cout << "No hay contactos.\n";
            return;
        }

        Contacto* temp = head;
        while (temp) {
            cout << temp->nombre << " - " << temp->telefono
                 << " - " << temp->correo << endl;
            temp = temp->next;
        }
    }

    // Buscar de forma recursiva en la lista ligada
    Contacto* buscarRecursiva(Contacto* nodo, string nombre) {
        if (!nodo) return nullptr;
        if (toLower(nodo->nombre) == toLower(nombre)) return nodo;
        return buscarRecursiva(nodo->next, nombre);
    }

    // Mostrar contactos ordenados por nombre usando el BST
    void mostrarOrdenadosBST() {
        indiceBST.mostrarOrdenados();
    }

    // Buscar usando el arbol
    Contacto* buscarBST(string nombre) {
        return indiceBST.buscar(nombre);
    }

    // Contar elementos de la lista
    int contarIterativo() {
        int c = 0;
        Contacto* temp = head;
        while (temp) {
            c++;
            temp = temp->next;
        }
        return c;
    }

    // Guardar en archivo
    void guardarEnArchivo(const string &nombreArchivo) {
        ofstream archivo(nombreArchivo);
        if (!archivo.is_open()) {
            cout << "No se pudo abrir el archivo.\n";
            return;
        }

        Contacto* temp = head;
        while (temp) {
            archivo << temp->nombre << ";" 
                    << temp->telefono << ";" 
                    << temp->correo << "\n";
            temp = temp->next;
        }
    }

    // Cargar datos desde archivo
    void cargarDesdeArchivo(const string &nombreArchivo) {
        ifstream archivo(nombreArchivo);
        if (!archivo.is_open()) {
            cout << "No existe el archivo aun.\n";
            return;
        }

        string linea;
        while (getline(archivo, linea)) {

            if (linea.empty()) continue;

            size_t p1 = linea.find(';');
            size_t p2 = linea.find(';', p1 + 1);

            if (p1 == string::npos || p2 == string::npos) continue;

            string nombre = linea.substr(0, p1);
            string tel = linea.substr(p1 + 1, p2 - p1 - 1);
            string correo = linea.substr(p2 + 1);

            insertar(nombre, tel, correo);
        }
    }

    // Eliminar un contacto de la lista ligada
    void eliminar(string nombre) {

        if (!head) {
            cout << "La lista esta vacia.\n";
            return;
        }

        Contacto* temp = head;
        Contacto* ant = nullptr;

        // Caso: el primer elemento
        if (toLower(temp->nombre) == toLower(nombre)) {
            head = temp->next;
            delete temp;
            cout << "Contacto eliminado.\n";
            return;
        }

        // Buscar en el resto
        while (temp) {
            if (toLower(temp->nombre) == toLower(nombre)) {
                ant->next = temp->next;
                delete temp;
                cout << "Contacto eliminado.\n";
                return;
            }
            ant = temp;
            temp = temp->next;
        }

        cout << "No encontrado.\n";
    }

    // ================
    // BUSQUEDA BINARIA
    // ================

    // Paso 1: convertir la lista en vector
    vector<Contacto*> listaAVector() {
        vector<Contacto*> v;
        Contacto* temp = head;
        while (temp) {
            v.push_back(temp);
            temp = temp->next;
        }
        return v;
    }

    // Merge sort para ordenar por numero
    void merge(vector<Contacto*>& v, int l, int m, int r) {

        int n1 = m - l + 1;
        int n2 = r - m;

        vector<Contacto*> L(n1), R(n2);

        for (int i = 0; i < n1; i++) L[i] = v[l + i];
        for (int i = 0; i < n2; i++) R[i] = v[m + 1 + i];

        int i = 0, j = 0, k = l;

        while (i < n1 && j < n2) {
            if (L[i]->telefono <= R[j]->telefono) {
                v[k] = L[i];
                i++;
            } else {
                v[k] = R[j];
                j++;
            }
            k++;
        }

        while (i < n1) v[k++] = L[i++];
        while (j < n2) v[k++] = R[j++];
    }

    void mergeSort(vector<Contacto*>& v, int l, int r) {
        if (l < r) {
            int m = (l + r) / 2;
            mergeSort(v, l, m);
            mergeSort(v, m + 1, r);
            merge(v, l, m, r);
        }
    }

    // Busqueda binaria por numero
    Contacto* busquedaBinariaPorNumero(string numero) {

        vector<Contacto*> v = listaAVector();
        if (v.empty()) return nullptr;

        // Primero ordeno por numero
        mergeSort(v, 0, v.size() - 1);

        // Aplicar busqueda binaria
        int left = 0, right = v.size() - 1;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (v[mid]->telefono == numero)
                return v[mid];

            if (v[mid]->telefono < numero)
                left = mid + 1;
            else
                right = mid - 1;
        }

        return nullptr;
    }

    Contacto* getHead() {
        return head;
    }
};

#endif