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
- General
    - Si se ingresan numeros cuando se piden letras o palabras, se puede generar un error. También cuando se ingresan letras en vez de numeros puede llevar a un error de ejecución
- Black Jack
    - Posibles errores en la función split
- Carrera de Caballos
    - aaa
- Crash
    - Problemas al ingresar dos o más caracteres cuando se le pide solo uno, desde errores gráficos hasta la finalización del programa.
- Ruleta
    - Historial

### A mejorar:

- Se podria mejorar la interfaz del menú de registro e inicio de sesion para que sea más amigable
- 

## Descripcion de las diversas funciones 

### Inicio del programa

Primero se muestra el nombre del casino, como tambien si es que los usuarios se han leido correctamente. Se pide el nombre al usuario y se lee el archivo de [jugadores](Jugadores.csv). 

**Caso 1**

En el caso de que se encuentre el nombre, se le informa al usuario y se muestra el saldo actual. Se le pregunta al usuario si es que se desea modificar el saldo, en donde si el usuario lo encuentre oportuno, se ingresara el saldo, en caso contrario se muestra el menu principal.

```
Jugador encontrado. Saldo Actual: 10100
Desea modificar su saldo? (s/n): s
Ingrese el monto a modificar: 2000
```

**Caso 2**

En el caso de que el jugador no se encuentre, se informa y se le pide al usuario que ingrese un nombre y saldo para este nuevo jugador. En el caso de que el nombre entregado coincida con alguno del archivo, se informa que el usuario si existe.

```
Sub-caso 1:
Jugador no encontrado, registre un nuevo jugador.
Ingrese su nombre: Jorge
Ingrese su dinero: 15000
Jugador registrado exitosamente

Sub-caso 2:
Jugador no encontrado, registre un nuevo jugador.
Ingrese su nombre: Andres
El jugador ya existe.
```

### Menu de juegos

Se muestra el menu que contiene todos los juegos y la opcion de salir, siendo el usuario el elija alguna de estas.

```
==================================

    Bienvenido a Casino Zona 3    

==================================

¿Cual juego desea jugar?
1. Blackjack
2. Ruleta
3. Carrera de caballos
4. Crash
5. Salir
```

### **Opcion 1**

Se inicializa el programa del Blackjack, preguntadole al usuario si es que desea ver las reglas del juego, mostrandolas si asi lo desea este y en caso contrario mostrando el menu principal

```
 --------------------------------
|Bienvenido al juego de Blackjack|
 --------------------------------
|Desea saber las reglas?        |
|1. Si                          |
|2. No                          |
 ------------------------------- 
```
**Paso 1.5: Ver las reglas**
Si el jugador desea ver las reglas verá lo siguiente

```
 ----------------------------------------------------------------------------------------------------
|Las reglas son las siguientes:                                                                      |
|1. Al jugador se le entregaran 2 cartas.                                                            |
|2. Al Crupier se le entregaran 2 cartas. Solo una es visible                                        |
|3. El objetivo del juego es tener una puntuacion lo más cercana posible a 21 sin pasarse.           |
|4. Si el jugador tiene un As, puede tomarlo como un 1 o como un 11.                                 |
|5. Si el jugador tiene dos As, el segundo As se toma como un 1.                                     |
|6. Si el jugador tiene un As y un 10, gana directamente.                                            |
|7. Si el crupier supera los 21, el jugador gana.                                                    |
|8. Las cartas J, Q y K valen 10.                                                                    |
|9. Se puede utilizar la opcion de doblar y pedir solo si tiene el saldo necesario                   |
|10. Se puede utilizar la opcion de dividir manos si tiene el saldo necesario                        |
|11. En caso de que se seleccione una de estas opciones y no sea posible, sera tomado como quedarse. |
 ----------------------------------------------------------------------------------------------------
|Presione enter para continuar...                                                                    |
 ----------------------------------------------------------------------------------------------------

```
**Paso 2 : Ingresar la apuesta**

Se ingresa la apuesta que desea hacer el jugador
```
Su saldo actual es de $270266
Cuanto desea apostar?
1000
```

**Paso 3 : Se muestran las cartas de crupier y el jugador**
*Paso 3.5 :En caso de que el jugador tenga 21 gana directamente*

```
    --------------------------
   |Carta visible del crupier:|   
    --------------------------
              ----- 
             |♠    |
             |  4  |
             |    ♠|
              ----- 

             ------- 
            |Tu mano|
             ------- 
       -----         -----  
      |♠    |       |♦    | 
      |  K  |       |  A  | 
      |    ♠|       |    ♦| 
       -----         -----  
          ------------- 
         |Puntuacion:21|
          ------------- 
 ---------------------------------
|¡Felicidades! Has ganado con 21 |
 ---------------------------------
El dinero del jugador Sepu ha sido modificado exitosamente
Quieres seguir jugando? (1 para si, 0 para no): .

```
*Paso 3.7 : El jugador debe elegir una opcion*
El jugador debe selecciona si quedarse, pedir, doblar o dividir en caso de que sea posible
```
    --------------------------
   |Carta visible del crupier:|   
    --------------------------
              ----- 
             |♥    |
             |  6  |
             |    ♥|
              ----- 

             ------- 
            |Tu mano|
             ------- 
       -----         -----  
      |♦    |       |♠    | 
      |  5  |       |  7  | 
      |    ♦|       |    ♠| 
       -----         -----  
          ------------- 
         |Puntuacion:12|
          ------------- 
¿Que desea hacer?
1) Pedir carta
2) Plantarse
3) Doblar
4) Dividir (split)
```
si el jugador desea otra carta selecciona la opción 1, si no de sea otra la opción 2, si desea doblar su apuesta y pedir una unica carta la opción 3 y si desea dividir sus manos en 2 diferentes la opción 4

### **Opcion 2: Ruleta**

Se inicializa el Programa de la ruleta europea, esta comienza preguntando si quiere saber las reglas del juego y mostrando tu saldo actual

### **Opcion 3: Carrera de caballos**



### **Opcion 4: Crash**

**Paso 1: Inicio**

Se inicializa el programa del Crash, preguntándole al usuario si desea ver las reglas del juego.

````
Has elegido la opción 4: Crash
¿Deseas leer las reglas? (s/n)
````

Las reglas se muestran cuando el usuario escribe 's'. En caso contrario, prosigue al Paso 2.

````
Has elegido la opción 4: Crash
¿Deseas leer las reglas? (s/n) s
Reglas del juego:
El juego consiste en un avión que se mueve mientras que un multiplicador va aumentando. La idea es retirar el multiplicador antes de que el avión explote.
Presione cualquier tecla para continuar.
````

**Paso 2: Apuesta**

Se le pide al jugador que ingrese la cantidad de dinero a apostar.
````
¡Bienvenido al juego de Crash!
Tu saldo actual es: $271766
Ingresa la cantidad que deseas apostar: 
````
Si se ingresa un monto válido, el programa se prepara para empezar.
````
¡Bienvenido al juego de Crash!
Tu saldo actual es: $271766
Ingresa la cantidad que deseas apostar: 100
Iniciando juego...
````
En caso contrario, se sale del juego.
````
¡Bienvenido al juego de Crash!
Tu saldo actual es: $271766
Ingresa la cantidad que deseas apostar: 300000
No tienes suficiente saldo para realizar esta apuesta.
Presione cualquier tecla para salir del juego.
````

**Paso 3: Jugar y retirar**

Inicia el juego y se muestra al avión avanzando y el multiplicador aumentando. El usuario decide en qué momento retirar presionando cualquier tecla, siempre y cuando sea antes que el avión explote.

Pantalla que se muestra en un momento cualquiera de la ejecución:
````
      _  _
     ( `   )_
    (    )    `)
  (_   (_ .  _) _)

               _
             -=\`\
         |\ ____\_\__
------ -=\c`""""""" "`)
          `~~~~~/ /~~`
            -==/ /
              '-'
                                   _
                                  (  )
   _ .                         ( `  ) . )
 (  _ )                      (_, _(  ,_)_)
(_ ,)
                1.13
````

Pantalla que se muestra en un momento cualquiera después de presionar una tecla:
````
          _  _
         ( `   )_
        (    )    `)
      (_   (_ .  _) _)

               _
             -=\`\
         |\ ____\_\__
------ -=\c`""""""" "`)
          `~~~~~/ /~~`
            -==/ /
              '-'
                                     _
                                    (  )
     _ .                         ( `  ) . )
   (  _ )_                      (_, _(  ,_)_)
 (_  _(_ ,)
                2.46
Ya retiraste.
````

**Paso 4: Fin del juego y resultados**

Se presenta la explosión del avión y el resultado de la partida. Además, se muestra el historial de las partidas realizadas en el tiempo de ejecución.

En caso de perder:
````
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⠀⡀⢀⠀⢠⠀⠀⠀⠀⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⢠⢤⣀⠀⠀⠀⠈⣆⢧⠈⡆⢸⠀⠀⠀⢰⢡⠇⠀⠀⠀⠀⠀⡀⠀⠀⠀⠀⠀
⠀⠀⠀⢀⠀⠀⣯⢀⣨⠃⠀⠀⠀⠸⡜⣄⣣⢸⠀⠀⠀⡜⡌⠀⠀⠀⠀⢀⡜⡁⠀⠀⠀⠀⠀
⠀⠀⠙⢮⡳⢄⠈⠁⠀⢠⠴⠍⣛⣚⣣⢳⢽⡀⣏⣲⣀⢧⡥⠤⠶⢤⣠⢎⠜⠁⠀⠀⠀⠀⠀
⠀⠠⣀⠀⠙⢦⡑⢄⢀⣾⣧⡎⠁⠀⠙⡎⡇⡇⡇⠹⢪⣀⡓⣦⢀⣼⣵⠋⢀⠴⣊⠔⠁⠀⠀
⠀⠀⠈⠑⢦⣀⠙⣲⣝⢭⡚⠃⠀⠀⠀⠸⠸⣹⠁⠀⠀⠀⠉⣹⣪⣎⡸⢞⡵⠊⠁⣀⠀⠀⠀
⠀⠀⠀⠀⠀⠈⣷⢯⣨⠷⣝⠦⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⠵⣪⢶⣙⡤⠖⢉⣀⠤⠖⠂
⠀⠀⠀⠀⠀⢀⡞⢠⠾⠓⢮⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢬⣺⡯⢕⢲⠉⣥⣀⡀⠀⠀
⠀⠀⢀⡤⣀⢈⡷⠻⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠁⠘⠀⢱⢾⠘⢇⢴⠁⠀⠀
⠀⠀⢻⣀⡼⢘⣧⢀⡟⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡄⢙⣞⠆⠀⠀⠀⠀⠀
⠀⠀⠀⠉⠀⢿⡀⠈⠧⡤⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣸⠇⣹⣦⠇⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠸⢤⡴⢺⡧⣴⡶⢗⡣⠀⡀⠀⠀⠀⡄⠀⢀⣄⠢⣔⡞⣤⠦⡇⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⣀⡤⣖⣯⡗⣪⢽⡻⣅⠀⣜⡜⠀⠀⠀⠸⡜⡌⣮⡣⡙⢗⢏⡽⠁⠰⡏⠙⡆⠀⠀
⠀⠀⣒⡭⠖⣋⡥⣞⣿⡚⠉⠉⢉⢟⣞⣀⣀⣀⠐⢦⢵⠹⡍⢳⡝⢮⡷⢝⢦⡀⠉⠙⠁⠀⠀
⠐⠊⢡⠴⠚⠕⠋⠹⣍⡉⠹⢧⢫⢯⣀⣄⣀⠈⣹⢯⣀⣧⢹⡉⠙⢦⠙⣄⠑⢌⠲⣄⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠘⠧⡴⣳⣃⣸⠦⠴⠖⢾⣥⠞⠛⠘⣆⢳⡀⠈⠳⡈⠳⡄⠁⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⢀⡜⡱⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⡄⢣⠀⠀⠉⠀⠈⠂⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⢀⠞⡼⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠹⡀⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
El avion ha crasheado.
Perdiste.
Tu saldo actual es: $272000
El dinero del jugador Sepu ha sido modificado exitosamente
Historial de partidas: 
+3
-15

Quieres seguir jugando? (1 para si, 0 para no): 
````
En caso de ganar:
````
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⠀⡀⢀⠀⢠⠀⠀⠀⠀⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⢠⢤⣀⠀⠀⠀⠈⣆⢧⠈⡆⢸⠀⠀⠀⢰⢡⠇⠀⠀⠀⠀⠀⡀⠀⠀⠀⠀⠀
⠀⠀⠀⢀⠀⠀⣯⢀⣨⠃⠀⠀⠀⠸⡜⣄⣣⢸⠀⠀⠀⡜⡌⠀⠀⠀⠀⢀⡜⡁⠀⠀⠀⠀⠀
⠀⠀⠙⢮⡳⢄⠈⠁⠀⢠⠴⠍⣛⣚⣣⢳⢽⡀⣏⣲⣀⢧⡥⠤⠶⢤⣠⢎⠜⠁⠀⠀⠀⠀⠀
⠀⠠⣀⠀⠙⢦⡑⢄⢀⣾⣧⡎⠁⠀⠙⡎⡇⡇⡇⠹⢪⣀⡓⣦⢀⣼⣵⠋⢀⠴⣊⠔⠁⠀⠀
⠀⠀⠈⠑⢦⣀⠙⣲⣝⢭⡚⠃⠀⠀⠀⠸⠸⣹⠁⠀⠀⠀⠉⣹⣪⣎⡸⢞⡵⠊⠁⣀⠀⠀⠀
⠀⠀⠀⠀⠀⠈⣷⢯⣨⠷⣝⠦⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⠵⣪⢶⣙⡤⠖⢉⣀⠤⠖⠂
⠀⠀⠀⠀⠀⢀⡞⢠⠾⠓⢮⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢬⣺⡯⢕⢲⠉⣥⣀⡀⠀⠀
⠀⠀⢀⡤⣀⢈⡷⠻⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠁⠘⠀⢱⢾⠘⢇⢴⠁⠀⠀
⠀⠀⢻⣀⡼⢘⣧⢀⡟⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡄⢙⣞⠆⠀⠀⠀⠀⠀
⠀⠀⠀⠉⠀⢿⡀⠈⠧⡤⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣸⠇⣹⣦⠇⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠸⢤⡴⢺⡧⣴⡶⢗⡣⠀⡀⠀⠀⠀⡄⠀⢀⣄⠢⣔⡞⣤⠦⡇⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⣀⡤⣖⣯⡗⣪⢽⡻⣅⠀⣜⡜⠀⠀⠀⠸⡜⡌⣮⡣⡙⢗⢏⡽⠁⠰⡏⠙⡆⠀⠀
⠀⠀⣒⡭⠖⣋⡥⣞⣿⡚⠉⠉⢉⢟⣞⣀⣀⣀⠐⢦⢵⠹⡍⢳⡝⢮⡷⢝⢦⡀⠉⠙⠁⠀⠀
⠐⠊⢡⠴⠚⠕⠋⠹⣍⡉⠹⢧⢫⢯⣀⣄⣀⠈⣹⢯⣀⣧⢹⡉⠙⢦⠙⣄⠑⢌⠲⣄⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠘⠧⡴⣳⣃⣸⠦⠴⠖⢾⣥⠞⠛⠘⣆⢳⡀⠈⠳⡈⠳⡄⠁⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⢀⡜⡱⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⡄⢣⠀⠀⠉⠀⠈⠂⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⢀⠞⡼⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠹⡀⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
El avion ha crasheado.
Ganaste con un multiplicador de 2.20
Tu saldo actual es: $272006
El dinero del jugador Sepu ha sido modificado exitosamente
Historial de partidas: 
+240

Quieres seguir jugando? (1 para si, 0 para no): 
````
Finalmente se pregunta si se quiere seguir jugando. Si la respuesta es 1, se vuelve al menú principal. En caso contrario, se finaliza el programa.