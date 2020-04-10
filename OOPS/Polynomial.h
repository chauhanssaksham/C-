class Polynomial {
    int *degCoeff;      // Name of your array (Don't change this)
    int capacity;

  public:
    //Constructor
    Polynomial(){
        degCoeff = new int[5];
        capacity = 5;
        for(int i=0; i<5; i++){
            degCoeff[i] = 0;
        }
    }
    //Copy Constructor
    Polynomial(Polynomial const &P){
        capacity = P.capacity;
        degCoeff = new int[capacity];
        for(int i=0; i<capacity; i++){
            degCoeff[i] = P.degCoeff[i];
        }
    }
    //Copy assignment operator
    void operator=(Polynomial const &P){
        capacity = P.capacity;
        degCoeff = new int[capacity];
        for(int i=0; i<capacity; i++){
            degCoeff[i] = P.degCoeff[i];
        }
    }
    //setCoefficient
    void setCoefficient(int deg, int coeff){
        if (deg >= capacity){
            int *newDegCoeff = new int[deg+1];
            for (int i=0; i<capacity; i++){
                newDegCoeff[i] = degCoeff[i];
            }
            for(int i=capacity; i<deg; i++){
                newDegCoeff[i] = 0;
            }
            newDegCoeff[deg] = coeff;
            delete degCoeff;
            degCoeff = newDegCoeff;
            capacity = deg+1;
        } else {
            degCoeff[deg] = coeff;
        }
    }
    // +
    Polynomial operator+(Polynomial const &P) const {
        Polynomial Q;
        int x = min(capacity, P.capacity);
        for (int i=0; i<x; i++){
            Q.setCoefficient(i, degCoeff[i] + P.degCoeff[i]);
        }
        if (x==capacity){
            //this array is smaller
            for (int i=x; i<P.capacity; i++){
                Q.setCoefficient(i, P.degCoeff[i]);
            }
        } else {
            //P ka array is smaller
            for (int i=x; i<capacity; i++){
                Q.setCoefficient(i, degCoeff[i]);
            }
        }
        return Q;
    }
    // - (Unary)
    Polynomial operator-() const {
        Polynomial Q;
        for (int i=0; i<capacity; i++){
            Q.setCoefficient(i, -(degCoeff[i]));
        }
        return Q;
    }
    // - (Binary)
    Polynomial operator-(Polynomial const &P) const{
        Polynomial Q= -P;
        Q = (*this) + Q;
        return Q;
    }
    // *
    Polynomial operator*(Polynomial const &P) const{
        Polynomial Q;
        Q.setCoefficient(capacity + P.capacity - 2, 0);
        for (int i=0; i<capacity; i++){
            for (int j=0; j<P.capacity; j++){
                Q.degCoeff[i+j] += this->degCoeff[i] * P.degCoeff[j];
            }
        }
        return Q;
    }
    //print
    void print() const {
        
        for(int i=0; i<capacity; i++){
            if (degCoeff[i] != 0){
                cout << degCoeff[i] << "x" << i << " ";
            }
        }
        cout << endl;
    }
};