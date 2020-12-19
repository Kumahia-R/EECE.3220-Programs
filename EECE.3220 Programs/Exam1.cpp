/*
	M. Geiger
	EECE.3220: Data Structures
	Code for Summer 2020 Midterm
	string.cpp: Program to test understanding of C++ strings
*/

#include <string>
#include <iostream>
using namespace std;

// Finds the longest matching substring in the two arguments
//   s1 and s2 and returns it
string longestSubMatch(string s1, string s2) {
	unsigned i, j;		// Loop indexes
	string longest;	// Current longest matching substring
	string sub;			// Substring to search for
	//char addSub;
	int streak = 1;
   /***** ADD YOUR OWN CODE HERE TO CORRECTLY COMPLETE THIS FUNCTION *****/
	for (i = 0; i < s1.length()-1; i++) {
		
		//addSub = s1.at(i);
		for (j = 0; j < s1.length()-i; j++) {
			if (s1.size() < s2.size()) {
				if (s1.at(i + streak) == s2.at(j)) {
					sub += s2.at(j);
						streak++;
				}
				else {
					streak = 0;
						if (sub.length() > longest.length()) {
							longest = sub;
						}
					sub.erase();
				}
			}
			else {
				if (i + streak < s2.size() && s2.at(i + streak) == s1.at(j)) {
					sub += s1.at(j);
					streak++;
				}
				else {
					streak = 0;
					if (sub.length() > longest.length()) {
						longest = sub;
					}
					sub.erase();
				}
			}
			
		}
		if (sub.length() > longest.length()) {
			longest = sub;
		}
		sub.erase();
	}
	return longest;
}

int main() {
	string test1 = "EECE.3220";
	string test2 = "ECE Application Programming";
	string test3 = "program";
	string test4 = "Vacation";
	string L;

	cout << "Longest matching substring in \"" << test1 << "\" and \"" << test2
		<< "\" is: \"" << longestSubMatch(test1, test2) << "\"\n";
	cout << "Longest matching substring in \"" << test2 << "\" and \"" << test3
		<< "\" is: \"" << longestSubMatch(test2, test3) << "\"\n";
	cout << "Longest matching substring in \"" << test2 << "\" and \"" << test4
		<< "\" is: \"" << longestSubMatch(test2, test4) << "\"\n";
	cout << "Longest matching substring in \"" << test3 << "\" and \"" << test4
		<< "\" is: \"" << longestSubMatch(test3, test4) << "\"\n";
	cout << "Longest matching substring in \"" << test1 << "\" and \"" << test3
		<< "\" is: \"" << longestSubMatch(test1, test3) << "\"\n";



	L = longestSubMatch(test1, test2);

	return 0;
}