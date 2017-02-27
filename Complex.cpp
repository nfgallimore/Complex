// Member-function definitions for class Complex.
#include <iostream>
#include <sstream> // for ostringstream class
#include "Complex.hpp"

Complex::Complex(double real, double imaginary)
   : realPart(real), imaginaryPart(imaginary) { }

Complex Complex::add(const Complex &right) const
{
   return Complex(
      realPart + right.realPart, imaginaryPart + right.imaginaryPart);
}

Complex Complex::subtract(const Complex &right) const
{
   return Complex(realPart - right.realPart, imaginaryPart - right.imaginaryPart);
}

Complex Complex::multiply(const Complex &right) const
{
   return Complex((realPart * right.realPart) - (imaginaryPart * right.imaginaryPart),
                  (imaginaryPart * right.imaginaryPart) + (realPart * right.realPart));
}

std::string Complex::toString() const
{
   std::ostringstream output;
   output << "(" << realPart << ", " << imaginaryPart << ")";
   return output.str();
}

void Complex::setComplexNumber(double rp, double ip)
{
   realPart = rp;
   imaginaryPart = ip;
}
Complex Complex::operator+(const Complex &right) const
{
   return this->add(right);
}

Complex Complex::operator-(const Complex &right) const
{
   return this->subtract(right);
}

Complex Complex::operator*(const Complex &right) const
{
   return this->multiply(right);
}

Complex Complex::operator=(const Complex &right)
{
   setComplexNumber(right.realPart, right.imaginaryPart);
   return *this;
}

std::ostream& operator<<(std::ostream& os, const Complex &right)
{  
   os << "(" << right.realPart << "," << right.imaginaryPart << ")";
   return os;
}

// Based off http://stackoverflow.com/questions/34220469/overloading-extraction-and-insertion-operator-c
template <char C>
std::istream& parser(std::istream& in)
{
   ((in >> std::skipws).peek() != C) ? in.setstate(std::ios_base::failbit) : (void)in.ignore();
   return in;
}
std::istream& (*const open_parenthesis)(std::istream&) = &parser<'('>;
std::istream& (*const close_parenthesis)(std::istream&) = &parser<')'>;
std::istream& (*const comma)(std::istream&) = &parser<','>;

std::istream& operator>>(std::istream& in, Complex &right)
{
   double real, imag;
   if (in >> open_parenthesis >> real >> comma >> imag >> close_parenthesis)
      right.setComplexNumber(real, imag);
   return in;
}

bool Complex::operator==(const Complex &right) const
{
   return (right.realPart == realPart && right.imaginaryPart == imaginaryPart);
}

bool Complex::operator!=(const Complex &right) const
{
   return (right.realPart != realPart && right.imaginaryPart != imaginaryPart);
}