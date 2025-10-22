# Proyectos_ag-dic.Benji

## Contexto
Mi proyecto consiste en una agenda digital que permite registrar, consultar, modificar y eliminar contactos de manera sencilla, ademas de guardar la informacion en un archivo para conservarla despues de cerrar el programa. 
La idea es que el usuario pueda registrar datos importantes como el nombre, teléfono y correo, y que estos se guarden en un archivo para no perder la información al cerrar el programa.  

## Objetivo
El objetivo principal de este proyecto es crear una herramienta básica para la gestión de contactos, aplicando conceptos de programación que se estan viendo en clase. 
De esta forma, se busca que el usuario tenga una experiencia sencilla y clara al interactuar con la agenda.

## Funcionalidad
El menú principal del programa ofrece las siguientes opciones:

- **Agregar contacto**: se solicita nombre, teléfono y correo. (En esta nueva entrega implemente para evitar duplicados o nombres vacios y asi evitar un error)
- **Mostrar contactos**: Muestra todos los contactos almacenados
- **Buscar contacto**: permite localizar un contacto por nombre de manera recursiva
- **Actualizar contacto**: cambia los datos de un contacto existente
- **Eliminar contacto**: borra un contacto de la lista ligada
- **Contar contactos**: muestra cuántos registros existen (el total)
- **Ordenar contactos por nombre**: el usuario puede elegir entre tres métodos distintos de ordenamiento (selection, bubble y merge)
- **Guardar y cargar automáticamente**:  los datos se guardan en un archivo llamado `contactos.txt`
- **Busqueda binaria**: Busca un contacto en la lista ya ordenada

## Algoritmos de ordenamiento
En clase hemos visto 3 diferentes tipos de algoritmos los cuales son "selection sort, bubble sort y merge sort". Cada uno es mejor en ciertos casos, a continaucion explico como funcionan y cual me conviene mas para mi proyecto:
- Selection sort: Lo que tiene el selection sort es que es simple, lo que ahce es buscar el elemento mas pequeño de la lista y colocarlo al inciio, repitiendo el rpoceso hasta que todo quede ordenado. Es recomendable para listas pequeñas por lo que en mi caso no es la mejor opcion
- Bubble sort: Este algoritmo compara los elemmentos de dos en dos y lo que ahce es que los va intercambiando si estan en el roden incorrecto. De igual manera es uno de los mas "basicos" pero este se suele usar con fines mas educativos o para listas cortas por lo que nuevamente no es la mejor opcion
- Merge sort: Por ultimo el merge sort y el que yo opte por utilizar, lo que hace es dividir la lista en partes mas pequeñas para asi ordenarlas individualmente y posteriormente combinarlas. Lo que tiene este y mi motivo de tomar este algoritmo es que es muchisimo mas rapido y eficiente en comparacion a los otros dos, precisamente cuando se trabaja con listas grandes o muchos contactios (como lo es mi caso)

En mi proyecto, Merge Sort es el más conveniente porque al tratarse de una agenda de contactos, la cantidad de registros puede aumentar con el tiempo. Este algoritmo me permite mantener los datos ordenados sin que el programa se vuelva demasiado lento, ya que su complejidad es O(n log n), lo cual es mucho más eficiente que los O(n²) de los otros métodos

## Estructura
Para almacenar los contactos decidi usar una lista ligada simple ya que es una estructura que se adpata bastante bien cuando no se sabe cuantos elementos se van a guardar. En mi programa cada contacto es un nodo que guarda el nombre, telefono, corre y un puntero al siguiente contacto. Lo que me permite agregar, eliminiar o actualizar contactos sin la ncesidad de mover todos los elementos como lo podria ser en un arreglo. De igual manera otra ventaja que el profe menciono es que la memoria se usa de forma dinamica por lo que solo sea creara un nodo cuando se necesite
