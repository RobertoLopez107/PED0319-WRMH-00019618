#include <iostream>
#include <string>
using namespace std;

struct pedido{
    string remitente, destinatario;
    char tipo, modalidad;
    float peso;
};

void calcularTotal1(pedido array[5]);
float calcularTotal2(pedido array[5]);

int main(void){
    pedido array[5];

    for(int i = 0; i < 5; i++){
        cout << "Remitente: "; getline(cin, array[i].remitente);
        cout << "Destinatario: "; getline(cin, array[i].destinatario);
        cout << "Tipo: "; cin >> array[i].tipo;

        do{
            cout << "Peso: "; cin >> array[i].peso;
        } while(array[i].peso <= 0);
        
        cout << "Modalidad: "; cin >> array[i].modalidad;
        cin.ignore();
    }

    // Usando la primera funcion
    calcularTotal1(array);
    // Usando la segunda funcion
    cout << "El total es de: $" << calcularTotal2(array) << endl;

    // Mensaje de despedida obligatorio
    cout << "Gracias por usar nuestro sistema, vuelva pronto!" << endl;

    return 0;
}

// Para realizar la funcion pudieron haber sido dos maneras
// Primera manera: una funcion que solamente imprimiera el resultado
void calcularTotal1(pedido array[5]){
    float total = 0;

    for(int i = 0; i < 5; i++){
        if(array[i].tipo == 'C'){
            // Tambien se podria usar if
            switch(array[i].modalidad){
                case 'U':
                    total += 3;
                    break;
                case 'N':
                    total += 1;
                    break;
                case 'I':
                    total += 2;
                    break;
            }
        }
        else{
            // Tambien se podria usar switch
            if(array[i].modalidad == 'U'){
                if(array[i].peso <= 500)
                    total += 10;
                else
                    total += 15;
            }
            else if(array[i].modalidad == 'N')
                total += 5;
            else{
                if(array[i].peso <= 100)
                    total += 5;
                else
                    total += 10;
            }
        }
    }

    cout << "El total es: $" << total << endl;
}

// Segunda manera: haciendo que la funcion retorne el valor del total
float calcularTotal2(pedido array[5]){
    float total = 0;

    for(int i = 0; i < 5; i++){
        if(array[i].tipo == 'C'){
            // Tambien se podria usar if
            switch(array[i].modalidad){
                case 'U':
                    total += 3;
                    break;
                case 'N':
                    total += 1;
                    break;
                case 'I':
                    total += 2;
                    break;
            }
        }
        else{
            // Tambien se podria usar switch
            if(array[i].modalidad == 'U'){
                if(array[i].peso <= 500)
                    total += 10;
                else
                    total += 15;
            }
            else if(array[i].modalidad == 'N')
                total += 5;
            else{
                if(array[i].peso <= 100)
                    total += 5;
                else
                    total += 10;
            }
        }
    }

    return total;
}