#ifndef CONTACTO_H
#define CONTACTO_H

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <cctype>
using namespace std;

// Estructura que representa un contacto en la lista ligada
struct Contacto {
    string nombre;
    string telefono;
    string correo;
    Contacto* next;
};

// Clase que gestiona la lista ligada de contactos
class ListaContactos {
private:
    Contacto* head;

    // Convierte texto a minúsculas (para comparar sin distinguir mayúsculas)
    string toLower(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        return s;
    }

public:
    ListaContactos() { head = nullptr; }

    // Inserta un nuevo contacto al final de la lista
    void insertar(string nombre, string telefono, string correo) {
        if (nombre.empty()) {
            cout << "Error: el nombre no puede estar vacío.\n";
            return;
        }

        Contacto* nuevo = new Contacto{nombre, telefono, correo, nullptr};

        if (head == nullptr) {
            head = nuevo;
            return;
        }

        // Evitar duplicados
        Contacto* temp = head;
        while (temp != nullptr) {
            if (toLower(temp->nombre) == toLower(nombre)) {
                cout << "El contacto ya existe.\n";
                delete nuevo;
                return;
            }
            if (temp->next == nullptr) break;
            temp = temp->next;
        }
        temp->next = nuevo;
    }

    // Muestra todos los contactos
    void mostrar() {
        if (head == nullptr) {
            cout << "No hay contactos.\n";
            return;
        }
        Contacto* temp = head;
        while (temp != nullptr) {
            cout << temp->nombre << " - " << temp->telefono << " - " << temp->correo << endl;
            temp = temp->next;
        }
    }

    // Buscar contacto (recursiva)
    Contacto* buscarRecursiva(Contacto* nodo, string nombre) {
        if (nodo == nullptr) return nullptr;
        if (toLower(nodo->nombre) == toLower(nombre)) return nodo;
        return buscarRecursiva(nodo->next, nombre);
    }

    // Actualizar contacto
    void actualizar(string nombre, string nuevoTel, string nuevoCorreo) {
        Contacto* c = buscarRecursiva(head, nombre);
        if (c) {
            c->telefono = nuevoTel;
            c->correo = nuevoCorreo;
            cout << "Contacto actualizado.\n";
        } else {
            cout << "No se encontro el contacto.\n";
        }
    }

    // Eliminar contacto
    void eliminar(string nombre) {
        if (head == nullptr) return;

        if (toLower(head->nombre) == toLower(nombre)) {
            Contacto* borrar = head;
            head = head->next;
            delete borrar;
            cout << "Contacto eliminado.\n";
            return;
        }

        Contacto* temp = head;
        while (temp->next && toLower(temp->next->nombre) != toLower(nombre)) {
            temp = temp->next;
        }

        if (temp->next) {
            Contacto* borrar = temp->next;
            temp->next = temp->next->next;
            delete borrar;
            cout << "Contacto eliminado.\n";
        } else {
            cout << "No se encontro el contacto.\n";
        }
    }

    // Contar contactos
    int contarIterativo() {
        int contador = 0;
        Contacto* temp = head;
        while (temp) {
            contador++;
            temp = temp->next;
        }
        return contador;
    }

    // Guardar contactos en archivo
    void guardarEnArchivo(const string &nombreArchivo) {
        ofstream archivo(nombreArchivo);
        if (!archivo.is_open()) {
            cout << "Error al abrir el archivo para guardar.\n";
            return;
        }
        Contacto* temp = head;
        while (temp) {
            archivo << temp->nombre << ";" << temp->telefono << ";" << temp->correo << "\n";
            temp = temp->next;
        }
        archivo.close();
    }

    // Cargar contactos desde archivo
    void cargarDesdeArchivo(const string &nombreArchivo) {
        ifstream archivo(nombreArchivo);
        if (!archivo.is_open()) {
            cout << "No se encontro el archivo, se creara al guardar.\n";
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
        archivo.close();
    }

    Contacto* getHead() { return head; }
};

#endif
