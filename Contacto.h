#ifndef CONTACTO_H
#define CONTACTO_H

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

// Estructura basica para guardar un contacto
// Aqui solo guardo nombre, telefono, correo y el apuntador next para formar la lista ligada
struct Contacto {
    string nombre;
    string telefono;
    string correo;
    Contacto* next;
};

// Funcion para convertir cadenas a minusculas y asi comparar sin errores
string toLowerStr(string s) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}

#endif
