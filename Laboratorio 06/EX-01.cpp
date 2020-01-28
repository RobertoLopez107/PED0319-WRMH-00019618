#include <iostream>
#include <queue>
using namespace std;

struct elements{
    int number;
    char letter;
};
typedef elements T;

int main(void){
    T aux;
    queue<T> q;

    aux.letter = 'a'; aux.number = 1; q.push(aux);
    aux.letter = 'b'; aux.number = 2; q.push(aux);
    aux.letter = 'c'; aux.number = 3; q.push(aux);

    cout << q.size() << endl;
    cout << q.empty() << endl;

    while(!q.empty()){
        aux = q.front();
        cout << aux.letter << "\t" << aux.number << endl;
        aux = q.back();
        cout << aux.letter << "\t" << aux.number << endl;
        
        q.pop();
    }

    return 0;
}