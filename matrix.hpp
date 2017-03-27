#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sys/ioctl.h>
#include <unistd.h>
using namespace std;

/** En forma general, el presente código se encarga de imprimir en pantalla vectores con caracteres al
azar dando un efecto visual de caída como lluvia de dichos caracteres por la consola */


/**
*@param $rows - Parámetro que indica la cantidad de filas de la consola, sean calculadas por el programa o
introducidas por consola.
*@param $columns - Parámetro que indica la cantidad de columnas de la consola, sean calculadas por el programa
o introducidas por consola.
 */
//global variables
int rows = 0;
int columns = 0;
int validation = 0;

/**
*@brief Función que se encarga de calcular las dimensiones (filas, columnas) de la consola.
*En caso de no introducir las dimensiones de la consola al ejecutar el programa, esta función varía los parámetros
globales rows y columns con la cantidad total de filas y columnas de la consola, respectivamente.
*/

void get_dimention()
{
    validation = 0;
    struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);
    rows = w.ws_row;
    columns = w.ws_col;
}

void set_dimention(int a, int b) {
    validation = 1;
    rows = a;
    columns = b;
}

void wait(unsigned int time)
{
   usleep(time);
}

void printScreen() {
    int vector_randomize[columns];
    char vector[columns];
    int lagrima;

    for (int n = 0; n < 20; n++)
    {
        lagrima = (rand() % 10 + 6);
        for (int i = 0; i < columns; ++i)
        {
            vector_randomize[i] = rand()%46;
        }
        for (int k = 0; k < lagrima; ++k)
        {
            for (int j = 0; j < columns; ++j)
            {
                if (validation == 0)
                {
                    get_dimention();
                }
                if (vector_randomize[j] < (rand()%6+5))
                {
                    vector[j] = rand() % 94 + 33;
                }
                else
                {
                    vector[j] = 32;
                }
            }
            for (int j = 0; j < columns; ++j)
            {
                wait(700);
                cout << "\e[92m" << vector[j];
                if (j == (columns - 1))
                {
                    cout << "\n";
                }
            }
        }
    }
}

void moveScreen() {
    cout << "\r\r\r\r";
    for (int i = 0; i < columns*20; ++i)
    {
        cout << "\r";
        for (int j = 0; j < columns; ++j)
        {
            cout << " ";
        }
    }
}

void clearScreen()
{
    system("clear");
}
