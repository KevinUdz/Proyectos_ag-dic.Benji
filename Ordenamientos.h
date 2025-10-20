#ifndef ORDENAMIENTOS_H
#define ORDENAMIENTOS_H
#include "Contacto.h"

// Comparación case-insensitive
bool ciMenor(Contacto* a, Contacto* b) {
    string A = a->nombre, B = b->nombre;
    transform(A.begin(), A.end(), A.begin(), ::tolower);
    transform(B.begin(), B.end(), B.begin(), ::tolower);
    return A < B;
}

// Selection Sort 
void selectionSort(Contacto* arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
            if (ciMenor(arr[j], arr[minIdx])) minIdx = j;
        swap(arr[i], arr[minIdx]);
    }
}

// Bubble Sort
void bubbleSort(Contacto* arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (!ciMenor(arr[j], arr[j + 1])) swap(arr[j], arr[j + 1]);
}

// Merge Sort 
void merge(Contacto* arr[], int left, int mid, int right) {
    int n1 = mid - left + 1, n2 = right - mid;
    Contacto** L = new Contacto*[n1];
    Contacto** R = new Contacto*[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
        arr[k++] = (ciMenor(L[i], R[j])) ? L[i++] : R[j++];
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
    delete[] L; delete[] R;
}

void mergeSort(Contacto* arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Búsqueda binaria 
Contacto* busquedaBinaria(Contacto* arr[], int n, string nombre) {
    transform(nombre.begin(), nombre.end(), nombre.begin(), ::tolower);
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        string midName = arr[mid]->nombre;
        transform(midName.begin(), midName.end(), midName.begin(), ::tolower);
        if (midName == nombre) return arr[mid];
        else if (midName < nombre) left = mid + 1;
        else right = mid - 1;
    }
    return nullptr;
}

#endif
