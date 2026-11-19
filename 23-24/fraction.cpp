#include <iostream>
#include <cmath>
using namespace std;

class Fraction {
public:
    Fraction() : num(0), den(1) {}
    Fraction(int numerator, int denominator);

    int numerator() const { return num; }
    int denominator() const { return den; }

    Fraction sum(const Fraction& right) const;
    Fraction sub(const Fraction& right) const;
    Fraction mul(const Fraction& right) const;
    Fraction div(const Fraction& right) const;

    static int gcd(int a, int b);
    static void normalise(int& numerator, int& denominator);
    void write() const;

private:
    int num; 
    int den; 
};

Fraction::Fraction(int numerator, int denominator) {
    if (denominator < 0) {
        numerator *= -1;
        denominator *= -1;
    }
    num = numerator;
    den = denominator;
    normalise(num, den);
}

int Fraction::gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

void Fraction::normalise(int& numerator, int& denominator) {
    int divisor = gcd(std::abs(numerator), denominator);
    numerator /= divisor;
    denominator /= divisor;
}

Fraction Fraction::sum(const Fraction& right) const {
    int new_num = num * right.denominator() + right.numerator() * den;
    int new_den = den * right.denominator();
    normalise(new_num, new_den);
    return Fraction(new_num, new_den);
}

Fraction Fraction::sub(const Fraction& right) const {
    int new_num = num * right.denominator() - right.numerator() * den;
    int new_den = den * right.denominator();
    normalise(new_num, new_den);
    return Fraction(new_num, new_den);
}

Fraction Fraction::mul(const Fraction& right) const {
    int new_num = num * right.numerator();
    int new_den = den * right.denominator();
    normalise(new_num, new_den);
    return Fraction(new_num, new_den);
}

Fraction Fraction::div(const Fraction& right) const {
    int new_num = num * right.denominator();
    int new_den = den * right.numerator();
    normalise(new_num, new_den);
    return Fraction(new_num, new_den);
}

void Fraction::write() const {
    cout << num << "/" << den;
}