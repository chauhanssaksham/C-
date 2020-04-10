#include <iostream>
using namespace std;
#include "DynamicArray.h"

int main(){
    DynamicArray<int> array;
    array.add(10);
    array.add(20);
    array.add(30);
    array.add(40);
    array.add(50);
    DynamicArray<int> D2;
    D2 = array;
    array.add(0, 100);
    array.print();
    D2.print();
    return 0;
}