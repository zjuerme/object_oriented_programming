#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <string>
#include <stdexcept>
class Fraction {
    private:
        int numerator;
        int denominator;
        void reduce();
        int gcd(int a, int b);
    public:
        // Constructors
        Fraction(int numerator = 0, int denominator = 1);
        Fraction(const Fraction& other);
        Fraction(double value);
        // Arithmetic operators
        Fraction operator+(const Fraction& other) const;
        Fraction operator-(const Fraction& other) const;
        Fraction operator*(const Fraction& other) const;
        Fraction operator/(const Fraction& other) const;
        // Relational operators
        bool operator<(const Fraction& other) const;
        bool operator<=(const Fraction& other) const;
        bool operator==(const Fraction& other) const;
        bool operator!=(const Fraction& other) const;
        bool operator>=(const Fraction& other) const;
        bool operator>(const Fraction& other) const;
        // Typecast operators
        operator double() const;
        // String representation
        std::string to_string() const;
        // Stream operators
        friend std::istream& operator>>(std::istream& is, Fraction& fraction);
        friend std::ostream& operator<<(std::ostream& os, const Fraction& fraction);
};
#endif