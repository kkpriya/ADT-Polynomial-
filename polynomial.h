
#ifndef ADT_POLYNOMIAL_H
#define ADT_POLYNOMIAL_H

#endif //ADT_POLYNOMIAL_H

#include <string>
#include <vector>

struct p{
    //what consists in the vector
    int coefficient;
    int degree;
};

class polynomial {

    public:
        std ::vector<p> poly; //stores original polynomial
        std ::vector<p> poly2; //stores polynomial that is being added
        std ::vector<p> poly3; //stores sum of 2 polynomials
        std ::vector<p> poly4; //stores the answer of the multiplication
        polynomial(); //default constructor
        void readFromUser(); //asks user what they want to do and stores polynomial
        int degree(); //returns the highest degree of a polynomial
        int coefficient(int power); //returns the coefficient of a certain degree
        void changeCoefficient(int newCoefficient, int power); //changes the coefficient of a certain degree
        void multiplyPolynomial(int multiplier); //multiplies the polynomial with the integer asked from user
        int addPolynomial(std ::vector<p> add, std ::vector<p> poly3); //adds 2 polynomials
        void printPolynomial(std ::vector<p> print); //prints the polynomial
        polynomial operator-(); //negates the polynomial


};