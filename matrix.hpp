#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sys/ioctl.h>
#include <unistd.h>
using namespace std;

//global variables
int rows;
int columns;

void get_dimention()
{
    struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);
    rows = w.ws_row;
    columns = w.ws_col;
}

void set_dimention(int a, int b) {
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
                get_dimention();
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
    wait(1200);
    cout << "\r\r\r\r";
    for (int i = 0; i < columns*20; ++i)
    {
        cout << "\r";
        for (int j = 0; j < columns; ++j)
        {
            cout << " ";
        }
        wait(1200);
    }
}

void clearScreen()
{
    system("clear");
}
