#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sys/ioctl.h>
#include <unistd.h>
using namespace std;

//global variables
int rows_param;
int columns_param;
int rows;
int columns;

//functions used
void wait(int time);
int get_dimention(int pos);
void printScreen();
void clear_Screen();

int main(int argc, char* argv[])
{
    srand(time(NULL));
    rows_param = atoi(argv[1]);
    columns_param = atoi(argv[2]);
    rows = get_dimention(0);
    columns = get_dimention(1);
    clear_Screen();
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

void wait(int time)
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

void clear_Screen()
{
    system("clear");
}
