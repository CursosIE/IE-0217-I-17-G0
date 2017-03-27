#include "matrix.hpp"
int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        get_dimention();
    }
    else
    {
        rows = atoi(argv[1]);
        columns = atoi(argv[2]);
        set_dimention(rows, columns);
    }
    srand(time(NULL));
    clearScreen();
    printScreen();
    wait(900);
    moveScreen();
    return 0;
}
