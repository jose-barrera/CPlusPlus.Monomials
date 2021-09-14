#include <iostream>
#include "Monomial.h"

using namespace std;

void testMonomialStringRepresentation()
{
    cout << Monomial(0, 0) << endl;
    cout << Monomial(0, 1) << endl;
    cout << Monomial(0, 5) << endl;
    cout << Monomial(1, 0) << endl;
    cout << Monomial(1, 1) << endl;
    cout << Monomial(1, 5) << endl;
    cout << Monomial(7.5, 0) << endl;
    cout << Monomial(7.5, 1) << endl;
    cout << Monomial(7.5, 5) << endl;
    cout << Monomial(-0, 0) << endl;
    cout << Monomial(-0, 1) << endl;
    cout << Monomial(-0, 5) << endl;
    cout << Monomial(-1, 0) << endl;
    cout << Monomial(-1, 1) << endl;
    cout << Monomial(-1, 5) << endl;
    cout << Monomial(-7.5, 0) << endl;
    cout << Monomial(-7.5, 1) << endl;
    cout << Monomial(-7.5, 5) << endl;
    cout << Monomial(91, 0) << endl;
    cout << Monomial(91, 1) << endl;
    cout << Monomial(91, 5) << endl;
}

int main()
{
    // testMonomialStringRepresentation();

    cout << "This program allows to perform basic arithmetic with two" << endl;
    cout << "monomials, assuming that conditions are complied." << endl;
    cout << "" << endl;

    cout << "*** MONOMIAL 1 ***" << endl;
    cout << "Write the coefficient 1: " << endl;
    double c1;
    cin >> c1;
    cout << "Write the exponent 1: " << endl;
    int e1;
    cin >> e1;
    cout << "" << endl;
    Monomial M1 = Monomial(c1, e1);

    cout << "*** MONOMIAL 2 ***" << endl;
    cout << "Write the coefficient 2: " << endl;
    double c2;
    cin >> c2;
    cout << "Write the exponent 2: " << endl;
    int e2;
    cin >> e2;
    cout << "" << endl;
    Monomial M2 = Monomial(c2, e2);

    bool valid_sum = true;
    bool valid_difference = true;
    bool valid_quotient = true;

    Monomial sum;
    Monomial difference;
    Monomial product;
    Monomial quotient;

    // Monomial addition: M1 + M2
    try
    {
        sum = M1.add(M2);
        cout << "SUM: " << sum << endl;
    }
    catch (const invalid_argument& e)
    {
        valid_sum = false;
        cout << "SUM: Invalid operation." << endl;
    }
    // Monomial subtraction: M1 - M2
    try
    {
        difference = M1.subtract(M2);
        cout << "DIFFERENCE: " << difference << endl;
    }
    catch (const invalid_argument& e)
    {
        valid_difference = false;
        cout << "DIFFERENCE: Invalid operation." << endl;
    }
    // Monomial multiplication: M1 * M2
    product = M1.multiply(M2);
    cout << "PRODUCT: " << product << endl;
    // Monomial division: M1 / M2;
    try
    {
        quotient = M1.divide(M2);
        cout << "QUOTIENT: " << quotient << endl;
    }
    catch (const invalid_argument& e)
    {
        valid_quotient = false;
        cout << "QUOTIENT: Invalid operation." << endl;
    }
    cout << endl;

    cout << "Write the value to evaluate: " << endl;
    double value;
    cin >> value;
    cout << endl;

    cout << "Value of M1 is " << M1.evaluate(value) << endl;
    cout << "Value of M2 is " << M2.evaluate(value) << endl;
    if (valid_sum)
    {
        cout << "Value of M1 + M2 is " << sum.evaluate(value) << endl;
    }
    else
    {
        cout << "Value of M1 + M2 cannot be computed because is an invalid operation." << endl;
    }
    if (valid_difference)
    {
        cout << "Value of M1 - M2 is " << difference.evaluate(value) << endl;
    }
    else
    {
        cout << "Value of M1 - M2 cannot be computed because is an invalid operation." << endl;
    }
    cout << "Value of M1 * M2 is " << product.evaluate(value) << endl;
    if (valid_quotient)
    {
        cout << "Value of M1 / M2 is " << quotient.evaluate(value) << endl;
    }
    else
    {
        cout << "Value of M1 / M2 cannot be computed because is an invalid operation." << endl;
    }

    cout << "" << endl;
    cout << "THANK YOU FOR USING THIS PROGRAM!" << endl;

    return 0;
}
