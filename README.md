## Player Manager
### Luis Fernando Martinez Barragan - A01613426
El proyecto Player Manager permite administrar jugadores de la NFL junto con su puntaje, utilizando diferentes estructuras de datos. El sistema lee informacion desde un archivo, mostrarla, modificarla y almacenarla nuevamente, ofreciendo comparacion entre estructuras lineales y no lineales.

### Descripcion del avance 1

En el primer avance el proyecto utilizaba unicamente un vector para almacenar los jugadores y aun no contaba con un archivo README. Las funciones estaban limitadas y no existia documentacion sobre el funcionamiento del programa.

### Descripcion del avance 2

En el segundo avance se anadio un archivo README con la documentacion basica del proyecto y se implemento un menu de cuatro opciones. Ademas, el programa ya permitia ordenar la lista de jugadores por puntaje y guardar los datos procesados en un nuevo archivo de salida. Con estas mejoras, el sistema comenzo a ofrecer funcionalidad mas completa y dejo de depender unicamente del almacenamiento temporal en memoria.

## Cambios sobre el primer avance

Se agrego el README
Razon: era necesario documentar el proyecto para que se pudiera revisar el proposito, funcionamiento y alcance del programa.

Se implemento el menu con 4 opciones
Razon: se busco mejorar la interaccion del usuario y organizar las funciones principales del programa de manera mas clara.

Se anadio la opcion de ordenar jugadores
Razon: ordenar la informacion permitio preparar los datos para otras operaciones y cumplir con los requerimientos del curso relacionados con algoritmos de ordenamiento.

Se habilito guardar los datos en un nuevo archivo
Razon: se necesito agregar persistencia para conservar los cambios realizados sobre la lista de jugadores y evitar depender solo de la memoria durante la ejecucion.

Descripcion del avance 3

En el tercer avance se integraron tres estructuras de datos avanzadas: linkedlist, doublylinkedlist y binarysearchtree. El menu se amplio de cuatro a siete opciones, lo que permitio agregar, buscar, eliminar jugadores y cambiar la estructura utilizada durante la ejecucion del programa. Tambien se mantuvo la capacidad de guardar los datos actualizados en un archivo, asegurando persistencia despues de cada modificacion. Con este avance, el proyecto dejo de depender de una sola estructura lineal y comenzo a ofrecer mecanismos mas completos para la gestion dinamica de la informacion.

Cambios sobre el segundo avance

Se integraron estructuras de datos avanzadas (linkedlist, doublylinkedlist y binarysearchtree)
Razon: fue necesario ampliar el proyecto para cumplir con los requerimientos del curso

El menu se amplio de 4 a 7 opciones
Razon: se buscaba ofrecer un mayor control sobre los datos y permitir nuevas operaciones que no estaban disponibles en el avance anterior.

Se anadio la opcion de agregar, buscar y eliminar jugadores
Razon: estas funciones permitieron gestionar la informacion de forma dinamica y demostrar el uso real de las estructuras avanzadas

Se implemento el cambio de estructura durante la ejecucion
Razon: esto permitio analizar el comportamiento de cada estructura con los mismos datos y fortalecer la argumentacion en competencias.

Entrega final

La entrega final del proyecto incluye un programa funcional llamado Player Manager el cual es capaz de leer un archivo con jugadores y sus puntajes, almacenarlos en diferentes estructuras de datos (vector, linkedlist, doublylinkedlist y binarysearchtree) y permitir su gestion mediante un menu con siete opciones, ademas el sistema puede agregar nuevos jugadores, buscarlos, eliminarlos, cambiar la estructura utilizada durante la ejecucion, ordenarlos cuando es necesario y guardar los datos actualizados en un archivo de salida. Todo el codigo compila correctamente, cuenta con identificacion del autor y se encuentra documentado. El proyecto demuestra el uso de estructuras lineales y no lineales, asi como mecanismos de lectura y escritura de archivos y operaciones de consulta sobre los datos.

Cambios sobre el tercer avance

Se completo el analisis de complejidad de todas las estructuras y operaciones
Razon: era necesario para cumplir con las especificaciones y justificar decisiones con fundamentos tecnicos.

Actualice el REadMe con la plantilla oficial
Razon: el avance anterior no permitia evaluar las competencias solicitadas por falta de formato adecuado.

Se organizaron las explicaciones para el video y documentacion final
Razon: con el fin de presentar de manera clara los fundamentos teoricos del proyecto.

## Instrucciones para compilar el proyecto

Ejecutar en la terminal:

g++ main.cpp players.h players.cpp advanced_structures.h advanced_structures.cpp

## Descripcion de las entradas del proyecto

El programa requiere un archivo llamado jugadores.txt con el siguiente formato:

Nombre Apellido-Puntaje


Ejemplo:

Patrick Mahomes-50
Josh Allen-45
Joe Burrow-42

Descripcion de las salidas del proyecto

El programa muestra en pantalla la informacion de los jugadores segun la estructura seleccionada y genera un archivo actualizado cuando el usuario lo solicita (Opcion 7). Esta lista incluye: 

lista de jugadores

jugadores ordenados

archivo nuevo con los cambios realizados
