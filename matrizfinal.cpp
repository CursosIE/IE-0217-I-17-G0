#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sys/ioctl.h>
#include <unistd.h>
using namespace std;

//global variables
int rows;
int columns;

//functions used
void wait(unsigned int time);
int get_dimention(int pos);
void printScreen();
void clearScreen();
void moveScreen();

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        rows = get_dimention(0);
        columns = get_dimention(1);
    }
    else
    {
        rows = atoi(argv[1]);
        columns = atoi(argv[2]);
    }
    srand(time(NULL));
    clearScreen();
    printScreen();
    return 0;
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
                rows = get_dimention(0);
                columns = get_dimention(1);
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

void wait(unsigned int time)
{
   usleep(time);
}

int get_dimention(int pos)
{
    struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);
    int vec[2]= {w.ws_row,w.ws_col};
    return vec[pos];
}

void clearScreen()
{
    system("clear");
}
