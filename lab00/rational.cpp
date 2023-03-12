//
// Created by Mali Abramovitch on 08/03/2023.
//

#include <sstream>
#include "rational.h"
#include <math.h>

rational::rational() : numerator(0), denominator(1) {}

rational::rational(int n) : numerator(n), denominator(1) {}

rational::rational(int n, int d) {
    if (d == 0) throw DevizionByZero();
    numerator = n;
    denominator = d;
    GCD();
}

rational::rational(std::string &str) {
    std::stringstream ss(str);
    char slash;
    numerator = 0;
    denominator = 1;
    ss >> numerator >> slash >> denominator;
    if (denominator == 0) throw DevizionByZero();
    GCD();
}

rational &rational::operator=(int n) {
    numerator = n;
    denominator = 1;
    return *this;
}

rational &rational::assign(int n, int d) {
    if (d == 0) throw DevizionByZero();
    numerator = n;
    denominator = d;
    GCD();
}

int rational::getNum() const {
    return numerator;
}

int rational::getDenom() const {
    return denominator;
}

rational &rational::operator+=(const rational &r) {
    numerator = numerator * r.denominator + r.numerator * denominator;
    denominator = denominator * r.denominator;
    if (denominator == 0) throw (DevizionByZero());
    GCD();
    return *this;
}

rational &rational::operator-=(const rational &r) {
    numerator = numerator * r.denominator - r.numerator * denominator;
    denominator = denominator * r.denominator;
    GCD();
    return *this;
}

rational &rational::operator*=(const rational &r) throw(DevizionByZero) {
    numerator *= r.numerator;
    denominator *= r.denominator;
    if (denominator == 0) throw DevizionByZero();
    GCD();
    return *this;
}

rational &rational::operator/=(const rational &r) throw(DevizionByZero) {
    numerator *= r.denominator;
    denominator *= r.numerator;
    if (denominator == 0) throw DevizionByZero();
    GCD();
    return *this;
}

bool rational::operator<(const rational &r) const {
    return (numerator * r.denominator - r.numerator * denominator) < 0;
}

bool rational::operator==(const rational &r) const {
    return (numerator * r.denominator - r.numerator * denominator) == 0;
}

rational::operator std::string() const {
    std::string str;
    std::stringstream ss;
    ss << numerator;
    ss << "/";
    ss << denominator;
    return ss.str();
}

rational::Power rational::operator*() const {
    double d = static_cast<double>(numerator) / static_cast<double>(denominator);
    return Power(d);
}


double operator*(const rational &r, const rational::Power &p) {
    double d = pow((r.numerator / r.denominator), p.value);
    return d;
}

std::ostream &operator<<(std::ostream &os, rational &r) {
    return os << r.numerator << '/' << r.denominator << std::endl;
}

void rational::GCD() {
    int min = std::min(numerator, denominator);
    int gcd = 1;
    for (int i = min; i > 0; --i) {
        if (numerator % min == 0 && denominator % min == 0) {
            gcd = i;
            break;
        }
    }
    numerator /= gcd;
    denominator /= gcd;
}







