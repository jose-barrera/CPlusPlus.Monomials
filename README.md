# Monomials

A monomial **M(x)** is a product of powers of the variable *x* having nonnegative integer exponents and a real coefficient.

This project uses **object oriented paradigm** to define and implement a class that represents a monomial and has the following:
    
PROPERTIES
* coefficient (read-only)
* exponent (read-only)

METHODS
* add
* subtract
* multiply
* divide
* evaluate

Notes:
1. *To add or subtract two monomial, both must have equal exponents. The result is also a monomial.*
2. *To multiply two monomials, there are no restrictions. The result is also a monomial.*
3. *To divide two monomials, coefficient of divisor must be different than zero, and exponent of dividend must be equal or greater than the exponent of divisor. The result is also a monomial.*
