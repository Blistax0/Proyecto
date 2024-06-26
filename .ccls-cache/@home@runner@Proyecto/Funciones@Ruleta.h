#ifndef RULETA_H
#define RULETA_H

typedef struct Ruleta_slot Ruleta_slot;
typedef struct Node Node;
typedef struct ListaResultados ListaResultados;

void ini_lista(ListaResultados* lista);

void agregar_resultado(ListaResultados* lista, Ruleta_slot resultado);

void imprimir_lista(ListaResultados* lista);

// Función para inicializar la ruleta
void inicializar_ruleta(Ruleta_slot* ruleta);

Ruleta_slot girar_ruleta(Ruleta_slot* ruleta, int size);

void animacion_girar(Ruleta_slot* ruleta, int size, int index);
// Función para imprimir la mesa de apuestas
void print_mesa_apuesta();

void reglas();


int tu_apuesta();

void elegir_apuesta(int* apuestas, int* valores, int num_apuestas, Ruleta_slot resultado);
int obtener_numero(int tipo_de_apuesta);

void Ruleta_Main();
#endif