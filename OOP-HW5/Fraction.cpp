#include "Fraction.h"
#include <cmath>
using namespace std;

int Fraction::gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
void Fraction::reduce() {
    if (denominator == 0)
        throw invalid_argument("Errors: Cannot divide by zero.");
    int gcd_v = gcd(abs(numerator), abs(denominator));
    numerator /= gcd_v;
    denominator /= gcd_v;
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
}
Fraction::Fraction(int numerator, int denominator): numerator(numerator), denominator(denominator) {
    reduce();
}
Fraction::Fraction(const Fraction& other): numerator(other.numerator), denominator(other.denominator) {}
Fraction::Fraction(double value) {
    int decimal_places = 10000;
    numerator = round(value * decimal_places);
    denominator = decimal_places;
    reduce();
}
Fraction Fraction::operator+(const Fraction& other) const {
    return Fraction(numerator * other.denominator + other.numerator * denominator, denominator * other.denominator);
}
Fraction Fraction::operator-(const Fraction& other) const {
    return Fraction(numerator * other.denominator - other.numerator * denominator, denominator * other.denominator);
}
Fraction Fraction::operator*(const Fraction& other) const {
    return Fraction(numerator * other.numerator, denominator * other.denominator);
}
Fraction Fraction::operator/(const Fraction& other) const {
    if (other.numerator == 0)
        throw domain_error("Errors: Cannot divide by zero.");
    return Fraction(numerator * other.denominator, denominator * other.numerator);
}
bool Fraction::operator<(const Fraction& other) const {
    return numerator * other.denominator < other.numerator * denominator;
}
bool Fraction::operator<=(const Fraction& other) const {
    return numerator * other.denominator <= other.numerator * denominator;
}
bool Fraction::operator==(const Fraction& other) const {
    return numerator == other.numerator && denominator == other.denominator;
}
bool Fraction::operator!=(const Fraction& other) const {
    return !(*this == other);
}
bool Fraction::operator>=(const Fraction& other) const {
    return numerator * other.denominator >= other.numerator * denominator;
}
bool Fraction::operator>(const Fraction& other) const {
    return numerator * other.denominator > other.numerator * denominator;
}
Fraction::operator double() const {
    return static_cast<double>(numerator) / static_cast<double>(denominator);
}
string Fraction::to_string() const {
    if (denominator == 1)
        return std::to_string(numerator);
    return std::to_string(numerator) + "/" + std::to_string(denominator);
}

istream& operator>>(istream& is, Fraction& fraction) {
    char separator;
    is >> fraction.numerator >> separator >> fraction.denominator;
    if (separator != '/')
        is.setstate(std::ios_base::failbit);
    else
        fraction.reduce();
    return is;
}
ostream& operator<<(ostream& os, const Fraction& fraction) {
    os << fraction.to_string();
    return os;
}