#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <sys/ioctl.h>
using namespace std;

void print_display(char characters[])
{
    cout << characters[rand()%sizeof(characters)] << endl;
}

int get_dimention(int pos)
{
    struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);
    int vec[2]= {w.ws_row,w.ws_col};
    return vec[pos];
}

void clear_Screen(int rows){
  int i;
  for (i = 0; i < rows; i++) {
    cout<<endl;
  }

}



int main(int argc, char* argv[])
{
    int rows_param = atoi(argv[1]);
    int columns_param = atoi(argv[2]);
    int rows = get_dimention(0);
    int columns = get_dimention(1);
    clear_Screen(rows);
    char characters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789,@;.:-_{}[]^`+*|°¬!#$%&/()='?¿¡";
    std::cout << "INFO LA LONGITUD DE characters ES:" << sizeof(characters) << "\n";
    char space[] = " ";
    int i, j;
    int matrix_randomize[rows][columns];
    char matrix[rows][columns];




    //TODO estos for's se encargan de llenar matrices de unos y cesos, luego si tiene un 1 le asigna un caracter, si tiene un
    //cero le asigna un espacio
    // el TODO está puesto por dos motivos:
    //primero que me pareció no ser un método bonito para llenar la matrix_randomize y que quede bonita a la hora de imprimir
    //luego que los caracteres ascii por algun maldito motivo estan fallando

    for(i = 0; i < rows; i++)
    {
        for (j = 0; j < columns; ++j)
        {
            matrix_randomize[i][j] = rand()%2;
        }
    }
    for(i = 0; i < rows; i++)
    {
        for (j = 0; j < columns; ++j)
        {
            if (j == (columns - 1))
            {
                cout << "\n";
            }
            else
            {
                cout << matrix_randomize[i][j];
            }
        }
    }
    for(i = 0; i < rows; i++)
    {
        for (j = 0; j < columns; ++j)
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
    for(i = 0; i < rows; i++)
    {
        for (j = 0; j < columns; ++j)
        {
            cout << matrix[i][j];
            if (j == (columns - 1))
            {
                cout << "\n";
            }
        }
    }
    //print_display(characters);
    return 0;
}
