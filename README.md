##Contexto

Mi proyecto consiste en una agenda digital que permite registrar, consultar, modificar y eliminar contactos de manera sencilla, ademas de guardar la informacion en un archivo para conservarla despues de cerrar el programa.
La idea es que el usuario pueda registrar datos importantes como nombre, telefono y correo, y que estos se guarden en un archivo para no perder la informacion al cerrar el programa.

##Objetivo

El objetivo principal es crear una herramienta basica para la gestion de contactos aplicando los conceptos de programacion vistos en clase.
De esta forma, se busca que el usuario tenga una experiencia sencilla y clara al interactuar con la agenda.

##Cambios realizados y por que se hicieron

En esta nueva version del proyecto realice varios cambios para mejorar la estructura, cumplir con la rubrica y evitar que me faltaran puntos:

1. Se agrego un arbol BST

El profesor pidio que se usara una estructura de datos un poco mas avanzada que solo la lista ligada, asi que agregue un BST (Binary Search Tree).
Este arbol me sirve para:

Mostrar contactos ordenados alfabeticamente sin usar ordenar la lista

Buscar un contacto por nombre mas rapido que en la lista

Tener una estructura de datos adicional para cumplir la rubrica

Lo elegi porque es mas sencillo y practico que un AVL y aun asi cumple bien con lo que pide el profe.

2. Se agrego la busqueda binaria por numero

El profe tambien quiso que aplicara varios tipos de busquedas, asi que implemente la busqueda binaria.
Para usarla convierto la lista en un vector, lo ordeno por numero y luego aplico binaria.
La gente del curso si entiende este proceso porque es lo mismo que vimos en clase.

3. Se agregaron validaciones

Evitar nombres vacios

Evitar contactos duplicados

Mensajes mas claros para el usuario

4. Se corrigio la carga y guardado del archivo

Ahora al agregar, actualizar o eliminar tambien se actualiza el archivo automaticamente.

5. Se agregaron comentarios simples dentro del codigo

Todo esta escrito de manera sencilla para que el profe vea que entiendo lo que hago.

Funcionalidad del programa

El menu principal ofrece:

Agregar contacto: pide nombre, telefono y correo.

Mostrar contactos: muestra todos los registros.

Buscar contacto recursivo: busca por nombre usando recursion.

Actualizar contacto: cambia los datos del contacto.

Eliminar contacto: borra un contacto de la lista ligada.

Contar contactos: muestra el total.

Ordenamientos: selection sort, bubble sort y merge sort.

Busqueda binaria: busca por numero en una lista ordenada.

BST:

Mostrar contactos ordenados automaticamente

Buscar por nombre usando el arbol

Algoritmos de ordenamiento

En clase vimos 3 metodos y analice cual es mejor para mi proyecto:

Selection sort

Es simple pero muy lento para listas grandes.

Se usa mas para ejemplos educativos.

Tiene complejidad O(n^2).

Bubble sort

Compara elementos de dos en dos e intercambia si estan mal.

Igual que el anterior, sirve mas para demostrar el concepto.

Complejidad O(n^2).

Merge sort

Divide la lista en partes mas pequenas, las ordena y luego las combina.

Es mucho mas rapido y eficiente.

Complejidad O(n log n).

Lo elegi como el algoritmo principal porque al manejar muchos contactos no quiero que el programa se vuelva lento.

Estructura de datos
Lista ligada simple

Decidi usar una lista ligada porque:

No necesito saber cuantos contactos habra

Es facil agregar, eliminar o actualizar sin mover todos los elementos

Se usa memoria dinamica (solo se crea lo que se necesita)

Cada contacto es un nodo con:

nombre

telefono

correo

puntero al siguiente

Arbol BST (estructura adicional)

El profesor pidio una estructura mas avanzada, por eso agregue un BST.
Lo uso para:

Mostrar contactos en orden alfabetico

Buscar mas rapido por nombre

Complejidad del programa
Lista ligada

Insertar: O(n)

Buscar: O(n)

Actualizar: O(n)

Eliminar: O(n)

Contar: O(n)

Guardar archivo: O(n)

Cargar archivo: O(n^2) (porque se llama insertar por cada linea)

Ordenamientos

Selection Sort -> O(n^2)

Bubble Sort -> O(n^2)

Merge Sort -> O(n log n)

Busquedas

Recursiva (lista) -> O(n)

Binaria -> O(log n) si ya esta ordenado

BST:

Buscar -> O(log n) en promedio

Insertar -> O(log n) en promedio

Mostrar ordenado -> O(n)
