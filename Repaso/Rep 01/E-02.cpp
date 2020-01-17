#include <iostream>
#include <string>
using namespace std;

struct car{
    char plate[9];
    string color, brand, type;
    float price;
};

int main(void){
    car dCar;

    cout << "Placa: ";
    for(int i = 0; i < 9; i++){
        cin >> dCar.plate[i];
    }
    cout << "Color: "; cin >> dCar.color;
    cout << "Marca: "; cin >> dCar.brand;
    cout << "Tipo: "; cin >> dCar.type;
    cout << "Precio: "; cin >> dCar.price;

    return 0;
}