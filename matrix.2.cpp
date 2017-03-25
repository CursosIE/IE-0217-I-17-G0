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
    //clear_Screen();

    int vector_randomize[columns];
    char vector[columns];
    int lagrima = 12;
    int velocidad = 1000;

    for (int i = 0; i < columns; ++i)
    {
        vector_randomize[i] = rand()%16;
    }
    for (int k = 0; k < lagrima; ++k)
    {
        for (int j = 0; j < columns; ++j)
        {
            if (vector_randomize[j] < 1)
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
<<<<<<< HEAD
            wait(100000);
=======
            wait(velocidad);
>>>>>>> c533d579ca9f5979f042597dcac61527214c600c
            cout <<  vector[j];
            if (j == (columns - 1))
            {
                cout << "\n";
            }
        }
    }


    return 0;
}
