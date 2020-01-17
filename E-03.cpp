// Falto aclarar, la funcion de este ejercicio debe ser recursiva
#include <iostream>
#include <string>
using namespace std;

void printReverse(string word, int pos);

int main(void){
    string word;
    cout << "Palabra: "; cin >> word;
    cout << "Palabra revertida: ";
    printReverse(word, 0);
    cout << endl;
    
    return 0;
}

void printReverse(string word, int pos){
    if(pos == word.length())
        return;
    else{
        printReverse(word, pos + 1);
        cout << word[pos];
    }
}