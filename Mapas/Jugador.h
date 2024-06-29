#ifndef JUGADOR_H
#define JUGADOR_H

#include "list.h"
#include "map.h"

typedef struct Jugador Jugador;

void cargarTodosJugadores(Map* Jugadores);

Jugador *cargarJugador(Map *Jugadores);

void guardarJugador(Map *Jugadores);

void registrarJugador(Map *Jugadores);

void modificarJugador(Map *Jugadores,char *nombre, int monto);

void modificarSaldo(Map* Jugadores, char *nombre, int monto);

#endif