#ifndef RULETA_H
#define RULETA_H

typedef struct Ruleta_slot Ruleta_slot;
typedef struct Node Node;
typedef struct ListaResultados ListaResultados;

//Inicializar la lista enlazada
void ini_lista(ListaResultados* lista);
//Agregar los resultados a la lista
void agregar_resultado(ListaResultados* lista, Ruleta_slot resultado);
//Imrpime las lista de numeros y colores ganadores
void imprimir_lista(ListaResultados* lista);

// Función para inicializar la ruleta
void inicializar_ruleta(Ruleta_slot* ruleta);
//Funcion que gira la ruleta y da el resultado dependiendo de las vueltas
Ruleta_slot girar_ruleta(Ruleta_slot* ruleta, int size);
// Función para girar la ruleta(animacion de esta)
void animacion_girar(Ruleta_slot* ruleta, int size, int index);
// Función para imprimir la mesa de apuestas
void print_mesa_apuesta();
//funcion para mostrar reglas
void reglas();

//Funcion para mostrar el menu
int tu_apuesta();
//Funcion para mostrar el tipo de apuestas, y saber si ganaste o no
void elegir_apuesta(int* apuestas, int* valores, int num_apuestas, Ruleta_slot resultado);
//Funcion para obetener solo el numero de la ruleta, esto es necesario para la funcion elegir apuesta
int obtener_numero(int tipo_de_apuesta);
//Funcion Principal de la ruleta que contiene todo.
void Ruleta_Main();
#endif