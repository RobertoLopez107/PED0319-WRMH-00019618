#include <iostream>
#include <string>
using namespace std;

struct pavo{
    string nombre;
    int edad;
    float peso;
    char genero;
};

int pavosReproducir(pavo pavos[6]);

int main(void){
    pavo pavos[6];

    for(int i = 0; i < 6; i++){
        cout << "Nombre: "; cin >> pavos[i].nombre;
        cout << "Edad: "; cin >> pavos[i].edad;
        cout << "Peso: "; cin >> pavos[i].peso;
        cout << "Genero: "; cin >> pavos[i].genero;
    }

    cout << "Cantidad de pavos que se pueden reproducir: " << pavosReproducir(pavos) << endl;
    return 0;
}

int pavosReproducir(pavo pavos[6]){
    int aux = 0;
    for(int i = 0; i < 6; i++){
        if(pavos[i].genero == 'h' || pavos[i].genero == 'H')
            if(pavos[i].edad >= 2)
                aux++;
    }
    return aux;
}