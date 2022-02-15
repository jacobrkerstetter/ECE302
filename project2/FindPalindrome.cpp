#include <string>
#include <vector>
#include <iostream>
#include <locale> 
#include <algorithm>
#include <unordered_map>
#include <set>
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
		std::string testWord;

		for (string s : candidateStringVector)
			testWord += s;

		if (isPalindrome(testWord)) {
			palindromes.push_back(candidateStringVector);
			numPalin++;
		}
		
		return;
	}

	if (!cutTest2(candidateStringVector, currentStringVector)) return;

	// start for loop of recursion
	for (int i = 0; i < currentStringVector.size(); i++) {

		// edit the string vectors towards current string empty
		candidateStringVector.push_back(currentStringVector[i]); // add the first element of the words vector to the candidate
		currentStringVector.erase(currentStringVector.begin() + i); // remove the first element of the words vector

		// recurse
		recursiveFindPalindromes(candidateStringVector, currentStringVector);

		// add elements back to vectors to restore the state
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
	palindromes.clear();
	numPalin = 0;
}

bool FindPalindrome::cutTest1(const vector<string> & stringVector)
{
	int oddCount = 0;
	int charCount = 0;
	std::unordered_map<char, int> map;

	for (int i = 0; i < stringVector.size(); i++)
		for (int j = 0; j < stringVector[i].size(); j++) {
			charCount++;
			if (map.find(stringVector[i][j]) != map.end()) {
				map.insert({stringVector[i][j], ++map[stringVector[i][j]]});
				
				if (map[stringVector[i][j]] % 2 != 0)
					oddCount++;
				else
					oddCount--;
			}
			else {
				map.insert({stringVector[i][j], 1});
				oddCount++;
			}
		}
	
	return (oddCount % 2 == 0 && charCount % 2 == 0) || (oddCount == 1 && charCount % 2 != 0);
}

bool FindPalindrome::cutTest2(const vector<string> & stringVector1,
                              const vector<string> & stringVector2)
{
	int count1 = 0, count2 = 0;
	string s1, s2;
	unordered_map<char, int> map1, map2;

	if (stringVector1.empty() || stringVector2.empty())
		return true;

	for (string s : stringVector1)
		for (const char &c: s) {
			char temp = tolower(c);
			map1[temp]++;
			s1 += c;  
			count1++;
		}
	for (string s : stringVector2)
		for (const char &c : s) {
			char temp = tolower(c);
			map2[temp]++;
			s2 += c;
			count2++;
		}

	if (count1 < count2)
		for (char c : s1) {
			char temp = tolower(c);
			if (map1[temp] > map2[temp]) return false;
		}
	else 
		for (char c : s1) {
			char temp = tolower(c);
			if (map2[temp] > map1[temp]) return false;
		}
	
	return true;
}

bool FindPalindrome::add(const string & value)
{	
	// check for in correct range of characters
	for (char c : value)
		if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')))
			return false;

	for (string w : words) {
		string temp1 = w, temp2 = value;
		convertToLowerCase(temp1);
		convertToLowerCase(temp2);

		if (temp1 == temp2) return false;
	}
	
	// else, add word
	words.push_back(value);

	// reset number of palindromes in instance of class
	numPalin = 0;

	// create temp blank vector and recompute palindromes
	vector<string> temp;
	
	if (this->cutTest1(words))
		recursiveFindPalindromes(temp, words);

	return true;
}

bool FindPalindrome::add(const vector<string> & stringVector)
{
	// for each word in vector, check all the characters for range - check word for existance in words vector already
	for (std::string s : stringVector) {
		for (char c : s)
			if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')))
				return false;
		for (string w : words) {
			string temp1 = w, temp2 = s;
			convertToLowerCase(temp1);
			convertToLowerCase(temp2);

			if (temp1 == temp2) return false;
		}

		words.push_back(s);
	}

	// reset number of palindromes in instance of class
	numPalin = 0;

	// create temp blank vector and recompute palindromes
	vector<string> temp;

	if (this->cutTest1(words))
		recursiveFindPalindromes(temp, words);

	return true;
}

vector< vector<string> > FindPalindrome::toVector() const
{
	return palindromes;
}

