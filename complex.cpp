#include "complex.hpp"

#include <cmath>
#include <sstream>
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

std::string Complex::to_str() const {
    std::ostringstream oss;

    if (real != 0 || imag == 0) {
        oss << real;
    }

    if (imag != 0) {
        if (imag > 0 && real != 0) {
            oss << " + ";
        } else if (imag < 0) {
            if (real != 0) {
                oss << " - ";
            } else {
                oss << "-";
            }
        }

        if (imag != 1 && imag != -1) {
            oss << std::abs(imag);
        }

        oss << "i";
    }

    return oss.str();
}

bool Complex::operator<(const Complex &other) {
    return sqrt(real * real + imag * imag) < sqrt(other.real * other.real + other.imag * other.imag);
}

ostream &operator<<(ostream &os, const Complex &complex) {
    os << complex.to_str();
    return os;
}