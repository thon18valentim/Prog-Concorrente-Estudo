#pragma once

#include <iostream>
#include <cmath>

//UTIL
int Gcd(int a, int b)
{
	return (b == 0) ? std::abs(a) : Gcd(b, a % b);
}

int Lcm(int a, int b)
{
	return (a / Gcd(a, b)) * b;
}

class Fraction
{
	int numerator; // reduced value for operations
	int denominator; // reduced value for operations
	int m_numerator; // for print
	int m_denominator; // for print
public:
	Fraction(int n, int d) : numerator{ n }, denominator{ d }, m_numerator{ n }, m_denominator{ d } { reduce(); }

	void reduce()
	{
		int gcd = Gcd(numerator, denominator);
		if (gcd)
		{
			numerator /= gcd;
			denominator /= gcd;
		}
	}

	friend std::ostream& operator<<(std::ostream& out, const Fraction& f) { out << f.numerator << "/" << f.denominator; return out; }
	friend bool operator==(const Fraction& f1, const Fraction& f2);
	friend bool operator<(const Fraction& f1, const Fraction& f2);
	friend bool operator>(const Fraction& f1, const Fraction& f2);

	friend Fraction operator+(const Fraction& f1, const Fraction& f2);
	friend Fraction operator-(const Fraction& f1, const Fraction& f2);
	friend Fraction operator/(const Fraction& f1, const Fraction& f2);
	friend Fraction operator*(const Fraction& f1, const Fraction& f2);
};

// FRACTION
bool operator==(const Fraction& f1, const Fraction& f2)
{
	return (f1.numerator == f2.numerator) && (f1.denominator == f2.denominator);
}

bool operator<(const Fraction& f1, const Fraction& f2)
{
	return (f1.numerator * f2.denominator < f2.numerator* f1.denominator);
}

bool operator>(const Fraction& f1, const Fraction& f2)
{
	return operator<(f2, f1);
}

Fraction operator+(const Fraction& f1, const Fraction& f2)
{
	if (f1.denominator == f2.denominator)
		return Fraction{ f1.numerator + f2.numerator, f1.denominator };
	else
	{
		Fraction t1{ f1.m_numerator * f2.m_denominator, f1.m_denominator * f2.m_denominator };
		Fraction t2{ f2.m_numerator * f1.m_denominator, f2.m_denominator * f1.m_denominator };
		return Fraction{ t1.m_numerator + t2.m_numerator, t1.m_denominator };
	}
}

Fraction operator-(const Fraction& f1, const Fraction& f2)
{
	int lcm = Lcm(f1.m_denominator, f2.m_denominator);
	Fraction t1{ f1.m_numerator * (lcm / f1.m_denominator), lcm };
	Fraction t2{ f2.m_numerator * (lcm / f2.m_denominator), lcm };
	return Fraction{ t1.m_numerator - t2.m_numerator, t1.m_denominator };
}
