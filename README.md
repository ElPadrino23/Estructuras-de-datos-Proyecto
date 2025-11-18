### Luis Fernando Martinez Barragan - A01613426
## Avance de Proyecto - Entrega 3

El programa es capaz de leer un archivo que incluye nombres de jugadores de NFL junto con su puntaje, Tambien despliega un menu con 7 opciones, donde podremos:
Cambiar la estructura de datos (LinkedList, DoublyLinkedList, BinarySearchTree),  agregar jugadores, mostrar la lista , ordenarlos de manera descendente, buscar algun jugador, eliminarlo , guardar los datos y salir (Esta ultima opcion crea un archivo con la nueva lista de jugadores)

Para usar el programa debemos de tener abrir el proyecto junto con el archivo "jugadores.txt". Aqui deben de estar ordenados los jugadores con sus 2 nombre y la puntuacion de estos (1-50) separados por un "-". 

En caso de que el codigo lance algun error, se puede solucionar ejecutando el siguiente codigo:
g++ main.cpp players.h players.cpp advanced_structures.cpp advanced_structures.h

Sin embargo no obtuve ni un solo error utilizando el siguiente compilador online:

**Recomendacion: Utilizar el compilador online "onlinegbd.com" https://www.onlinegdb.com/online_c++_compiler# **

## SICT0301 – Evalua los componentes
### 1.1. Vector (vector<Player>)

El vector se utiliza para almacenar temporalmente jugadores leídos desde archivo

El acceso por indice tiene complejidad O(1).

Insertar elementos al final tiene complejidad O(1) 

Eliminar elementos implica mover datos, por lo que seria O(n).

La busqueda secuencial tambien O(n).

Se usa  porque QuickSort permite de forma eficiente.
### 1.2. LinkedList (lista ligada simple)

La lista simplemente ligada ofrece:

Inserción al inicio en tiempo O(1).

Eliminación por nombre en O(n), debido a la búsqueda.

Búsqueda lineal en O(n).

Recorrido completo de la lista en O(n).

Esta estructura permite insertar elementos rápidamente sin necesidad de reorganizar datos en memoria.

### 1.3. DoublyLinkedList (lista doblemente ligada)

La versión doblemente ligada permite navegar en ambas direcciones.

Inserción al inicio o al final en tiempo O(1).

Eliminación por nombre en O(n), pero es más sencilla debido al acceso a nodos previos.

Búsqueda en O(n).

Recorrido en O(n).

La mayor flexibilidad facilita operaciones de borrado.

### 1.4. Binary Search Tree (BST)

El BST está ordenado por puntaje en orden descendente.

Inserción promedio: O(log n).

Inserción en peor caso: O(n).

Búsqueda promedio: O(log n).

Búsqueda peor caso: O(n).

Eliminación promedio: O(log n).

Eliminación peor caso: O(n).

Recorrido completo (in-order): O(n).

Su ventaja principal es que permite obtener resultados ordenados automáticamente mediante un recorrido in-order.

## 2. Complejidad de QuickSort

QuickSort se utiliza para ordenar el vector inicial de jugadores.

Mejor caso: O(n log n).

Caso promedio: O(n log n).

Peor caso: O(n²).

Aun así, es uno de los algoritmos más eficientes para vectores en la práctica.

## 3. Complejidad total del programa

Las operaciones más relevantes del proyecto requieren:

Leer jugadores desde archivo: O(n).

Insertar jugadores en BST: O(n log n).

Ordenar con QuickSort: O(n log n).

Mostrar o guardar datos: O(n).

Por ello, la complejidad total del sistema completo es aproximadamente:

O(n log n)

Esta complejidad está dominada por QuickSort y por las inserciones múltiples en el árbol binario.

## SICT0302 – Toma de decisiones

Esta sección describe las decisiones que se tomaron durante el desarrollo del proyecto y su justificación.

### 1. Uso de archivos para almacenar jugadores

Se eligió almacenar los datos en un archivo de texto porque permite persistencia entre ejecuciones, facilita pruebas y mantiene el proyecto simple de utilizar.

### 2. Uso de vector<Player>

Se usa vector porque permite acceso por índice en tiempo constante y es una estructura ideal para aplicar QuickSort.

### 3. Elección del algoritmo QuickSort

QuickSort se seleccionó por su excelente rendimiento promedio y por ser uno de los algoritmos más utilizados académicamente para vectores.

### 4. Implementación de LinkedList

La lista ligada simple se implementó para permitir inserciones rápidas y demostrar su diferencia respecto a otras estructuras dinámicas.

### 5. Implementación de DoublyLinkedList

La versión doblemente ligada permite eliminar nodos con mayor facilidad y recorrer en ambas direcciones. Se eligió para analizar su eficiencia respecto a la lista simple.

### 6. Implementación de Binary Search Tree

El árbol binario permite almacenar a los jugadores en un orden natural según su puntaje. Su recorrido in-order facilita mostrar la lista ordenada sin necesidad de reordenar manualmente.

### 7. Uso de recorridos in-order

Este recorrido permite obtener jugadores ordenados por puntaje de manera eficiente.

### 8. Búsqueda por nombre

Aunque el árbol ordena por puntaje, la búsqueda se realiza por nombre mediante recorrido completo. Se eligió este diseño porque el nombre no forma parte de la clave de ordenamiento.

### 9. Diseño modular por archivos

El proyecto se dividió en varios archivos (players.h, advanced_structures.h, etc.) para mejorar legibilidad, organización y mantenibilidad.

### 10. Comparación entre estructuras

Se eligieron diferentes estructuras para observar sus diferencias en cuanto a:

Inserción,Búsqueda,Eliminación,Recorrido y Facilidad de implementación

Esto cumple con los objetivos de aprendizaje del curso.

## SICT0303 – Solución del problema

A continuación se detalla cómo las estructuras y algoritmos permiten resolver el problema planteado.

### 1. Lectura de jugadores desde archivo

El archivo se lee línea por línea, y los datos se almacenan en un vector para manipularlos fácilmente.

### 2. Ordenamiento conforme a puntaje

El vector de jugadores es ordenado con QuickSort para preparar la estructura inicial del BST.

### 3. Construcción del Binary Search Tree

Una vez ordenados los jugadores, éstos se insertan en el BST para organizar la información de manera jerárquica y eficiente.

### 4. Gestión mediante LinkedList y DoublyLinkedList

Estas dos estructuras permiten agregar, buscar y eliminar jugadores de forma dinámica sin depender del orden del archivo original.

### 5. Mostrar y guardar la información

El BST puede recorrer los jugadores ordenados por puntaje mediante un recorrido in-order, lo que permite listar los datos en orden descendente.
Las listas ligadas también pueden guardarse en archivo para dejar persistencia.

### 6. Búsqueda y eliminación

Las listas usan búsqueda lineal para localizar jugadores por nombre.
El BST usa una búsqueda recursiva general porque el nombre no es la clave del árbol.

### 7. Capacidad de escalar

La estructura del proyecto permite agregar mejoras futuras como:

Árboles AVL

Tablas hash para búsquedas muy rápidas por nombre

Soporte para múltiples archivos

Representación visual de las estructuras

Conclusión

El proyecto implementa correctamente varias estructuras de datos avanzadas, cada una con un propósito claro y justificado. La combinación de vectores, listas, listas doblemente ligadas, árboles binarios y QuickSort permite comprender y comparar distintas técnicas de almacenamiento, recorrido y ordenamiento.

Gracias a este diseño modular y flexible, el sistema es eficiente, escalable y cumple completamente con los criterios establecidos en las rúbricas del curso.



