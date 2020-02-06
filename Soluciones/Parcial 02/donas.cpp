#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;

enum tipo {dona, platoFuerte};

const float preciosDonas[] = {1, 1.25, 1.50, 1.75};
const float preciosPlatos[] = {2.5, 5, 3.50};

struct pedido{
    string nombre;
    tipo tipoP;
    float precio;
};
typedef pedido T;

struct cliente{
    string apellido;
    vector<T> pedidos;
    float monto;
};
typedef cliente C;

void imprimirMenu(void);

int main(void){
    int opcion = 0;
    queue<C> donas;
    queue<C> platos;

    do{
        imprimirMenu(); cin >> opcion; cin.ignore();

        switch (opcion){
            
        }

    } while(opcion != 0);

    return 0;
}

void imprimirMenu(void){
    cout << "1.\t Atender cliente" << endl;
    cout << "2.\t Calcular ganancias en donas" << endl;
    cout << "3.\t Calcular ganancias en plato fuerte" << endl;
    cout << "0.\t Salir" << endl;
    cout << "Su opcion:\t";
}

void agregarOrden(){
    int opcion = 0, opcion2 = 0;
    C antendiendo;
    T aux;

    cout << "Apellido:\t"; cin >> antendiendo.apellido;

    do{
        cout << "1.\tDona" << endl;
        cout << "2.\tPlato fuerte" << endl;
        cout << "0. Salir" << endl;
        cout << "Su opcion:\t";

        switch(opcion){
            case 1:
                cout << "1.\tDona sencilla de azucar $1.00" << endl;
                cout << "2.\tDona sencilla de chocolate $1.25" << endl;
                cout << "3.\tDona rellena de coco $1.50" << endl;
                cout << "4.\tDona rellena de moca $1.75" << endl;
                cin >> opcion2; cin.ignore();
                aux.precio = preciosDonas[opcion2 - 1];
                aux.tipoP = dona;

                switch(opcion2){
                    case 1:
                        aux.nombre = "Dona sencilla de azucar";
                    break;
                    case 2:
                        aux.nombre = "Dona sencilla de chocolate";
                    break;
                    case 3:
                        aux.nombre = "Dona rellena de coco";
                    break;
                    case 4:
                        aux.nombre = "Dona rellena de moca";
                    break;
                }

                antendiendo.pedidos.push_back(aux);

            break;
            case 2:
                cout << "1.\tDesayuno $2.00" << endl;
                cout << "2.\tAlmuerzo $5.00" << endl;
                cout << "3.\tCena $3.50" << endl;
                cin >> opcion2; cin.ignore();
                aux.precio = preciosPlatos[opcion2 - 1];
                aux.tipoP = platoFuerte;

                switch(opcion2){
                    case 1:
                        aux.nombre = "Desayuno";
                    break;
                    case 2:
                        aux.nombre = "Almuerzo";
                    break;
                    case 3:
                        aux.nombre = "Cena";
                    break;
                }

                antendiendo.pedidos.push_back(aux);

            break;
            case 0:
                if(antendiendo.pedidos.empty()){
                    opcion = 999;
                    cout << "Aun no ha ordenado nada" << endl;
                }
            break;
        }
    } while(opcion != 0);
}