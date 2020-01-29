/*
    Ejemplo de pila utilizando punteros y typedef
    Programa para almacenar datos para la creacion de un correo electronico
*/
#include <iostream>
using namespace std;

// Declaracion de estructura que contendra la informacion requerida
struct email{
    string mail, fullname, country, postalCode, phone;
    int age;
};
// Redefinicion del tipo email a tipo T (template)
typedef email T;

// Declaracion de estructura correspondiente a los nodos de la pila
struct node{
    T info;
    node* next;
};

// Prototipos
node* push(node* st, T aux);
T top(node* st);
node* pop(node* st);
int size(node* st);
bool empty(node* st);

int main(void){
    // Declaracion e inizalizacion del puntero que apuntara al inicio de la pila
    node* st = NULL;

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
        st = push(st, aux);

        cout << "Crear nuevo correo (1 - si, 0 - no)\t"; cin >> option; cin.ignore();
        cout << endl;
    } while(option != 0);

    (empty(st)) ? cout << "La pila esta vacia" : cout << "La pila no esta vacia";

    cout << "Se han creado " << size(st) << " nuevos correos" << endl;
    aux = top(st);

    cout << "Datos del ultimo correo anadido" << endl;
    cout << "Nombre:\t" << aux.fullname << endl;
    cout << "Edad:\t" << aux.age << endl;
    cout << "Pais:\t" << aux.country << endl;
    cout << "Codigo postal:\t" << aux.postalCode << endl;
    cout << "Telefono:\t" << aux.phone << endl;
    cout << "Correo electronico:\t" << aux.mail << endl;

    cout << "Eliminando ultimo correo electronico" << endl;
    st = pop(st);

    return 0;
}

// Funcion de insercion de elemento en la pila
node* push(node* st, T aux){
    // Creacion de nodo a insertar en la pila
    node* insert = new node;

    // Asignacion de la informacion
    insert->info = aux;

    // Conexion con lo demas de la pila
    insert->next = st;
    st = insert;

    // Retorno de la lista modificada
    return st;
}

// Funcion para consultar al elemento de la cima de la pila
T top(node* st){
    // Declaracion de nodo auxiliar a devolver
    node* aux = st;

    // Desconexion de los demas nodos de la lista
    aux->next = NULL;

    // Si auxiliar esta vacia, entonces retornar un elemento vacio, sino retornar el elemento en el nodo
    if(!aux){
        T auxReturn = {"", "", "", "", "", 0};
        return auxReturn;
    }
    else
        return aux->info;

    /*
        Aclaraciones
        * Si la pila esta vacia, la funcion retornara una variable de tipo T por defecto vacia
        * Al enviarse el puntero de la lista por valor, no se pierde la conexion de todos los nodos en el main
    */
}

// Funcion para eliminar el elemento de la cima de la pila
node* pop(node* st){
    return st->next;
}

// Funcion recursiva que determina la cantidad de nodos en la pila
int size(node* st){
    // Caso base: que la pila este vacia
    if(!st)
        return 0;
    // Si la pila contiene elementos, se regresa 1 + la cantidad de elementos del resto de la pila (llamada rec)
    else
        return 1 + size(st->next);
}

// Funcion que determina si la pila esta vacia
bool empty(node* st){
    return (!st);
}