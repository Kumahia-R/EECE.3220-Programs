#include <iostream>
#include <string>
// FIXME include string library
using namespace std;

int main() {
    string inputString;
    cout << "Enter text:" << endl;
    getline(cin, inputString);
    cout << "You entered: " << inputString << endl;
    if (inputString.find("BFF") != string::npos) {
        inputString.replace(inputString.find("BFF"), 3, "best friend forever");
    }
    if (inputString.find("IDK") != string::npos) {
        inputString.replace(inputString.find("IDK"), 3, "I don't know");
    }
    if (inputString.find("JK") != string::npos) {
        inputString.replace(inputString.find("JK"), 2, "just kidding");
    }
    if (inputString.find("TMI") != string::npos) {
        inputString.replace(inputString.find("TMI"), 3, "too much information");
    }
    if (inputString.find("TTYL") != string::npos) {
        inputString.replace(inputString.find("TTYL"), 4, "talk to you later");
    }
    cout << "Expanded: " << inputString << endl;
    /* Type your code here. */

    return 0;
}