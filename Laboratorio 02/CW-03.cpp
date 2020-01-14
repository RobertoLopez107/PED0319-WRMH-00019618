#include <iostream>
using namespace std;

void printLetters(char* printArray, int size);

int main(void){
    int size = 0;

    cout << "Digite la cantidad de letras: "; cin >> size;

    char* array;
    array = new char[size];

    for(int i = 0; i < size; i++){
        cout << "Digite letra: "; cin >> array[i];
        // cout << "Digite letra: "; cin >> *(array + i);
    }

    printLetters(array, size);
    
    return 0;
}


void printLetters(char* printArray, int size){
    for(int i = 0; i < size; i++){
        cout << "Letra: " << printArray[i] << endl;
    }
}