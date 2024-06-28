# Casino Zona 3

## Descripción

Este programa simula la experiencia de juego de un casino real, permitiendo a los usuarios elegir entre 4 juegos de azar, siendo estos la carrera de caballos, la ruleta, el crash y el blackjack. Cada juego esta pensando de tal manera que sea una experiencia atractiva y lo más similar posible a la de un casino online.

## Cómo compilar y ejecutar

Dado que el sistema está diseñado para ser accesible y de fácil utilizacion, recomendamos usar [Repl.it](http://repl.it/) para una rápida configuración y ejecución. Sigue estos pasos para comenzar:

1. Visita el URL del repositorio que se encuentra en este [Link](https://replit.com/@felipechg/Proyecto#README.md).
2. Da click en el boton "Fork and run".
3. Crea una cuenta en el caso de que no la hayas creado.
4. Luego solo debes presionar el boton "Run" que se encuentra en la parte superior de la interfaz de Replit.com.

## Funcionalidades

### Funcionando correctamente:

- Blackjack.
- Carrera de caballos.
- Crash.
- Ruleta.

### Problemas conocidos:

- A
- B
- C
- D

### A mejorar:

- A
- B
- C
- D

## Descripcion de las diversas funciones 

### **Inicio del programa**

Primero se muestra el nombre del casino, como tambien si es que los usuarios se han leido correctamente. Se pide el nombre al usuario y se lee el archivo de [jugadores](Jugadores.csv). 

**Caso 1**

En el caso de que se encuentre el nombre, se le informa al usuario y se muestra el saldo actual. Se le pregunta al usuario si es que se desea modificar el saldo, en donde si el usuario lo encuentre oportuno, se ingresara el saldo, en caso contrario se muestra el menu principal.

```
Jugador encontrado. Saldo Actual: 10100
Desea modificar su saldo? (s/n): s
Ingrese el monto a modificar: 2000
```

**Caso 2**

En el caso de que el jugadore


### **Opcion 1**

Estado inicial:

X  -  2  -  8 

1  -  3  -  4 

6  -  5  -  7

Se realiza la busqueda por profundidad al estado inicial, generando los movimientos adyacentes, como tambien los posibles casos, no almacenando los repetidos y evitando iteraciones innecesarias. Luego se muestra el camino mas rapido a la solucion encontrada.

```
Opción seleccionada: 1) Búsqueda en Profundidad
Se realizan los procedimientos necesarios y se 
imprimen por pantalla los pasos de la resolucion
en el caso de que el usuario asi lo desee...
```

**Opcion 2: Buscar peliculas por su ID**

Estado inicial:

X  -  2  -  8 

1  -  3  -  4 

6  -  5  -  7

Se realiza la busqueda por anchura al estado inicial, generando los movimientos adyacentes, como tambien los posibles casos, no almacenando los repetidos y evitando iteraciones innecesarias. Luego se muestra el camino mas rapido a la solucion encontrada.

```
Opción seleccionada: 2) Búsqueda en Anchura
Se realizan los procedimientos necesarios y se 
imprimen por pantalla los pasos de la resolucion
en el caso de que el usuario asi lo desee...

```

**Opcion 3: Buscar Mejor Primero**

Funcion no programada debido a que esta se realizaba en el caso de hacer la tarea en parejas.

**Opcion 4: Salir del programa**

Esta funcion termina el programa, liberando la memoria de las listas utilizadas.

```
Opción seleccionada: 4) Salir
Presione una tecla para continuar...
```