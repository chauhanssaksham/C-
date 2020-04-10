template <typename T>
class Node {
    public:
    T data;
    Node<T> *next;
    Node (T data){
        this->data = data;
        this->next = NULL;
    }
};

template <typename T>
class Queue{
    Node<T> *head;
    Node<T> *tail;
    int size;
    public:
    Queue(){
        head = NULL;
        tail = NULL;
        size = 0;
    }
    int getSize(){
        return size;
    }
    bool isEmpty(){
        return size == 0;
    }
    void enqueue(T element){
        Node<T> *newNode = new Node<T>(element);
        if (size == 0){
            head = newNode;
            tail = newNode;
            size++;
            return;
        }
        tail->next = newNode;
        tail = tail->next;
        size++;
    } 
    T dequeue(){
        if (size == 0){
            cout << "Queue is empty" << endl;
            return 0;
        }
        T ans = head->data;
        Node<T> *toDel = head;
        head = head->next;
        delete toDel;
        size--;
        if (size == 0){
            head = NULL;
            tail = NULL;
        }
        return ans;
    }
    T front(){
        if (size == 0){
            cout << "Queue is empty" << endl;
            return 0;
        }
        return head->data;
    }
};