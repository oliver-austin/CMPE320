/*
 * fraction_15oa16.cpp
 * CMPE 320 Assignment 2
 * Oliver Austin - 20011458
 */
#include <iostream>
#include <stdlib.h>
#include <string>
#include "fraction.h"
using namespace std;

// no argument constructor sets fraction to 0/1
Fraction::Fraction(void) :
				num(0),
				denom(1) {
}

// one argument constructor sets fraction to num/1
Fraction::Fraction(const int num) :
				num(num),
				denom(1) {
}

// two argument constructor sets fraction to num/denom
Fraction::Fraction(const int num, const int denom) :
				num(num),
				denom(denom) {

	// check for invalid denominator
	if (denom == 0){
		throw FractionException("Denominator cannot be zero.");
	}

	// reduce fraction and standardize negatives
	normalize();
}

int Fraction::numerator(){
	return num;
}

int Fraction::denominator(){
	return denom;
}

void Fraction::normalize(){
	//find greatest common denominator
	int divisor = gcd(this->num, this->denom);

	// divide numerator and denominator by GCD
	this->num = this->num/divisor;
	this->denom = this->denom/divisor;

	// if both numerator and denominator are negative, set both to positive
	if(this->num<0 && this->denom<0){
		this->num = abs(this->num);
		this->denom = abs(this->denom);
	}

	// if numerator is positive and denominator negative, set numerator to negative and denominator to positive
	else if(this->num>0 && this->denom<0){
		this->num = -this->num;
		this->denom = abs(this->denom);
	}
}

int Fraction::gcd(int n, int m){
	// use magnitude of inputs to find GCD
	int absN = abs(n);
	int absM = abs(m);
	if(absM<=absN && absN%absM==0){
		return absM;
	}
	else if(absN<absM){
		gcd(m,n);
	}
	else{
		gcd(m,n%m);
	}
}


Fraction Fraction::operator-() const {
	Fraction fraction;
	fraction.num = -(this->num);
	fraction.denom = this->denom;
	return fraction;
}

Fraction& Fraction::operator++()  {
	num+=denom;
	return *this;
}

Fraction Fraction::operator++(int){
	Fraction temp = *this;
	++*this;
	temp.normalize();
	return temp;
}

Fraction operator+(const Fraction& f1, const Fraction& f2){
	Fraction fraction;
	fraction.num = (f1.num * f2.denom)+(f1.denom * f2.num);
	fraction.denom = f1.denom * f2.denom;
	fraction.normalize();
	return fraction;
}
Fraction operator+(const Fraction& f, int i){
	Fraction fraction;
	fraction.num = (f.num + i*f.denom);
	fraction.denom = f.denom;
	fraction.normalize();
	return fraction;
}
Fraction operator+(int i, const Fraction& f){
	Fraction fraction;
	fraction.num = (f.num + i*f.denom);
	fraction.denom = f.denom;
	fraction.normalize();
	return fraction;
}

Fraction operator-(const Fraction& f1, const Fraction& f2) {
	Fraction fraction;
	fraction.num = (f1.num * f2.denom)-(f1.denom * f2.num);
	fraction.denom = f1.denom * f2.denom;
	int divisor = fraction.gcd(fraction.num, fraction.denom);
	fraction.num = fraction.num/divisor;
	fraction.denom = fraction.denom/divisor;
	fraction.normalize();
	return fraction;
}
Fraction operator-(const Fraction& f, int i){
	Fraction fraction;
	fraction.num = (f.num - i*f.denom);
	fraction.denom = f.denom;
	fraction.normalize();
	return fraction;
}
Fraction operator-(int i, const Fraction& f){
	Fraction fraction;
	fraction.num = (i*f.denom - f.num);
	fraction.denom = f.denom;
	fraction.normalize();
	return fraction;
}

Fraction operator*(const Fraction& f1, const Fraction& f2) {
	Fraction fraction;
	fraction.num = f1.num * f2.num;
	fraction.denom = f1.denom * f2.denom;
	fraction.normalize();
	return fraction;
}
Fraction operator*(const Fraction& f, int i){
	Fraction fraction;
	fraction.num = f.num*i;
	fraction.denom = f.denom;
	fraction.normalize();
	return fraction;
}
Fraction operator*(int i, const Fraction& f){
	Fraction fraction;
	fraction.num = f.num*i;
	fraction.denom = f.denom;
	fraction.normalize();
	return fraction;
}

Fraction operator/(const Fraction& f1, const Fraction& f2) {
	Fraction fraction;
	fraction.num = f1.num * f2.denom;
	fraction.denom = f1.denom * f2.num;
	fraction.normalize();
	return fraction;
}
Fraction operator/(const Fraction& f, int i){
	Fraction fraction;
	fraction.num = f.num;
	fraction.denom = f.denom*i;
	fraction.normalize();
	return fraction;
}
Fraction operator/(int i, const Fraction& f){
	Fraction fraction;
	fraction.num = f.denom*i;
	fraction.denom = f.num;
	fraction.normalize();
	return fraction;
}

Fraction& Fraction::operator+=(const Fraction& f){
	num = (num * f.denom)+(denom * f.num);
	denom = denom * f.denom;
	normalize();
	return *this;
}
Fraction& Fraction::operator+=(int i){
	num = num +i*denom;
	normalize();
	return *this;
}

bool operator<(const Fraction& f1, const Fraction& f2){
	if(f1.num * f2.denom < f2.num*f1.denom){return true;}
	return false;
}
bool operator<(const Fraction& f, int i){
	if(f.num < i*f.denom){return true;}
	return false;
}
bool operator<(int i, const Fraction& f){
	if(i*f.denom < f.num){return true;}
	return false;
}

bool operator<=(const Fraction& f1, const Fraction& f2){
	if(f1.num * f2.denom <= f2.num*f1.denom){return true;}
	return false;
}
bool operator<=(const Fraction& f, int i){
	if(f.num <= i*f.denom){return true;}
	return false;
}
bool operator<=(int i, const Fraction& f){
	if(i*f.denom <= f.num){return true;}
	return false;
}

bool operator==(const Fraction& f1, const Fraction& f2){
	if(f1.num * f2.denom == f2.num*f1.denom){return true;}
	return false;
}
bool operator==(const Fraction& f, int i){
	if(f.num == i*f.denom){return true;}
	return false;
}
bool operator==(int i, const Fraction& f){
	if(i*f.denom == f.num){return true;}
	return false;
}

bool operator!=(const Fraction& f1, const Fraction& f2){
	if(f1.num * f2.denom != f2.num*f1.denom){return true;}
	return false;
}
bool operator!=(const Fraction& f, int i){
	if(f.num != i*f.denom){return true;}
	return false;
}
bool operator!=(int i, const Fraction& f){
	if(i*f.denom != f.num){return true;}
	return false;
}

bool operator>=(const Fraction& f1, const Fraction& f2){
	if(f1.num * f2.denom >= f2.num*f1.denom){return true;}
	return false;
}
bool operator>=(const Fraction& f, int i){
	if(f.num >= i*f.denom){return true;}
	return false;
}
bool operator>=(int i, const Fraction& f){
	if(i*f.denom >= f.num){return true;}
	return false;
}

bool operator>(const Fraction& f1, const Fraction& f2){
	if(f1.num * f2.denom > f2.num*f1.denom){return true;}
	return false;
}
bool operator>(const Fraction& f, int i){
	if(f.num > i*f.denom){return true;}
	return false;
}
bool operator>(int i, const Fraction& f){
	if(i*f.denom > f.num){return true;}
	return false;
}

ostream& operator<<(ostream& os, const Fraction& f)
{
	// write numerator and denominator seperated by '/' to output stream
	os << f.num << '/' << f.denom;
	return os;
}

istream &operator>>(istream &is, Fraction& f)
{
	// read numerator
	is >> f.num;
	// read next character
	int current = is.get();
	// if the user entered a zero, or a whole number, set denominator to 1 and return from input stream
	if (f.num == 0 || current == 10){
		f.denom = 1;
		return is;
	}
	// read denominator and return from input stream
	is >>f.denom;
	return is;
}

FractionException::FractionException(const string& message) :
				message(message) {
}
string& FractionException::what() {
	return message;
}
