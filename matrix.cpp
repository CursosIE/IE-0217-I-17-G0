#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;

void print_display(char characters[]) {
    cout << characters[rand()%sizeof(characters)] << endl;
}

int main(int argc, char* argv[])
{
    char characters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890|°¬!'?¿¡+*{[]}^`-.,;:_";
    print_display(characters);
    return 0;
}
