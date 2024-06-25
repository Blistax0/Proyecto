#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "BlackJack.h"

#define Max_cartas 52
/*
typedef enum Palo{ 
    CORAZONES, 
    DIAMANTES, 
    TREBOLES, 
    PICAS 
} Palo;
*/
typedef struct Carta{
  int valor; // Valorizamos las cartas de 1 a 13 para saber cual es cual(1 el As y 13 el Rey)
  Palo palo; // Palo de la carta
}Carta;

typedef struct Baraja{
  Carta cartas[Max_cartas]; // Mazo de las cartas
  int top; // Carta la cual se encuentra en el tope del mazo
}Baraja;

typedef struct Jugador{
  Carta mano[11]; // Mano del jugador
  int num_cartas; // Numero de cartas en la mano
  int puntuacion; // Puntuacion de la mano
  Carta mano_split[11]; // Mano del jugador en caso de split
  int num_cartas_split; // Numero de cartas en la mano del jugador en caso de split
  int puntuacion_split; // Puntuacion de la mano en caso de split
  bool split; // Si el jugador ha hecho split
}Jugador;
void limpiarPantalla() { system("clear"); }

void inicializar_baraja(Baraja *baraja){
  int aux = 0;
   for (int palo = CORAZONES; palo <= PICAS; palo++){
     for (int valor = 1; valor <= 13; valor++){
       baraja->cartas[aux].valor = valor; // Asignamos el valor de la carta
       baraja->cartas[aux].palo = palo; // Asignamos el palo de la carta
       aux++; // Incrementamos el contador
     }
   }
  baraja->top = 51; // Inicializamos el tope del mazo 
}

void mezclar_bajara(Baraja *baraja){
  srand(time(NULL));
  for (int i = 0; i < Max_cartas; i++){
    int j = rand() % Max_cartas; // Se genera un número aleatorio entre 0 y Max_cartas-1
    Carta temp = baraja->cartas[i]; // Se guarda la carta en la pos i en un temp
    baraja->cartas[i] = baraja->cartas[j];// Se intercambia la carta en la posición i con la carta en la posición j
    baraja->cartas[j] = temp; // Se intercambia la carta en la posición j con la anteriormente guardada en el temp
  }
}

Carta repartir_carta(Baraja *baraja){
  return baraja->cartas[baraja->top--]; //Retorna la carta en la posición top de la baraja y luego decrementa el top
}
void guardar_picas(Carta carta, char lineas[5][20]){
  if (carta.valor == 1){
    strcpy(lineas[0], " ----- ");
    strcpy(lineas[1], "|♠    |");
    strcpy(lineas[2], "|  A  |");
    strcpy(lineas[3], "|    ♠|");
    strcpy(lineas[4], " ----- ");
  }
  else if (carta.valor == 11){
    strcpy(lineas[0], " ----- ");
    strcpy(lineas[1], "|♠    |");
    strcpy(lineas[2], "|  J  |");
    strcpy(lineas[3], "|    ♠|");
    strcpy(lineas[4], " ----- ");
  }
  else if (carta.valor == 12){
    strcpy(lineas[0], " ----- ");
    strcpy(lineas[1], "|♠    |");
    strcpy(lineas[2], "|  Q  |");
    strcpy(lineas[3], "|    ♠|");
    strcpy(lineas[4], " ----- ");
  }
  else if (carta.valor == 13){
    strcpy(lineas[0], " ----- ");
    strcpy(lineas[1], "|♠    |");
    strcpy(lineas[2], "|  K  |");
    strcpy(lineas[3], "|    ♠|");
    strcpy(lineas[4], " ----- ");
  }
  else{
    strcpy(lineas[0], " ----- ");
    strcpy(lineas[1], "|♠    |");
    sprintf(lineas[2], "| %2d  |", carta.valor);
    strcpy(lineas[3], "|    ♠|");
    strcpy(lineas[4], " ----- ");
  }
}
void guardar_trebol(Carta carta,char lineas[5][20]){
  if (carta.valor == 1){
    strcpy(lineas[0], " ----- ");
    strcpy(lineas[1], "|♣    |");
    strcpy(lineas[2], "|  A  |");
    strcpy(lineas[3], "|    ♣|");
    strcpy(lineas[4], " ----- ");
  }
  else if (carta.valor == 11){
    strcpy(lineas[0], " ----- ");
    strcpy(lineas[1], "|♣    |");
    strcpy(lineas[2], "|  J  |");
    strcpy(lineas[3], "|    ♣|");
    strcpy(lineas[4], " ----- ");
  }
  else if (carta.valor == 12){
    strcpy(lineas[0], " ----- ");
    strcpy(lineas[1], "|♣    |");
    strcpy(lineas[2], "|  Q  |");
    strcpy(lineas[3], "|    ♣|");
    strcpy(lineas[4], " ----- ");
  }
  else if (carta.valor == 13){
    strcpy(lineas[0], " ----- ");
    strcpy(lineas[1], "|♣    |");
    strcpy(lineas[2], "|  K  |");
    strcpy(lineas[3], "|    ♣|");
    strcpy(lineas[4], " ----- ");
  }
  else{
    strcpy(lineas[0], " ----- ");
    strcpy(lineas[1], "|♣    |");
    sprintf(lineas[2], "| %2d  |", carta.valor);
    strcpy(lineas[3], "|    ♣|");
    strcpy(lineas[4], " ----- ");
  }
}
void guardar_diamante(Carta carta, char lineas[5][20]){
  if (carta.valor == 1){
    strcpy(lineas[0], " ----- ");
    strcpy(lineas[1], "|♦    |");
    strcpy(lineas[2], "|  A  |");
    strcpy(lineas[3], "|    ♦|");
    strcpy(lineas[4], " ----- ");
  }
  else if (carta.valor == 11){
    strcpy(lineas[0], " ----- ");
    strcpy(lineas[1], "|♦    |");
    strcpy(lineas[2], "|  J  |");
    strcpy(lineas[3], "|    ♦|");
    strcpy(lineas[4], " ----- ");
  }
  else if (carta.valor == 12){
    strcpy(lineas[0], " ----- ");
    strcpy(lineas[1], "|♦    |");
    strcpy(lineas[2], "|  Q  |");
    strcpy(lineas[3], "|    ♦|");
    strcpy(lineas[4], " ----- ");
  }
  else if (carta.valor == 13){
    strcpy(lineas[0], " ----- ");
    strcpy(lineas[1], "|♦    |");
    strcpy(lineas[2], "|  K  |");
    strcpy(lineas[3], "|    ♦|");
    strcpy(lineas[4], " ----- ");
  }
  else{
    strcpy(lineas[0], " ----- ");
    strcpy(lineas[1], "|♦    |");
    sprintf(lineas[2], "| %2d  |", carta.valor);
    strcpy(lineas[3], "|    ♦|");
    strcpy(lineas[4], " ----- ");
  }
}
void guardar_corazones(Carta carta, char lineas[5][20]){
  if (carta.valor == 1){
    strcpy(lineas[0], " ----- ");
    strcpy(lineas[1], "|♥    |");
    strcpy(lineas[2], "|  A  |");
    strcpy(lineas[3], "|    ♥|");
    strcpy(lineas[4], " ----- ");
  }
  else if (carta.valor == 11){
    strcpy(lineas[0], " ----- ");
    strcpy(lineas[1], "|♥    |");
    strcpy(lineas[2], "|  J  |");
    strcpy(lineas[3], "|    ♥|");
    strcpy(lineas[4], " ----- ");
  }
  else if (carta.valor == 12){
    strcpy(lineas[0], " ----- ");
    strcpy(lineas[1], "|♥    |");
    strcpy(lineas[2], "|  Q  |");
    strcpy(lineas[3], "|    ♥|");
    strcpy(lineas[4], " ----- ");
  }
  else if (carta.valor == 13){
    strcpy(lineas[0], " ----- ");
    strcpy(lineas[1], "|♥    |");
    strcpy(lineas[2], "|  K  |");
    strcpy(lineas[3], "|    ♥|");
    strcpy(lineas[4], " ----- ");
  }
  else{
    strcpy(lineas[0], " ----- ");
    strcpy(lineas[1], "|♥    |");
    sprintf(lineas[2], "| %2d  |", carta.valor);
    strcpy(lineas[3], "|    ♥|");
    strcpy(lineas[4], " ----- ");
  }
}

void guardar_carta(Carta carta, char matriz[5][20]){
  const char * valores[] = {"As", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"}; //Creamos todos los posibles valores 
  const char *palos[] = {"Corazones", "Diamantes", "Treboles", "Picas"}; // Creamos todos los posibles palos
  if (strcmp(palos[carta.palo], "Corazones") == 0){
    guardar_corazones(carta, matriz);
  }
  else if (strcmp(palos[carta.palo], "Diamantes") == 0){
    guardar_diamante(carta, matriz);
  }
  else if (strcmp(palos[carta.palo], "Treboles") == 0){
    guardar_trebol(carta, matriz);
  }
  else if (strcmp(palos[carta.palo], "Picas") == 0){
    guardar_picas(carta, matriz);
  }
}
void mostrar_carta(Carta carta){
  char matriz[5][20];
  guardar_carta(carta, matriz);
  for (int i = 0; i < 5; i++){
    printf("             %s\n", matriz[i]);
  }
}
void mostrar_mano(Jugador jugador){
  char matriz_cartas[jugador.num_cartas][5][20];
  for (int i = 0; i < jugador.num_cartas; i++){
    guardar_carta(jugador.mano[i], matriz_cartas[i]);
  }

  for (int l = 0; l < 5; l++) {
      for (int c = 0; c < jugador.num_cartas; c++) {
        printf("      %s ", matriz_cartas[c][l]);
      }
    printf("\n");
  }
}
void mostrar_mano_split(Jugador jugador) {
  char matriz_cartas[jugador.num_cartas_split][5][20];
  for (int i = 0; i < jugador.num_cartas_split; i++){
    guardar_carta(jugador.mano_split[i], matriz_cartas[i]);
  }

  for (int l = 0; l < 5; l++) {
      for (int c = 0; c < jugador.num_cartas_split; c++) {
        printf("      %s ", matriz_cartas[c][l]);
      }
    printf("\n");
  }
}
void calcular_puntuacion(Jugador *jugador){

  jugador->puntuacion = 0; // Iniciamos su puntuacion en 0
  int num_ases = 0; //Creamos un contador para saber cuantas cartas As tiene el jugador 
  for (int i = 0; i < jugador->num_cartas; i++){
    int valor = jugador->mano[i].valor; // Guardamos el valor de la carta en la posición i en la variable valor
    if (valor == 1){ // Si el valor es 1, significa que es un As
      num_ases++; // Incrementamos el contador de As
      valor = 11; // Inicialmente lo tomamos con valor 11
    }
    else if (valor > 10){ // Si el valor es mayor a 10, significa que puede ser un J, Q o K
      valor = 10; // Se le asigna el valor 10 a cualquiera de los anteriores
    }
    jugador->puntuacion += valor; // Sumamos el valor de la carta a la puntuacion del jugador
  }
  while (num_ases > 0 && jugador->puntuacion > 21){// Crea un bucle que se ejecuta si el número de ases es mayor que 0 y la puntuación es mayor a 21
    jugador->puntuacion -= 10; // Utilizamos el As como 1 para no pasar de 21
    num_ases--; // Restamos en uno el numero de Ases
  }
}
void calcular_puntuacion_split(Jugador * jugador){

  jugador->puntuacion_split = 0; // Iniciamos su puntuacion en 0
  int num_ases = 0; //Creamos un contador para saber cuantas cartas As tiene el jugador 
  for (int i = 0; i < jugador->num_cartas_split; i++){
    int valor = jugador->mano_split[i].valor; // Guardamos el valor de la carta en la posición i en la variable valor
    if (valor == 1){ // Si el valor es 1, significa que es un As
      num_ases++; // Incrementamos el contador de As
      valor = 11; // Inicialmente lo tomamos con valor 11
    }
    else if (valor > 10){ // Si el valor es mayor a 10, significa que puede ser un J, Q o K
      valor = 10; // Se le asigna el valor 10 a cualquiera de los anteriores
    }
    jugador->puntuacion_split += valor; // Sumamos el valor de la carta a la puntuacion del jugador
  }
  while (num_ases > 0 && jugador->puntuacion_split > 21){// Crea un bucle que se ejecuta si el número de ases es mayor que 0 y la puntuación es mayor a 21
    jugador->puntuacion -= 10; // Utilizamos el As como 1 para no pasar de 21
    num_ases--; // Restamos en uno el numero de Ases
  }
}
void split(Jugador *jugador, Baraja *baraja){
  if (jugador->num_cartas == 2 && jugador->mano[0].valor == jugador->mano[1].valor) {
    jugador->mano_split[0] = jugador->mano[1];
    jugador->num_cartas_split = 1;
    jugador->num_cartas = 1;
    jugador->split = true;

    // Repartir una carta a cada mano
    jugador->mano[jugador->num_cartas++] = repartir_carta(baraja);
    jugador->mano_split[jugador->num_cartas_split++] = repartir_carta(baraja);

    // Calcular puntuación para ambas manos
    calcular_puntuacion(jugador);
    calcular_puntuacion_split(jugador);

    // Mostrar las manos
    printf("Primera mano:\n");
    mostrar_mano(*jugador);
    printf("Puntuacion: %d\n", jugador->puntuacion);

    printf("Segunda mano:\n");
    mostrar_mano_split(*jugador);
    printf("Puntuacion: %d\n", jugador->puntuacion_split);
  } else {
    printf("No puedes dividir esta mano.\n");
  }
}
void pedir_carta(Jugador *jugador, Baraja *baraja){
  limpiarPantalla();
  jugador->mano[jugador->num_cartas++] = repartir_carta(baraja);
  calcular_puntuacion(jugador);
  printf("Mano del Jugador\n");
  mostrar_mano(*jugador);
  printf("Puntuacion: %d\n", jugador->puntuacion);
}
void pedir_carta_split(Jugador *jugador, Baraja *baraja){
  limpiarPantalla();
  jugador->mano_split[jugador->num_cartas_split++]= repartir_carta(baraja);
  calcular_puntuacion_split(jugador);
  printf("Segunda Mano: \n");
  mostrar_mano_split(*jugador);
  printf("Puntuacion: %d\n", jugador->puntuacion_split);
}
void declarar_ganador(Jugador jugador, Jugador * crupier, Baraja *baraja){
  if (jugador.puntuacion > 21){
    printf(" ---------------------------------\n");
    printf("|Te has pasado de 21. Has perdido |\n");
    printf(" ---------------------------------\n");
    return;
  }
  while (crupier->puntuacion < 17) {
     crupier->mano[crupier->num_cartas++] = repartir_carta(baraja);
     calcular_puntuacion(crupier);
   }
  printf("Mano del crupier:\n");
  mostrar_mano(*crupier);
  printf("Puntuacion: %d\n\n", crupier->puntuacion);
  if (crupier->puntuacion > 21){
    printf(" -----------------------------------------\n");
    printf("|Puntuacion del crupier %2d                |\n", crupier->puntuacion);
    printf("|El crupier se ha pasado de 21. Has ganado|\n");
    printf(" -----------------------------------------\n");
  }
  else {
    if (crupier->puntuacion > 21 || jugador.puntuacion > crupier->puntuacion){
      printf(" -------------------------\n");
      printf("|Puntuacion del jugador %2d|\n", jugador.puntuacion);
      printf("|Puntuacion del crupier %2d|\n", crupier->puntuacion);
      printf("|       Has ganado        |\n");
      printf(" -------------------------\n");
    }
    else if (jugador.puntuacion == crupier->puntuacion){
      printf("---------------------------\n");
      printf("|Puntuacion del jugador %2d|\n", jugador.puntuacion);
      printf("|Puntuacion del crupier %2d|\n", crupier->puntuacion);
      printf("|        Empate           |\n");
      printf(" --------------------------\n");
    }
    else{
      printf(" -------------------------\n");
      printf("|Puntuacion del jugador %2d|\n", jugador.puntuacion);
      printf("|Puntuacion del crupier %2d|\n", crupier->puntuacion);
      printf("|      Perdiste           |\n");
      printf(" -------------------------\n");
    }
  }
  if (jugador.split) {
    // Evaluar segunda mano
    if (jugador.puntuacion_split > 21) {
      printf(" ---------------------------------\n");
      printf("|Te has pasado de 21 en la segunda mano. Has perdido |\n");
      printf(" ---------------------------------\n");
    } else {
      while (crupier->puntuacion < 17) {
        crupier->mano[crupier->num_cartas++] = repartir_carta(baraja);
        calcular_puntuacion(crupier);
      }
      printf("Mano del crupier:\n");
      mostrar_mano(*crupier);
      printf("Puntuacion: %d\n\n", crupier->puntuacion);
      if (crupier->puntuacion > 21 || jugador.puntuacion_split > crupier->puntuacion) {
        printf(" -------------------------\n");
        printf("|Puntuacion del jugador en la segunda mano %2d|\n", jugador.puntuacion_split);
        printf("|Puntuacion del crupier %2d|\n", crupier->puntuacion);
        printf("|       Has ganado        |\n");
        printf(" -------------------------\n");
      } else if (jugador.puntuacion_split == crupier->puntuacion) {
        printf(" ---------------------------\n");
        printf("|Puntuacion del jugador en la segunda mano %2d|\n", jugador.puntuacion_split);
        printf("|Puntuacion del crupier %2d|\n", crupier->puntuacion);
        printf("|        Empate           |\n");
        printf(" --------------------------\n");
      } else {
        printf(" -------------------------\n");
        printf("|Puntuacion del jugador en la segunda mano %2d|\n", jugador.puntuacion_split);
        printf("|Puntuacion del crupier %2d|\n", crupier->puntuacion);
        printf("|      Perdiste           |\n");
        printf(" -------------------------\n");
      }
    }
  }
}
void doblar_pedir(Jugador *jugador, Baraja *baraja){
  pedir_carta(jugador, baraja);
}
void doblar_pedir_split(Jugador *jugador, Baraja *baraja){
  pedir_carta_split(jugador, baraja);
}
void jugar_blackjack(){

  Baraja baraja; // Creamos una baraja
  inicializar_baraja(&baraja); // Inicializamos la baraja
  mezclar_bajara(&baraja); // Mezclamos la baraja

  Jugador jugador; // Creamos un jugador
  jugador.num_cartas = 0; // Inicializamos el numero de cartas en 0
  jugador.puntuacion = 0; // Inicializamos la puntuacion en 0

  Jugador crupier; // Se crea un crupier
  crupier.num_cartas = 0; // Se inicializa el numero de cartas en 0 del crupier
  crupier.puntuacion = 0; // Se inicializa la puntuacion en 0 del crupier

  jugador.mano[jugador.num_cartas++] = repartir_carta(&baraja); // Se reparte una carta al jugador
  crupier.mano[crupier.num_cartas++] = repartir_carta(&baraja); // Se reparte una carta al crupier
  jugador.mano[jugador.num_cartas++] = repartir_carta(&baraja); // Se reparte la segunda carta al jugador
  crupier.mano[crupier.num_cartas++] = repartir_carta(&baraja); // Se reparte la segunda carta al crupier

  calcular_puntuacion(&jugador); //Se calcula la puntuacion del jugador 
  calcular_puntuacion(&crupier); // Se calcula la puntuacion del crupier

  printf(" --------------------------------\n");
  printf("|Bienvenido al juego de Blackjack|\n");
  printf(" --------------------------------\n");
  printf("   |Carta visible del crupier:|   \n");
  printf("    --------------------------\n");
  mostrar_carta(crupier.mano[0]); // Se muestra la carta visible del crupier
  printf("\n");
  printf("             ------- \n");
  printf("            |Tu mano|\n");
  printf("             ------- \n");
  mostrar_mano(jugador);// Se muestra la mano del jugador
  printf("          ------------- \n");
  printf("         |Puntuacion:%2d|\n", jugador.puntuacion); // Se muestra la puntuacion del jugador
  printf("          ------------- \n");

  char opcion;
  while (jugador.puntuacion < 21) {
    printf("¿Que desea hacer?\n1) Pedir carta\n2) Plantarse\n3) Doblar\n4) Dividir (split)\n");
    scanf(" %c", &opcion);
    while (opcion != '1' && opcion != '2' && opcion != '3' && opcion != '4') {
      printf("¿Que desea hacer?\n1) Pedir carta\n2) Plantarse\n3) Doblar\n4) Dividir (split)\n");
      scanf(" %c", &opcion);
    }

    if (opcion == '1') {
      pedir_carta(&jugador, &baraja);
    } else if (opcion == '2') {
      limpiarPantalla();
      break;
    } else if (opcion == '3') {
      doblar_pedir(&jugador, &baraja);
      break;
    } else if (opcion == '4') {
      split(&jugador, &baraja);
      if (jugador.split == false){
        limpiarPantalla();
        break;
      }
      // Permitir al jugador jugar ambas manos
      while (jugador.puntuacion < 21) {
        printf("Primera mano:\n");
        mostrar_mano(jugador);
        printf("¿Que desea hacer para la primera mano?\n1) Pedir carta\n2) Plantarse\n3) Doblar\n");
        scanf(" %c", &opcion);
        if (opcion == '1') {
          pedir_carta(&jugador, &baraja);
        } else if (opcion == '2') {
          limpiarPantalla();
          break;
        } else if (opcion == '3') {
          doblar_pedir(&jugador, &baraja);
          break;
        }
      }
      while (jugador.puntuacion_split < 21) {
        printf("Segunda mano:\n");
        mostrar_mano_split(jugador);
        printf("¿Que desea hacer para la segunda mano?\n1) Pedir carta\n2) Plantarse\n3) Doblar\n");
        scanf(" %c", &opcion);
        if (opcion == '1') {
          pedir_carta_split(&jugador, &baraja);
        } else if (opcion == '2') {
          limpiarPantalla();
          break;
        } else if (opcion == '3') {
          doblar_pedir_split(&jugador, &baraja);
          break;
        }
      }
      break;
    }
  }
  declarar_ganador(jugador, &crupier, &baraja);
}
