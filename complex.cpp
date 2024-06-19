#include "complex.hpp"

string to_string(const Complex &complex) {
    return complex.to_str();
}

Complex::Complex(double real, double imag) : real(real), imag(imag) {}

double Complex::getReal() {
    return real;
}

double Complex::getImag() {
    return imag;
}

bool Complex::operator==(const Complex &other) const {
    return real == other.real && imag == other.imag;
}

string Complex::to_str() const {
    return "(" + std::to_string(real) + ", " + std::to_string(imag) + ")";
}

ostream &operator<<(ostream &os, const Complex &complex) {
    os << complex.to_str();
    return os;
}