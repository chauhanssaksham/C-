template <typename T>
class Queue{
    T *data;
    int nextIndex;
    int firstIndex;
    int size;
    int capacity;
    public:
    Queue(int totalSize){
        data = new T[totalSize];
        nextIndex = 0;
        firstIndex = -1;
        size = 0;
        capacity = totalSize;
    }
    int getSize(){
        return size;
    }   
    bool isEmpty(){
        return size==0;
    }
    void enqueue(T element){
        if (size == capacity){
            cout << "Queue is full" << endl;
            return;
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