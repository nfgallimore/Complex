#ifndef COMPLEX_HPP
#define COMPLEX_HPP
#include <string>

class Complex
{
public:
	Complex(double = 0.0, double = 0.0); // default constructor
	Complex add(const Complex&) const;			  // function add
	Complex subtract(const Complex&) const; // function subtract
	Complex multiply(const Complex&) const; // function multiply
	std::string toString() const;  // return string representation
	void setComplexNumber(double, double); // set complex number
	Complex operator+(const Complex &right) const;
	Complex operator-(const Complex &right) const;
	Complex operator*(const Complex &right) const;
	Complex operator=(const Complex &right);
	friend std::ostream& operator<<(std::ostream &out, const Complex &right);
	friend std::istream& operator>>(std::istream &in, Complex &right);
	bool operator==(const Complex &right) const;
	bool operator!=(const Complex &right) const;
	std::istream& parser(std::istream& in);

private:
   double realPart;
   double imaginaryPart;
};

#endif

