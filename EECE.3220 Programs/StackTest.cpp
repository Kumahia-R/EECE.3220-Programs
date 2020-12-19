/*
 * EECE.3220: Data Structures
 * Instructor: M. Geiger
 *
 * Exam 2 code
 * Main program to test Stack functions
 */

#include <iostream>
using namespace std;

#include "Stack.h"

int main() {
    unsigned part;              // Which part of the problem is being tested?
    Stack S1, S2(10), S3(256);  // Stacks to be used in part 1
    unsigned i;                 // Loop index
    double val;                 // Value to be pushed on stack

    cout << "Which part?  ";
    cin >> part;

    switch (part) {

    case 1:         // Code to test part 1 (print function)
        val = 1.1;
        for (i = 0; i < 5; i++) {
            S1.push(val);
            S2.push(100 - val);
            val *= 2;
        }
        S1.push(val);
        S1.push(0.3220);

        cout << "Printing S1:\n";
        S1.print(cout);
        cout << "\nPrinting S2:\n";
        S2.print(cout);
        cout << "\nPrinting S3:\n";
        S3.print(cout);
        break;

    case 2:         // Code to test part 2 ()
        for (i = 0; i < 5; i++) {
            S1.push(i);
            S2.push(5 - i);
        }
        S1.push(5);
        S1.push(6);

        cout << "S1 before swap:\n";
        S1.print(cout);
        cout << "\nS2 before swap:\n";
        S2.print(cout);

        S1.swap(S2);
        cout << "\nS1 after swap\n";
        S1.print(cout);
        cout << "\nS2 after swap\n";
        S2.print(cout);
        break;
    }

    return 0;
}