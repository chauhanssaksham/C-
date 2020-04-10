#include <iostream>
using namespace std;
#include "Fraction.h"

int main(){
    Fraction f1(1,2);
    Fraction f2(1,4);
    f1 += (f1+=f2);
    f1.print();
    f2.print();
    return 0;
}