#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <algorithm>   // for the transform() function
#include <string>
#include "MathOperations.h"

using namespace std;

// default constructor
MathOperations::MathOperations() {
    int operand1;  // the first operand for basic math operation
    int operand2;  // the second operand for basic math operation
    char theoperator; // the current operator;
    int answer;    // the correct answer
}

// set the private data members: operand1 and operand2
// to op1 and op2 respectively
void MathOperations::setOperands(int op1, int op2) {
    operand1 = op1;
    operand2 = op2;
}

//*** "getOp1" and "getOp2"added to retrieve operand1 and operand1 ***
int MathOperations::getOp1() const {
    return operand1;
}
int MathOperations::getOp2() const {
    return operand2;
}

// get the current value of the private data member: theoperator
char MathOperations::getOperator() const {

    char op = theoperator;

    return op;
}

// return the value of the data member: answer
int MathOperations::getAnswer() const {
    /*int input = answer;

    cin >> input;
    checkAnswer(input);
    return input;*/
    return answer;
}

// set theoperator to '+'
// apply the addition operation to operand1 and operand2
// set the answer equal to operand1 + operand2
void  MathOperations::Addition() {
    theoperator = '+';

    answer = operand1 + operand2;
}

// set theoperator to '-'
// apply the subtraction operation to operand1 and operand2
// set the answer equal to operand1 - operand2
void  MathOperations::Subtraction() {
    theoperator = '-';

    answer = operand1 - operand2;
}

// set theoperator to '*'
// apply the multiplication operation to operand1 and operand2
// set the answer equal to operand1 * operand2
void  MathOperations::Multiplication() {
    theoperator = '*';

    answer = operand1 * operand2;
}

// set theoperator to const DivisionSymbol, it is ASCII code for obelus
// apply the division operation to operand1 and operand2
// set the answer equal to operand1 / operand2
void  MathOperations::Division() {
    theoperator = '/';

    answer = operand1 / operand2;
}

// if answer == response, it returns true
// otherwise it returns false
bool  MathOperations::checkAnswer(int response) const {

    if (answer == response) {
        //cout << "Congratulations! " << answer << " is the right answer." << endl;
        return true;
    }
    else {
        //cout << "Sorry, the correct answer is " << answer << "." << endl;
        return false;
    }
}

//display the question in the format described in the problem statement
// for example:
//    135
//  +  78
//  _____
//
void  MathOperations::print() const {
    cout << setw(5) << right << operand1 << endl;
    cout << theoperator;
    cout << setw(4) << right << operand2 << endl;
    cout << right << "-----" << endl;
    getAnswer();
}