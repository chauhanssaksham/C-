#include <iostream>
using namespace std;

class Scooty{
    public:
        void print();
        void tint(){
            cout << "Hello ";
        }
};

class Bus{
    public:
        void print();
};

class Truck{
    private:
        int x;
    friend void Bus::print();
    friend void test();
    friend class Scooty;
};

void Scooty::print(){
            Truck t;
    t.x = 10;
    cout << t.x ;
}

void test(){
    Truck t;
    t.x = 10;
    cout <<t.x ;
}

void Bus::print(){
    Truck t;
    t.x = 10;
    cout << t.x;
}


int main(){
    Bus b;
    b.print();
    test();
    Scooty S;
    S.tint();
    return 0;
}