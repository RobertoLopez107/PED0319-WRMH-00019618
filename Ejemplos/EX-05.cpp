#include <iostream>
using namespace std;

// Estructura de la lista
struct node{
    int n;
    node* sig;
};

node* agregar(node* pInicio, int n);
node* insertarDesorden(node* pInicio, int n);
int buscarPosicion(node* pInicio, int n);
void imprimir(node* lista);


int main(void){
    // Puntero al inicio de la lista
    node* pInicio = NULL;
    
    // Agregando datos a la lista de manera ordenada
    pInicio = agregar(pInicio, 5);
    pInicio = agregar(pInicio, 9);
    pInicio = agregar(pInicio, 18);
    pInicio = agregar(pInicio, 21);

    // Agregando elementos a la lista desordenados
    pInicio = insertarDesorden(pInicio, 2);
    imprimir(pInicio); cout << endl << endl;
    pInicio = insertarDesorden(pInicio, 10);
    imprimir(pInicio); cout << endl << endl;
    pInicio = insertarDesorden(pInicio, 100);
    imprimir(pInicio); cout << endl << endl;
    pInicio = insertarDesorden(pInicio, 10);
    imprimir(pInicio); cout << endl << endl;
    pInicio = insertarDesorden(pInicio, 99);
    imprimir(pInicio); cout << endl << endl;

    return 0;
}

// Impresion recursiva de la lista
void imprimir(node* lista){
    if(lista){
        cout << lista->n << "\t";
        imprimir(lista->sig);
    }
}

// Agregar elementos a la lista (en forma de cola)
node* agregar(node* pInicio, int n){
    node* nuevo = new node;
    nuevo->n = n;
    nuevo->sig = NULL;

    if(!pInicio)
        pInicio = nuevo;
    else{
        node* aux = pInicio;
        
        while(aux->sig)
            aux = aux->sig;

        aux->sig = nuevo;
    }

    return pInicio;
}

// Busca la posicion en la cual debe insertarse el elemento en orden ascendente, devuelve el numero de la posicion
int buscarPosicion(node* pInicio, int n){
    node* aux = pInicio;
    int pos = 0;

    // Recorre la lista y aumenta el valor de pos si el numero acutal es menor, si es mayor no
    while(aux){
        if(n > aux->n)
            pos++;

        // Cambia de posicion en la lista
        aux = aux->sig;
    }
    return pos;
}

// Modifica y añade el elemento pasado por argumento en la lista
node* insertarDesorden(node* pInicio, int n){
    // Posicion en la que se inserta
    int pos = buscarPosicion(pInicio, n);

    // Creacion del nodo a insertar, asignando el numero en su campo de informacion
    node* nuevo = new node;
    nuevo->n = n;

    // Declaracion de nodos auxiliares, iran con diferencia de un nodo
    node* aux = pInicio;
    node* aux2 = pInicio;

    // Ciclo para llegar hasta la posicion en la que se debe insertar
    for(int i = 0; i < pos; i++){
        // En aux2 se guarda el nodo en pos - 1, y en aux el nodo en pos
        aux2 = aux;
        aux = aux->sig;
    }

    // Si el nodo a insertar debe estar al inicio de la lista
    if(pos == 0){
        // El enlace del nuevo nodo a insertar apunta a aux, aux contiene la lista entera
        nuevo->sig = aux;

        // Se hace que aux ahora apunte a nuevo, ya que contiene el nuevo nodo + la lista completa
        aux = nuevo;

        // Se iguala pInicio con aux para que pInicio siempre apunte al inicio de la lista
        pInicio = aux;
    }
    // Si el nodo a insertar debe estar entre dos nodos, o al final de la lista
    else{
        // aux2 al ser el nodo anterior a la posicion donde se debe insertar, su siguiente corresponde al nuevo
        aux2->sig = nuevo;

        // El siguiente del nuevo nodo sera lo restante de la lista, almacenado en aux
        nuevo->sig = aux;
    }

    // Se retorna pInicio para que se almacene la modificacion de la lista
    return pInicio;
}