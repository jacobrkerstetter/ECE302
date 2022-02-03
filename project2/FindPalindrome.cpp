#include <string>
#include <vector>
#include <iostream>
#include <locale> 
#include "FindPalindrome.hpp"

using namespace std;

//------------------- HELPER FUNCTIONS -----------------------------------------

// non-class helper functions go here, should be declared as "static" so that
// their scope is limited

// helper function to convert string to lower case
static void convertToLowerCase(string & value)
{
	locale loc;
	for (int i=0; i<value.size(); i++) {
		value[i] = tolower(value[i],loc);
	}
}

//------------------- PRIVATE CLASS METHODS ------------------------------------

// private recursive function. Must use this signature!
void FindPalindrome::recursiveFindPalindromes(vector<string>
        candidateStringVector, vector<string> currentStringVector)
{
	// base case: when currentStringVector is empty
	if (currentStringVector.empty())
		return;
	
	recursiveFindPalindromes(candidateStringVector.push_back(currentStringVector.back()), currentStringVector.pop_back());

	string testWord;

	for (int i = 0; i < candidateStringVector.size(); i++)
		testWord += candidateStringVector[i];
	if (isPalindrome(testWord))
		numPalin++;

	return;


	// current: remaining words that could be added to candidate
}

// private function to determine if a string is a palindrome (given, you
// may change this if you want)
bool FindPalindrome::isPalindrome(string currentString) const
{
	locale loc;
	// make sure that the string is lower case...
	convertToLowerCase(currentString);
	// see if the characters are symmetric...
	int stringLength = currentString.size();
	for (int i=0; i<stringLength/2; i++) {
		if (currentString[i] != currentString[stringLength - i - 1]) {
			return false;
		}
	}
	return true;
}

//------------------- PUBLIC CLASS METHODS -------------------------------------

FindPalindrome::FindPalindrome() : numPalin(0) {}

FindPalindrome::~FindPalindrome() {}

int FindPalindrome::number() const
{
	return numPalin;
}

void FindPalindrome::clear()
{
	words.clear();
	numPalin = 0;
}

bool FindPalindrome::cutTest1(const vector<string> & stringVector)
{
	string temp(stringVector.begin(), stringVector.end());
	
	return isPalindrome(temp);
}

bool FindPalindrome::cutTest2(const vector<string> & stringVector1,
                              const vector<string> & stringVector2)
{
	// TODO need to implement this...
	return false;
}

bool FindPalindrome::add(const string & value)
{	
	
}

bool FindPalindrome::add(const vector<string> & stringVector)
{
	// check each word in the vector for validity
	// if the words are valid, set words vector equal to stringVector
	// call recursive shit
	return false;
}

vector< vector<string> > FindPalindrome::toVector() const
{
	// TODO need to implement this...
	vector<vector<string>> returnThingie;
	return returnThingie;
}

