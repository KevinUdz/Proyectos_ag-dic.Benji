#include "Contacto.h"
#include <iostream>
using namespace std;

int main() {
    ListaContactos lista; // Creamos la lista ligada de contactos
    int opcion;

    do {
        // ====== MENÚ PRINCIPAL ======
        cout << "\n----------------------------------------\n";
        cout << "       AGENDA DE CONTACTOS      \n";
        cout << "----------------------------------------\n";
        cout << "1. Agregar contacto\n";
        cout << "2. Ver todos los contactos\n";
        cout << "3. Buscar contacto\n";
        cout << "4. Actualizar contacto\n";
        cout << "5. Eliminar contacto\n";
        cout << "6. Contar contactos\n";
        cout << "------------------------------\n";
        cout << "Ordenar contactos por nombre:\n";
        cout << "(Estos metodos ordenan la lista de distintas maneras,\n";
        cout << "no se modifica la informacion, solo el orden en que se muestran)\n";
        cout << "  7. Ordenar (Metodo 1)\n";
        cout << "  8. Ordenar (Metodo 2)\n";
        cout << "  9. Ordenar (Metodo 3)\n";
        cout << "------------------------------\n";
        cout << "0. Salir\n";
        cout << "Elige una opcion: ";
        cin >> opcion;
        cin.ignore();

        // Se agrega el contacto
        if (opcion == 1) {
            string n, t, c;
            cout << "\n--- Agregar nuevo contacto ---\n";
            cout << "Nombre: "; getline(cin, n);
            cout << "Telefono: "; getline(cin, t);
            cout << "Correo: "; getline(cin, c);
            lista.insertar(n, t, c); // Insertamos al final de la lista
            cout << "Contacto agregado correctamente.\n";
        }
        // Se muestra el contacto
        else if (opcion == 2) {
            cout << "\n--- Lista de Contactos ---\n";
            lista.mostrar(); // Recorre la lista y muestra cada contacto
        }
        // Busca el contacto
        else if (opcion == 3) {
            string n;
            cout << "\n--- Buscar contacto ---\n";
            cout << "Nombre a buscar: "; getline(cin, n);
            Contacto* res = lista.buscarRecursiva(lista.getHead(), n);
            if (res)
                cout << "Contacto encontrado: " << res->nombre << " (" << res->telefono << ")\n";
            else
                cout << "Contacto no encontrado.\n";
        }
        // Actualiza el contacto
        else if (opcion == 4) {
            string n, t, c;
            cout << "\n--- Actualizar contacto ---\n";
            cout << "Nombre a actualizar: "; getline(cin, n);
            cout << "Nuevo telefono: "; getline(cin, t);
            cout << "Nuevo correo: "; getline(cin, c);
            if (lista.actualizar(n, t, c))
                cout << "Contacto actualizado correctamente.\n";
            else
                cout << "No se encontro el contacto.\n";
        }
        // Elimina el contacto
        else if (opcion == 5) {
            string n;
            cout << "\n--- Eliminar contacto ---\n";
            cout << "Nombre a eliminar: "; getline(cin, n);
            if (lista.eliminar(n))
                cout << "Contacto eliminado correctamente.\n";
            else
                cout << "No se encontro el contacto.\n";
        }
        // cuenta los contactos que se tengan registrados
        else if (opcion == 6) {
            cout << "\nCantidad total de contactos: " << lista.contarIterativo() << "\n";
        }
        // ordena los contactos por nombre usando distintos metodos
        else if (opcion >= 7 && opcion <= 9) {
            int n = lista.contarIterativo();
            if (n == 0) {
                cout << "\nNo hay contactos para ordenar.\n";
                continue;
            }

            // Pasar lista ligada a un arreglo temporal para ordenarla
            Contacto** arr = new Contacto*[n];
            Contacto* temp = lista.getHead();
            for (int i = 0; i < n; i++) {
                arr[i] = temp;
                temp = temp->next;
            }

            // Llamar al metodo de ordenamiento segun la opcion elegida
            if (opcion == 7) selectionSort(arr, n);
            if (opcion == 8) bubbleSort(arr, n);
            if (opcion == 9) mergeSort(arr, 0, n - 1);

            // se muestra el resultado ordenado
            cout << "\n--- Contactos Ordenados ---\n";
            for (int i = 0; i < n; i++) {
                cout << arr[i]->nombre << " - " << arr[i]->telefono << " - " << arr[i]->correo << "\n";
            }

            delete[] arr; // liberar memoria dinámica
        }
        
        // Si la opcion no es valida
        else if (opcion != 0) {
            cout << "Opcion no valida, intenta de nuevo.\n";
        }

    } while (opcion != 0);

    cout << "\nSaliendo de la agenda... Gracias por usar el programa.\n";
    return 0;
}
