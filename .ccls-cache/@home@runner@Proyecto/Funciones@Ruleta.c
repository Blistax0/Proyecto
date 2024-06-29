#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include "Ruleta.h"
#define Ruleta_max 37


// Definir la estructura de las casillas de la ruleta
typedef struct Ruleta_slot {
    int numero;
    char color[10]; // Colores: rojo, negro y verde
} Ruleta_slot;

// Estructura de la lista enlazada para almacenar jugadas ganadas
typedef struct Node {
    Ruleta_slot resultado;
    struct Node* siguiente;
} Node;
// Función para inicializar la lista enlazada
typedef struct ListaResultados{
    Node* cabeza;
}ListaResultados;


void ini_lista(ListaResultados* lista){
    lista->cabeza = NULL;
}
// Función para agregar un resultado a la lista
void agregar_resultado(ListaResultados* lista, Ruleta_slot resultado){
    Node* nuevo_nodo = (Node*)malloc(sizeof(Node));  
    nuevo_nodo->resultado = resultado;
    nuevo_nodo->siguiente = lista->cabeza;
    lista->cabeza = nuevo_nodo;
}

// Función para imprimir la lista de resultados
void imprimir_lista(ListaResultados* lista){
    Node* actual = lista->cabeza;
    printf("=================================================\n");
    printf("Historial de resultado:\n");
    while(actual != NULL){
        printf("Número: %d, Color: %s\n",actual->resultado.numero, actual->resultado.color);
        actual = actual->siguiente;
    }
}

// Función para inicializar la ruleta
void inicializar_ruleta(Ruleta_slot* ruleta) {
    ruleta[0].numero = 0; // Casilla 0: Verde
    strcpy(ruleta[0].color, "Verde");

    int rojo[] = {1, 3, 5, 7, 9, 12, 14, 16, 18, 19, 21, 23, 25, 27, 30, 32, 34, 36}; //casillas de los numeros rojos
    int negro[] = {2, 4, 6, 8, 10, 11, 13, 15, 17, 20, 22, 24, 26, 28, 29, 31, 33, 35}; //casillas de los numeros negros
//Funcion para inicializar la ruleta segun su color y numero
    for (int i = 0; i < 18; i++) {
        ruleta[rojo[i]].numero = rojo[i];
        strcpy(ruleta[rojo[i]].color, "Rojo");

        ruleta[negro[i]].numero = negro[i];
        strcpy(ruleta[negro[i]].color, "Negro");
    }
}
// Función para girar la ruleta, este da un valor  que sera el resultado
Ruleta_slot girar_ruleta(Ruleta_slot* ruleta, int size) {
    int index = rand() % size;
    return ruleta[index];
}

void animacion_girar(Ruleta_slot* ruleta, int size, int index) {
    const int cantidad_vueltas = 3;// Cantidad de vueltas de la ruleta
    const int delay_ms = 100000; //microsegundos

    int orden_ruleta_europea[] = {0, 32, 15, 19, 4, 21, 2, 25, 17, 34, 6, 27, 13, 36, 11, 30, 8, 23, 10, 5, 24, 16, 33, 1, 20, 14, 31, 9, 22, 18, 29, 7, 28, 12, 35, 3, 26}; // Orden de la ruleta europea, ajustado para que el 0 aparezca al principio

    printf("Girar la ruleta...\n"); // Mensaje de inicio de la animación
    for(int i = 0; i < cantidad_vueltas; i++){ // Ciclo para realizar las vueltas
        for(int j = 0; j < size; j++){
            int numero_actual = orden_ruleta_europea[j]; // Número actual en la ruleta
            printf("\rGirando: %d (%s) ",ruleta[numero_actual].numero, ruleta[numero_actual].color);// Imprimir el número actual en la ruleta
            fflush(stdout);// Limpiar el buffer de salida para que se imprima el número actual
            usleep(delay_ms);// Esperar un tiempo antes de la siguiente iteración
        }
    }
    for(int k = 0; k <= index; k++){ // Ciclo para imprimir el número final
        int numero_actual = orden_ruleta_europea[k]; // Número actual en la ruleta
        printf("\rrGirando: %d (%s) ",ruleta[numero_actual].numero, ruleta[numero_actual].color); // Imprimir el número actual en la ruleta
        fflush(stdout); // Limpiar el buffer de salida para que se imprima el número actual
        usleep(delay_ms); // Esperar un tiempo antes de la siguiente iteración
    }
    printf("\n");
}
// Función para imprimir la mesa de apuestas
void print_mesa_apuesta() {
    printf("         /  ================================================================================\n");
    printf("        /   |  3  |  6  |  9  | 12   | 15   | 18   | 21   | 24   | 27   | 30  | 33   | 36  |\n");
    printf("       /    | Rojo|Negro| Rojo| Rojo | Negro|Rojo  | Rojo |Negro | Rojo |Rojo | Negro|Rojo |\n");
    printf("      /     ================================================================================\n");
    printf("     |  O   |  2  |  5  |  8  | 11   | 14   | 17   | 20   | 23   | 26   | 29   | 32  | 35  |\n");
    printf("     | Verde|Negro| Rojo|Negro|Negro | Rojo | Negro|Negro | Rojo |Negro | Negro|Rojo| Negro|\n");
    printf("      \\     ================================================================================\n");
    printf("       \\    |  1  |  4  |  7  | 10  | 13   | 16   | 19   | 22   | 25   | 28  | 31   | 34   |\n");
    printf("        \\   | Rojo|Negro| Rojo|Negro| Negro|Rojo  | Rojo |Negro | Rojo |Negro| Negro|Rojo  |\n");
    printf("         \\  =============================================================================\n");
    printf("         ===============================================================================\n");
    printf("         |        1ra 12          |          2da 12          |          3ra 12          |\n");
    printf("         ===============================================================================\n");
    printf("         |    1-18    |    PAR    |    ROJO    |    NEGRO    |    IMPAR    |    19-36   |\n");
    printf("         ================================================================================ \n");
    printf("Tipos de apuesta\n");
    printf("=================================================\n");
    printf("1. Elegir un numero\n");
    printf("2. Apostar Rojo       | ");
    printf("3. Apostar Negro\n");
    printf("4. Apostar Par        | ");
    printf("5. Apostar Impar\n");
    printf("6. Apostar en 1ra 12  | ");
    printf("7. Apostar en 2da 12  | ");
    printf("8. Apostar en 3ra 12\n");
    printf("9. Apostar en 1-18    | ");
    printf("10. Apostar en 19-36\n");
    printf("=================================================\n");
}
//Void que imprime las reglas
void reglas() {
    printf(" -> Seleccionar Tipo de Apuesta:\n");
    printf(" -> Seleccionar Cantidad de Dinero a Apostar:\n");
    printf(" -> Seleccionar Numero a Apostar:\n");
    printf(" -> Girar la Ruleta:\n");
    printf(" -> Si el numero ganador es igual al numero apostado, se multiplica por 35\n");
    printf(" -> Si el numero ganador es igual al color apostado, se multiplica por 1\n");
    printf(" -> Si el numero ganador es igual al par o impar apostado, se multiplica por 1\n");
    printf(" -> Si el numero ganador esta en el primer, segundo o tercer docena, se multiplica por 2\n");
    printf(" -> Si el numero ganador esta entre 1 y 18, se multiplica por 2\n");
    printf(" -> Si el numero ganador esta entre 19 y 36, se multiplica por 2\n");
}
//Aca el usuario Elige el tipo de apuesta segun la tabla de apuestas.
int tu_apuesta() {
    int tipo_de_apuesta;
    printf("Ingrese el tipo de apuesta: ");
    scanf("%d", &tipo_de_apuesta);
    return tipo_de_apuesta;
}

/*Aca el usario con la respuesta de la funcion anterior, ve si gana o pierde su apuesta  todo esto segun el el valor que ingreso

Falta ingresar el dinero que se aposto y el numero que se aposto
*/
void elegir_apuesta(int* apuestas, int* valores, int num_apuestas, Ruleta_slot resultado, int *cantidad_dinero, int * saldo) {
    int win = 0;
    int ganancias = 0;
    for (int i = 0; i < num_apuestas; i++) {
        printf("=================================================\n");
        switch (apuestas[i]) {
            case 1:
                printf("Hiciste una apuesta en el número %d\n", valores[i]); //Apuesta por numero
                if (valores[i] == resultado.numero) win = 1;
                break;
            case 2:
                printf("Hiciste una apuesta en el color Rojo\n");//Apuesta por color
                if (strcmp(resultado.color, "Rojo") == 0) win = 1;
                break;
            case 3:
                printf("Hiciste una apuesta en el color Negro\n");//Apuesta por color
                if (strcmp(resultado.color, "Negro") == 0) win = 1;
                break;
            case 4:
                printf("Hiciste una apuesta en los números pares\n");//Apuesta por pares
                if (resultado.numero != 0 && resultado.numero % 2 == 0) win = 1; 
                break;
            case 5:
                printf("Hiciste una apuesta en los números impares\n");//Apuesta por Impares
                if (resultado.numero % 2 != 0) win = 1;
                break;
            case 6:
                printf("Hiciste una apuesta en el primer cuartil\n");
                if (resultado.numero >= 1 && resultado.numero <= 12) win = 1;
                break;
            case 7:
                printf("Hiciste una apuesta en el segundo cuartil\n");
                if (resultado.numero >= 13 && resultado.numero <= 24) win = 1;
                break;
            case 8:
                printf("Hiciste una apuesta en el tercer cuartil\n");
                if (resultado.numero >= 25 && resultado.numero <= 36) win = 1;
                break;
            case 9:
                printf("Hiciste una apuesta en el 1 hasta 18\n");
                if (resultado.numero >= 1 && resultado.numero <= 18) win = 1;
                break;
            case 10:
                printf("Hiciste una apuesta en el 19 hasta 36\n");
                if (resultado.numero >= 19 && resultado.numero <= 36) win = 1;
                break;
            default:
                break;
        }
        if (win) {
            printf("Felicidades, ganaste!\n");
            switch (apuestas[i]){
                case 1: //Numero
                    ganancias += cantidad_dinero[i] * 35; break;
                case 2: // Rojo
                    ganancias += cantidad_dinero[i] ; break;
                case 3: // Negro
                    ganancias += cantidad_dinero[i] ; break;
                case 4: // Par
                    ganancias += cantidad_dinero[i] ; break;
                case 5: // Impar
                    ganancias += cantidad_dinero[i] ; break;
                case 6: // 1ra 12
                    ganancias += cantidad_dinero[i] * 2; break;
                case 7: // Segunda 12
                    ganancias += cantidad_dinero[i] * 2; break;
                case 8: // Tercer 12
                    ganancias += cantidad_dinero[i] * 2; break;
                case 9: // 1-18
                    ganancias += cantidad_dinero[i] * 2; break;
                case 10: // 19-36
                    ganancias += cantidad_dinero[i] * 2; break;
                }
                printf("Ganaste %d\n", ganancias);
                *saldo += ganancias;
        } 
    else 
        {
            printf("Lo siento, perdiste. El número ganador era %d (%s).\n", resultado.numero, resultado.color);
            *saldo -= cantidad_dinero[i];
        }
    }
}
//Funcion 
int obtener_cantidad_dinero(int * saldo){
    int cantidad_apuestass;
    printf("Ingrese el dinero que desea apostar: ");
    scanf("%d", &cantidad_apuestass);
    if (cantidad_apuestass > *saldo){
        printf("No tienes suficiente saldo para realizar esa cantidad de apuestas.\n");
    }
    return cantidad_apuestass;
}

//Aca el usuario ingresa el numero que quiere apostar, esto es importante para la funcion elegir apuesta la opcion 1.
int obtener_numero(int tipo_de_apuesta) {
    int valor_apuesta = -1;
    if (tipo_de_apuesta == 1) {
        printf("Ingrese un numero que quiera apostar (0-36): ");
        scanf("%d", &valor_apuesta);
    }
    return valor_apuesta;    
}
//Funcion main para que funcione el juego
void Ruleta_Main(int * saldo) {
    Ruleta_slot ruleta[Ruleta_max]; //ruleta 
    inicializar_ruleta(ruleta);//inicializar la ruleta
    srand(time(NULL));//generar numeros aleatorios
    ListaResultados lista;//lista de resultados
    ini_lista(&lista);//inicializar la lista de resultados
    //int seguir_jugando = 1; //opcion para seguir jugando
    
    // Opcion que tiene el jugador para ver si quiere seguir jugando
    //while (seguir_jugando) {
        int opcion = 0;
        printf("Antes de jugar quieres saber las reglas: (1: SI | 2: NO): ");
        scanf("%d", &opcion);
        if (opcion == 1) {
            reglas();
            printf("Ingrese cualquier tecla para continuar...\n");
            getchar(); // Consumir el '\n' pendiente
            getchar(); // Esperar a que el usuario presione una tecla
            system("clear");
        }
        system("clear");
        print_mesa_apuesta(); //imprimir la mesa de apuestas
        printf("Tu saldo actual es: %d\n", *saldo);
        int num_apuestas = 0; // cantidad de apuestas
        int apuestas[10]; // lista con valores max 20 [2,2,3,4,5,6,7,8,9] -> la elecciones que hizo el usuario
        int valores[20];// lista con apuestas max 10, estos son si el jugador eligio la opcion 1(elegir un numero)
        int cantidad_dinero[20]; // cantidad de dinero por apuestas guardadas en un lista [100,200,300]
        char continuar = 's';
    
        while (continuar == 's' || continuar == 'S') {
            apuestas[num_apuestas] = tu_apuesta(); // elegir el tipo de apuesta
            valores[num_apuestas] = obtener_numero(apuestas[num_apuestas]);// elegir el numero a apostar (si es opcion 1)
            cantidad_dinero[num_apuestas] = obtener_cantidad_dinero(saldo);// cantidad de dinero que tiene por apuesta
            
            num_apuestas++;// aumentar la cantidad de apuestas
    
            *saldo -= cantidad_dinero[num_apuestas];//CAMBIO DE SALDO
            
            printf("¿Quieres hacer otra apuesta? (s/n): "); // opcion para seguir haciendo apuestas
            scanf(" %c", &continuar);// leer la opcion
        }

        Ruleta_slot resultado = girar_ruleta(ruleta, Ruleta_max);//girar la ruleta y recibe el resultado generado aleatoriamente
        animacion_girar(ruleta, Ruleta_max, resultado.numero);//animacion de la ruleta
        system("clear");
        
        printf("Resultado del lanzamiento: %d (%s)\n", resultado.numero, resultado.color);

        elegir_apuesta(apuestas, valores, num_apuestas, resultado, cantidad_dinero, saldo);//elegir apuesta y ver si gana o pierde

        agregar_resultado(&lista, resultado); //agregar resultado a la lista de resultados
        imprimir_lista(&lista);//imprimir la lista de resultados

        //printf("¿Quieres seguir jugando? (1: SI | 0: NO): ");//opcion para seguir jugando
        //scanf("%d", &seguir_jugando);
        printf("Presione cualquier tecla para continuar...\n");
        getchar(); // Consumir el '\n' pendiente
        getchar(); // Esperar a que el usuario presione una tecla
        system("clear");    
    //}

    printf("Gracias por jugar!\n");
}
