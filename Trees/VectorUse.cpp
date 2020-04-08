#include <iostream>
#include <vector>
using namespace std;

int main(){
    // vector<int> *vp = new vector<int>();        //Dynamic Allocation
    vector<int> V;
    V.push_back(10);
    cout << V.at(5);
    return 0;
}