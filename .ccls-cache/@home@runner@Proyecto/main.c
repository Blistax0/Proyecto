#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <unistd.h>
#include "Mapas/map.h"
#include "Mapas/Jugador.h"
#include "Mapas/list.h"
#include "Funciones/Ruleta.h"
#include "Funciones/BlackJack.h"
#include "Funciones/Crash.h"
#include "Funciones/CarreraCaballos.h"

typedef struct Apostador{
  char nombre[50];
  int dinero;
}Apostador;

void guardarDatos(Map *map) {
  FILE *file = fopen("jugadores.txt", "w");
  if (!file) {
    perror("No se pudo abrir el archivo");
    return;
  }

  // Suponiendo que tienes una función para iterar sobre el mapa
  MapPair *pair;
  while ((pair = map_next(map)) != NULL) {
    Apostador *player = (Apostador *)pair->value;
    fprintf(file, "%s %d\n", player->nombre, player->dinero);
  }

  fclose(file);
}

int is_equal_str(void *key1, void *key2) {
  return strcmp((char *)key1, (char *)key2) == 0;
}

int is_equal_int(void *key1, void *key2) {
  return *(int *)key1 == *(int *)key2; // Compara valores enteros directamente
}

void mensaje_incio(){
  printf(" ____    _                                         _       _                        ____                 _                     _____                            _____ \n");
  printf("| __ )  (_)   ___   _ __   __   __   ___   _ __   (_)   __| |   ___       __ _     / ___|   __ _   ___  (_)  _ __     ___     |__  /   ___    _ __     __ _    |___ / \n");
  printf("|  _ \\  | |  / _ \\ | '_ \\  \\ \\ / /  / _ \\ | '_ \\  | |  / _` |  / _ \\     / _` |   | |      / _` | / __| | | | '_ \\   / _ \\      / /   / _ \\  | '_ \\   / _` |     |_ \\ \n");
  printf("| |_) | | | |  __/ | | | |  \\ V /  |  __/ | | | | | | | (_| | | (_) |   | (_| |   | |___  | (_| | \\__ \\ | | | | | | | (_) |    / /_  | (_) | | | | | | (_| |    ___) |\n");
  printf("|____/  |_|  \\___| |_| |_|   \\_/    \\___| |_| |_| |_|  \\__,_|  \\___/     \\__,_|    \\____|  \\__,_| |___/ |_| |_| |_|  \\___/    /____|  \\___/  |_| |_|  \\__,_|   |____/ \n\n");
}

void mensaje_final(){
  printf("   ____                         _                                                                    _         _   _           \n");
  printf("  / ___|  _ __    __ _    ___  (_)   __ _   ___     _ __     ___    _ __     ___   _   _    __   __ (_)  ___  (_) | |_    __ _ \n");
  printf(" | |  _  | '__|  / _` |  / __| | |  / _` | / __|   | '_ \\   / _ \\  | '__|   / __| | | | |   \\ \\ / / | | / __| | | | __|  / _` |\n");
  printf(" | |_| | | |    | (_| | | (__  | | | (_| | \\__ \\   | |_) | | (_) | | |      \\__ \\ | |_| |    \\ V /  | | \\__ \\ | | | |_  | (_| |\n");
  printf("  \\____| |_|     \\__,_|  \\___| |_|  \\__,_| |___/   | .__/   \\___/  |_|      |___/  \\__,_|     \\_/   |_| |___/ |_|  \\__|  \\__,_|\n");
  printf("                                                   |_|                                                                         \n");
}


int main(void) {
  mensaje_incio();
  Map *Mapa_Jugadores = map_create(is_equal_str);
  cargarTodosJugadores(Mapa_Jugadores);
  
  char nombre[50];
  int saldo, mantener, aux, dinero_ingresado;
  char opcion;
  Apostador *player;
  List *historialCrash = list_create();
  
  mantener = 1;
  aux = 0;
  // Crear un mapa con el nombre y saldo de los jugadores
  do{
    if (aux == 0){
      printf("Ingrese su nombre: ");
      scanf("%s", nombre);
      MapPair *pair = map_search(Mapa_Jugadores, nombre);
      if(pair){
        player = (Apostador*)pair->value;
        saldo = player->dinero;
        printf("Jugador encontrado. Saldo Actual: %d\n", saldo);
        printf("Desea modificar su saldo? (s/n): ");
        scanf(" %c", &opcion);
        if (opcion == 's' || opcion == 'S')
        {
          printf("Ingrese el monto a modificar: ");
          scanf("%d", &dinero_ingresado);
          modificarJugador(Mapa_Jugadores, nombre, dinero_ingresado);
          guardarDatos(Mapa_Jugadores);
        }
      }
      else{
        printf("Jugador no encontrado, registre un nuevo jugador.\n");
        registrarJugador(Mapa_Jugadores);
        sleep(3);
      }
      aux = 1;
    }
    //Despues de ingresar el nombre y saldo, se le pregunta si quiere jugar
    limpiarPantalla();
    printf("==================================\n\n");
    printf("    Bienvenido a Casino Zona 3    \n\n");
    printf("==================================\n\n");
    printf("¿Cual juego desea jugar?\n");
    printf("1. Blackjack\n");
    printf("2. Ruleta\n");
    printf("3. Carrera de caballos\n");
    printf("4. Crash\n");
    printf("5. Salir\n");
    scanf(" %c", &opcion);
    switch(opcion){
      case '1':
        limpiarPantalla();
        jugar_blackjack(&saldo);
        player->dinero = saldo;
        modificarSaldo(Mapa_Jugadores, nombre, saldo);
        guardarDatos(Mapa_Jugadores);  // Guardar cambios en el archivo
        printf("Quieres seguir jugando? (1 para si, 0 para no): ");
        scanf(" %d", &mantener);
        if(mantener == 0)
          break;
        saldo = player->dinero;
      case '2':
        if (opcion == '2')
          Ruleta_Main(&saldo);
          player->dinero = saldo;
          modificarSaldo(Mapa_Jugadores, nombre, saldo);
          guardarDatos(Mapa_Jugadores);
        break;
      case '3':
        carrera();
        break;
      case '4':
        mantener = 1;
        limpiarPantalla();
        reglasCrash();
        limpiarPantalla();
        crash(&saldo);
        int diff = saldo - player->dinero;
        list_pushBack(historialCrash, &diff);
        player->dinero = saldo;
        modificarSaldo(Mapa_Jugadores, nombre, saldo);
        guardarDatos(Mapa_Jugadores);
        printf("Historial de partidas: \n");
        List *aux = list_first(historialCrash);
        printf("%d", *(int*)aux);
        while (aux != NULL)
        {
          if (*(int*)aux > 0)
            printf("+%d\n", *(int*)aux);
          else
            printf("%d\n", *(int*)aux);
          aux = list_next(historialCrash);
        }
        printf("\n");
        
        printf("Quieres seguir jugando? (1 para si, 0 para no): ");
        if (scanf(" %d", &mantener) != 1) {
            while (getchar() != '\n'); // Limpiar el búfer de entrada
            mantener = 0; // En caso de entrada no válida, detener el juego
            break;
        }
        saldo = player->dinero;
        //break;
      case '5':
        aux = 0;
        limpiarPantalla();
        break;
      default:
        printf("Opcion invalida. Intente de nuevo.\n");
    }
  }while(mantener);
  mensaje_final();
  list_clean(historialCrash);
  return 0;
}