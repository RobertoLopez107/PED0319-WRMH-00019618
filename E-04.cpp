#include <iostream>
using namespace std;

void modifyValue(int* aux);

int main(void){
    int a = 5, *b;
    b = &a;

    modifyValue(b);
    cout << "Nuevo valor: " << *b << endl;

    return 0;
}

void modifyValue(int* aux){
    *aux = 10;
}