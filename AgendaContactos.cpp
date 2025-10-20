#include "Contacto.h"
#include "Ordenamientos.h"
#include <iostream>
using namespace std;

int main() {
    ListaContactos lista;
    const string archivo = "contactos.txt";

     // Primero se verificara si existe el archivo de contactos para cargar los datos
    // si no se encuentra se creara uno al guardar
    lista.cargarDesdeArchivo(archivo);

    int opcion = -1;
    do {
        // Diseño un menu de opciones para el usuario
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
        cout << "10. Buscar (Binaria)\n";
        cout << "0. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;
        cin.ignore();

        // Si elige la opcion 1 se le pediran los datos del contacto y se insertara en la lista

        if (opcion == 1) {
            string n, t, c;
            cout << "Nombre: "; getline(cin, n);
            cout << "Telefono: "; getline(cin, t);
            cout << "Correo: "; getline(cin, c);
            lista.insertar(n, t, c);
            lista.guardarEnArchivo(archivo);
        }

        // si elige la opcion 2 se mostraran todos los contactos almacenados
        else if (opcion == 2) lista.mostrar();

        // si elige la opcion 3 se le pedira el nombre del contacto a buscar
        else if (opcion == 3) {
            string n;
            cout << "Buscar (recursivo): "; getline(cin, n);
            Contacto* r = lista.buscarRecursiva(lista.getHead(), n);
            if (r) cout << "Encontrado: " << r->nombre << " | " << r->telefono << "\n";
            else cout << "No encontrado.\n";
        }

        // si elige la opcion 4 se le pediran los datos del contacto a actualizar
        else if (opcion == 4) {
            string n, t, c;
            cout << "Actualizar: "; getline(cin, n);
            cout << "Nuevo tel: "; getline(cin, t);
            cout << "Nuevo correo: "; getline(cin, c);
            lista.actualizar(n, t, c);
            lista.guardarEnArchivo(archivo);
        }

        // si elige la opcion 5 se le pedira el nombre del contacto a eliminar
        else if (opcion == 5) {
            string n;
            cout << "Eliminar: "; getline(cin, n);
            lista.eliminar(n);
            lista.guardarEnArchivo(archivo);
        }

        // si elige la opcion 6 se mostrara el total de contactos almacenados
        else if (opcion == 6)
            cout << "Total de contactos: " << lista.contarIterativo() << "\n";

            // si elige las opciones 7, 8 o 9 se ordenaran los contactos usando el algoritmo seleccionado
        else if (opcion >= 7 && opcion <= 9) {
            int n = lista.contarIterativo();
            if (n == 0) { cout << "No hay contactos.\n"; continue; }
            Contacto** arr = new Contacto*[n];
            Contacto* tmp = lista.getHead();
            for (int i = 0; i < n; i++) { arr[i] = tmp; tmp = tmp->next; }
            if (opcion == 7) selectionSort(arr, n);
            if (opcion == 8) bubbleSort(arr, n);
            if (opcion == 9) mergeSort(arr, 0, n - 1);
            cout << "\n--- Contactos ordenados ---\n";
            for (int i = 0; i < n; i++)
                cout << arr[i]->nombre << " - " << arr[i]->telefono << " - " << arr[i]->correo << endl;
            delete[] arr;
        }

            // si elige la opcion 10 se le pedira el nombre del contacto a buscar usando busqueda binaria
        else if (opcion == 10) {
            int n = lista.contarIterativo();
            if (n == 0) { cout << "No hay contactos.\n"; continue; }
            Contacto** arr = new Contacto*[n];
            Contacto* tmp = lista.getHead();
            for (int i = 0; i < n; i++) { arr[i] = tmp; tmp = tmp->next; }
            mergeSort(arr, 0, n - 1);
            string buscar;
            cout << "Nombre a buscar: "; getline(cin, buscar);
            Contacto* r = busquedaBinaria(arr, n, buscar);
            if (r) cout << "Encontrado: " << r->nombre << " | " << r->telefono << endl;
            else cout << "No encontrado.\n";
            delete[] arr;
        }

    } while (opcion != 0);

    cout << "Saliendo...\n";
    return 0;
}
