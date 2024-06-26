#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>
#include "Crash.h"

int inputReceived = 0; // Flag to indicate input has been received
pthread_mutex_t inputMutex; // Mutex for thread synchronization

// Function for the input thread
void *handleInput(void *arg) 
{
  while (1) 
  {
    // Check for input using nonblocking read
    char input;
    int bytesRead = read(STDIN_FILENO, &input, 1);
    if (bytesRead > 0) 
    {
      // Input received, update the flag
      pthread_mutex_lock(&inputMutex);
      inputReceived = 1; 
      pthread_mutex_unlock(&inputMutex);
    }
  }
  return NULL;
}

// Función para generar un número aleatorio con probabilidades personalizadas
int numeroAleatorioConProbabilidades() 
{
  int numeroAleatorio = rand() % 100 + 1;  // Genera un número aleatorio entre 1 y 100

  if (numeroAleatorio <= 60) 
    return 1;  // 60% de probabilidad 1 a 5

  else if (numeroAleatorio <= 75) 
    return 2;  // 15% de probabilidad 5,1 a 10

  else if (numeroAleatorio <= 85) 
    return 3;  // 10% de probabilidad 10,1 a 20

  else if (numeroAleatorio <= 90)
    return 4;  // 5% de probabilidad 20,1 a 30

  else if (numeroAleatorio <= 94)
    return 5;  // 4% de probabilidad 30,1 a 40

  else if (numeroAleatorio <= 96)
    return 6;  // 2% de probabilidad 40,1 a 50

  else if (numeroAleatorio <= 97)
    return 7;  // 1% de probabilidad 50,1 a 60

  else if (numeroAleatorio <= 98)
    return 8;  // 1% de probabilidad 60,1 a 70

  else if (numeroAleatorio <= 99)
    return 9;  // 1% de probabilidad 70,1 a 80

  else
    return 10;  // 1% de probabilidad 80,1 a 102
}

// Función para generar un número aleatorio en el intervalo indicado
float randomizar(int min, int max)
{
  int num = (rand() % (max - min + 1)) + min;
  float numConvert = (float) num / 100; // Convierte el número a decimal
  return numConvert;
}

// Función para generar el número decimal aleatorio
float numeroMax()
{
  int rango = numeroAleatorioConProbabilidades();
  float numero;
  switch(rango)
  {
    case 1:
      numero = randomizar(100, 500);
      break;

    case 2:
      numero = randomizar(501, 1000);
      break;

    case 3:
      numero = randomizar(1001, 2000);
      break;

    case 4:
      numero = randomizar(2001, 3000);
      break;

    case 5:
      numero = randomizar(3001, 4000);
      break;

    case 6:
      numero = randomizar(4001, 5000);
      break;

    case 7:
      numero = randomizar(5001, 6000);
      break;

    case 8:
      numero = randomizar(6001, 7000);
      break;

    case 9:
      numero = randomizar(7001, 8000);
      break;

    case 10:
      numero = randomizar(8001, 10200);
      break;
  }
  return numero;
}

// Forma el avión
void avion()
{
  printf("               _\n");
  printf("             -=\\`\\\n");
  printf("         |\\ ____\\_\\__\n");
  printf("------ -=\\c`\"\"\"\"\"\"\" \"`)\n");
  printf("          `~~~~~/ /~~`\n");
  printf("            -==/ /\n");
  printf("              '-'\n");
}

// Muestra la animación del avión en la pantalla
void mostrarAvion(int estado)
{
  if (estado <= 3)
  {
    printf("          _  _\n");
    printf("         ( `   )_\n");
    printf("        (    )    `)\n");
    printf("      (_   (_ .  _) _)\n\n");
    avion();
    printf("                                     _\n");
    printf("                                    (  )\n");
    printf("     _ .                         ( `  ) . )\n");
    printf("   (  _ )_                      (_, _(  ,_)_)\n");
    printf(" (_  _(_ ,)\n");
  }

  else if (estado <= 6)
  {
    printf("      _  _\n");
    printf("     ( `   )_\n");
    printf("    (    )    `)\n");
    printf("  (_   (_ .  _) _)\n\n");
    avion();
    printf("                                   _\n");
    printf("                                  (  )\n");
    printf("   _ .                         ( `  ) . )\n");
    printf(" (  _ )                      (_, _(  ,_)_)\n");
    printf("(_ ,)\n");
  }

  else
  {
    printf("    _  _\n");
    printf("   ( `   )_\n");
    printf("  (    )    `)\n");
    printf("(_   (_ .  _) _)\n\n");
    avion();
    printf("                             _\n");
    printf("                            (  )\n");
    printf("                         ( `  ) . )\n");
    printf("                       (_, _(  ,_)_)\n");
    printf("\n");
  }


}

// Muestra la explosión en la pantalla
void explosion()
{
  printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⠀⡀⢀⠀⢠⠀⠀⠀⠀⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
  printf("⠀⠀⠀⠀⠀⠀⢠⢤⣀⠀⠀⠀⠈⣆⢧⠈⡆⢸⠀⠀⠀⢰⢡⠇⠀⠀⠀⠀⠀⡀⠀⠀⠀⠀⠀\n");
  printf("⠀⠀⠀⢀⠀⠀⣯⢀⣨⠃⠀⠀⠀⠸⡜⣄⣣⢸⠀⠀⠀⡜⡌⠀⠀⠀⠀⢀⡜⡁⠀⠀⠀⠀⠀\n");
  printf("⠀⠀⠙⢮⡳⢄⠈⠁⠀⢠⠴⠍⣛⣚⣣⢳⢽⡀⣏⣲⣀⢧⡥⠤⠶⢤⣠⢎⠜⠁⠀⠀⠀⠀⠀\n");
  printf("⠀⠠⣀⠀⠙⢦⡑⢄⢀⣾⣧⡎⠁⠀⠙⡎⡇⡇⡇⠹⢪⣀⡓⣦⢀⣼⣵⠋⢀⠴⣊⠔⠁⠀⠀\n");
  printf("⠀⠀⠈⠑⢦⣀⠙⣲⣝⢭⡚⠃⠀⠀⠀⠸⠸⣹⠁⠀⠀⠀⠉⣹⣪⣎⡸⢞⡵⠊⠁⣀⠀⠀⠀\n");
  printf("⠀⠀⠀⠀⠀⠈⣷⢯⣨⠷⣝⠦⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⠵⣪⢶⣙⡤⠖⢉⣀⠤⠖⠂\n");
  printf("⠀⠀⠀⠀⠀⢀⡞⢠⠾⠓⢮⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢬⣺⡯⢕⢲⠉⣥⣀⡀⠀⠀\n");
  printf("⠀⠀⢀⡤⣀⢈⡷⠻⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠁⠘⠀⢱⢾⠘⢇⢴⠁⠀⠀\n");
  printf("⠀⠀⢻⣀⡼⢘⣧⢀⡟⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡄⢙⣞⠆⠀⠀⠀⠀⠀\n");
  printf("⠀⠀⠀⠉⠀⢿⡀⠈⠧⡤⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣸⠇⣹⣦⠇⠀⠀⠀⠀⠀\n");
  printf("⠀⠀⠀⠀⠀⠸⢤⡴⢺⡧⣴⡶⢗⡣⠀⡀⠀⠀⠀⡄⠀⢀⣄⠢⣔⡞⣤⠦⡇⠀⠀⠀⠀⠀⠀\n");
  printf("⠀⠀⠀⠀⣀⡤⣖⣯⡗⣪⢽⡻⣅⠀⣜⡜⠀⠀⠀⠸⡜⡌⣮⡣⡙⢗⢏⡽⠁⠰⡏⠙⡆⠀⠀\n");
  printf("⠀⠀⣒⡭⠖⣋⡥⣞⣿⡚⠉⠉⢉⢟⣞⣀⣀⣀⠐⢦⢵⠹⡍⢳⡝⢮⡷⢝⢦⡀⠉⠙⠁⠀⠀\n");
  printf("⠐⠊⢡⠴⠚⠕⠋⠹⣍⡉⠹⢧⢫⢯⣀⣄⣀⠈⣹⢯⣀⣧⢹⡉⠙⢦⠙⣄⠑⢌⠲⣄⠀⠀⠀\n");
  printf("⠀⠀⠀⠀⠀⠀⠀⠀⠘⠧⡴⣳⣃⣸⠦⠴⠖⢾⣥⠞⠛⠘⣆⢳⡀⠈⠳⡈⠳⡄⠁⠀⠀⠀⠀\n");
  printf("⠀⠀⠀⠀⠀⠀⠀⠀⢀⡜⡱⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⡄⢣⠀⠀⠉⠀⠈⠂⠀⠀⠀⠀\n");
  printf("⠀⠀⠀⠀⠀⠀⠀⢀⠞⡼⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠹⡀⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
  printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
}

// Juego crash
void crash() 
{
  srand(time(NULL)); 
  float maximo = numeroMax();
  float numero = 1.00;
  float retirada = numero; 
  int retiro = 0;
  int cont = 1;

  pthread_mutex_init(&inputMutex, NULL);

  pthread_t inputThread;
  pthread_create(&inputThread, NULL, handleInput, NULL);

  // Display the initial state before the loop
  limpiarPantalla();
  mostrarAvion(cont);
  printf("%20.2f\n", numero);

  while (numero <= maximo) 
  {
    // Update the display only when needed
    if (numero != 1.00 || retiro) 
    { // Check if 'numero' has changed or user input
      limpiarPantalla();
      mostrarAvion(cont);
      if (cont > 9) cont = 1;
      printf("%20.2f\n", numero);
      if (retiro) printf("Ya retiraste.\n");
      cont++;
    }

    // Check for input only if the user hasn't already withdrawn
    if (!retiro) 
    {
      pthread_mutex_lock(&inputMutex);
      if (inputReceived) 
      {
        retiro = 1;
        retirada = numero;
        inputReceived = 0; // Reset the flag
      }
      pthread_mutex_unlock(&inputMutex);
    }

    // Generate a random increment
    float incremento = randomizar(2, 6);
    numero = numero + incremento;

    usleep(300000); 
  }

  limpiarPantalla();
  explosion();
  printf("El avion ha crasheado.\n");
  if (!retiro) 
  {
    retirada = 0;
    printf("Perdiste.\n");
  } 
  else 
  {
    printf("Ganaste con un multiplicador de %.2f\n", retirada);
  }
  printf("Quieres seguir jugando? (s/n): ");
  char respuesta;
  do
  {
    scanf(" %c", &respuesta);
    if (respuesta == 's' || respuesta == 'S')
      crash();
    else if (respuesta == 'n' || respuesta == 'N')
      return;
    printf("Respuesta invalida. Ingrese su respuesta de nuevo: ");
  } while (respuesta != 's' && respuesta != 'S' && respuesta != 'n' && respuesta != 'N');
}

/*void reglasCrash()
{
  printf("¿Deseas leer las reglas? (s/n) \n");
  char respuesta;
  do
  {
    scanf(" %c", &respuesta);
    if (respuesta == 's' || respuesta == 'S')
    {
      printf("Reglas del juego:\n");
      printf("El juego consiste en un avión que se mueve mientras que
     }
    else if (respuesta == 'n' || respuesta == 'N')
      return;
    printf("Respuesta invalida. Ingrese su respuesta de nuevo: ");
  } while (respuesta != 's' && respuesta != 'S' && respuesta != 'n' && respuesta != 'N');
}*/