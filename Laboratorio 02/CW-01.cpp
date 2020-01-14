#include <iostream>
using namespace std;

int main(void){
    float array[3];

    for(int i = 0; i < 3; i++){
        cout << "Digite nota: "; cin >> array[i];
    }

    for(int i = 0; i < 3; i++){
        cout << "Nota " << (i + 1) << ":\t" << array[i] << "\n";
    }

    return 0;
}