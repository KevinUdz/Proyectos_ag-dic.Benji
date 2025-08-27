// Kevin Uriel Dzib Uc - A00842744
// funciones.h - Tarea 1 Funciones Iterativas y Recursivas

#ifndef FUNCIONES_H_
#define FUNCIONES_H_


// Creo la clase "funciones" para agurpar los metodos matematicos que me ayudaran para calcular la suma solicitada

class funciones {
public:

// Creo la función "sumaIterativa" haciendo uso de un ciclo for. 
    int sumaIterativa(int n);

// Creo la función "sumaRecursiva" que sumara los números de 1 a n con la llamada recursiva
    int sumaRecursiva(int n);

// Creo la función "sumaDirecta" haciendo uso de la formula matematica vista en clase 
    int sumaDirecta(int n);
};

// Empiezo con la suma usando ciclo for (iterativa)
int funciones::sumaIterativa(int n) {
    int sumit = 0;
    for (int i = 1; i <= n; i++) {
        sumit += i;
    }
    return sumit;
}

// Sigo con la suma usando recursividad
int funciones::sumaRecursiva(int n) {
    if (n <= 0)
        return 0;
    return n + sumaRecursiva(n - 1);
}

// Termino con la suma usando la fórmula directa
int funciones::sumaDirecta(int n) {
    return (n * (n + 1)) / 2;
}

#endif
