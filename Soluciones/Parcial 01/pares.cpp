#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

void nulificarPares(int* array, int size);
void imprimirArreglo(int* array, int size);

int main(void){
    int size = 0, *array; 

    do{
        cout << "Tamano arreglo: "; cin >> size;
    } while(size < 2);

    array = new int[size];

    for(int i = 0; i < size; i++){
        array[i] = rand() % 100 + 1;    
        // Numeros aleatorios entre 1 y 100 para evitar valores demasiado grandes,
        // no era necesario limitar los numeros
    }
    
    // Imprimiendo antes de nulificar (opcional)
    imprimirArreglo(array, size);
    // Nulificando pares
    nulificarPares(array, size);
    // Imprimiendo despues de nulificar
    imprimirArreglo(array, size);

    return 0;
}

void nulificarPares(int* array, int size){
    for(int i = 0; i < size; i++){
        if(array[i] % 2 == 0)
            array[i] = 0;
    }
}

// Opcional: funcion para imprimir arreglo y hacer mas ordenado el codigo
void imprimirArreglo(int* array, int size){
    for(int i = 0; i < size; i++){
        cout << array[i] << endl;
    }
    cout << endl;
}