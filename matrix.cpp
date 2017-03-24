#include <iostream>
#include <cmath>
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

void wait(unsigned int time)
{
    sleep(time);
}

int get_dimention(int pos)
{
    struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);
    int vec[2]= {w.ws_row,w.ws_col};
    return vec[pos];
}

void clear_Screen(){
  int i;
  for (i = 0; i < rows; i++) {
    cout<<endl;
  }

}


int main(int argc, char* argv[])
{
    srand(time(NULL));
    rows_param = atoi(argv[1]);
    columns_param = atoi(argv[2]);
    rows = get_dimention(0);
    columns = get_dimention(1);
    clear_Screen();
    int matrix_randomize[rows][columns];
    char matrix[rows][columns];


    //TODO estos for's se encargan de llenar matrices de unos y cesos, luego si tiene un 1 le asigna un caracter, si tiene un
    //cero le asigna un espacio
    // el TODO está puesto por dos motivos:
    //primero que me pareció no ser un método bonito para llenar la matrix_randomize y que quede bonita a la hora de imprimir
    //luego que los caracteres ascii por algun maldito motivo estan fallando

    for(int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; ++j)
        {
            matrix_randomize[i][j] = rand()%2;
        }
    }

    for(int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; ++j)
        {
            if (matrix_randomize[i][j] == 1)
            {
                matrix[i][j] = (rand() % 94 + 33);
            }
            else
            {
                matrix[i][j] = 32;
            }
        }
    }

    for(int i = 0; i < rows; i++)
    {
        wait(1);
        for (int j = 0; j < columns; ++j)
        {
            if (j == (columns - 1))
            {
                cout << "\n";
            }
            else
            {
                cout << matrix[i][j];
            }
        }
    }

    return 0;
}
