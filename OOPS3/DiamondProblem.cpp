#include <string>
#include <iostream>
using namespace std;

class Vehicle{
    private: 
        int maxSpeed;
    protected:
        int numTyres;
    public:
        void print(){
            cout << "Vehicle " << endl;
        }
};
class Car: virtual public Vehicle{
    public:
    int numGears;
    Car(){
        cout << "Car's constructor called " << endl;
    }
};
class Truck: virtual public Vehicle{
    public:
    Truck(){
        cout << "Truck's constructor called" << endl; 
    }
};
class Bus: public Car, public Truck{
    public:
        Bus(){
            cout << "Bus's constructor called" << endl;
        }
};


int main(){
    Bus B;

    return 0;
}