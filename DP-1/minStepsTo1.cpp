#include <iostream>
#include <climits>
using namespace std;

int countStepsTo1(int n){
    int c = countStepsTo1(n-1);
    if (n % 6 == 0){
        int a = countStepsTo1(n/3);
        int b = countStepsTo1(n/2);
        return 1 + min(a, min(b, c));
    }
    else if (n % 3 == 0){
        int a = countStepsTo1(n/3);
        return 1 + min(a, c);
    } else if (n % 2 == 0){
        int b = countStepsTo1(n/2);
        return 1 + min(b,c);
    }
        return 1 + c;
}

int main(){

    return 0;
}