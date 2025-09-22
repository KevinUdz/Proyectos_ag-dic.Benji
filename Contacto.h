#ifndef CONTACTOS_H
#define CONTACTOS_H

#include <iostream>
#include <string>
#include <fstream> // para mi manejo de archivos
using namespace std;

struct Contacto {
    string nombre;     
    string telefono;   
    string correo;     
    Contacto* next;    // Apuntador al siguiente nodo en la lista
};

//  CLASE LISTA DE CONTACTOS
//  Manejara todas las operaciones sobre la lista ligada
class ListaContactos {
private:
    Contacto* head; // Apuntador al primer nodo de la lista

public:
    // hago uso de constructor para inicializar la lista
    ListaContactos() { head = nullptr; }

    void insertar(string nombre, string telefono, string correo) {
        Contacto* nuevo = new Contacto{nombre, telefono, correo, nullptr};
        if (!head) head = nuevo; // si la lista está vacía, nuevo es la cabeza
        else {
            Contacto* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = nuevo; // insertamos al final
        }
    }

// se muestran todos los contactos en la lista
    void mostrar() {
        if (!head) {
            cout << "No hay contactos.\n";
            return;
        }
        Contacto* temp = head;
        while (temp) {
            cout << temp->nombre << " - " << temp->telefono << " - " << temp->correo << "\n";
            temp = temp->next;
        }
    }

    // inicio con la busqueda secuencial
    Contacto* buscarSecuencial(string nombre) {
        Contacto* temp = head;
        while (temp) {
            if (temp->nombre == nombre) return temp;
            temp = temp->next;
        }
        return nullptr;
    }

    // asimismo incluyo la busqueda recursiva
    Contacto* buscarRecursiva(Contacto* nodo, string nombre) {
        if (!nodo) return nullptr;                 // caso base: lista vacía
        if (nodo->nombre == nombre) return nodo;   // encontrado
        return buscarRecursiva(nodo->next, nombre);// recursión sobre el siguiente
    }

    // funcion para obtener la cabeza de la lista
    Contacto* getHead() { return head; }

    // se actualiza el contacto
    bool actualizar(string nombre, string nuevoTel, string nuevoCorreo) {
        Contacto* c = buscarSecuencial(nombre);
        if (c) {
            c->telefono = nuevoTel;
            c->correo = nuevoCorreo;
            return true;
        }
        return false;
    }

    // se elimina el contacto
    bool eliminar(string nombre) {
        if (!head) return false; // lista vacía

        // Si es el primer nodo
        if (head->nombre == nombre) {
            Contacto* borrar = head;
            head = head->next;
            delete borrar;
            return true;
        }

        // Si está en otro nodo
        Contacto* temp = head;
        while (temp->next && temp->next->nombre != nombre)
            temp = temp->next;

        if (temp->next) {
            Contacto* borrar = temp->next;
            temp->next = borrar->next;
            delete borrar;
            return true;
        }
        return false;
    }

    // se cuentan los contactos de forma iterativa
    int contarIterativo() {
        int contador = 0;
        Contacto* temp = head;
        while (temp) {
            contador++;
            temp = temp->next;
        }
        return contador;
    }
};

// agrego las funciones para guardar y cargar desde archivo
inline void guardarEnArchivo(ListaContactos &lista, const string &nombreArchivo) {
    ofstream archivo(nombreArchivo);
    if (!archivo) {
        cout << "No se pudo abrir el archivo para guardar.\n";
        return;
    }
    Contacto* temp = lista.getHead();
    while (temp) {
        archivo << temp->nombre << "," << temp->telefono << "," << temp->correo << "\n";
        temp = temp->next;
    }
    archivo.close();
}

inline void cargarDesdeArchivo(ListaContactos &lista, const string &nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if (!archivo) {
        cout << "No se encontro el archivo, iniciando lista vacia.\n";
        return;
    }

    string linea;
    while (getline(archivo, linea)) {
        size_t p1 = linea.find(',');
        size_t p2 = linea.find(',', p1 + 1);
        if (p1 == string::npos || p2 == string::npos) continue;

        string nombre = linea.substr(0, p1);
        string telefono = linea.substr(p1 + 1, p2 - p1 - 1);
        string correo = linea.substr(p2 + 1);

        lista.insertar(nombre, telefono, correo);
    }
    archivo.close();
}

// agrego los metodos de ordenamiento

// selection sort
inline void selectionSort(Contacto* arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j]->nombre < arr[minIndex]->nombre)
                minIndex = j;
        }
        swap(arr[i], arr[minIndex]);
    }
}

// bubble sort
inline void bubbleSort(Contacto* arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j]->nombre > arr[j + 1]->nombre)
                swap(arr[j], arr[j + 1]);
        }
    }
}

// creo una funcion de fusion para merge sort
inline void merge(Contacto* arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    Contacto** L = new Contacto*[n1];
    Contacto** R = new Contacto*[n2];

    // Copiar datos a arreglos temporales
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i]->nombre <= R[j]->nombre) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    delete[] L;
    delete[] R;
}

// merge sort
inline void mergeSort(Contacto* arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

#endif
