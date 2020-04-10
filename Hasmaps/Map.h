template <typename V>
class mapNode{
    public: 
    string key;
    V value;
    mapNode* next;

    mapNode(string key, V value){
        this->key = key;
        this->value = value;
        this->next = NULL;
    }
    ~mapNode(){
        delete next;
    }
};

template <typename V>
class Map{
    mapNode<V>** buckets;       //Array of mapNode<V>* type
    int count;
    int numBuckets;
    int primeNum;
    public:
        Map(){
            count = 0;
            numBuckets = 5;
            buckets = new mapNode<V>*[numBuckets];
            for(int i=0; i<numBuckets; i++){
                buckets[i] = NULL;
            }
            primeNum = 37;
        }
        ~Map(){
            for (int i=0; i<numBuckets; i++){
                delete buckets[i];
            }
            delete [] buckets;
        }
    private: 
        int getBucketIndex(string key){
            int hashCode=0;
            int currentCoeffecient = 1;
            for(int i=key.length()-1; i>=0; i--){
                hashCode += key[i] * currentCoeffecient;
                hashCode = hashCode % numBuckets;  // (x*y*z) % r = ((x%r)*(y%r)*(z%r))%r
                currentCoeffecient *= primeNum;    
                currentCoeffecient = currentCoeffecient % numBuckets;
            }

            return hashCode % numBuckets;
        }
        void reHash(){
            mapNode<V>**temp = buckets;
            mapNode<V>**newBucketArray = new mapNode<V>*[numBuckets * 2];
            buckets = newBucketArray;
            int oldBucketCount = numBuckets;
            numBuckets *= 2;
            for (int i=0; i<numBuckets;i++){
                newBucketArray[i] = NULL;       //Emptying the new bucket array of garbage values
            }
            count = 0;
            for (int i=0; i<oldBucketCount; i++){
                mapNode<V>* head = temp[i];
                while(head!=NULL){
                    string key = head->key;
                    V value = head->value;
                    insert(key, value);
                    head = head->next;
                }
            }
            for(int i=0; i<oldBucketCount; i++){
                delete temp[i];
            }
            delete [] temp;
        }
    public:
        double getLoadFactor(){
            return (1.0*count)/numBuckets;
        }
        int size(){
            return count;
        }
        V getValue(string key){
            int bucketIndex = getBucketIndex(key);
            mapNode<V>* head = buckets[bucketIndex];
            while(head!=NULL){
                if (head->key == key){
                    return head->value;
                }
                head=head->next;
            }
            return 0;
        }
        void insert(string key, V value){
            int bucketIndex = getBucketIndex(key);
            mapNode<V>* head = buckets[bucketIndex];
            while (head!=NULL){
                if (head->key == key){
                    head->value = value;
                    return;
                }
                head = head->next;
            }
            mapNode<V>* newNode = new mapNode<V>(key, value);
            head = buckets[bucketIndex];
            newNode -> next = head;
            buckets[bucketIndex] = newNode;
            count++;
            double loadFactor = (1.0 * count)/numBuckets;           //Multiplied by 1.0 to make int/int into float/int to get a double as a result
            if (loadFactor > 0.7){
                reHash();
            }
        }
        V remove(string key){
            int bucketIndex = getBucketIndex(key);
            mapNode<V>* head = buckets[bucketIndex];
            mapNode<V>* prev = NULL;
            while(head!=NULL){
                if (head->key == key){
                    if (prev == NULL){
                        buckets[bucketIndex] = head->next;
                    } else {
                        prev->next = head->next;
                    }
                    V val = head->value;
                    head->next=NULL;        //So that head does not recursively delete all the next values
                    delete head;
                    count--;
                    return val;
                }
                prev = head;
                head=head->next;
            }
            return 0;
        }
};