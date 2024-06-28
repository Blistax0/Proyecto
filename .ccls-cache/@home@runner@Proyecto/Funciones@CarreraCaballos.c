#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define NUM_CABALLOS 6
#define DISTANCIA_META 50

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

    printf("====================================\n");
    printf("         Carrera en curso        \n");
    printf("====================================\n");

    for (int i = 0; i < NUM_CABALLOS; i++) {
        printf("Caballo %d: ", i + 1);
        for (int j = 0; j < posiciones[i]; j++) {
            printf("-");
        }
        printf("🏇\n");
    }
    printf("====================================\n");
}

void iniciarCarrera(int apuestaCaballo, int montoApuesta) {
    int posiciones[NUM_CABALLOS] = {0};  // Inicializa todas las posiciones en 0
    int carreraTerminada = 0;

    printf("\nIniciando carrera...\n");

    while (!carreraTerminada) {
        for (int i = 0; i < NUM_CABALLOS; i++) {
            posiciones[i] += rand() % 3;  // Cada caballo avanza entre 0 y 2 posiciones
            if (posiciones[i] >= DISTANCIA_META) {
                carreraTerminada = 1;
            }
        }

        mostrarProgreso(posiciones);

        usleep(500000);
    }

    int ganador = 0;
    for (int i = 1; i < NUM_CABALLOS; i++) {
        if (posiciones[i] > posiciones[ganador]) {
            ganador = i;
        }
    }

    printf("\n¡El caballo %d ha ganado la carrera!\n", ganador + 1);

    if (ganador == apuestaCaballo - 1) {
        printf("¡Felicidades! Ganaste $%d\n\n", montoApuesta * NUM_CABALLOS);
    } 
    else {
        printf("Lo siento, perdiste tu apuesta de $%d.\n\n", montoApuesta);
    }
}

int obtenerApuesta(int *montoApuesta) {
    int caballo;

    printf("\nSeleccione el caballo al que desea apostar (1-%d): ", NUM_CABALLOS);
    scanf("%d", &caballo);

    while (caballo < 1 || caballo > NUM_CABALLOS) {
        printf("Número de caballo inválido. Seleccione un caballo entre 1 y %d: ", NUM_CABALLOS);
        scanf("%d", &caballo);
    }

    printf("Ingrese el monto a apostar: ");
    scanf("%d", montoApuesta);

    while (*montoApuesta <= 0) {
        printf("Monto inválido. Ingrese un monto positivo: ");
        scanf("%d", montoApuesta);
    }

    return caballo;
}

int carrera() {
    int opcion;
    int apuestaCaballo = 0;
    int montoApuesta = 0;

    srand(time(NULL)); 

    do {
        mostrarMenu();
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                apuestaCaballo = obtenerApuesta(&montoApuesta);
                iniciarCarrera(apuestaCaballo, montoApuesta);
                break;
            case 2:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opción no válida. Intente nuevamente.\n");
        }
    } while (opcion != 2);

    return 0;
}




