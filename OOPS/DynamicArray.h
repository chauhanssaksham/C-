template <typename T>
class DynamicArray{
    T *data;
    int nextIndex;
    int capacity;
  public:

    DynamicArray(){
        data = new T[5];
        nextIndex =0;
        capacity=5;
    }

    DynamicArray(DynamicArray const  &D){
        // this->data = D.data;  SHALLOW COPY
        //DEEP COPY
        this->data = new T[D.capacity];
        for(int i=0; i<D.nextIndex; i++){
            this->data[i] = D.data[i];
        }
        this->nextIndex = D.nextIndex;
        this->capacity = D.capacity;
    }

    void add(T element){
        if (nextIndex == capacity){
            T *newData = new T[capacity*2];
            for(int i=0; i<capacity; i++){
                newData[i] = data[i];
            }
            delete data;
            data = newData;
            capacity*=2;
        }
        data[nextIndex] = element;
        nextIndex++;
    }

    //Copy assignment operator
    void operator=(DynamicArray const &D){
        // this->data = D.data;  SHALLOW COPY
        //DEEP COPY
        this->data = new T[D.capacity];
        for(int i=0; i<D.nextIndex; i++){
            this->data[i] = D.data[i];
        }
        this->nextIndex = D.nextIndex;
        this->capacity = D.capacity;
    }

    T at(int index) const{
        if (index >= nextIndex){
            cout << "Bad request" << endl;
            return 0;
        }
        return data[index];
    }

    void add(int i, T element){
        if (i < nextIndex){
            data[i] = element;
        } else if (i==nextIndex){
            add(element);
        } else {
            cout << "Bad request" << endl;
            return;
        }
    }

    void print() const{
        cout << "Array: " << endl;
        for (int i=0; i<nextIndex; i++){
            cout << data[i] << " ";
        }
        cout << endl;
    }
};