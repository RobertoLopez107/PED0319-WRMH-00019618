#include <iostream>
using namespace std;

struct node{
    int number;
    node* next;
};

int main(void){
    node* pStart = NULL;
    pStart = addStack(pStart, 8);
    pStart = addStack(pStart, 5);
    pStart = addStack(pStart, 10);
    // addStack(&pStart, 9);
}

node* addStack(node* list, int n){
    node* newNode = new node;
    newNode->number = n;

    newNode->next = list;
    list = newNode;

    return list;
}

node* addQueue(node* list, int n){
    node* newNode = new node;
    newNode->number = n;

    if(!list)
        list = newNode;
    else{
        node* aux = list;

        while(!aux->next)
            aux = aux->next;
        
        aux->next = newNode;
    }
    
    return list;
}

void printElements(node* list){
    if(!list)
        return;
    else{
        cout << list->number << endl;
        printElements(list->next);
    }
}

int countNumbers(node* list, int n){
    if(!list)
        return 0;
    else{
        if(list->number == n)
            return 1 + countNumbers(list->next, n);
        else
            return 0 + countNumbers(list->next, n);
    }
}

void addStack(node** list, int n){
    node* newNode = new node;
    newNode->number = n;

    (*(*list)).number;
    (*(*list)).next;
    &(*(*list)).next;

    newNode->next = *list;
    *list = newNode;
}