/*
 * fraction_15oa16.h
 * CMPE 320 Assignment 2
 * Oliver Austin - 20011458
 */
#include <iostream>
#include <string>
using namespace std;

class Fraction {
public:
	// Fraction constructors for no argument, one argument, and two arguments cases.
	Fraction();
	Fraction(int num);
	Fraction(int num, int denom);

	// method to reduce fractions and standardize negatives
	void normalize();

	// method to calculate the greatest common denominator of a fraction
	int gcd(int num, int denom);

	// accessors for numerator and denominator fields.
	int numerator();
	int denominator();

	// UNARY OPERATOR OVERLOADING

	// overload negation operator
	Fraction operator-() const;

	// overload prefix incrementation operator
	Fraction& operator++();

	// overload postfix incrementation operator
	Fraction operator++(int);

	// BINARY OPERATOR OVERLOADING:

	// Arithmetic Operators: all overloaded operators include three cases; fraction{operator}fraction, fraction{operator}int, and int{operator}fraction.
	// overload addition operator
	friend Fraction operator+(const Fraction& f1, const Fraction& f2);
	friend Fraction operator+(const Fraction& f, int i);
	friend Fraction operator+(int i, const Fraction& f);

	// overload subtraction operator
	friend Fraction operator-(const Fraction& f1, const Fraction& f2);
	friend Fraction operator-(const Fraction& f, int i);
	friend Fraction operator-(int i, const Fraction& f);

	// overload multiplication operator
	friend Fraction operator*(const Fraction& f1, const Fraction& f2);
	friend Fraction operator*(const Fraction& f, int i);
	friend Fraction operator*(int i, const Fraction& f);

	// overload division operator
	friend Fraction operator/(const Fraction& f1, const Fraction& f2);
	friend Fraction operator/(const Fraction& f, int i);
	friend Fraction operator/(int i, const Fraction& f);

	// Assignment Operators: overloaded operator includes two cases: fraction+=fraction, and fraction+=int.
	// overload addition assignment operator
	Fraction& operator+=(const Fraction& f);
	Fraction& operator+=(int i);

	//Comparison Operators: all overloaded operators include three cases; fraction{operator}fraction, fraction{operator}int, and int{operator}fraction.
	// overload less than operator
	friend bool operator<(const Fraction& f1, const Fraction& f2);
	friend bool operator<(const Fraction& f, int i);
	friend bool operator<(int i, const Fraction& f);

	// overload less than or equal to operator
	friend bool operator<=(const Fraction& f1, const Fraction& f2);
	friend bool operator<=(const Fraction& f, int i);
	friend bool operator<=(int i, const Fraction& f);

	// overload equal to operator
	friend bool operator==(const Fraction& f1, const Fraction& f2);
	friend bool operator==(const Fraction& f, int i);
	friend bool operator==(int i, const Fraction& f);

	// overload not equal to operator
	friend bool operator!=(const Fraction& f1, const Fraction& f2);
	friend bool operator!=(const Fraction& f, int i);
	friend bool operator!=(int i, const Fraction& f);

	// overload greater than or equal to operator
	friend bool operator>=(const Fraction& f1, const Fraction& f2);
	friend bool operator>=(const Fraction& f, int i);
	friend bool operator>=(int i, const Fraction& f);

	// overload greater than operator
	friend bool operator>(const Fraction& f1, const Fraction& f2);
	friend bool operator>(const Fraction& f, int i);
	friend bool operator>(int i, const Fraction& f);

	// overload I/O operators
	friend ostream& operator<<(ostream& os, const Fraction& f);
	friend istream &operator>>(istream &is, Fraction& f);

private:
	// data of Fraction class
	int num;
	int denom;
};

// Exception class for invalid fractions
class FractionException {
public:
	FractionException(const string& message);

	//
	string& what(void);
private:
	string message;
};
