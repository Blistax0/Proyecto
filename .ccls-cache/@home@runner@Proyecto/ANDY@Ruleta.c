#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
/*
#define Ruleta_max 37
//Definir la estructura de las casillas de la ruleta
typedef struct {
    int numero;
    char color; // colores: rojo, negro y verde
} Ruleta_slot;

// estructura lista de numeros y colores que ya salieron.
struct Node{
  int numeros[Ruleta_max];
  char colores[Ruleta_max];
  struct node *next;
 };

// Funcion para crear una lista vacia
void add_list(struct Node *head, int numero, const char* color){
  struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
  new_node->numero = numero;
  strcpy(new_node->color, color);
  new_node->next = *head;
  *head = new_node;
}
//Funcion para imprimir la lista de casos que hay
void imprimir_lista(struct Node *head){
  struct Node *current = head;
  while(current != NULL){
    printf("Numero: %d, Color: %s\n", current->numero, current->color);
    current = current->next;  
  }
}
//Funcion para inicializar la ruleta
void inicializar_ruleta(Ruleta_slot *ruleta){
  // NUMERO 0 Y COLOR VERDE
  ruleta[0].numero = 0;
  strcpy(ruleta[0].color, "Verde");
  // NUMEROS ROJO Y NEGRO
  int rojo [] = {1,3,5,7,9,12,14,16,18,19,21,23,25,27,30,32,34,36};
  int negro [] = {2,4,6,8,10,11,13,15,17,20,22,24,26,28,29,31,33,35};

  for(int i = 0; i < 18; i++)
  {
    ruleta[i].numero = rojo[i];
    strcpy(ruleta[i].color, "Rojo");
    ruleta[i].numero = negro[i];
    strcpy(ruleta[i].color, "Negro");
  }

}
  


}


*/