#include <iostream>
using namespace std;
#include "QueueUsingLL.h"

int main(){
    Queue<int> Q;
    Q.enqueue(10);
    Q.enqueue(20);
    Q.enqueue(30);
    Q.enqueue(40);
    Q.enqueue(50);
    Q.enqueue(60);
    cout << Q.front() << endl;
    cout << Q.dequeue() << endl;
    cout << Q.dequeue() << endl;
    cout << Q.dequeue() << endl;
    cout << Q.getSize() << endl;

    return 0;
}