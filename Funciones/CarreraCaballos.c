#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "CarreraCaballos.h"

#define totalCaballos 6

void mostrarMenu() {
    printf("====================================\n");
    printf("        Carrera de Caballos  \n");
    printf("====================================\n");
    printf("1. Apostar e iniciar carrera\n");
    printf("2. Salir\n");
    printf("====================================\n");
}

void mostrarProgreso(int posiciones[]) {
    system("clear");  

    printf("=========================================================\n");
    printf("                    Carrera en curso                     \n");
    printf("=========================================================\n");

    for (int i = 0; i < totalCaballos; i++) {
        printf("Caballo %d: ", i + 1);
        for (int j = 0; j < posiciones[i]; j++) {
            printf("-");
        }
        printf("🏇\n");
    }
    printf("=========================================================\n");
}

void iniciarCarrera(int *montoUsuario) {
    int posiciones[totalCaballos] = {0};  // Inicializa todas las posiciones en 0
    int carreraTerminada = 0;
    int montoApostado = 0;
    int numCaballo = 0;
    int distanciaMax = 50;
    
    printf("\nSeleccione el caballo al que desea apostar (1-%d): ", totalCaballos);
    scanf("%d", &numCaballo);

    while (numCaballo < 1 || numCaballo > totalCaballos) {
        printf("Número de caballo inválido. Seleccione un caballo entre 1 y %d: ", totalCaballos);
        scanf("%d", &numCaballo);
    }

    printf("\nTu saldo actual es: %d\n", *montoUsuario);
    printf("Ingrese el monto a apostar: ");
    scanf("%d", &montoApostado);

    if (montoApostado > *montoUsuario){
        printf("\nTu saldo actual es: %d\n", *montoUsuario);
        printf("Tu saldo a apostar es: %d\n", montoApostado);
        printf("No tienes suficiente saldo para apostar esa cantidad.\n");
        printf("Volviendo al menu principal...\n");
        sleep(2);
        return;
    }
    
    while (montoApostado <= 0) {
        printf("Monto inválido. Ingrese un monto positivo: ");
        scanf("%d", &montoApostado);
    }

    *montoUsuario -= montoApostado;
    
    printf("\nIniciando carrera...\n");

    while (carreraTerminada != 1) {
        for (int i = 0; i < totalCaballos; i++) {
            posiciones[i] += rand() % (3 - 1 + 1) + 1;
            if (i == 4){
                posiciones[i] += 19;
            }
            if (posiciones[i] >= distanciaMax) {
                carreraTerminada = 1;
            }
        }

        mostrarProgreso(posiciones);

        usleep(50000);
    }

    int ganador = 0;
    for (int i = 1; i < totalCaballos; i++) {
        if (posiciones[i] > posiciones[ganador]) {
            ganador = i;
        }
    }

    printf("\n¡El caballo %d ha ganado la carrera!\n", ganador + 1);

    if (ganador == numCaballo - 1) {
        printf("¡Felicidades! Ganaste $%d\n\n", montoApostado * 2);
        *montoUsuario += montoApostado * 2;
    } 
    else {
        printf("Lo siento, perdiste tu apuesta de $%d.\n\n", montoApostado);
    }
    
}

void carrera(int *montoUsuario) {
    char respuesta;
    int opcion;
    int jugado = 0;
    int apuestaCaballo = 0;

    mostrarMenu();

    do {
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                iniciarCarrera(montoUsuario);
                jugado = 1;
                break;
            case 2:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opción no válida. Intente nuevamente.\n");
        } 

        if (jugado != 0){
            do {
                printf("¿Deseas seguir jugando? (s/n): ");
                scanf(" %c", &respuesta);
                switch (respuesta){
                    case 's':
                        jugado = 0;
                        system("clear");
                        mostrarMenu();
                        break;
                    case 'n':
                        printf("Saliendo...\n");
                        break;
                    default:
                        printf("Respuesta inválida. Intente nuevamente.\n");
                        break;
                }
            } while (respuesta != 's' && respuesta != 'n');
        }
    } while (opcion != 2 && respuesta != 'n');
}

void reglasCarrera(){
    int opcionReglas = 0;
    
    printf("==========================================\n");
    printf("    ¿Deseas leer las reglas del juego?:   \n"); 
    printf("==========================================\n");
    printf("1. Si\n");
    printf("2. No\n");
    printf("==========================================\n");

    do{
        printf("Ingrese su respuesta: ");
        scanf(" %d", &opcionReglas);
        
        switch (opcionReglas){
            case 1:
                system("clear");
                printf("==========================================\n");
                printf(" Las reglas del juego son las siguientes: \n");
                printf("==========================================\n");
                printf(" Hay 6 caballos por lo que apostar, cada  \n");
                printf(  "caballo tiene un numero y probabilidad  \n");
                printf("    aleatoria, que no define si sera el   \n");
                printf("ganador o no. En caso de ganar, los pagos \n");
                printf("se realizaran devolviendo el doble de lo  \n");
                printf("apostado. En caso de perder, se le restara\n");
                printf("      lo apostado de su saldo total.      \n");
                printf("==========================================\n");
                printf("      Presione Enter para continuar...    \n");
                printf("==========================================\n");
                getchar();
                getchar();
                return;
            case 2:
                printf("Mostrando menu principal...\n");
                sleep(1);
                return;
            default:
                printf("Opcion no valida. Intente nuevamente.\n");
                break;
        }
        
    } while (opcionReglas != 1 || opcionReglas != 2);
}