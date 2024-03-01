#include "complexo.hpp"
#include <cmath>
#include <limits>
using namespace std;

Complexo::Complexo(double a, double b) noexcept : a{a}, b{b}
{
}

Complexo Complexo::operator+(const Complexo &c) const noexcept // (a+bi) + (c+di) = (a+c) + (b+d)i
{
    return Complexo { a + c.a, b + c.b };
}

Complexo Complexo::operator-(const Complexo &c) const noexcept // (a+bi) − (c+di) = (a−c) + (b−d)i
{
    return Complexo { a - c.a, b - c.b };
}

Complexo Complexo::operator*(const Complexo &c) const noexcept // (a+bi) ∗ (c+di) = (ac−bd) + (ad+bc)i
{
    return Complexo { a * c.a - b * c.b, a * c.b + b * c.a };
}

Complexo Complexo::operator/(const Complexo &c) const noexcept // (a+bi) / (c+di) = (ac+bd) / ((c^2+d^2) + (bc-ad) / (c^2+d^2))i
{
    double Real { (a * c.a + b * c.b) / (pow(c.a, 2) + pow(c.b,2)) };      // (ac + bd) / (c^2 + d^2)
    double Imaginaria { (b * c.a - a * c.b) / (pow(c.a,2) * pow(c.b,2)) }; // (bc - ad) / (c^2 + d^2)
    return Complexo { Real, Imaginaria };
}

Complexo& Complexo::operator*=(const Complexo &c) noexcept
{
    return *this = *this * c; 
}

Complexo Complexo::Exponenciacao(int expoente) const
{
    Complexo resul { a, b };
    for(int i = 1;i < expoente;++i)
        resul *= resul; 
    return resul;
}

double Complexo::Modulo() const noexcept
{
    return double { sqrt(pow(a,2) + pow(b,2)) };
}

ostream &operator<<(ostream &os, const Complexo &c)
{
    return os << c.a << showpos << c.b << "i\n" << noshowpos;
}

istream &operator>>(istream & is, Complexo &c)
{
    is.exceptions(istream::failbit | istream::badbit);
    bool entradaValida { false };
    while (!entradaValida) {
        try {
            is >> c.a >> c.b;
            entradaValida = true; 
        } catch(const exception& e) {
            clog << "Erro ao ler o número complexo! Por favor, digite novamente o numero complexo (a+bi): ";
            is.clear();
            is.ignore(numeric_limits<streamsize>::max(), '\n'); 
        }
    }
    is.ignore(numeric_limits<streamsize>::max(), '\n'); 
    return is;
}