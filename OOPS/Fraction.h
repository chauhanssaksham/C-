class Fraction{
  private:
    int numerator;
    int denominator;

    void simplify(){
        int hcf = 1;
        for(int i= min(numerator, denominator);  i>0; i--){
            if(numerator%i == 0 && denominator % i == 0){
                hcf = i;
                break;
            }
        }
        numerator = numerator/hcf;
        denominator = denominator/hcf;
    }
    Fraction add(Fraction const &f2) const{
        int lcm = denominator * f2.denominator;
        int x = lcm/denominator;
        int y = lcm/f2.denominator;
        int num = x*numerator + y*f2.numerator;
        // numerator = num;
        // denominator = lcm;
        // simplify();
        Fraction fnew(num, lcm);
        fnew.simplify();
        return fnew;
    }
    Fraction multiply(Fraction const &f2) const {
        int num = numerator * f2.numerator;
        int den = denominator * f2.denominator;
        Fraction fnew(num, den);
        fnew.simplify();
        return fnew;
    }
  public:
    
    Fraction(int numerator, int denominator){
        this->numerator = numerator;
        this->denominator = denominator;
    }
    
    void print(){
        cout << numerator << "/" << denominator << endl;
    }

    Fraction operator+(Fraction const &f2) const{
        return this->add(f2);
    }

    Fraction operator*(Fraction const &f2) const{
        return this->multiply(f2);
    }

    bool operator==(Fraction const &f2) const{
        if (numerator*f2.denominator == denominator*f2.numerator){
            return true;
        }
        return false;
    }
    Fraction& operator++(){
        numerator = numerator+denominator;
        simplify();
        return (*this);
    }
    Fraction operator++(int){
        Fraction fNew(numerator, denominator);
        numerator = numerator+denominator;
        simplify();
        fNew.simplify();
        return fNew;
    }
    Fraction& operator+=(Fraction const &f2){
        (*this) = this->add(f2);
        return (*this);
    }
};