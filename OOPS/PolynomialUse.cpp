#include <iostream>
using namespace std;
#include "Polynomial.h"

int main(){
    Polynomial P, Q, T;
    P.setCoefficient(0, 1);
    P.setCoefficient(1, 1);
    P.setCoefficient(2, 1);
    Q.setCoefficient(1, 1);
    Q.setCoefficient(0, -1);
    T = P*Q;
    P.print();
    Q.print();
    T.print();
    return 0;
}