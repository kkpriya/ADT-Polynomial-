#include "polynomial.h"
#include <iostream>
#include <iomanip>

using namespace std;

p info;


//default constructor
polynomial ::polynomial() {
    info.degree = NULL;
    info.coefficient = NULL;
}

//derives information from the user
void polynomial ::readFromUser() {

    int num;

    cout << "Please enter accordingly to obtain a polynomial. How many terms will you be entering?\n";
    cout << "\te.g., p = 5x^2 + 3x + 4 are 3 terms" << endl;
    cin >> num;

    cout<<"Enter in accordingly. If you are entering a constant number, enter 0 for degree."<<endl;

    for (int i = 1; i <= num; i++){
        cout << "Term "<< i <<" coefficient: ";
        cin >> info.coefficient;
        cout << "Term "<< i <<" degree: ";
        cin >> info.degree;
        poly.push_back(info);
        cout <<"\n";
    }
        cout << "-------------------------------------------------------------------------------\n";
        int pick;
        cout << "You could do the following with the polynomial:\n1)Check the Highest Degree\n2)Check the coefficient of a certain degree\n3)Replace the coefficient of x^degree term\n4)Multiply it with an integer\n5)Add a polynomial\n6)Print polynomial" <<endl;
        cout << "Enter in the number of what you would like to work with: ";
        cin >> pick;
        switch(pick){
            case 1:
                cout <<"The highest degree is: " << degree();
                break;
            case 2:
                int power;
                cout <<"enter the degree: ";
                cin >> power;
                cout << "The coefficient is: " <<coefficient(power);
                break;
            case 3:
                int coeff; int deg;
                cout <<"enter the coefficient: "; cin >> coeff;
                cout <<"enter the degree: "; cin >> deg;
                changeCoefficient(coeff, deg);
                break;
            case 4:
                int multiplier;
                cout << "What number would you like to multiply with your polynomial?";
                cin >> multiplier;
                multiplyPolynomial(multiplier);
                break;
            case 5:
                cout << "Enter in the polynomial accordingly to add to with polynomial: " <<endl;
                for (int i = 1; i <= num; i++) {
                    cout << "Term " << i << " coefficient: ";
                    cin >> info.coefficient;
                    cout << "Term " << i << " degree: ";
                    cin >> info.degree;
                    poly2.push_back(info);
                }
                addPolynomial(poly2, poly3);
                break;
            case 6:
                printPolynomial(poly);
                break;
            default:
                cout<<"invalid output"<<endl;
                break;
        }

}

//returns the highest degree of the polynomial
int polynomial :: degree() {

    int high = 0;
    for (int i = 0; i < poly.size(); i++){
        if (high <= poly[i].degree){
            high = poly[i].degree;
        }
    }
    return high;
}

//returns the coefficient of a certain power
int polynomial ::coefficient(int power) {

    for (int i = 0; i < poly.size(); i++){
        if(power == poly[i].degree){
            return poly[i].coefficient;
        }
    }
}

//replaces the coefficient of a certain power
void polynomial ::changeCoefficient(int newCoefficient, int power) {

    for (int i = 0; i < poly.size(); i++){
        if(power == poly[i].degree){
            poly[i].coefficient = newCoefficient;
        }
    }
    cout << "\nThe new polynomial is: ";
    printPolynomial(poly);
}

//multiplies the polynomial with an integer
void polynomial ::multiplyPolynomial(int multiplier) {

    for (int i = 0; i < poly.size(); i++){
            info.coefficient = poly[i].coefficient* multiplier;
            info.degree = poly[i].degree;
            poly4.push_back(info);
    }
    cout << "\nThe new polynomial is: ";
    printPolynomial(poly4);

}

//adds 2 polynomials
int polynomial ::addPolynomial(vector<p> add, vector<p> poly3) {

   for (int i = 0; i < poly.size(); i++){
        for (int j = 0; i < add.size(); i++){
            if(poly[i].degree == add[j].degree){
               info.coefficient = poly[i].coefficient + add[j].coefficient;
               info.degree = poly[i].degree;
               poly3.push_back(info);
            } else{
                info.coefficient = poly[i].coefficient;
                info.degree = poly[i].degree;
                poly3.push_back(info);
            }
        }

    }
    cout << "The new polynomial is: ";
    printPolynomial(poly3);

}

//prints the polynomial
void polynomial ::printPolynomial(vector<p> print) {

    cout <<"\np = ";
    for(int i = 0; i < print.size(); i++){
        if(i ==  print.size()-1){
            cout << print[i].coefficient << "x^" << print[i].degree;
        }else {
            cout << print[i].coefficient << "x^" << print[i].degree << " + ";
        }
    }

}

//negates the polynomial
polynomial polynomial ::operator-() {
    for(int i = 0; i < poly.size();i++){
        poly[i].coefficient*= -1;
    }
    cout <<"\n\nThe negation of your polynomial you initially entered is: ";
    printPolynomial(poly);
}

