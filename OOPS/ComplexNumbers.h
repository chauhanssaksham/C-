class ComplexNumbers{
  private:
    int real;
    int imaginary;
  public:
    ComplexNumbers(int r, int i){
        real = r;
        imaginary=i;
    }
    void plus(ComplexNumbers const &c2){
        real += c2.real;
        imaginary += c2.imaginary;
    }
    void multiply(ComplexNumbers const &c2){
        int x = (real*c2.real) - (imaginary*c2.imaginary);
        int y = (real*c2.imaginary) + (imaginary*c2.real);
        real = x;
        imaginary = y;
    }
    void print(){
        cout << real << " i" << imaginary;
    }
};