#ifndef MONOMIAL_H
#define MONOMIAL_H

#include <iostream>

using namespace std;

class Monomial
{
    private:
        double coefficient;
        int exponent;

    public:
        Monomial();
        Monomial(double coefficient, int exponent);
        double getCoefficient();
        int getExponent();
        Monomial add(Monomial monomial);
        Monomial subtract(Monomial monomial);
        Monomial multiply(Monomial monomial);
        Monomial divide(Monomial monomial);
        double evaluate(double value);
        friend ostream& operator<<(ostream& out, const Monomial& monomial);
};

#endif // MONOMIAL_H
