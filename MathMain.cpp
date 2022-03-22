/*
 * Project: Math Practice
 * Purpose: this program can be used as a math tutor for a young student.
 *          it repeatedly allow the user to practice solving Multiplication questions untill the user inputs "5" to stop
 *          when the practice for the user stops, this program generates the report:
 *          (1) the list of questions with correct answers which the user has practiced;
 *          (2) the total number of questions the user has solved;
 *          (3) the total number of mistakes the user has made;
 *          (4) display either "Great job!"(if (2) > (3)) or "You will do better next time..." (otherwise)
 *          it then quits the program.
 * Author: David Taylor
 */

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "MathOperations.h"
#include "MathReport.h"

using namespace std;

int main()
{
    string choice;     // The user's choice: either answer the question or quit
    MathReport userReport;  // The user report for using Math Tutor program
    bool check_input = false; // checks for valid user input
    // Seed the random number generator.
    srand(time(0));
    // loops if user input is invalid
    while (check_input == false) {

        cout << "\tMath Is Fun! Take a challenge..." << endl;
        cout << "----------------------------------------------" << endl;
        cout << "1. Addition problem" << endl;
        cout << "2. Subtraction problem" << endl;
        cout << "3. Multiplication problem" << endl;
        cout << "4. Division problem" << endl;
        cout << "5. Quit this program" << endl;
        cout << "----------------------------------------------" << endl;
        cout << "Enter your choie (1-5): ";
        // get user input
        getline(cin, choice);

        // if input is "1", "2", "3", "4", or "5" changes input check to true
        if (choice == "1" || choice == "2" || choice == "3" || choice == "4" || choice == "5") {
            check_input = true;
        }

        if (check_input == false) {
            cout << "Invalid choice! The valid choices are 1, 2, 3, 4, and 5." << endl;
        }
    }
   
    while (choice != "5") {
        int num1;          // The first random number
        int num2;          // The second random number
        int studentAnswer; // The student's answer
        MathOperations question; // the question for user to solve

        bool check_input = false; // resets input check if user continues program

        // Addition function
        if (choice == "1") {
            // Generate two random numbers: 
        // The first one is in the range of [1, 500];
        // The second one is in the range of [1, 500].
            num1 = 1 + rand() % 500;
            num2 = 1 + rand() % 500;
            question.setOperands(num1, num2);

            question.Addition();
        }

        // Subtraction function
        else if (choice == "2") {
            // check for negative numbers
            int negative_check = -1;
            
            // loops if answer is negative
            while (negative_check < 0) {
            // Generate two random numbers: 
            // The first one is in the range of [1, 500];
            // The second one is in the range of [1, 500].
                num1 = 1 + rand() % 500;
                num2 = 1 + rand() % 500;
                negative_check = num1 - num2;

            }
            question.setOperands(num1, num2);

            question.Subtraction();
        }

        // Multiplication function
        else if (choice == "3") {
        // Generate two random numbers: 
        // The first one is in the range of [1, 100];
        // The second one is in the range of [1, 9].
            num1 = 1 + rand() % 100;
            num2 = 1 + rand() % 9;
            question.setOperands(num1, num2);

            question.Multiplication();
        }

        // Division function
        else if (choice == "4") {
            // remainder check
            int r_check = 1;
        
            while (r_check != 0) {
            // loops if answer is has a remainder
               
                // Generate two random numbers: 
                // The first one is in the range of [1, 999];
                // The second one is in the range of [1, 9].
            
                num1 = 1 + rand() % 999;
                num2 = 1 + rand() % 9;
                r_check = num1 % num2;
            }
            question.setOperands(num1, num2);

            question.Division();
        }

        // Display the problem.
        question.print();
        cout << "Your answer is: ";
        cin >> studentAnswer;
        cin.ignore(256, '\n');

        // user input validation
        // if the user input is invalid, allow the user to try again
        while (cin.fail()) {
            cin.clear(); // reset the status to "good"
            cin.ignore(256, '\n'); // clean the leftover in the pipe
            cout << "Invalid input! Please try again..." << endl;
            cout << "Your answer is: ";
            cin >> studentAnswer;
            cin.ignore(256, '\n');
        }

        // when the user input is valid
        // check if it is the correct answer
        if (question.checkAnswer(studentAnswer)) {
            cout << "Congratulations! " << studentAnswer << " is the right answer." << endl;
        }
        else {
            cout << "Sorry, the correct answer is " << question.getAnswer() << "." << endl;
        }

        //add the current question and the user answer into the user report
        userReport.insert(question, studentAnswer);

        // loops if user input is invalid
        while (check_input == false) {

            cout << "\tMath Is Fun! Take a challenge..." << endl;
            cout << "----------------------------------------------" << endl;
            cout << "1. Addition problem" << endl;
            cout << "2. Subtraction problem" << endl;
            cout << "3. Multiplication problem" << endl;
            cout << "4. Division problem" << endl;
            cout << "5. Quit this program" << endl;
            cout << "----------------------------------------------" << endl;
            cout << "Enter your choie (1-5): ";
            // get user input
            getline(cin, choice);

            // if input is "1", "2", "3", "4", or "5" changes input check to true
            if (choice == "1" || choice == "2" || choice == "3" || choice == "4" || choice == "5") {
                check_input = true;
            }

            if (check_input == false) {
                cout << "Invalid choice! The valid choices are 1, 2, 3, 4, and 5." << endl;
            }
        }
    }

    // generate the user report for using Math Tutor
    cout << endl;
    userReport.generateReport();
    cout << "Thank you for using Math Tutor." << endl;
    return 0;
}