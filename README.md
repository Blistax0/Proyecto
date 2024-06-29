# Casino Zona 3

## Descripción

Este programa simula la experiencia de juego de un casino real, permitiendo a los usuarios elegir entre 4 juegos de azar: la carrera de caballos, la ruleta, el crash y el blackjack. Cada juego esta pensando de tal manera que sea una experiencia atractiva y lo más similar posible a la de un casino online.

## Cómo compilar y ejecutar

Dado que el sistema está diseñado para ser accesible y de fácil utilizacion, recomendamos usar [Repl.it](http://repl.it/) para una rápida configuración y ejecución. Sigue estos pasos para comenzar:

1. Visita el URL del repositorio que se encuentra en este [Link](https://replit.com/@felipechg/Proyecto#README.md).
2. Da click en el boton "Fork and run".
3. Crea una cuenta en el caso de que no la hayas creado.
4. Luego solo debes presionar el boton "Run" que se encuentra en la parte superior de la interfaz de Replit.com.
5. Se recomienda que se ponga en pantalla completa para una correcta visualización.

## Funcionalidades

### Funcionando correctamente:

- Blackjack.
- Carrera de caballos.
- Crash.
- Ruleta.

### Problemas conocidos:
- General
    - Si se ingresan numeros cuando se piden letras o palabras, se puede generar un error. También cuando se ingresan letras en vez de numeros puede llevar a un error de ejecución.
    - Un error en alguno de los juegos puede hacer que se tenga que reiniciar el programa para su correcto funcionamiento.
- Black Jack
    - Posibles errores en la función split.
- Carrera de Caballos
    - En el caso de que se ingresen numeros en partes que piden caracteres o viceversa, el programa imprime textos de error infinitamente.
- Crash
    - En el caso que se ingresen una mayor cantidad de caracteres que los pedidos, podrían ocurrir diversos errores.
- Ruleta
    - No se guarda el historial.
    - Si se ingresa un valor que no se muestre(ejemplo: si el programa dice ingrese 2 y el usuario pone 1, el programa va correr y va dar error).
    - No se puede hacer que el programa se mantenga, ya que no se guarda el saldo en el cvs y da algunos problemas con los otros programas.

### A mejorar:

- Se podría mejorar la interfaz del menú de registro e inicio de sesion para que sea más amigable
- Corregir errores mencionados anteriormente.

## Descripción de las diversas funciones 

### Inicio del programa

Primero se muestra el nombre del casino, como también si es que los usuarios se han leido correctamente. Se pide el nombre al usuario y se lee el archivo de [jugadores](Jugadores.csv). 

**Caso 1**

En el caso de que se encuentre el nombre, se le informa al usuario y se muestra el saldo actual. Se le pregunta si desea ajustar el mismo. Si el usuario lo prefiere, puede ingresar el nuevo monto. De lo contrario, se muestra el menú principal.

```
Jugador encontrado. Saldo Actual: 10100
Desea modificar su saldo? (s/n): s
Ingrese el monto a modificar: 2000
```

**Caso 2**

En caso que el jugador no se encuentre, se informa y se le pide al usuario que ingrese un nombre y saldo para este nuevo jugador. En el caso de que el nombre entregado coincida con alguno del archivo, se informa que el usuario ya existe.


Sub-caso 1:
```
Jugador no encontrado, registre un nuevo jugador.
Ingrese su nombre: Jorge
Ingrese su dinero: 15000
Jugador registrado exitosamente
```
Sub-caso 2:
```
Jugador no encontrado, registre un nuevo jugador.
Ingrese su nombre: Andres
El jugador ya existe.
```

### Menú de juegos

Se muestra el menú que contiene todos los juegos y la opción de salir.

```
                ==================================

                |   Bienvenido a Casino Zona 3    |

                ==================================

                    Tu saldo actual es: 20132
¿Cual juego desea jugar?
1. Blackjack
2. Ruleta
3. Carrera de caballos
4. Crash
5. Agregar saldo
6. Salir
```

### **Opción 1**

Se inicializa el programa del Blackjack, preguntándole al usuario si desea ver las reglas del juego. Las muestra si así lo desea y en caso contrario muestra el menú principal.

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
Si el jugador desea ver las reglas verá lo siguiente:

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

Se ingresa la apuesta que desea hacer el jugador.
```
Su saldo actual es de $270266
Cuanto desea apostar?
1000
```

**Paso 3 : Se muestran las cartas de crupier y el jugador**
*Paso 315 :En caso de que el jugador tenga 21 gana directamente*

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
**paso 1**

Se inicializa el Programa de la ruleta europea, esta comienza preguntando si quiere saber las reglas del juego.
```
                ==================================

                |   Bienvenido a Casino Zona 3    |

                ==================================

                    Tu saldo actual es: 1
¿Cual juego desea jugar?
1. Blackjack
2. Ruleta
3. Carrera de caballos
4. Crash
5. Agregar saldo
6. Salir
2
Antes de jugar quieres saber las reglas: (1: SI | 2: NO): 
```
**paso 2**

Si el usuario quiere saber las reglas debe apretar el numero 1.
Aparece las reglas del juego y cada multiplicador.
```
Antes de jugar quieres saber las reglas: (1: SI | 2: NO): 1
 -> Seleccionar Tipo de Apuesta:
 -> Seleccionar Cantidad de Dinero a Apostar:
 -> Seleccionar Numero a Apostar:
 -> Girar la Ruleta:
 -> Si el numero ganador es igual al numero apostado, se multiplica por 35
 -> Si el numero ganador es igual al color apostado, se multiplica por 1
 -> Si el numero ganador es igual al par o impar apostado, se multiplica por 1
 -> Si el numero ganador esta en el primer, segundo o tercer docena, se multiplica por 2
 -> Si el numero ganador esta entre 1 y 18, se multiplica por 2
 -> Si el numero ganador esta entre 19 y 36, se multiplica por 2
Ingrese cualquier tecla para continuar...

```
**paso 3**

Al presionar enter o cualquier otra letra, se mostrara la tabla de apostar con los numeros y sus colores respectivos, Ademas aparece los tipos de apuestas.
```
         /  ================================================================================
        /   |  3  |  6  |  9  | 12   | 15   | 18   | 21   | 24   | 27   | 30  | 33   | 36  |
       /    | Rojo|Negro| Rojo| Rojo | Negro|Rojo  | Rojo |Negro | Rojo |Rojo | Negro|Rojo |
      /     ================================================================================
     |  O   |  2  |  5  |  8  | 11   | 14   | 17   | 20   | 23   | 26   | 29   | 32  | 35  |
     | Verde|Negro| Rojo|Negro|Negro | Rojo | Negro|Negro | Rojo |Negro | Negro|Rojo| Negro|
      \     ================================================================================
       \    |  1  |  4  |  7  | 10  | 13   | 16   | 19   | 22   | 25   | 28  | 31   | 34   |
        \   | Rojo|Negro| Rojo|Negro| Negro|Rojo  | Rojo |Negro | Rojo |Negro| Negro|Rojo  |
         \  =============================================================================
         ===============================================================================
         |        1ra 12          |          2da 12          |          3ra 12          |
         ===============================================================================
         |    1-18    |    PAR    |    ROJO    |    NEGRO    |    IMPAR    |    19-36   |
         ================================================================================ 
Tipos de apuesta
=================================================
1. Elegir un numero
2. Apostar Rojo       | 3. Apostar Negro
4. Apostar Par        | 5. Apostar Impar
6. Apostar en 1ra 12  | 7. Apostar en 2da 12  | 8. Apostar en 3ra 12
9. Apostar en 1-18    | 10. Apostar en 19-36
=================================================
Tu saldo actual es: 1
Ingrese el tipo de apuesta: 
```
Acá el usuario debe elegir un tipo de apuesta, esto va depender de cuanto dinero tiene.
**caso 1**
Si el usuario apuesta mas dinero de lo que tiene el programa va decirle que no tiene suficiente saldo y si desea hace otra apuesta.
```
=================================================
1. Elegir un numero
2. Apostar Rojo       | 3. Apostar Negro
4. Apostar Par        | 5. Apostar Impar
6. Apostar en 1ra 12  | 7. Apostar en 2da 12  | 8. Apostar en 3ra 12
9. Apostar en 1-18    | 10. Apostar en 19-36
=================================================
Tu saldo actual es: 1
Ingrese el tipo de apuesta: 1
Ingrese un numero que quiera apostar (0-36): 2
Ingrese el dinero que desea apostar: 100
No tienes suficiente saldo para realizar esa cantidad de apuestas.
¿Quieres hacer otra apuesta? (s/n):
```
**caso 2**
Si el usuario puede apostar, el programa le va preguntar si quiere hacer otra apuesta
```
Tipos de apuesta
=================================================
1. Elegir un numero
2. Apostar Rojo       | 3. Apostar Negro
4. Apostar Par        | 5. Apostar Impar
6. Apostar en 1ra 12  | 7. Apostar en 2da 12  | 8. Apostar en 3ra 12
9. Apostar en 1-18    | 10. Apostar en 19-36
=================================================
Tu saldo actual es: 1
Ingrese el tipo de apuesta: 2
Ingrese el dinero que desea apostar: 1
¿Quieres hacer otra apuesta? (s/n): n
```

**Caso 3**
Si el usuario desea seguir hacer apuestas en su turno, le va preguntar que tipo de apuesta quiere hacer y el dinero que desea apostar

Para finalizar esta parte el codigo mostrara la ruleta girando, esto es una animacion.
```
Tipos de apuesta
=================================================
1. Elegir un numero
2. Apostar Rojo       | 3. Apostar Negro
4. Apostar Par        | 5. Apostar Impar
6. Apostar en 1ra 12  | 7. Apostar en 2da 12  | 8. Apostar en 3ra 12
9. Apostar en 1-18    | 10. Apostar en 19-36
=================================================
Tu saldo actual es: 6000
Ingrese el tipo de apuesta: 1
Ingrese un numero que quiera apostar (0-36): 2
Ingrese el dinero que desea apostar: 200
¿Quieres hacer otra apuesta? (s/n): s
Ingrese el tipo de apuesta: 2
Ingrese el dinero que desea apostar: 200
¿Quieres hacer otra apuesta? (s/n): n
Girar la ruleta...
Girando: 30 (Rojo)  
```

**Parte 3**

Aca se mostrara el resultado del lanzamiento y las apuestas que hizo el usuario, aca se mostrara el numero y color ganador y se mostrara en pantalla si el usario gano o perdio
```
Resultado del lanzamiento: 35 (Negro)
=================================================
Hiciste una apuesta en el color Rojo
Lo siento, perdiste. El número ganador era 35 (Negro).
=================================================
Lo siento, perdiste. El número ganador era 35 (Negro).
=================================================
Historial de resultado:
Número: 35, Color: Negro
Presione cualquier tecla para continuar...
```
Para finalizar el programa, le va decir el usuario que presione cualquier tecla, y esto lo va enviar al menu principal.


### **Opcion 3: Carrera de caballos**

**Paso 1: Seleccionar carrera de caballos**

Al seleccionar la opcion 3, la cual es la carrera de caballos, se muestra un menu preguntadole al usuario si es que desea leer las reglas.

```
Opcion seleccionada: 3. Carrera de caballos
==========================================
    ¿Deseas leer las reglas del juego?:   
==========================================
1. Si
2. No
==========================================
Ingrese su respuesta:
```

**Paso 1.1**

La opcion 1 mostrara las reglas del juego y los pagos.

```
==========================================
 Las reglas del juego son las siguientes: 
==========================================
 Hay 6 caballos por lo que apostar, cada  
  caballo tiene un numero y probabilidad  
    aleatoria, que no define si sera el   
ganador o no. En caso de ganar, los pagos 
se realizaran devolviendo el doble de lo  
apostado. En caso de perder, se le restara
      lo apostado de su saldo total.      
==========================================
      Presione Enter para continuar...    
==========================================
```

**Paso 1.1**

La opcion 2 mandara al usuario al menu principal del juego.

```
Mostrando menu principal...
```

**Paso 2**

Se muestra el menu principal, dando las opciones de apostar e iniciar la carrera o salir.

```
====================================
        Carrera de Caballos  
====================================
1. Apostar e iniciar carrera
2. Salir
====================================
Seleccione una opción:
```

**Paso 2.1**

Al seleccionar la primera opcion, se le pregunta al usuario por el caballo y el saldo a apostar. 

```
Seleccione el caballo al que desea apostar (1-6): 4
Tu saldo actual es: 5000
Ingrese el monto a apostar: 1500
```

**Paso 2.2**

Al seleccionar la segunda opcion, se retoran al menu principal del casino.

**Paso 3**

Se ejecuta el codigo y se muestra el curso de la carrera.

```
=========================================================
                    Carrera en curso                     
=========================================================
Caballo 1: ---------------------------------🏇
Caballo 2: --------------------------🏇
Caballo 3: -------------------------------------🏇
Caballo 4: -------------------------------🏇
Caballo 5: ----------------------------------🏇
Caballo 6: --------------------------------🏇
=========================================================
```

**Resultado: Caso 1**

En el caso de ganar se muestra el siguiente mensaje.

```
¡El caballo 5 ha ganado la carrera!
¡Felicidades! Ganaste $4000
```

**Resultado: Caso 2**

En el caso de perder se muestra el siguiente mensaje.

```
¡El caballo 5 ha ganado la carrera!
Lo siento, perdiste tu apuesta de $2000.
```

**Paso 4**

Se le pregunta al usuario si es que desea seguir jugando.

```

```

**Caso 1**

Si es que asi lo desea, se sigue jugando y se repiten los pasos anteriores.

**Caso 2**

En el caso de que no se desee seguir jugando, serea 

```

```

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
Presione Enter para salir del juego.
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
Presione Enter para salir del juego.
````
Finalmente se le pide al usuario que presione Enter para salir del juego. Esto hace que el jugador vuelva al menú principal.
### **Opcion 5: Agregar saldo**


# Contribuciones

## David Henríquez
- Código BlackJack
- Mensaje de bienvenida y despedida
- Redacción ReadMe BlackJack
- Comentó su parte del código
## Benjamín Sepúlveda
- Código del Crash.
- Redacción ReadMe Crash y correción general.
- Solucionó problemas varios.
- Comentó su parte del código.
## Andrés Perez
- Código de la ruleta
- Presentación de codigo
- Realizó el registro de jugadores
- Comentó su parte del código.
## Felipe Chavez
- Complementó el registro de los jugadores
- Código de la carrera de caballos
- Solucionó errores
- Comentó su parte del código.