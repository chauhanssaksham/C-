#include <iostream>
using namespace std;
#include "StackUsingLL.h"

int main(){
    Stack<char> S;
    S.push(100);
    S.push(102);
    cout << S.pop() << " " << S.pop() << endl;
    
    return 0;
}