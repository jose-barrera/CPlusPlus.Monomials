#include "Monomial.h"
#include <iostream>
#include <stdexcept>
#include <math.h>
#include <string>
#include <regex>

using namespace std;

/*
 *     A monomial M(x) is a product of powers of the variable x
 *     having nonnegative integer exponents and a real coefficient.
 *
 *     This class represents a monomial and has the following:
 *
 *     PROPERTIES
 *     * coefficient (read-only)
 *     * exponent (read-only)
 *
 *     METHODS
 *     * add
 *     * subtract
 *     * multiply
 *     * divide
 *     * evaluate
 *
 *     Notes:
 *
 *     1. To add or subtract two monomial, both must have equal
 *        exponents. The result is also a monomial.
 *     2. To multiply two monomials, there are no restrictions.
 *        The result is also a monomial.
 *     3. To divide two monomials, coefficient of divisor must
 *        be different than zero, and exponent of dividend must
 *        be equal or greater than the exponent of divisor. The
 *        result is also a monomial.
 *
 */

//
// CONSTRUCTORS
//

// This constructor assumes that M(x) = 0
Monomial::Monomial()
{
    this->coefficient = 0;
    this->exponent = 0;
}

// This constructor receives coefficient and exponent.
Monomial::Monomial(double coefficient, int exponent)
{
    // Exponent must be a nonnegative integer.
    if (exponent >= 0)
    {
        this->coefficient = coefficient;
        this->exponent = exponent;
    }
    else
    {
        // Throws a runtime error.
        throw invalid_argument("Exponent must be a nonnegative integer.");
    }
}

//
// PROPERTIES
//

double Monomial::getCoefficient()
{
    return this->coefficient;
}

int Monomial::getExponent()
{
    return this->exponent;
}

//
// METHODS
//

Monomial Monomial::add(Monomial monomial)
{
    // To add monomials, both exponents must be equal.
    if (this->exponent == monomial.exponent)
    {
        return Monomial(this->coefficient + monomial.getCoefficient(), this->exponent);
    }
    else
    {
        throw invalid_argument("ADD: Invalid operation.");
    }
}

Monomial Monomial::subtract(Monomial monomial)
{
    // To subtract monomials, both exponents must be equal.
    if (this->exponent == monomial.exponent)
    {
        return Monomial(this->coefficient - monomial.getCoefficient(), this->exponent);
    }
    else
    {
        throw invalid_argument("SUBTRACT: Invalid operation.");
    }
}

Monomial Monomial::multiply(Monomial monomial)
{
     return Monomial(this->coefficient * monomial.getCoefficient(), this->exponent + monomial.getExponent());
}

Monomial Monomial::divide(Monomial divisor)
{
    // To divide monomials, coefficient of divisor must be different
    // than zero and exponent of dividend must be equal or greater than
    // exponent of divisor.
    if (divisor.getCoefficient() != 0 && this->exponent >= divisor.getExponent())
    {
        return Monomial(this->coefficient / divisor.getCoefficient(), this->exponent - divisor.getExponent());
    }
    else
    {
        throw invalid_argument("DIVIDE: Invalid operation.");
    }
}

double Monomial::evaluate(double value)
{
    return this->coefficient * pow(value, this->exponent);
}

//
// AUXILIARY FUNCTIONS
//

ostream& operator<<(ostream& out, const Monomial& monomial)
{
    double coefficient = monomial.coefficient;
    int exponent = monomial.exponent;
    string result, sign, value, power;

    // String representation of sign is "+" or "-" depending
    // if coefficient is positive or negative.
    sign = coefficient >= 0 ? "+ " : "- ";

    // String representation of coefficient is the absolute
    // value of the coefficient.
    value = to_string(abs(coefficient));

    // If exponent is 0, power is equal to "1";
    // if exponent is 1, string representation of power is "x";
    // if exponent is greater than 1, string representation of
    // power is "x^" followed by exponent value.
    switch (exponent) {
        case 0:
            power = "";
            break;
        case 1:
            power = " x";
            break;
        default:
            power = " x^" + to_string(exponent);
            break;
    }

    // SPECIAL CASE: Coefficient is 0, consequently the
    // monomial is zero.
    if (coefficient == 0)
    {
        result = "+ 0";
    }
    else
    {
        result = sign + value + power;
        // "1x" is commonly written as only "x".
        result = regex_replace(result, regex(" 1.000000 x"), " x");
    }

    out << result;

    return out;
}
