#include <iostream>

class Fraction{
// This "class" will store all the input infos of fraction, and you can create function using said infos.
public:
    int numerator, denominator;

    int GCD (int numr, int denom) {
        if (denom == 0) return numr;
        return GCD(denom, numr % denom);
        // This will take two numbers and will print out their shared Greatest Common Divisor ( GCD ), you can check the wiki for more infos.
    }

    void simplify ( Fraction& frac )
    {
        int shared_GCD = GCD ( frac.numerator, frac.denominator );
        frac.numerator /= shared_GCD;
        frac.denominator /= shared_GCD;
        std::cout << "Fraction after simplifying: ";
        // As the name suggests, this will simplify the fraction given by you. [ For example : 8/6 ( input ) will be simplified to 4/3 ( output ) ]
    }

   friend std::ostream& operator<< ( std::ostream& out, const Fraction& frac ){
        if ( frac.numerator == 0 ) return out << 0;
        if ( frac.denominator == 1 ) return out << frac.numerator ;
        out << frac.numerator << "/" << frac.denominator;
        return out;
        // This will be used to manipulate the output of class type variables, normally you can't print out class type variables since the program didn't know how, however, with this you can.
    }

   friend std::istream& operator>> ( std::istream& in, Fraction& frac ){
        std::cout << "Input numerator: ";
        in >> frac.numerator;
        std::cout << "Input denominator: ";
        in >> frac.denominator;
        while (frac.denominator == 0) {
            std::cerr << "Error: denominator cannot be zero. Input new denominator: ";
            in >> frac.denominator;
        } ;
        return in;
        // This enables the user to input class type variable infos directly, thus prevent runtime error caused by 0/0.
    }
};

int main(){
    Fraction frac{};
    std::cin >> frac;
    std::cout << "Fraction before simplifying: " << frac << "\n";
    frac.simplify(frac);
    std::cout << frac << std::endl;
}
