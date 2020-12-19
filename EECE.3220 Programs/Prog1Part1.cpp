#include <iostream>
#include <cmath>                   // Note: Needed for math functions in part (3)
#include <iomanip>
using namespace std;

int main() {
    double wallHeight;
    double wallWidth;
    double wallArea;

    cout << "Enter wall height (feet):" << endl;
    cin >> wallHeight;
    cout << "Enter wall width (feet):" << endl;
    cin >> wallWidth;               // FIXME (1): Prompt user to input wall's width

    // Calculate and output wall area
    wallArea = wallHeight * wallWidth;                 // FIXME (1): Calculate the wall's area
    cout << "Wall area: " << setprecision(2) << fixed << wallArea << " square feet" << endl;  // FIXME (1): Finish the output statement


    // FIXME (2): Calculate and output the amount of paint in gallons needed to paint the wall
    double paintNeeded;
    paintNeeded = wallArea / 350;
    cout << "Paint needed: " << paintNeeded << " gallons" << endl;
    // FIXME (3): Calculate and output the number of 1 gallon cans needed to paint the wall, rounded up to nearest integer
    int cansNeeded;
    cansNeeded = ceil(paintNeeded);
    cout << "Cans Needed: " << cansNeeded << " can(s)" << endl;
    return 0;
}