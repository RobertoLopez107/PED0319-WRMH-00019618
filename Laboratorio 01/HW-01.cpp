#include <iostream>
using namespace std;

bool isPrime(int n){
    
}

int addPrimes(void){
    int sum = 0;
    for(int i = 2; i <= 100; i++){
        if(isPrime(i) == true)
            sum += i;
    }

    return sum;
}