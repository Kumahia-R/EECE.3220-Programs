/*
 * EECE.3220: Data Structures
 * Instructor: M. Geiger
 *
 * Time.cpp: Time function definitions
 * Includes blank definitions for overloaded operators to be written for Program 3
 */

#include "Time.h"	   // Necessary for Time class definition; implicitly includes <iostream>
#include <iomanip>	// Necessary for setw(), setfill()
using std::setw;
using std::setfill;

/*** OVERLOADED OPERATORS TO BE ADDED FOR PROGRAM 3 ***/
/*** PREVIOUSLY DEFINED FUNCTIONS START ON LINE 145 (BEFORE YOU START ADDING CODE) ***/
/*** UPDATED 10/11 TO FIX PARAMETERIZED CONSTRUCTOR, advance() ***/

// Output operator
ostream& operator <<(ostream& out, const Time& rhs) {
	Time print = rhs;
	print.display(out);
	/*************************************************
	* Print time using form:
	*    h:mm _M  or hh:mm _M
	* where:
	*    h or hh	= # of hours (1 or 2 digits)
	*    mm			= # of minutes (always 2 digits)
	*    _M			= AM or PM
	**************************************************/

	return out;
}

// Input operator
istream& operator >>(istream& in, Time& rhs) {
	char colon;
	in >> rhs.hours;
	in >> colon;
	in >> rhs.minutes;
	in >> rhs.AMorPM;
	in.ignore();
	/*************************************************
	* Read time assuming it is written in form:
	*    h:mm _M  or hh:mm _M
	* where:
	*    h or hh	= # of hours (1 or 2 digits)
	*    mm			= # of minutes (always 2 digits)
	*    _M			= AM or PM
	**************************************************/

	return in;
}

// Comparison operators
bool Time::operator ==(const Time& rhs) {
	if (hours == rhs.hours && minutes == rhs.minutes && AMorPM == rhs.AMorPM) {
		return true;
	}
	else {
		return false;
	}
	/********************************************
	* Returns true if calling object matches rhs,
	*   false otherwise
	*********************************************/

}

bool Time::operator !=(const Time& rhs) {
	if (hours == rhs.hours && minutes == rhs.minutes && AMorPM == rhs.AMorPM) {
		return false;
	}
	else {
		return true;
	}
	/**************************************************
	* Returns true if calling object doesn't match rhs,
	*   false otherwise
	***************************************************/

}

bool Time::operator <(const Time& rhs) {
	if (miltime < rhs.miltime) {
		return true;
	}
	else {
		return false;
	}
	/**********************************************
	* Returns true if calling object is less
	*   (earlier in day) than rhs, false otherwise
	***********************************************/

}

bool Time::operator >(const Time& rhs) {
	if (miltime > rhs.miltime) {
		return true;
	}
	else {
		return false;
	}
	/********************************************
	* Returns true if calling object is greater
	*   (later in day) than rhs, false otherwise
	*********************************************/

	return false;
}

// Arithmetic operators
Time Time::operator +(const Time& rhs) {
	Time sum;
	sum.advance(rhs.miltime/100, rhs.minutes);
	sum.advance(miltime/100, minutes);
	/********************************************
	* Add two Time objects and return sum
	*   See examples in spec
	*********************************************/

	return sum;
}


Time Time::operator -(const Time& rhs) {
	Time diff;
	if (rhs.miltime > miltime) {
		miltime += 2400;
		diff.miltime = (miltime - rhs.miltime);
	}
	else {
		diff.miltime = (miltime - rhs.miltime);
	}
	if (diff.miltime % 100 > 60) {
		diff.miltime -= 40;
	}
	if ((diff.miltime / 100) % 12 == 0 ) {
		diff.hours = 12;
	}
	else {
		diff.hours = (diff.miltime / 100) % 12;
	}
	diff.minutes = diff.miltime % 60;
	if (diff.miltime < 1200) {
		diff.AMorPM = 'A';
	}
	else {
		diff.AMorPM = 'P';
	}
	
	
	/*************************************************
	* Subtract two Time objects and return difference
	*   See examples in spec
	**************************************************/

	return diff;
}

Time& Time::operator +=(const Time& rhs) {
	advance(rhs.miltime / 100 , rhs.minutes);

	/**************************************************
	* Same as + operator, but modifies calling object
	*   and returns reference to calling object
	***************************************************/
	return *this;
}

Time& Time::operator -=(const Time& rhs) {
	if (rhs.miltime > miltime) {
		miltime += 2400;
		miltime -= rhs.miltime;
	}
	else {
		miltime = (miltime - rhs.miltime);
	}
	if (miltime % 100 > 60) {
		miltime -= 40;
	}
	if ((miltime / 100) % 12 == 0) {
		hours = 12;
	}
	else {
		hours = (miltime / 100) % 12;
	}
	minutes = miltime % 100;
	if (miltime < 1200) {
		AMorPM = 'A';
	}
	else {
		AMorPM = 'P';
	}

	/**************************************************
	* Same as - operator, but modifies calling object
	*   and returns reference to calling object
	***************************************************/
	return *this;
}

// Increment operators--adds 1 minute to current time
Time& Time::operator++() {
	advance(0, 1);
	return *this;
	/*************************
	* Pre-increment operator
	**************************/
}

Time Time::operator++(int) {
	Time newTime = *this;
	advance(0, 1);
	return newTime;
	/*************************
	* Post-increment operator
	**************************/
}
/*** END OVERLOADED OPERATORS TO BE ADDED FOR PROGRAM 3 ***/
/*** DO NOT MODIFY CODE BELOW THIS LINE ***/
// Default constructor
Time::Time() : hours(0), minutes(0), miltime(0), AMorPM('A')
{}

// Parameterized constructor
Time::Time(unsigned h, unsigned m, char AP) : hours(h), minutes(m), AMorPM(AP) {
	miltime = 100 * h + m;

	/*** FIXED 10/11: ORIGINAL VERSION DID NOT CORRECTLY HANDLE 12 AM OR 12 PM ***/
	if (AP == 'P' && h != 12)
		miltime += 1200;
	else if (AP == 'A' && h == 12)
		miltime -= 1200;
}

// Set time data members
void Time::set(unsigned h, unsigned m, char AP) {
	hours = h;
	minutes = m;
	AMorPM = AP;
	miltime = 100 * h + m;
	if (AP == 'P')
		miltime += 1200;
}

// Print time to desired output stream
void Time::display(ostream& out) {
	out << hours << ':'
		<< setw(2) << setfill('0') << minutes		// setw(2) forces minutes to be printed with 2 chars
		<< ' ' << AMorPM << 'M';					// setfill('0') adds leading 0 to minutes if needed
}

// Advance time by h hours, m minutes
// Use modulo arithmetic to ensure 
//   1 <= hours <= 12, 0 <= minutes <= 59
/*** FIXED 10/11: ORIGINAL VERSION DIDN'T WORK FOR ALL CASES AND WAS FAR TOO CONVOLUTED ***/
/***  NEW VERSION DOES ALL MATH ON MILTIME AND THEN CORRECTS HOURS, MINUTES ***/
void Time::advance(unsigned h, unsigned m) {

	unsigned tempMT = h * 100 + m;		// Temporary miltime representing amount
												//   of time to advance by, since math
												 //   is much easier using miltime!

	// If sum of minutes >= 60, need to account for extra hour added
	if (minutes + m >= 60)
		miltime = (miltime + tempMT + 40) % 2400;	// % 2400 ensures time between 0 & 2359
															 //   (since minutes adjustment guarantees
															 //    last two digits < 60)
	else
		miltime = (miltime + tempMT) % 2400;

	// Convert back from miltime to new hours/minutes
	hours = miltime / 100;

	// Special case 1: time in PM (other than 12 PM)
	if (hours > 12)
		hours -= 12;

	// Special case 2: 12:xx AM --> miltime / 100 = 0
	else if (hours == 0)
		hours = 12;

	minutes = miltime % 100;

	// Figure out if new time is in AM or PM
	AMorPM = (miltime < 1200 ? 'A' : 'P');
}

// Returns true if calling object is less than argument
bool Time::lessThan(const Time& rhs) {
	if (miltime < rhs.miltime)
		return true;
	else
		return false;
}