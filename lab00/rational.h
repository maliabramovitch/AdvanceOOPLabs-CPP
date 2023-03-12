//
// Created by Mali Abramovitch on 08/03/2023.
//

#ifndef LAB00_RATIONAL_H
#define LAB00_RATIONAL_H


#include <string>

class rational {
    int numerator, denominator;
    void GCD();
public:
    class Power {
    public:
        double value;

        Power(double d) : value(d) {};
    };

    class DevizionByZero : public std::exception {
    };

    // Constructors
    rational();          // Zero
    explicit rational(int n);       // Equal to n/1
    rational(int n, int d) noexcept(false);  // General case (n/d)
    explicit rational(std::string &str) noexcept(false);

    rational &operator=(int n);

    rational &assign(int n, int d);

    // Representation
    int getNum() const;

    int getDenom() const;

    // Arithmetic operators
    rational &operator+=(const rational &r);

    rational &operator-=(const rational &r);

    rational &operator*=(const rational &r) throw(DevizionByZero);

    rational &operator/=(const rational &r) throw(DevizionByZero);

    // Comparison operators
    bool operator<(const rational &r) const;

    bool operator==(const rational &r) const;

    explicit operator std::string() const;

    rational::Power operator*() const;

    friend double operator*(const rational& r, const Power &p);

    friend std::ostream& operator<<(std::ostream& os, rational&r);
};


#endif //LAB00_RATIONAL_H
