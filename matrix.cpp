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

int get_dimention(int pos,)
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
    int rows = get_dimention(0);
    int colums = get_dimention(1);
    char characters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890|°¬!'?¿¡+*{[]}^`-.,;:_";
    print_display(characters);
    return 0;
}
