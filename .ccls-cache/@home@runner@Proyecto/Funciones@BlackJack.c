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

typedef struct Apostador{
  char nombre[50];
  int dinero;
}Apostador;

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
} // Guarda las lines en la matriz para posteriormente 
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
}// Guarda las lines en la matriz para posteriormente 
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
}// Guarda las lines en la matriz para posteriormente 
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
}// Guarda las lines en la matriz para posteriormente 

void guardar_carta(Carta carta, char matriz[5][20]){
  const char * valores[] = {"As", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"}; //Creamos todos los posibles valores 
  const char *palos[] = {"Corazones", "Diamantes", "Treboles", "Picas"}; // Creamos todos los posibles palos
  if (strcmp(palos[carta.palo], "Corazones") == 0){
    guardar_corazones(carta, matriz); // Se manda a la funcion guardar_corazones
  }
  else if (strcmp(palos[carta.palo], "Diamantes") == 0){
    guardar_diamante(carta, matriz); // Se manda a la funcion guardar_diamante
  }
  else if (strcmp(palos[carta.palo], "Treboles") == 0){
    guardar_trebol(carta, matriz); // Se manda a la funcion guardar_trebol
  }
  else if (strcmp(palos[carta.palo], "Picas") == 0){
    guardar_picas(carta, matriz); // Se manda a la funcion guardar_picas
  }
}
void mostrar_carta(Carta carta){
  char matriz[5][20]; // Matriz para guardar las lineas de la carta
  guardar_carta(carta, matriz); // Se manda a la funcion guardar_carta
  for (int i = 0; i < 5; i++){
    printf("             %s\n", matriz[i]); // Se imprime la matriz
  }
}
void mostrar_mano(Jugador jugador){
  char matriz_cartas[jugador.num_cartas][5][20]; // Matriz para guardar las lineas de las cartas
  for (int i = 0; i < jugador.num_cartas; i++){
    guardar_carta(jugador.mano[i], matriz_cartas[i]); // Se manda a la funcion guardar_carta
  }

  for (int l = 0; l < 5; l++) {
      for (int c = 0; c < jugador.num_cartas; c++) {
        printf("      %s ", matriz_cartas[c][l]); // Se imprime la matriz
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
} // Igual que la funcion mostrar_mano pero para el caso de split
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
} // Igual que la funcion calcular_puntuacion pero para el caso de split
void split(Jugador *jugador, Baraja *baraja){
  if (jugador->num_cartas == 2 && jugador->mano[0].valor == jugador->mano[1].valor) {
    jugador->mano_split[0] = jugador->mano[1]; // La primera carta de la mano split es igual a la segunda carta de la mano original
    jugador->num_cartas_split = 1; // El numero de cartas de la mano split es 1
    jugador->num_cartas = 1; // El numero de cartas de la mano original es 1
    jugador->split = true; // El jugador hace split

    // Repartir una carta a cada mano
    jugador->mano[jugador->num_cartas++] = repartir_carta(baraja); // Repartimos una carta a la mano original
    jugador->mano_split[jugador->num_cartas_split++] = repartir_carta(baraja); // Repartimos una carta a la mano split

    // Calcular puntuación para ambas manos
    calcular_puntuacion(jugador); // Calculamos la puntuación de la mano original
    calcular_puntuacion_split(jugador); // Calculamos la puntuación de la mano split

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
  jugador->mano[jugador->num_cartas++] = repartir_carta(baraja); // Repartimos una carta a la mano original
  calcular_puntuacion(jugador); // Calculamos la puntuación de la mano original
  printf("Mano del Jugador\n"); 
  mostrar_mano(*jugador); // Mostramos la mano del jugador
  printf("Puntuacion: %d\n", jugador->puntuacion);
}
void pedir_carta_split(Jugador *jugador, Baraja *baraja){
  limpiarPantalla();
  jugador->mano_split[jugador->num_cartas_split++]= repartir_carta(baraja);
  calcular_puntuacion_split(jugador);
  printf("Segunda Mano: \n");
  mostrar_mano_split(*jugador);
  printf("Puntuacion: %d\n", jugador->puntuacion_split);
} //  Igual que la funcion pedir_carta pero para el caso de split
void declarar_ganador(Jugador jugador, Jugador *crupier, Baraja *baraja, int *saldo, int apuesta){
  if (jugador.puntuacion > 21){ // Si el jugador tiene más de 21 puntos, pierde
    printf(" ---------------------------------\n");
    printf("|Te has pasado de 21. Has perdido |\n");
    printf(" ---------------------------------\n");
    return;
  }
  else if (jugador.puntuacion == 21 && jugador.num_cartas == 2){ // Si tiene BlackJack
    printf(" ---------------------------------\n");
    printf("|¡Felicidades! Has ganado con 21 |\n");
    printf(" ---------------------------------\n");
    *saldo += apuesta * 2.5;
    return;
  }
  while (crupier->puntuacion < 17) { // El crupier sigue pidiendo cartas mientras su puntuación sea menor que 17
    crupier->mano[crupier->num_cartas++] = repartir_carta(baraja);
    calcular_puntuacion(crupier);
  }
  printf("Mano del crupier:\n");
  mostrar_mano(*crupier);
  printf("Puntuacion: %d\n\n", crupier->puntuacion);
  if (crupier->puntuacion > 21){ // Si el crupier tiene más de 21 puntos, gana el jugador
    printf(" -----------------------------------------\n");
    printf("|Puntuacion del crupier %2d                |\n", crupier->puntuacion);
    printf("|El crupier se ha pasado de 21.           |\n");
    printf("|             Has ganado %2i              |\n", apuesta*2);
    printf(" -----------------------------------------\n");
    *saldo += apuesta * 2;
  }
  else {
    if (crupier->puntuacion > 21 || jugador.puntuacion > crupier->puntuacion){ // Si el crupier tiene más de 21 puntos o el jugador tiene más puntos que
      printf(" -------------------------\n");
      printf("|Puntuacion del jugador %2d|\n", jugador.puntuacion);
      printf("|Puntuacion del crupier %2d|\n", crupier->puntuacion);
      printf("|      Has ganado %2i      |\n", apuesta * 2);
      printf(" -------------------------\n");
      *saldo += apuesta * 2;
    }
    else if (jugador.puntuacion == crupier->puntuacion){ // Si el jugador y el crupier tienen la misma puntuación
      printf("---------------------------\n");
      printf("|Puntuacion del jugador %2d|\n", jugador.puntuacion);
      printf("|Puntuacion del crupier %2d|\n", crupier->puntuacion);
      printf("|        Empate           |\n");
      printf(" --------------------------\n");
    }
    else{ // Si el jugador tiene menos puntos que el crupier
      printf(" -------------------------\n");
      printf("|Puntuacion del jugador %2d|\n", jugador.puntuacion);
      printf("|Puntuacion del crupier %2d|\n", crupier->puntuacion);
      printf("|      Perdiste           |\n");
      printf(" -------------------------\n");
    }
  }
  if (jugador.split) // Si el jugador hizo split Se le evalua la segunda mano
  {
    // Evaluar segunda mano
    if (jugador.puntuacion_split > 21) {
      printf(" ---------------------------------\n");
      printf("|Te has pasado de 21 en la segunda mano. Has perdido |\n");
      printf(" ---------------------------------\n");
    }
    else if (jugador.puntuacion_split == 21 && jugador.num_cartas_split == 2){ // Si tiene BlackJack
      printf(" ---------------------------------\n");
      printf("|¡Felicidades! Has ganado con 21 |\n");
      printf(" ---------------------------------\n");
      *saldo += apuesta * 2.5;
      return;
    }else {
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
        *saldo += apuesta * 2;
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
void doblar_pedir(Jugador *jugador, Baraja *baraja, int * saldo, int apuesta){
  if (*saldo > apuesta){ // Si el saldo del jugador es mayor que la apuesta
    *saldo -= apuesta; // Se le resta la apuesta al saldo del jugador
    apuesta*= 2; // Se duplica la apuesta
    pedir_carta(jugador, baraja); // Se le pide una carta a la mano del jugador
  }
}
void doblar_pedir_split(Jugador *jugador, Baraja *baraja, int * saldo, int apuesta){
  if (*saldo > apuesta){
    *saldo -= apuesta;
    apuesta*= 2;
    pedir_carta_split(jugador, baraja);
  }
} // Igual que doblar_pedir pero para el caso de split
void jugar_blackjack(int * saldo){ // main del blackjack
  
  int opcion;
  printf(" --------------------------------\n");
  printf("|Bienvenido al juego de Blackjack|\n");
  printf(" --------------------------------\n");
  printf("|Desea saber las reglas?        |\n");
  printf("|1. Si                          |\n");
  printf("|2. No                          |\n");
  printf(" ------------------------------- \n");
  scanf("%d", &opcion); // Se pregunta si quiere saber las reglas
  switch(opcion){
    case 1:
      limpiarPantalla();
      printf(" ----------------------------------------------------------------------------------------------------\n");
      printf("|Las reglas son las siguientes:                                                                      |\n");
      printf("|1. Al jugador se le entregaran 2 cartas.                                                            |\n");
      printf("|2. Al Crupier se le entregaran 2 cartas. Solo una es visible                                        |\n");
      printf("|3. El objetivo del juego es tener una puntuacion lo más cercana posible a 21 sin pasarse.           |\n");
      printf("|4. Si el jugador tiene un As, puede tomarlo como un 1 o como un 11.                                 |\n");
      printf("|5. Si el jugador tiene dos As, el segundo As se toma como un 1.                                     |\n");
      printf("|6. Si el jugador tiene un As y un 10, gana directamente.                                            |\n");
      printf("|7. Si el crupier supera los 21, el jugador gana.                                                    |\n");
      printf("|8. Las cartas J, Q y K valen 10.                                                                    |\n");
      printf("|9. Se puede utilizar la opcion de doblar y pedir solo si tiene el saldo necesario                   |\n");
      printf("|10. Se puede utilizar la opcion de dividir manos si tiene el saldo necesario                        |\n");
      printf("|11. En caso de que se seleccione una de estas opciones y no sea posible, sera tomado como quedarse. |\n");
      printf(" ----------------------------------------------------------------------------------------------------\n");
      printf("|Presione enter para continuar...                                                                    |\n");
      printf(" ----------------------------------------------------------------------------------------------------\n");
      getchar();
      getchar();

      break;
    case 2:
      break;
  }
  limpiarPantalla();
  printf("Su saldo actual es de $%d\n", *saldo); // Se muestra el saldo del jugador
  printf("Cuanto desea apostar?\n"); // Se pregunta cuanto desea apostar
  int apuesta;
  scanf("%d", &apuesta);
  if (apuesta > *saldo){
    printf("No tienes suficiente dinero para realizar esta apuesta\n");
  }
  else{
    *saldo -= apuesta; // Se le resta la apuesta al saldo del jugador
    printf("%i\n", apuesta);
    Baraja baraja; // Creamos una baraja
    inicializar_baraja(&baraja); // Inicializamos la baraja
    mezclar_bajara(&baraja); // Mezclamos la baraja

    Jugador jugador; // Creamos un jugador
    jugador.num_cartas = 0; // Inicializamos el numero de cartas en 0
    jugador.puntuacion = 0; // Inicializamos la puntuacion en 0
    jugador.split = false; // Inicializamos el split en falso
    jugador.num_cartas_split = 0; // Inicializamos el numero de cartas en 0
    jugador.puntuacion_split = 0; // Iniciamos su puntuacion en 0
    

    Jugador crupier; // Se crea un crupier
    crupier.num_cartas = 0; // Se inicializa el numero de cartas en 0 del crupier
    crupier.puntuacion = 0; // Se inicializa la puntuacion en 0 del crupier

    jugador.mano[jugador.num_cartas++] = repartir_carta(&baraja); // Se reparte una carta al jugador
    crupier.mano[crupier.num_cartas++] = repartir_carta(&baraja); // Se reparte una carta al crupier
    jugador.mano[jugador.num_cartas++] = repartir_carta(&baraja); // Se reparte la segunda carta al jugador
    crupier.mano[crupier.num_cartas++] = repartir_carta(&baraja); // Se reparte la segunda carta al crupier

    calcular_puntuacion(&jugador); //Se calcula la puntuacion del jugador 
    calcular_puntuacion(&crupier); // Se calcula la puntuacion del crupier

    printf("    --------------------------\n");
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
    while (jugador.puntuacion < 21) { // Mientras la puntuacion del jugador sea menor a 21 se le muestran las opciones
      printf("¿Que desea hacer?\n1) Pedir carta\n2) Plantarse\n3) Doblar\n4) Dividir (split)\n");
      scanf(" %c", &opcion);
      while (opcion != '1' && opcion != '2' && opcion != '3' && opcion != '4') {
        printf("¿Que desea hacer?\n1) Pedir carta\n2) Plantarse\n3) Doblar\n4) Dividir (split)\n");
        scanf(" %c", &opcion);
      }

      if (opcion == '1') {
        pedir_carta(&jugador, &baraja); // Se le pide una carta al jugador
      } else if (opcion == '2') {
        limpiarPantalla();// El jugador se queda
        break;
      } else if (opcion == '3') {
        doblar_pedir(&jugador, &baraja, saldo, apuesta); // Se le dobla la apuesta al jugador
        break;
      } else if (opcion == '4') {
        split(&jugador, &baraja); // Se le hace split al jugador
        if (jugador.split == false){
          limpiarPantalla();
          break;
        }
        // Permitir al jugador jugar ambas manos
        while (jugador.puntuacion < 21) {
          printf("Primera mano:\n"); // Se muestra la primera mano
          mostrar_mano(jugador); // Se muestra la mano del jugador
          printf("¿Que desea hacer para la primera mano?\n1) Pedir carta\n2) Plantarse\n3) Doblar\n"); // Se muestra las opciones para la primera mano
          scanf(" %c", &opcion);
          if (opcion == '1') {
            pedir_carta(&jugador, &baraja);
          } else if (opcion == '2') {
            limpiarPantalla();
            break;
          } else if (opcion == '3') {
            doblar_pedir(&jugador, &baraja, saldo, apuesta);
            break;
          }
        }
        while (jugador.puntuacion_split < 21) { // Se juega la segunda mano de manera aislada de la primera
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
            doblar_pedir_split(&jugador, &baraja, saldo, apuesta);
            break;
          }
        }
        break;
      }
    }
    declarar_ganador(jugador, &crupier, &baraja, saldo, apuesta); // Se declara el ganador de la partida
  }
}
