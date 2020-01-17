#include <iostream>
using namespace std;

long long int ackermann(int n, int m);

int main(void){
    cout << ackermann(0, 0) << endl;
}

long long int ackermann(int n, int m){
    if(m == 0)
        return n + 1;
    else if(m > 0){
        if(n == 0)
            return ackermann(m - 1, 1);
        else if(n > 0)
            return ackermann(m - 1, ackermann(m, n - 1));
    }
}