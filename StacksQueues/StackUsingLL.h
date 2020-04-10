template <typename T>
class Node{
    public:
    T data;
    Node<T> *next;
    Node(T data){
        this->data = data;
        this->next = NULL;
    }
};

template <typename T>
class Stack{
    private:
        Node<T> *head;
        int capacity;
    public:
        Stack(){
            this->head = NULL;
            this->capacity = 0;
        }
        Stack(T element){
            Stack<T>();
            this->push(element);
        }
        int size(){
            return capacity;
        }
        bool isEmpty(){
            return capacity == 0;
        }
        void push(T element){
            Node<T> *newNode = new Node<T>(element);
            newNode->next = head;
            this->head = newNode;
            capacity++;
        }
        T pop(){
            if (head == NULL){
                cout << "Stack underflow!" << endl;
                return 0;
            }
            Node<T> *current = head;
            this->head = head->next;
            capacity--;
            T toReturn = current->data;
            delete current;
            return toReturn;
        }
        T top(){
            if (head == NULL){
                cout << "Stack underflow!" << endl;
                return 0;
            }
            return this->head->data;
        }
};