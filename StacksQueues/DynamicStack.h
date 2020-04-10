#include <climits>
template <typename T>
class DynamicStack{        //Using Array
    T *data;
    int nextIndex;
    int capacity; //tells the toal size

    public:
        //Constructor
        DynamicStack(){ 
            data = new T[4];
            nextIndex = 0;
            capacity = 4;
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
                T *newData = new T[capacity*2];
                for(int i=0; i<capacity; i++){
                    newData[i] = data[i];
                }
                delete [] data;
                data = newData;
                capacity *= 2;
            }
            data[nextIndex] = element;
            nextIndex++;
        }
        T pop(){
            if (isEmpty()){
                cout << "Stack underflow" << endl;
                return 0;
            }
            nextIndex--;
            return data[nextIndex];
        }
        T top(){
            if (isEmpty()){
                cout << "Stack underflow" << endl;
                return 0;
            }
            return data[nextIndex-1];
        }
};