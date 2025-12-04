#include "Contacto.h"
#include "ListaContactos.h"
#include <iostream>
using namespace std;

int main() {

    ListaContactos lista;
    const string archivo = "contactos.txt";

    // Cargo los contactos si el archivo existe
    lista.cargarDesdeArchivo(archivo);

    int opcion = -1;

    do {
        // Menu principal
        cout << "\n===== AGENDA DE CONTACTOS =====\n";
        cout << "1. Agregar contacto\n";
        cout << "2. Mostrar contactos\n";
        cout << "3. Buscar (recursivo)\n";
        cout << "4. Actualizar\n";
        cout << "5. Eliminar\n";
        cout << "6. Contar\n";
        cout << "7. Ordenar (Selection Sort)\n";
        cout << "8. Ordenar (Bubble Sort)\n";
        cout << "9. Ordenar (Merge Sort)\n";
        cout << "10. Buscar (Binaria por numero)\n";
        cout << "11. Mostrar ordenados (BST)\n";
        cout << "12. Buscar (BST)\n";
        cout << "0. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;
        cin.ignore();

        // Agregar contacto
        if (opcion == 1) {
            string n, t, c;
            cout << "Nombre: ";
            getline(cin, n);
            cout << "Telefono: ";
            getline(cin, t);
            cout << "Correo: ";
            getline(cin, c);

            lista.insertar(n, t, c);
            lista.guardarEnArchivo(archivo);
        }

        // Mostrar contactos
        else if (opcion == 2) {
            lista.mostrar();
        }

        // Busqueda recursiva
        else if (opcion == 3) {
            string n;
            cout << "Nombre a buscar: ";
            getline(cin, n);

            Contacto* r = lista.buscarRecursiva(lista.getHead(), n);

            if (r)
                cout << "Encontrado: " << r->nombre << " | " << r->telefono << endl;
            else
                cout << "No encontrado.\n";
        }

        // Actualizar contacto
        else if (opcion == 4) {
            string n;
            cout << "Nombre a actualizar: ";
            getline(cin, n);

            Contacto* c = lista.buscarRecursiva(lista.getHead(), n);

            if (!c) {
                cout << "No se encontro el contacto.\n";
            } else {
                cout << "Nuevo telefono: ";
                getline(cin, c->telefono);
                cout << "Nuevo correo: ";
                getline(cin, c->correo);

                lista.guardarEnArchivo(archivo);
                cout << "Contacto actualizado.\n";
            }
        }

        // Eliminar contacto
        else if (opcion == 5) {
            string n;
            cout << "Nombre a eliminar: ";
            getline(cin, n);

            lista.eliminar(n);
            lista.guardarEnArchivo(archivo);
        }

        // Contar contactos
        else if (opcion == 6) {
            cout << "Total de contactos: " << lista.contarIterativo() << endl;
        }

        // Busqueda binaria por numero de telefono (mas practico que si fuera por nombre o mail)
        else if (opcion == 10) {
            string num;
            cout << "Numero a buscar: ";
            getline(cin, num);

            Contacto* c = lista.busquedaBinariaPorNumero(num);

            if (c)
                cout << "Encontrado: " << c->nombre << " | " << c->telefono << endl;
            else
                cout << "No encontrado.\n";
        }

        // Mostrar ordenados con BST
        else if (opcion == 11) {
            lista.mostrarOrdenadosBST();
        }

        // Buscar con BST
        else if (opcion == 12) {
            string n;
            cout << "Nombre a buscar: ";
            getline(cin, n);

            Contacto* c = lista.buscarBST(n);

            if (c)
                cout << "Encontrado: " << c->nombre << " | " << c->telefono << endl;
            else
                cout << "No encontrado.\n";
        }

    } while (opcion != 0);

    cout << "Saliendo...\n";
    return 0;
}
