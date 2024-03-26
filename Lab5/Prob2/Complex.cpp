#include "Complex.h"

Complex::Complex() : Complex(0, 0) {
}

Complex::Complex(double real, double imag) {
    real_data = real;
    imag_data = imag;
}

bool Complex::is_real() const {
    return imag() == 0;
}

double Complex::real() const {
    return real_data;
}

double Complex::imag() const {
    return imag_data;
}

double Complex::abs() const {
    return sqrt(real() * real() + imag() * imag());
}

Complex Complex::conjugate() const {
    return { real(), -imag() };
}

Complex& Complex::operator()(double real, double imag)
{
    Complex c(real, imag);
    return c;
}

Complex& Complex::operator++()
{
    this->real_data++;
    Complex c(this->real_data, this->imag_data);
    return c;
}

Complex Complex::operator++(int number)
{
    Complex temp(*this);
    ++(*this);
    return temp;
}

Complex& Complex::operator--()
{
    this->real_data--;
    Complex c(this->real_data, this->imag_data);
    return c;
}

Complex Complex::operator--(int number)
{
    Complex temp(*this);
    --(*this);
    return temp;
}

Complex operator+(const Complex& l, const Complex& r)
{
    return Complex(l.real()+ r.real(), l.imag() + r.imag());
}

Complex operator+(const Complex& l, double r)
{
    Complex c(r, 0);
    return l+c;
}

Complex operator+(double l, const Complex& r)
{
    Complex c(l, 0);
    return c+r;
}

Complex operator-(const Complex& l, const Complex& r)
{
    return Complex(l.real() - r.real(), l.imag() - r.imag());
}

Complex operator-(const Complex& l, double r)
{
    Complex c(r, 0);
    return l - c;
}

Complex operator-(double l, const Complex& r)
{
    Complex c(l, 0);
    return c - r;
}

Complex operator*(const Complex& l, const Complex& r)
{
    return Complex(l.real() * r.real() - l.imag() * r.imag(), l.real() * r.imag()+ l.imag()*r.real() );
}

Complex operator*(const Complex& l, double r)
{
    Complex c(r, 0);
    return l * c;
}

Complex operator*(double l, const Complex& r)
{
    Complex c(l, 0);
    return c * r;
}

Complex operator-(const Complex& obj)
{
    return Complex(-obj.real(), -obj.imag());
}

bool operator==(const Complex& l, const Complex& r)
{
    if (l.real() == r.real() && l.imag() == l.imag())
        return true;
    return false;
}

bool operator!=(const Complex& l, const Complex& r)
{
    if (l.real() == r.real() && l.imag() == l.imag())
        return false;
    return true;
}

std::ostream& operator<<(std::ostream& out, const Complex& complex)
{
    out << complex.real()<<"+"<<complex.imag()<<"i"<<std::endl;
    return out;
}


