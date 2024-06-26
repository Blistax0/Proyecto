#ifndef BLACKJACK_H
#define BLACKJACK_H
typedef enum { 
    CORAZONES, 
    DIAMANTES, 
    TREBOLES, 
    PICAS 
} Palo;

typedef struct Apostador Apostador;

typedef struct Carta Carta;

typedef struct Baraja Baraja;

typedef struct Jugador Jugador;
void limpiarPantalla();
void inicializar_baraja(Baraja *baraja);
void mezclar_bajara(Baraja *baraja);
Carta repartir_carta(Baraja *baraja);
void guardar_picas(Carta carta, char lineas[5][20]);
void guardar_trebol(Carta carta,char lineas[5][20]);
void guardar_diamante(Carta carta, char lineas[5][20]);
void guardar_corazones(Carta carta, char lineas[5][20]);
void guardar_carta(Carta carta, char matriz[5][20]);
void mostrar_mano(Jugador jugador);
void mostrar_mano_split(Jugador jugador);
void calcular_puntuacion(Jugador *jugador);
void calcular_puntuacion_split(Jugador * jugador);
void split(Jugador *jugador, Baraja *baraja);
void pedir_carta(Jugador *jugador, Baraja *baraja);
void pedir_carta_split(Jugador *jugador, Baraja *baraja);
void declarar_ganador(Jugador jugador, Jugador * crupier, Baraja *baraja, int * saldo, int apuesta);
void doblar_pedir(Jugador *jugador, Baraja *baraja, int * saldo, int apuesta);
void doblar_pedir_split(Jugador *jugador, Baraja *baraja);
int jugar_blackjack(int * saldo);

#endif