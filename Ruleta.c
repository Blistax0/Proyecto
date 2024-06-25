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

typedef struct ListaResultados{
    Node* cabeza;
}ListaResultados;


void ini_lista(ListaResultados* lista){
    lista->cabeza = NULL;
}

void agregar_resultado(ListaResultados* lista, Ruleta_slot resultado){
    Node* nuevo_nodo = (Node*)malloc(sizeof(Node));  
    nuevo_nodo->resultado = resultado;
    nuevo_nodo->siguiente = lista->cabeza;
    lista->cabeza = nuevo_nodo;
}

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
    ruleta[0].numero = 0;
    strcpy(ruleta[0].color, "Verde");

    int rojo[] = {1, 3, 5, 7, 9, 12, 14, 16, 18, 19, 21, 23, 25, 27, 30, 32, 34, 36};
    int negro[] = {2, 4, 6, 8, 10, 11, 13, 15, 17, 20, 22, 24, 26, 28, 29, 31, 33, 35};

    for (int i = 0; i < 18; i++) {
        ruleta[rojo[i]].numero = rojo[i];
        strcpy(ruleta[rojo[i]].color, "Rojo");

        ruleta[negro[i]].numero = negro[i];
        strcpy(ruleta[negro[i]].color, "Negro");
    }
}

Ruleta_slot girar_ruleta(Ruleta_slot* ruleta, int size) {
    int index = rand() % size;
    return ruleta[index];
}

void animacion_girar(Ruleta_slot* ruleta, int size, int index) {
    const int cantidad_vueltas = 3;
    const int delay_ms = 100000; //microsegundos

    int orden_ruleta_europea[] = {0, 32, 15, 19, 4, 21, 2, 25, 17, 34, 6, 27, 13, 36, 11, 30, 8, 23, 10, 5, 24, 16, 33, 1, 20, 14, 31, 9, 22, 18, 29, 7, 28, 12, 35, 3, 26};

    printf("Girar la ruleta...\n");
    for(int i = 0; i < cantidad_vueltas; i++){
        for(int j = 0; j < size; j++){
            int numero_actual = orden_ruleta_europea[j];
            printf("\rGirando: %d (%s) ",ruleta[numero_actual].numero, ruleta[numero_actual].color);
            fflush(stdout);
            usleep(delay_ms);
        }
    }
    for(int k = 0; k <= index; k++){
        int numero_actual = orden_ruleta_europea[k];
        printf("\rGirando: %d (%s) ",ruleta[numero_actual].numero, ruleta[numero_actual].color);
        fflush(stdout);
        usleep(delay_ms);
    }
    printf("\n");
}
// Función para imprimir la mesa de apuestas
void print_mesa_apuesta() {
    printf("=================================================\n");
    printf("|  0  |  1  |  2  |  3  |  4  |  5  |  6  |  7  |\n");
    printf("|Verde| Rojo|Negro| Rojo|Negro| Rojo|Negro| Rojo|\n");
    printf("=================================================\n");
    printf("|  8  |  9  | 10  | 11  | 12  | 13  | 14  | 15  |\n");
    printf("|Negro| Rojo|Negro|Negro| Rojo|Negro| Rojo|Negro|\n");
    printf("=================================================\n");
    printf("| 16  | 17  | 18  | 19  | 20  | 21  | 22  | 23  |\n");
    printf("| Rojo|Negro| Rojo| Rojo|Negro| Rojo|Negro| Rojo|\n");
    printf("=================================================\n");
    printf("| 24  | 25  | 26  | 27  | 28  | 29  | 30  | 31  |\n");
    printf("|Negro| Rojo|Negro| Rojo|Negro|Negro| Rojo|Negro|\n");
    printf("=================================================\n");
    printf("| 32  | 33  | 34  | 35  | 36  |\n");
    printf("| Rojo|Negro| Rojo|Negro| Rojo|\n");
    printf("=================================================\n");
    printf("Tipos de apuesta\n");
    printf("1. Elegir un numero\n");
    printf("2. Apostar Rojo       | ");
    printf("3. Apostar Negro\n");
    printf("4. Apostar Par        | ");
    printf("5. Apostar Impar\n");
    printf("6. Apostar en 1st 12  | ");
    printf("7. Apostar en 2nd 12  | ");
    printf("8. Apostar en 3rd 12\n");
    printf("9. Apostar en 1-18    | ");
    printf("10. Apostar en 19-36\n");
    printf("=================================================\n");
}

void reglas() {
    printf(" -> Seleccionar Tipo de Apuesta:\n");
    printf(" -> Seleccionar Cantidad de Dinero a Apostar:\n");
    printf(" -> Seleccionar Numero a Apostar:\n");
    printf(" -> Girar la Ruleta:\n");
    printf(" -> Si el numero ganador es igual al numero apostado, se multiplica por 35\n");
    printf(" -> Si el numero ganador es igual al color apostado, se multiplica por 1\n");
    printf(" -> Si el numero ganador es igual al par o impar apostado, se multiplica por 1\n");
    printf(" -> Si el numero ganador esta en el primer, segundo o tercer cuartil, se multiplica por 2\n");
    printf(" -> Si el numero ganador esta entre 1 y 18, se multiplica por 2\n");
    printf(" -> Si el numero ganador esta entre 19 y 36, se multiplica por 2\n");
}
int tu_apuesta() {
    int tipo_de_apuesta;
    printf("Ingrese el tipo de apuesta: ");
    scanf("%d", &tipo_de_apuesta);
    return tipo_de_apuesta;
}


void elegir_apuesta(int* apuestas, int* valores, int num_apuestas, Ruleta_slot resultado) {
    int win = 0;
    for (int i = 0; i < num_apuestas; i++) {
        printf("=================================================\n");
        switch (apuestas[i]) {
            case 1:
                printf("Hiciste una apuesta en el número %d\n", valores[i]);
                if (valores[i] == resultado.numero) win = 1;
                break;
            case 2:
                printf("Hiciste una apuesta en el color Rojo\n");
                if (strcmp(resultado.color, "Rojo") == 0) win = 1;
                break;
            case 3:
                printf("Hiciste una apuesta en el color Negro\n");
                if (strcmp(resultado.color, "Negro") == 0) win = 1;
                break;
            case 4:
                printf("Hiciste una apuesta en los números pares\n");
                if (resultado.numero != 0 && resultado.numero % 2 == 0) win = 1; 
                break;
            case 5:
                printf("Hiciste una apuesta en los números impares\n");
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
                printf("Apuesta inválida\n");
                break;
        }
        if (win) {
            printf("Felicidades, ganaste!\n");
        } else {
            printf("Lo siento, perdiste. El número ganador era %d (%s).\n", resultado.numero, resultado.color);
        }
    }
}
int obtener_numero(int tipo_de_apuesta) {
    int valor_apuesta = -1;
    if (tipo_de_apuesta == 1) {
        printf("Ingrese un numero que quiera apostar (0-36): ");
        scanf("%d", &valor_apuesta);
    }
    return valor_apuesta;    
}

void Ruleta_Main() {
    Ruleta_slot ruleta[Ruleta_max];
    inicializar_ruleta(ruleta);
    srand(time(NULL));
    ListaResultados lista;
    ini_lista(&lista);

    int seguir_jugando = 1;

    while (seguir_jugando) {
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
        print_mesa_apuesta();

        int num_apuestas = 0; // cantidad de apuestas
        int apuestas[1]; // lista con apuestas max 10
        int valores[10];
        char continuar = 's';

        while (continuar == 's' || continuar == 'S') {
            apuestas[num_apuestas] = tu_apuesta();
            valores[num_apuestas] = obtener_numero(apuestas[num_apuestas]);
            num_apuestas++;
            printf("¿Quieres hacer otra apuesta? (s/n): ");
            scanf(" %c", &continuar);
        }

        Ruleta_slot resultado = girar_ruleta(ruleta, Ruleta_max);
        animacion_girar(ruleta, Ruleta_max, resultado.numero);
        system("clear");

        printf("Resultado del lanzamiento: %d (%s)\n", resultado.numero, resultado.color);

        elegir_apuesta(apuestas, valores, num_apuestas, resultado);

        agregar_resultado(&lista, resultado);
        imprimir_lista(&lista);

        printf("¿Quieres seguir jugando? (1: SI | 0: NO): ");
        scanf("%d", &seguir_jugando);
        system("clear");
    }

    printf("Gracias por jugar!\n");
}
