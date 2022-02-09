#include <string>
#include <vector>
#include <iostream>
#include <locale> 
#include <algorithm>
#include <unordered_map>
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
	if (currentStringVector.empty()) {
		string testWord;

		for (int i = 0; i < candidateStringVector.size(); i++)
			testWord += candidateStringVector[i];
		if (isPalindrome(testWord))
			numPalin++;
		
		std::cout << testWord << std::endl;
		return;
	}
	
	// start for loop of recursion
	for (int i = 0; i < currentStringVector.size(); i++) {

		// edit the string vectors towards current string empty
		candidateStringVector.push_back(currentStringVector[i]); // add the first element of the words vector to the candidate
		currentStringVector.erase(currentStringVector.begin() + i); // remove the first element of the words vector
		
		// recurse
		recursiveFindPalindromes(candidateStringVector, currentStringVector);

		currentStringVector.insert(currentStringVector.begin(), candidateStringVector.back()); // add word back to current
		candidateStringVector.pop_back(); // remove word from candidate
	}
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
	// count characters
	// if odd number of characters: you can only have one char with odd amount
	// if even number of char: you can have 0 with odd amount
	
	return false;
}

bool FindPalindrome::cutTest2(const vector<string> & stringVector1,
                              const vector<string> & stringVector2)
{
	// TODO need to implement this...
	return false;
}

bool FindPalindrome::add(const string & value)
{	
	// check for in correct range of characters
	for (int i = 0; i < value.size(); i++)
		if (!((value[i] >= 'a' && value[i] <= 'z') || (value[i] >= 'A' && value[i] <= 'Z')))
			return false;

	// if word is already in words vector, return false
	if (std::count(words.begin(), words.end(), value))
		return false;
	
	// else, add word
	words.push_back(value);

	// reset number of palindromes in instance of class
	numPalin = 0;

	// create temp blank vector and recompute palindromes
	vector<string> temp;
	recursiveFindPalindromes(temp, words);

	return true;
}

bool FindPalindrome::add(const vector<string> & stringVector)
{
	// for each word in vector, check all the characters for range - check word for existance in words vector already
	for (int i = 0; i < stringVector.size(); i++) {
		std::string tempString = stringVector[i];
		for (int j = 0; j < tempString.size(); j++)
			if (!((tempString[j] >= 'a' && tempString[j] <= 'z') || (tempString[j] >= 'A' && tempString[j] <= 'Z')))
				return false;

		if (std::count(words.begin(), words.end(), tempString)) 
			return false;
	
		words.push_back(tempString);
	}

	// reset number of palindromes in instance of class
	numPalin = 0;

	// create temp blank vector and recompute palindromes
	vector<string> temp;
	recursiveFindPalindromes(temp, words);

	return true;
}

vector< vector<string> > FindPalindrome::toVector() const
{
	// TODO need to implement this...
	vector<vector<string>> returnThingie;
	return returnThingie;
}

