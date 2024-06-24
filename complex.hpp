#include <iostream>
#include <string>

using std::ostream;
using std::string;

class Complex {
   private:
    double real;
    double imag;

   public:
    Complex(double real, double imag);

    double getReal();
    double getImag();

    bool operator==(const Complex &other) const;
    // bool operator<(const Complex &other) const;

    string to_str() const;

    bool operator<(const Complex &other);
    friend ostream &operator<<(ostream &os, const Complex &complex);
};

string to_string(const Complex &complex);