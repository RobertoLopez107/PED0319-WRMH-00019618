#include <iostream>
#include <string>
using namespace std;

void jerigonzaP(string word, int size, int pos);

int main(void){
    string word = "";
    cout << "Palabra: "; 
    getline(cin, word);

    jerigonzaP(word, word.length(), 0);

    return 0;
}

void jerigonzaP(string word, int size, int pos){
    if(size == pos)
        return;
    else {
        if(word[pos] == 'a' || word[pos] == 'A' ||
        word[pos] == 'e' || word[pos] == 'E' ||
        word[pos] == 'i' || word[pos] == 'I' ||
        word[pos] == 'o' || word[pos] == 'O' ||
        word[pos] == 'u' || word[pos] == 'U'){
            cout << word[pos] << "p" << word[pos];
        }
        else
            cout << word[pos];

        jerigonzaP(word, size, pos + 1);
    }
}