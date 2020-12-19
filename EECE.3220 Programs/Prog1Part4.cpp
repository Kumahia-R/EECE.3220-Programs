#include <iostream>
#include <string>
using namespace std;
int GetNumOfNonWSCharacters(string inString) {
	int numChars = 0;
	for (int i = 0; i < inString.size(); i++) {
		if (inString.at(i) != ' ') {
			numChars++;
		}
	}
	return numChars;
}
int GetNumOfWords(string inString) {
	int numWords = 0;
	for (int i = 0; i < inString.size(); i++) {
		if (inString.at(i) == ' ' && inString.at(i - 1) != ' ') {
			numWords++;
		}
	}
	numWords++;
	return numWords;
}
int FindText(string userSample, string inString) {
	int numInstances = 0;
	int index = 0;
	for (int i = 0; i < inString.size(); i++) {
		if (inString.find(userSample, index) != -1) {

			numInstances++;
			index = inString.find(userSample, index);
			index++;
		}
	}
	return numInstances;
}
void ReplaceExclamation(string& inString) {
	for (int i = 0; i < inString.size(); i++) {
		if (inString.at(i) == '!') {
			inString.replace(i, 1, ".");
		}
	}

}
void ShortenSpace(string& inString) {
	for (int i = 0; i < inString.size(); i++) {
		if (inString.find("  ") != -1) {
			inString.erase(inString.find("  "), 1);
		}
	}
}
void PrintMenu(string inString) {
	string menuChoice;
	int numWords;
	while (menuChoice.compare("q")) {
		cout << "MENU" << endl;
		cout << "c - Number of non-whitespace characters" << endl;
		cout << "w - Number of words" << endl;
		cout << "f - Find text" << endl;
		cout << "r - Replace all !'s" << endl;
		cout << "s - Shorten spaces" << endl;
		cout << "q - Quit" << endl << endl;
		cout << "Choose an option:" << endl;
		cin >> menuChoice;
		if (!menuChoice.compare("c")) {
			cout << "Number of non-whitespace characters: " << GetNumOfNonWSCharacters(inString) << endl;
			cout << endl;
		}
		if (!menuChoice.compare("w")) {
			cout << "Number of words: " << GetNumOfWords(inString) << endl;
			cout << endl;
		}
		if (!menuChoice.compare("f")) {
			string sample;
			cin.ignore();
			cout << "Enter a word or phrase to be found:" << endl;
			getline(cin, sample);

			cout << "\"" << sample << "\" instances: " << FindText(sample, inString) << endl;
			cout << endl;
		}
		if (!menuChoice.compare("r")) {
			ReplaceExclamation(inString);
			cout << "Edited text: " << inString << endl;
			cout << endl;
		}
		if (!menuChoice.compare("s")) {
			ShortenSpace(inString);
			cout << "Edited text: " << inString << endl;
			cout << endl;
		}
	}
}


int main() {
	string inputString;
	cout << "Enter a sample text:" << endl << endl;
	getline(cin, inputString);
	cout << "You entered: " << inputString << endl << endl;
	PrintMenu(inputString);
	return 0;
}