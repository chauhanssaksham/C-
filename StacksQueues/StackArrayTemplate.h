#include <climits>

template <typename T>
class StackUsingArray{        //Using Array
    T *data;
    int nextIndex;
    int capacity; //tells the toal size

    public:
        //Constructor
        StackUsingArray(int totalSize){ 
            data = new T[totalSize];
            nextIndex = 0;
            capacity = totalSize;
        }
        //Return the size
        int size(){
            return nextIndex;
        }
        //Check if stack is empty
        bool isEmpty(){
            return nextIndex == 0;
        }
        //Insert an Element
        void push(T element){
            if (nextIndex == capacity){
                cout << "Stack overflow;" << endl;
                return;
            }
            data[nextIndex] = element;
            nextIndex++;
        }
        T pop(){
            if (isEmpty()){
                cout << "Stack underflow" << endl;
                return INT_MIN;
            }
            nextIndex--;
            return data[nextIndex];
        }
        T top(){
            if (isEmpty()){
                cout << "Stack underflow" << endl;
                return INT_MIN;
            }
            return data[nextIndex-1];
        }
};