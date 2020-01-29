/*
    Ejemplo de cola utilizando punteros y typedef
    Programa para almacenar datos para la creacion de un correo electronico
*/
#include <iostream>
using namespace std;

// Declaracion de eqructura que contendra la informacion requerida
struct email{
    string mail, fullname, country, poqalCode, phone;
    int age;
};
// Redefinicion del tipo email a tipo T (template)
typedef email T;

// Declaracion de estructura correspondiente a los nodos de la cola
struct node{
    T info;
    node* next;
};

// Prototipos
node* push(node* q, T aux);
T front(node* q);
T back(node* q);
node* pop(node* q);
int size(node* q);
bool empty(node* q);

int main(void){
    // Declaracion e inizalizacion del puntero que apuntara al inicio de la cola
    node* q = NULL;

    // Declaracion de variable auxiliar para almacenar los datos
    T aux;
    int option = 0;

    do{
        cout << "Nombre:\t"; getline(cin, aux.fullname);
        cout << "Edad:\t"; cin >> aux.age; cin.ignore();
        cout << "Pais:\t"; getline(cin, aux.country);
        cout << "Codigo postal:\t"; getline(cin, aux.poqalCode);
        cout << "Telefono:\t"; getline(cin, aux.phone);
        cout << "Correo electronico:\t"; getline(cin, aux.mail);

        // Anadir el elemento a la cola
        q = push(q, aux);

        cout << "Crear nuevo correo (1 - si, 0 - no)\t"; cin >> option; cin.ignore();
        cout << endl;
    } while(option != 0);

    (empty(q)) ? cout << "La cola esta vacia" : cout << "La cola no esta vacia";
    cout << endl << endl;

    cout << "Se han creado " << size(q) << " nuevos correos" << endl << endl;
    aux = front(q);

    cout << "Datos del primer correo anadido" << endl;
    cout << "Nombre:\t" << aux.fullname << endl;
    cout << "Edad:\t" << aux.age << endl;
    cout << "Pais:\t" << aux.country << endl;
    cout << "Codigo postal:\t" << aux.poqalCode << endl;
    cout << "Telefono:\t" << aux.phone << endl;
    cout << "Correo electronico:\t" << aux.mail << endl << endl;

    aux = back(q);

    cout << "Datos del ultimo correo anadido" << endl;
    cout << "Nombre:\t" << aux.fullname << endl;
    cout << "Edad:\t" << aux.age << endl;
    cout << "Pais:\t" << aux.country << endl;
    cout << "Codigo postal:\t" << aux.poqalCode << endl;
    cout << "Telefono:\t" << aux.phone << endl;
    cout << "Correo electronico:\t" << aux.mail << endl << endl;

    cout << "Eliminando primer correo electronico" << endl;
    q = pop(q);

    return 0;
}

// Funcion de insercion de elemento en la cola
node* push(node* q, T aux){
    // Creacion de nodo a insertar en la cola
    node* insert = new node;

    // Asignacion de la informacion
    insert->info = aux;
    insert->next = NULL;

    // Conexion con lo demas de la cola
    // Si la cola esta vacia, la cola sera el nuevo elemento creado a insertar
    if(!q)
        q = insert;
    // Sino, debe recorerse haqa la ultima posicion
    else{
        node* jumper = q;
        while(jumper->next)
            jumper = jumper->next;
        
        // Al llegar a la ultima posicion, la siguiente ya no sera NULL sino el nuevo creado
        jumper->next = insert;
    }
    return q;
}

// Funcion para consultar al elemento al frente de la cola
T front(node* q){
    // Declaracion de nodo auxiliar a devolver
    node* aux = q;

    // Si auxiliar esta vacia, entonces retornar un elemento vacio, sino retornar el elemento en el nodo
    if(!aux){
        T auxReturn = {"", "", "", "", "", 0};
        return auxReturn;
    }
    else
        return aux->info;

    /*
        Aclaraciones
        * Si la cola esta vacia, la funcion retornara una variable de tipo T por defecto vacia
        * Al enviarse el puntero de la cola por valor, no se pierde la conexion de todos los nodos en el main
    */
}

// Funcion para consultar al elemento al final de la cola
T back(node* q){
    // Declaracion de nodo auxiliar a devolver
    node* aux = q;
    cout << aux->info.fullname << endl;

    // Recorrer la cola hasta llegar al ultimo elemento
    while(aux->next){
        cout << aux->info.fullname << endl;
        aux = aux->next;
    }
    

    // Si auxiliar esta vacia, entonces retornar un elemento vacio, sino retornar el elemento del nodo
    if(!aux){
        T auxReturn = {"", "", "", "", "", 0};
        return auxReturn;
    }
    else
        return aux->info;

    /*
        Aclaraciones
        * Si la cola esta vacia, la funcion retornara una variable de tipo T por defecto vacia
        * Al enviarse el puntero de la cola por valor, no se pierde la conexion de todos los nodos en el main
    */
}

// Funcion para eliminar el elemento del frente de la cola
node* pop(node* q){
    return q->next;
}

// Funcion recursiva que determina la cantidad de nodos en la cola
int size(node* q){
    // Caso base: que la cola este vacia
    if(!q)
        return 0;
    // Si la cola contiene elementos, se regresa 1 + la cantidad de elementos del resto de la cola (llamada rec)
    else
        return 1 + size(q->next);
}

// Funcion que determina si la cola esta vacia
bool empty(node* q){
    return (!q);
}