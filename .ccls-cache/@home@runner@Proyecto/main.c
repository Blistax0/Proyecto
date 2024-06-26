#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "Funciones/Ruleta.h"
#include "Funciones/BlackJack.h"
#include "Mapas/map.h"
#include "Mapas/Jugador.h"
#include "Funciones/Crash.h"

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
        }
      }
      else{
        printf("Jugador no encontrado. Registre un nuevo jugador\n.");
        registrarJugador(Mapa_Jugadores);
      }
      aux = 1;
    }
    //Despues de ingresar el nombre y saldo, se le pregunta si quiere jugar
    limpiarPantalla();
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
        int diferencia = jugar_blackjack(&saldo);
        player->dinero = saldo;
        modificarSaldo(Mapa_Jugadores, nombre, saldo);
        guardarDatos(Mapa_Jugadores);  // Guardar cambios en el archivo
        printf("Quieres seguir jugando? (1 para si, 0 para no): ");
        scanf("%d", &mantener);
        if(mantener == 0)
          break;
        saldo = player->dinero;
      case '2':
        if (opcion == '2')
          Ruleta_Main();
        break;
      case '3':
        
        //jugar_carrera_caballos();
        break;
      case '4':
        //reglasCrash();
        crash();
        break;
      case '5':
        aux = 0;
        limpiarPantalla();
        break;
      default:
        printf("Opcion invalida. Intente de nuevo.\n");
    }
  }while(mantener);
  mensaje_final();
  return 0;
}