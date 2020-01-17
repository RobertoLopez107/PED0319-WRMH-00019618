#include <iostream>
#include <string>
using namespace std;

struct employee{
    string name;
    float salary;
    int age, workingYears;
    char gender;
};

if(gender == 'F' || gender =='f'){
    if(workingYears >= 25 && age >= 60)
        return true;
    else
        return false;
}
else{
    if(workingYears >= 25 && age >= 65)
        return true;
    else
        return false;
}