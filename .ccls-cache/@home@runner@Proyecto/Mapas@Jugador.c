#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "map.h"
#include "list.h"
#include "Jugador.h"

#define MAX_NOMBRE 50

typedef struct Jugador {
    char nombre[MAX_NOMBRE];
    int dinero;
} Jugador;

void cargarTodosJugadores(Map* Jugadores) {
    FILE *file = fopen("Jugadores.csv", "r");
    if (!file) {
        printf("No se pudo abrir el archivo Jugadores.csv para lectura.\n");
        return;
    }

    char lines[256];
    while (fgets(lines, sizeof(lines), file)) {
        Jugador *nuevo_jugador = (Jugador*)malloc(sizeof(Jugador));
        char *token = strtok(lines, ",");
        if (token) {
            strncpy(nuevo_jugador->nombre, token, MAX_NOMBRE - 1);
            nuevo_jugador->nombre[MAX_NOMBRE - 1] = '\0'; // Asegurar terminación de cadena

            // Eliminar salto de línea al final del nombre si existe
            char *newline = strchr(nuevo_jugador->nombre, '\n');
            if (newline) *newline = '\0';
        }

        token = strtok(NULL, ",");
        if (token) {
            nuevo_jugador->dinero = atoi(token);
        }

        map_insert(Jugadores, strdup(nuevo_jugador->nombre), nuevo_jugador);
    }

    fclose(file);
    printf("Todos los jugadores han sido cargados exitosamente.\n");
}
Jugador* cargarJugador(Map* Jugadores) {
    FILE *file = fopen("Jugadores.csv", "r");
    if (!file) return NULL;

    char lines[256];

    while (fgets(lines, sizeof(lines), file)) {
        Jugador *nuevo_jugador = (Jugador*)malloc(sizeof(Jugador));
        char *token = strtok(lines, ",");
        if (token) {
            strncpy(nuevo_jugador->nombre, token, MAX_NOMBRE - 1);
            nuevo_jugador->nombre[MAX_NOMBRE - 1] = '\0'; // Asegurar terminación de cadena
        }
        token = strtok(NULL, ",");
        if (token) {
            nuevo_jugador->dinero = atoi(token);
        }

        map_insert(Jugadores, strdup(nuevo_jugador->nombre), nuevo_jugador);
    }

    fclose(file); // Cerrar el archivo después de leer
    return NULL;
}

void guardarJugadorUnico(Jugador *jugador) {
    FILE *file = fopen("Jugadores.csv", "a"); // Abrir el archivo en modo append

    if (!file) {
        printf("No se pudo abrir el archivo para guardar.\n");
        return;
    }

    fprintf(file, "%s,%d\n", jugador->nombre, jugador->dinero);
    fclose(file);
}

void registrarJugador(Map* Jugadores) {
    char nombre[MAX_NOMBRE];
    int money;
    printf("Ingrese su nombre: ");
    scanf("%s", nombre);
    if (map_search(Jugadores, nombre)) {
        printf("El jugador ya existe. (Espere 3 segundos...)\n");
        return;
    }
    printf("Ingrese su dinero: ");
    scanf("%d", &money);

    Jugador *nuevo_jugador = (Jugador*)malloc(sizeof(Jugador));
    strncpy(nuevo_jugador->nombre, nombre, MAX_NOMBRE - 1);
    nuevo_jugador->nombre[MAX_NOMBRE - 1] = '\0'; // Asegurar terminación de cadena
    nuevo_jugador->dinero = money;

    map_insert(Jugadores, strdup(nuevo_jugador->nombre), nuevo_jugador);

    guardarJugadorUnico(nuevo_jugador); // Guardar el jugador recién registrado
    printf("Jugador registrado exitosamente. (Espere 3 segundos...)\n");
}

void guardarTodosJugadores(Map* Jugadores) {
    FILE *file = fopen("Jugadores.csv", "w+");

    if (!file) {
        printf("No se pudo abrir el archivo para guardar.\n");
        return;
    }

    MapPair *pair = map_first(Jugadores);
    while (pair != NULL) {
        Jugador *jugador = (Jugador*)pair->value;
        fprintf(file, "%s,%d\n", jugador->nombre, jugador->dinero);
        pair = map_next(Jugadores);
    }
    fclose(file);
}
void modificarJugador(Map* Jugadores, char *nombre, int monto) {
    MapPair *pair = map_search(Jugadores, nombre);
    if (!pair) {
        printf("Jugador no encontrado\n");
        return;
    }
    Jugador *jugador = (Jugador*)pair->value;
    jugador->dinero += monto;

    if (jugador->dinero < 0) jugador->dinero = 0;

    guardarTodosJugadores(Jugadores); // Guardar todos los jugadores después de modificar
    printf("El dinero del jugador %s ha sido modificado exitosamente\n", nombre);
}

void modificarSaldo(Map* Jugadores, char *nombre, int monto) {
    MapPair *pair = map_search(Jugadores, nombre);
    if (!pair) {
        printf("Jugador no encontrado\n");
        return;
    }
    Jugador *jugador = (Jugador*)pair->value;
    jugador->dinero = monto;

    if (jugador->dinero < 0) jugador->dinero = 0;

    guardarTodosJugadores(Jugadores); // Guardar todos los jugadores después de modificar
    printf("El dinero del jugador %s ha sido modificado exitosamente\n", nombre);
}

