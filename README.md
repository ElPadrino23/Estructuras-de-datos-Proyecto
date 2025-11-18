## Luis Fernando Martinez Barragan - A01613426
## Avance de proyecto - entrega 3

El programa es capaz de leer un archivo que incluye nombres de jugadores de nfl junto con su puntaje, tambien despliega un menu con 7 opciones donde podremos cambiar la estructura de datos (linkedlist doublylinkedlist binarysearchtree), agregar jugadores, mostrar la lista, ordenarlos de manera descendente, buscar algun jugador, eliminarlo, guardar los datos y salir (esta ultima opcion crea un archivo con la nueva lista de jugadores)

para usar el programa debemos tener abierto el proyecto junto con el archivo "jugadores.txt" aqui deben estar ordenados los jugadores con sus 2 nombres y la puntuacion de estos (1-50) separados por un "-"

en caso de que el codigo lance algun error se puede solucionar ejecutando el siguiente comando: 

g++ main.cpp players.h players.cpp advanced_structures.cpp advanced_structures.h

sin embargo no obtuve ni un solo error usando el compilador online

**recomendacion usar el compilador online "onlinegbd.com" https://www.onlinegdb.com/online_c++_compiler# **

## SICT0301 – evalua los componentes
### 1.1 vector (vector<Player>)

el vector se utiliza para almacenar temporalmente jugadores leidos desde archivo
el acceso por indice es O(1)
insertar al final es O(1)
eliminar elementos es O(n) porque mueve datos
la busqueda secuencial es O(n)
se usa porque quicksort funciona muy bien con el

### 1.2 linkedlist (lista ligada simple)

insertar al inicio O(1)
eliminar por nombre O(n)
busqueda O(n)
recorrido O(n)
sirve para insertar rapido sin reorganizar memoria

### 1.3 doublylinkedlist (lista doblemente ligada)

permite moverse en ambas direcciones
insercion O(1)
eliminacion O(n) pero mas facil por acceso a prev
busqueda O(n)
recorrido O(n)
mas flexible para borrar nodos

### 1.4 binary search tree (bst)

ordenado por puntaje
insercion promedio O(log n) peor caso O(n)
busqueda promedio O(log n) peor caso O(n)
eliminacion O(log n) a O(n)
recorrido in-order O(n)
ventaja obtener orden automatico

### 2 complejidad de quicksort

mejor caso O(n log n)
promedio O(n log n)
peor caso O(n^2)
aun asi es muy eficiente en la practica

### 3 complejidad total del programa

leer archivo O(n)
insertar en bst O(n log n)
ordenar vector O(n log n)
mostrar o guardar O(n)

complejidad total aproximada
O(n log n)
dominada por quicksort y el bst

## SICT0302 – toma de decisiones
### 1 uso de archivos para almacenar jugadores

se usa archivo de texto porque permite persistencia y facilita pruebas

### 2 uso de vector<Player>

permite acceso por indice y es ideal para quicksort

### 3 eleccion de quicksort

se eligio por su buen rendimiento promedio

### 4 implementacion de linkedlist

sirve para inserciones rapidas y comparar estructuras

### 5 implementacion de doublylinkedlist

mas facil borrar nodos y navegar

### 6 implementacion de binary search tree

ordena jugadores por puntaje y facilita mostrarlos ordenados

### 7 uso de recorrido in-order

permite obtener los jugadores ordenados sin esfuerzo extra

### 8 busqueda por nombre

se hace recorrido porque el bst esta ordenado por puntaje

### 9 diseño modular por archivos

mejora la legibilidad y organizacion

### 10 comparacion entre estructuras

se comparan insercion busqueda eliminacion recorrido y facilidad

## SICT0303 – solucion del problema
### 1 lectura de jugadores desde archivo

se lee cada linea y se guarda en un vector

### 2 ordenamiento conforme a puntaje

quicksort ordena el vector para preparar el bst

### 3 construccion del bst

se insertan los jugadores ya ordenados

### 4 gestion con linkedlist y doublylinkedlist

permiten agregar buscar y eliminar de forma dinamica

### 5 mostrar y guardar informacion

el bst entrega jugadores ordenados con in-order
las listas tambien pueden guardarse en archivo

### 6 busqueda y eliminacion

las listas usan busqueda lineal
el bst usa busqueda general por que el nombre no es la clave

### 7 capacidad de escalar

se puede ampliar con avl hash multiples archivos o visualizacion

### Concluision

El proyecto implementa varias estructuras avanzadas con propositos bastante claros la combinacion de vector,listas, listas dobles, bst y quicksort permite comparar tecnicas de almacenamiento y ordenamiento el sistema es eficiente escalable y cumple con lo requerido en las rubricas del curso
