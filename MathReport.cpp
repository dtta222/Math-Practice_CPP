#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
#include "MathOperations.h"
#include "MathReport.h"
#include <vector>

// default constructor
MathReport::MathReport() {
	numCorrectAnswers = 0;  // number of correctly answered questions
	numWrongAnswers = 0;  // number of wrong answers

}


// add a Question object into the vector of mathQuestions
// and the response to check with the correct answer: 
//    if response is correct, increase numCorrectAnswers
//    otherwise, increase numWrongAnswers
void MathReport::insert(MathOperations newQuestions, int response) {

	mathQuestions.push_back(newQuestions);

	int answer = newQuestions.getAnswer();

	/*mathQuestions.begin(newQuestions.print());
	cout << mathQuestions[0];*/

	if (response == answer) {
		numCorrectAnswers += 1;
	}
	else {
		numWrongAnswers += 1;
	}
}


// return the value of numCorrectAnswers
int MathReport::getNumOfCorrectAnswers() const {

	return numCorrectAnswers;
}


// return the value of numWrongAnswers
int MathReport::getNumOfWrongAnswers() const {

	return numWrongAnswers;
}


// generate a brief report
void MathReport::generateReport() const {

	cout << "You have solved the follwing " << mathQuestions.size() << " math problems: (display correct answer only)" << endl;

	//*** "getOp1" and "getOp2"added to retrieve operand1 and operand1 ***
	for (int i = 0; i < mathQuestions.size(); i++) {

		cout << endl << "Question " << i + 1 << ":" << endl;
		cout << setw(5) << right << mathQuestions[i].getOp1() << endl;
		cout << mathQuestions[i].getOperator();
		cout << setw(4) << right << mathQuestions[i].getOp2() << endl;
		cout << right << "-----" << endl;
		cout << setw(5) << right << mathQuestions[i].getAnswer() << endl;
	}

	cout << "---------------------------------" << endl;
	cout << "You answered " << numCorrectAnswers << " questions correctly." << endl;
	cout << "You made " << numWrongAnswers << " mistakes." << endl;
	if (numCorrectAnswers > numWrongAnswers) {
		cout << "Great job!" << endl;
	}
	else {
		cout << "You will do better next time..." << endl;
	}

}