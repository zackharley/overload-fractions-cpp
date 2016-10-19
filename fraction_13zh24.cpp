#include <iostream>
#include <stdlib.h>
using namespace std;

#include "fraction_13zh24.h"

Fraction::Fraction(const int& top, const int& bottom) {
	int topNormalized;
	int bottomNormalized;
	int gcd = 1;

	if(bottom == 0) {
		throw FractionException("Cannot have a fraction with a denominator of zero");
	}

	if(bottom < 0) {
		topNormalized = top * -1;
		bottomNormalized = bottom * -1;
	} else {
		topNormalized = top;
		bottomNormalized = bottom;
	}

	if(topNormalized != 0 && bottomNormalized != 0) {
		gcd = greatestCommonDenominator(topNormalized, bottomNormalized);
		numeratorVal = topNormalized / gcd;
		denominatorVal = bottomNormalized / gcd;
	} else {
		numeratorVal = topNormalized;
		denominatorVal = bottomNormalized;
	}
	
}

Fraction::Fraction(const int& top) : Fraction::Fraction(top, 1) {}

Fraction::Fraction() : Fraction::Fraction(0, 1) {}

int Fraction::greatestCommonDenominator(const int& n, const int& m) {
	int absN = abs(n);
	int absM = abs(m);

	if(absM <= absN && absN % absM == 0) {
		return absM;
	} else if(absN < absM) {
		return greatestCommonDenominator(absM, absN);
	} else {
		return greatestCommonDenominator(absM, absN % absM);
	}
}

int Fraction::numerator() const {
	return numeratorVal;
}

int Fraction::denominator() const {
	return denominatorVal;
}

Fraction Fraction::operator-() const {
	int top = this->numerator() * -1;
	int bottom = this->denominator();
	return Fraction(top, bottom);
}

// Pre-increment
Fraction& Fraction::operator++() {
	numeratorVal += denominatorVal;
	return *this;
}

// Post-increment
Fraction Fraction::operator++(int unused) {
	Fraction clone(numeratorVal, denominatorVal);
	numeratorVal += denominatorVal;
	return clone;
}

Fraction& Fraction::operator+=(const Fraction& right) {
	if(right.numerator()) {
		int leftNumerator = numeratorVal * right.denominator();
		int rightNumerator = right.numerator() * denominatorVal;
		int top = leftNumerator + rightNumerator;
		int bottom = right.denominator() * denominatorVal;
		int gcd;

		gcd = greatestCommonDenominator(top, bottom);
		numeratorVal = top / gcd;
		denominatorVal = bottom / gcd;
	}
	return *this;
}

Fraction& Fraction::operator+=(const int& right) {
	if(right != 0) {
		int leftNumerator = numeratorVal;
		int rightNumerator = right * denominatorVal;
		int top = leftNumerator + rightNumerator;
		int bottom = denominatorVal;
		int gcd;

		gcd = greatestCommonDenominator(top, bottom);
		numeratorVal = top / gcd;
		denominatorVal = bottom / gcd;
	}
	return *this;
}

bool Fraction::operator==(const Fraction& right) {
	return (numeratorVal == right.numerator() && denominatorVal == right.denominator());
}

bool Fraction::operator==(const int& right) {
	return (numeratorVal == right && denominatorVal == 1);
}

bool Fraction::operator!=(const Fraction& right) {
	return !(numeratorVal == right.numerator() && denominatorVal == right.denominator());
}

bool Fraction::operator!=(const int& right) {
	return !(numeratorVal == right && denominatorVal == 1);
}

bool Fraction::operator>(const Fraction& right) {
	int leftNumerator = numeratorVal * right.denominator();
	int rightNumerator = right.numerator() * denominatorVal;
	return leftNumerator > rightNumerator;
}

bool Fraction::operator>(const int& right) {
	int leftNumerator = numeratorVal;
	int rightNumerator = right * denominatorVal;
	return leftNumerator > rightNumerator;
}

bool Fraction::operator>=(const Fraction& right) {
	int leftNumerator = numeratorVal * right.denominator();
	int rightNumerator = right.numerator() * denominatorVal;
	return leftNumerator >= rightNumerator;
}

bool Fraction::operator>=(const int& right) {
	int leftNumerator = numeratorVal;
	int rightNumerator = right * denominatorVal;
	return leftNumerator >= rightNumerator;
}

bool Fraction::operator<(const Fraction& right) {
	int leftNumerator = numeratorVal * right.denominator();
	int rightNumerator = right.numerator() * denominatorVal;
	return leftNumerator < rightNumerator;
}

bool Fraction::operator<(const int& right) {
	int leftNumerator = numeratorVal;
	int rightNumerator = right * denominatorVal;
	return leftNumerator < rightNumerator;
}

bool Fraction::operator<=(const Fraction& right) {
	int leftNumerator = numeratorVal * right.denominator();
	int rightNumerator = right.numerator() * denominatorVal;
	return leftNumerator <= rightNumerator;
}

bool Fraction::operator<=(const int& right) {
	int leftNumerator = numeratorVal;
	int rightNumerator = right * denominatorVal;
	return leftNumerator <= rightNumerator;
}

ostream& operator<<(ostream& out, const Fraction& fraction) {
	out << fraction.numeratorVal << "/" << fraction.denominatorVal;
	return out;
}

istream& operator>>(istream& in, Fraction& fraction) {
	string value;
	in >> value;

	size_t found = value.find("/");

	if(found != string::npos) {
		int top = atoi(value.substr(0, found).c_str());;
		int bottom = atoi(value.substr(found + 1).c_str());
		if(top == 0 && bottom != 0) {
			fraction.numeratorVal = 0;
			fraction.denominatorVal = 1;
		} else if(top == 0 && bottom == 0) {
			throw FractionException("Invalid fraction! Cannot divide by zero");
		} else {
			fraction.numeratorVal = top;
			fraction.denominatorVal = bottom;
		}
	} else if(!value.empty()) {
		if(atoi(value.c_str()) == 0) {
			fraction.numeratorVal = 0;
			fraction.denominatorVal = 1;
		} else {
			fraction.numeratorVal = atoi(value.c_str());
			fraction.denominatorVal = 1;
		}
	}
	
	return in;
}

Fraction operator+(const Fraction& left, const Fraction& right) {
	int leftNumerator = left.numerator() * right.denominator();
	int rightNumerator = right.numerator() * left.denominator();
	int top = leftNumerator + rightNumerator;
	int bottom = right.denominator() * left.denominator();
	return Fraction(top, bottom);
}

Fraction operator+(const int& left, const Fraction& right) {
	int leftNumerator = left * right.denominator();
	int rightNumerator = right.numerator();
	int top = leftNumerator + rightNumerator;
	int bottom = right.denominator();
	return Fraction(top, bottom);
}

Fraction operator+(const Fraction& left, const int& right) {
	int leftNumerator = left.numerator();
	int rightNumerator = right * left.denominator();
	int top = leftNumerator + rightNumerator;
	int bottom = left.denominator();
	return Fraction(top, bottom);
}

Fraction operator-(const Fraction& left, const Fraction& right) {
	int leftNumerator = left.numerator() * right.denominator();
	int rightNumerator = right.numerator() * left.denominator();
	int top = leftNumerator - rightNumerator;
	int bottom = right.denominator() * left.denominator();
	return Fraction(top, bottom);
}

Fraction operator-(const int& left, const Fraction& right) {
	int leftNumerator = left * right.denominator();
	int rightNumerator = right.numerator();
	int top = leftNumerator - rightNumerator;
	int bottom = right.denominator();
	return Fraction(top, bottom);
}

Fraction operator-(const Fraction& left, const int& right) {
	int leftNumerator = left.numerator();
	int rightNumerator = right * left.denominator();
	int top = leftNumerator - rightNumerator;
	int bottom = left.denominator();
	return Fraction(top, bottom);
}

Fraction operator*(const Fraction& left, const Fraction& right) {
	int top = left.numerator() * right.numerator();
	int bottom = left.denominator() * right.denominator();
	return Fraction(top, bottom);
}

Fraction operator*(const int& left, const Fraction& right) {
	int top = left * right.numerator();
	int bottom = right.denominator();
	return Fraction(top, bottom);
}

Fraction operator*(const Fraction& left, const int& right) {
	int top = left.numerator() * right;
	int bottom = left.denominator();
	return Fraction(top, bottom);
}

Fraction operator/(const Fraction& left, const Fraction& right) {
	int top = left.numerator() * right.denominator();
	int bottom = left.denominator() * right.numerator();
	return Fraction(top, bottom);
}

Fraction operator/(const int& left, const Fraction& right) {
	int top = left * right.denominator();
	int bottom = right.numerator();
	return Fraction(top, bottom);
}

Fraction operator/(const Fraction& left, const int& right) {
	int top = left.numerator();
	int bottom = left.denominator() * right;
	return Fraction(top, bottom);
}

bool operator==(const int& left, const Fraction& right) {
	return (left == right.numerator() && right.denominator() == 1);
}

bool operator!=(const int& left, const Fraction& right) {
	return !(left == right.numerator() && right.denominator()  == 1);
}

bool operator>(const int& left, const Fraction& right) {
	int leftNumerator = left * right.denominator();
	int rightNumerator = right.numerator();
	return leftNumerator > rightNumerator;
}

bool operator>=(const int& left, const Fraction& right) {
	int leftNumerator = left * right.denominator();
	int rightNumerator = right.numerator();
	return leftNumerator >= rightNumerator;
}

bool operator<(const int& left, const Fraction& right) {
	int leftNumerator = left * right.denominator();
	int rightNumerator = right.numerator();
	return leftNumerator < rightNumerator;
}

bool operator<=(const int& left, const Fraction& right) {
	int leftNumerator = left * right.denominator();
	int rightNumerator = right.numerator();
	return leftNumerator <= rightNumerator;
}