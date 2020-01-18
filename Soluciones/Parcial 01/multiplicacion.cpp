#include <iostream>
using namespace std;

int multiplicacion(int a, int b);

int main(void){
    int a = 0, b = 0;

    cout << "Digite a y b: "; cin >> a >> b;

    if(a <= 0 || b <= 0){
        cout << "Error en datos ingresados" << endl;
        return 0;
    }

    cout << multiplicacion(a, b) << endl;

    return 0;
}

// Obligatoriamente de tipo int ya que el valor debe ser devuelto, no impreso
int multiplicacion(int a, int b){
    if(b == 1)
        return a;
    else
        return a + multiplicacion(a, b - 1);
}