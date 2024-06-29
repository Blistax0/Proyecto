#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>
#include "Crash.h"

int inputReceived = 0; // Para saber si se ha recibido un input del usuario
pthread_mutex_t inputMutex; // Mutex for thread synchronization

// Función para manejar el input
void *handleInput(void *arg) 
{
  while (1) 
  {
    // Comprueba si se ha recibido un input del usuario 
    char input;
    int bytesRead = read(STDIN_FILENO, &input, 1);
    if (bytesRead > 0) 
    {
      // Input recibido
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

  if (numeroAleatorio <= 45) 
    return 1;  // 45% de probabilidad 1 a 2,5
  
  if (numeroAleatorio <= 90) 
    return 2;  // 45% de probabilidad 2,5 a 5

  else if (numeroAleatorio <=92) 
    return 3;  // 2% de probabilidad 5,1 a 10

  else if (numeroAleatorio <= 93) 
    return 4;  // 1% de probabilidad 10,1 a 20

  else if (numeroAleatorio <= 94)
    return 5;  // 1% de probabilidad 20,1 a 30

  else if (numeroAleatorio <= 95)
    return 6;  // 1% de probabilidad 30,1 a 40

  else if (numeroAleatorio <= 96)
    return 7;  // 1% de probabilidad 40,1 a 50

  else if (numeroAleatorio <= 97)
    return 8;  // 1% de probabilidad 50,1 a 60

  else if (numeroAleatorio <= 98)
    return 9;  // 1% de probabilidad 60,1 a 70

  else if (numeroAleatorio <= 99)
    return 10;  // 1% de probabilidad 70,1 a 80

  else
    return 11;  // 1% de probabilidad 80,1 a 102
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
      numero = randomizar(100, 250);
      break;
    case 2:
      numero = randomizar(251, 500);
      break;

    case 3:
      numero = randomizar(501, 1000);
      break;

    case 4:
      numero = randomizar(1001, 2000);
      break;

    case 5:
      numero = randomizar(2001, 3000);
      break;

    case 6:
      numero = randomizar(3001, 4000);
      break;

    case 7:
      numero = randomizar(4001, 5000);
      break;

    case 8:
      numero = randomizar(5001, 6000);
      break;

    case 9:
      numero = randomizar(6001, 7000);
      break;

    case 10:
      numero = randomizar(7001, 8000);
      break;

    case 11:
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
void crash(int *saldo)
{
  srand(time(NULL)); // Inicializa la semilla del generador de números aleatorios
  float maximo = numeroMax(); // Máximo antes de la explosión
  float numero = 1.01; // Multiplicador
  float retirada = numero; // Monto a ganar
  int retiro = 0; // Si ya se retiró o no
  int cont = 1; // Contador para mostrar la animación
  int apuesta;

  printf("¡Bienvenido al juego de Crash!\n");
  printf("Tu saldo actual es: $%d\n", *saldo);
  printf("Ingresa la cantidad que deseas apostar: "); // Se le pide al usuario que ingrese la cantidad que desea apostar
  scanf("%d", &apuesta);
  getchar();
  if (apuesta > *saldo || apuesta <= 0)
  {
    printf("No tienes suficiente saldo para realizar esta apuesta.\n");
    printf("Presione cualquier tecla para salir del juego.\n");
    getchar();
    return;
  }
  *saldo -= apuesta; //Registra la apuesta
  printf("Iniciando juego...\n");
  usleep(2000000); //Espera 2 segundos

  pthread_mutex_init(&inputMutex, NULL);

  pthread_t inputThread;
  pthread_create(&inputThread, NULL, handleInput, NULL);
  
  // Muestra la animación del avión en la pantalla por primera vez
  limpiarPantalla();
  mostrarAvion(cont);
  printf("%20.2f\n", numero);

  while (numero <= maximo) 
  {
    // Actualiza la pantalla
    if (numero != 1.00 || retiro) 
    {
      limpiarPantalla();
      mostrarAvion(cont);
      if (cont > 9) cont = 1;
      printf("%20.2f\n", numero);
      if (retiro) printf("Ya retiraste.\n");
      cont++;
    }

    // Se revisa si el usuario pulsó un botón solo cuando este no ha retirado
    if (!retiro) 
    {
      pthread_mutex_lock(&inputMutex);
      if (inputReceived) 
      {
        retiro = 1;
        retirada = numero;
        inputReceived = 0;
      }
      pthread_mutex_unlock(&inputMutex);
    }

    // Genera un incremento aleatorio
    float incremento = randomizar(2, 6);
    numero = numero + incremento;
    
    usleep(300000); // Espera 0.3 segundos
  }

  // Muestra la explosión en la pantalla
  limpiarPantalla();
  explosion();
  printf("El avion ha crasheado.\n");
  if (!retiro) // Si el usuario no retiró a tiempo
  {
    retirada = 0;
    printf("Perdiste.\n");
  } 
  else // Si el usuario retiró a tiempo
  {
    printf("Ganaste con un multiplicador de %.2f\n", retirada);
  }
  *saldo = *saldo + (apuesta * retirada);
  printf("Tu saldo actual es: $%d\n", *saldo);

  //Se termina de comprobar si el usuario presiona una tecla
  pthread_cancel(inputThread); 
  pthread_join(inputThread, NULL);
  inputReceived = 0;
}

// Función para mostrar las reglas del crash
void reglasCrash()
{
  printf("Has elegido la opción 4: Crash\n");
  printf("¿Deseas leer las reglas? (s/n) ");
  char respuesta;
  do
  {
    scanf(" %c", &respuesta);
    getchar();
    if (respuesta == 's' || respuesta == 'S')
    {
      printf("Reglas del juego:\n");
      printf("El juego consiste en un avión que se mueve mientras que un multiplicador va aumentando. La idea es retirar el multiplicador antes de que el avión explote.\n");
      printf("Presione cualquier tecla para continuar.\n");
      getchar();
      return;
    }
    else if (respuesta == 'n' || respuesta == 'N')
      return;
    printf("Respuesta invalida. Ingrese su respuesta de nuevo: ");
  } while (respuesta != 's' && respuesta != 'S' && respuesta != 'n' && respuesta != 'N');
}