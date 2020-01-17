#include <iostream>
using namespace std;

void print(int n, int limit);

int main(void){
    int num = 0;
    cin >> num;

    print(1, num);

    return 0;
}

void print(int n, int limit){
    if(n == limit)
        cout << limit << endl;
    else{
        cout << n << endl;
        print(n + 1, limit);
        cout << n << endl;
    }
}