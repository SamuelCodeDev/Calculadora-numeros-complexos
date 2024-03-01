#ifndef COMPLEXO_HPP
#define COMPLEXO_HPP

#pragma once

#include <iostream>
using std::ostream;
using std::istream;

class Complexo
{
  private:
    double a;
    double b;

  public:
    Complexo(double a = 0, double b = 0) noexcept;

    Complexo operator+(const Complexo & c) const noexcept;
    Complexo operator-(const Complexo & c) const noexcept;
    Complexo operator*(const Complexo & c) const noexcept;
    Complexo operator/(const Complexo & c) const noexcept;
    Complexo& operator*=(const Complexo & c) noexcept;
    Complexo Exponenciacao(int expoente) const;
    Complexo Conjugado() const noexcept;
    double Modulo() const noexcept;

    friend ostream& operator<<(ostream & os, const Complexo & c);
    friend istream& operator>>(istream & os, Complexo & c);
};

inline Complexo Complexo::Conjugado() const noexcept
{ return Complexo { a, -b }; }

#endif