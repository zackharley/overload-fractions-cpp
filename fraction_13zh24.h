#pragma once

#include <iostream>
#include <exception>
using namespace std;

class Fraction {
public:
	Fraction(const int& top, const int& bottom);
	Fraction(const int& top);
	Fraction();

	static int greatestCommonDenominator(const int& n, const int& m);

	int numerator() const;
	int denominator() const;

	Fraction operator-() const;

	Fraction& operator++();	// Pre-increment
	Fraction operator++(int); // Post-increment

	Fraction& operator+=(const Fraction& right);
	Fraction& operator+=(const int& right);

	bool operator==(const Fraction& right);
	bool operator==(const int& right);

	bool operator!=(const Fraction& right);
	bool operator!=(const int& right);

	bool operator>(const Fraction& right);
	bool operator>(const int& right);

	bool operator>=(const Fraction& right);
	bool operator>=(const int& right);

	bool operator<(const Fraction& right);
	bool operator<(const int& right);

	bool operator<=(const Fraction& right);
	bool operator<=(const int& right);

	friend ostream& operator<<(ostream& out, const Fraction& fraction);
	friend istream& operator>>(istream& in, Fraction& fraction);
private:
	int numeratorVal;
	int denominatorVal;
};

class FractionException : public exception {
public:
	explicit FractionException(const string& message) : msg(message) {}
	virtual ~FractionException() throw() {}
	virtual const char* what() const throw() {
		return msg.c_str();
	}
protected:
	string msg;
};

Fraction operator+(const Fraction& left, const Fraction& right);
Fraction operator+(const int& left, const Fraction& right);
Fraction operator+(const Fraction& left, const int& right);

Fraction operator-(const Fraction& left, const Fraction& right);
Fraction operator-(const int& left, const Fraction& right);
Fraction operator-(const Fraction& left, const int& right);

Fraction operator*(const Fraction& left, const Fraction& right);
Fraction operator*(const int& left, const Fraction& right);
Fraction operator*(const Fraction& left, const int& right);

Fraction operator/(const Fraction& left, const Fraction& right);
Fraction operator/(const int& left, const Fraction& right);
Fraction operator/(const Fraction& left, const int& right);

bool operator==(const int& left, const Fraction& right);
bool operator!=(const int& left, const Fraction& right);
bool operator>(const int& left, const Fraction& right);
bool operator>=(const int& left, const Fraction& right);
bool operator<(const int& left, const Fraction& right);
bool operator<=(const int& left, const Fraction& right);
