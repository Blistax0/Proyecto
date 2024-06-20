#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define Ruleta_max 37
//Definir la estructura de las casillas de la ruleta
typedef struct {
    int numero;
    char color; // colores, rojo,negro y verde
} Ruleta_slot;

// estructura lista de numeros y colores que ya salieron.
struct Node{
  int numeros[Ruleta_max];
  char colores[Ruleta_max];
  struct node *next;
 };

// Funcion para crear una lista vacia
void ￼add_list(struct Node *head, int numero, char color){
  struct Node *new_node = (struct Node*)malloc(sizeof(struct Node)))
}


