template <typename T>
class Queue{
    T *data;
    int nextIndex;
    int firstIndex;
    int size;
    int capacity;
    public:
    Queue(){
        data = new T[5];
        nextIndex = 0;
        firstIndex = -1;
        size = 0;
        capacity = 5;
    }
    int getSize(){
        return size;
    }   
    bool isEmpty(){
        return size==0;
    }
    void enqueue(T element){
        if (size == capacity){
            T *newData = new T[capacity * 2];
            int i=0;
            for (int x=firstIndex; x<capacity; x++, i++){
                newData[i] = data[x];
            }
            for (int x=0; x<firstIndex; x++){
                newData[i] = data[x];
            }
            firstIndex = 0;
            nextIndex = capacity;
            delete [] data;
            data = newData;
            capacity *= 2;
        }
        data[nextIndex] = element;
        nextIndex = (nextIndex + 1)%capacity;
        if (firstIndex == -1){
            firstIndex++;
        }
        size++;
    }
    T front(){
        if (size == 0){
            cout << "Queue is empty" << endl;
            return 0;
        }
        return data[firstIndex];
    }
    T dequeue(){
        if (size == 0){
            cout << "Queue is empty" << endl;
            return 0;
        }
        T ans = data[firstIndex];
        firstIndex = (firstIndex + 1)%capacity;
        size--;
        if (size == 0){
            firstIndex = -1;
            nextIndex = 0;
        }
        return ans;
    }
};