/*
    Ejemplo de cola utilizando libreria y typedef
    Programa para almacenar datos para la creacion de un correo electronico
*/
#include <iostream>
#include <queue>
using namespace std;


// Declaracion de estructura que contendra la informacion requerida
struct email{
    string mail, fullname, country, postalCode, phone;
    int age;
};
// Redefinicion del tipo email a tipo T (template)
typedef email T;

int main(void){
    // Declaracion de pila de tipo T (es decir que contendra elementos de tipo T)
    queue<T> q;
    
    // Declaracion de variable auxiliar para almacenar los datos
    T aux;
    int option = 0;

    do{
        cout << "Nombre:\t"; getline(cin, aux.fullname);
        cout << "Edad:\t"; cin >> aux.age; cin.ignore();
        cout << "Pais:\t"; getline(cin, aux.country);
        cout << "Codigo postal:\t"; getline(cin, aux.postalCode);
        cout << "Telefono:\t"; getline(cin, aux.phone);
        cout << "Correo electronico:\t"; getline(cin, aux.mail);

        // Anadir el elemento a la pila
        q.push(aux);

        cout << "Crear nuevo correo (1 - si, 0 - no)\t"; cin >> option; cin.ignore();
        cout << endl;
    } while(option != 0);
}