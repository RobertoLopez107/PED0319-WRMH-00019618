#include <iostream>
using namespace std;

struct node{
    int num;
    node* next;
};

int buscarPosicion(node* lista, int n);
void imprimirLista(node* lista);
node* insertarOrdenado(node* lista, int n);

int main(void){
    node* lista = NULL;
    lista = insertarOrdenado(lista, 2);
    lista = insertarOrdenado(lista, 8);
    lista = insertarOrdenado(lista, 1);
    lista = insertarOrdenado(lista, 15);

    imprimirLista(lista);

    return 0;
}

int buscarPosicion(node* lista, int n){
    int pos = 0;
    node* aux = lista;

    while(aux){
        if(n > aux->num)
            pos++;
        
        aux = aux->next;
    }
    return pos;
}

void imprimirLista(node* lista){
    if(lista){
        cout << lista->num << "\t";
        imprimirLista(lista->next);
    }
}

node* insertarOrdenado(node* lista, int n){
    node* nuevo = new node;
    nuevo->num = n;

    node* posterior = lista;
    node* anterior = NULL;

    int pos = buscarPosicion(lista, n);

    for(int i = 0; i < pos; i++){
        anterior = posterior;
        posterior = posterior->next;
    }

    if(pos == 0){
        nuevo->next = posterior;
        posterior = nuevo;
        lista = posterior;
    }
    else{
        nuevo->next = posterior;
        anterior->next = nuevo;
    }

    return lista;
}