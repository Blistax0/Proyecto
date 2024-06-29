#ifndef CRASH_H
#define CRASH_H

void explosion(); // Muestra la explosión en la pantalla
void crash(int *saldo); // Juego crash
void *handleInput(void *arg); // Función para manejar la entrada del usuario
float numeroMax(); // Función para generar el número máximo aleatorio
int numeroAleatorioConProbabilidades(); // Función para generar un número aleatorio con probabilidades
float randomizar(int min, int max); // Función para generar un número aleatorio en un rango dado y en float
void avion(); // Dibujo del avión
void mostrarAvion(int cont); // Dibuja el avión en la pantalla
void reglasCrash(); // Muestra las reglas del juego

#endif