#include <iostream>
using namespace std;

void reverseArray(int* A, int* B, int size, int aux1, int aux2);
void printArray(int* array, int size);

int main(void){
    int size = 0;
    int *arrayA, *arrayB;

    cout << "Tamano: "; cin >> size;
    arrayA = new int[size];
    arrayB = new int[size];

    for(int i = 0; i < size; i++){
        cout << "Num: "; cin >> arrayA[i];
    }

    printArray(arrayA, size);
    reverseArray(arrayA, arrayB, size, size - 1, 0);
    printArray(arrayB, size);

    return 0;
}

void printArray(int* array, int size){
    for(int i = 0; i < size; i++){
        cout << array[i] << endl;
    }
    cout << endl;
}

void reverseArray(int* A, int* B, int size, int aux1, int aux2){
    if(aux2 == size)
        return;
    else{
        B[aux2] = A[aux1];
        reverseArray(A, B, size, aux1 - 1, aux2 + 1);
    }
}