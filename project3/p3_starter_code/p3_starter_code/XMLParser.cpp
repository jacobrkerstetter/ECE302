// Project 3 -- XML Parsing Project

/** XML parsing class implementation.
    @file XMLParser.cpp */

#include <string>
#include <assert.h>
#include "XMLParser.hpp"

XMLParser::XMLParser()
{
	// instantiate all pointers to new objects in the class
	elementNameBag = new Bag<std::string>;
	parseStack = new Stack<TokenStruct>;

}  // end default constructor

XMLParser::~XMLParser()
{
	// deallocate the dynamic memory
	delete elementNameBag;
	delete parseStack;
}  // end destructor

// TODO: Implement the tokenizeInputString method
bool XMLParser::tokenizeInputString(const std::string &inputString)
{
	// loop through input string (DONE)
	// create a token from TokenStruct (DONE)
	// push_back to vector (DONE)
	// if anything is invalid set tokenized to false, clear, and return false

	for (int i = 0; i < inputString.size(); i++) {
		std::string tag;
		TokenStruct token;

		if (inputString[i] == '<') {
			i++;
			if (inputString[i] == '?') { // declaration case
				i++;
				while (inputString[i] != '?') {	// loop to get all content
					// check for nested tags
					if (inputString[i] == '<') {
						tokenized = false;
						return false;
					}

					tag += inputString[i];
					i++;
				}
				
				// create token and append to vector				
				token.tokenType = DECLARATION;
			}
			else if (std::isalpha(inputString[i])) { // start or empty case
				while (inputString[i] != '>' && inputString[i] != '/') {	// loop to get all content
					// check for nested tags
					if (inputString[i] == '<') {
						tokenized = false;
						return false;
					}

					tag += inputString[i];
					i++;
				}
				tag = deleteAttributes(tag); // delete attributes
				
				// create token and append to vector
				// check if empty or start tag
				if (inputString[i] == '/') {
					tag = tag.substr(0, tag.size());
					token.tokenType = EMPTY_TAG;
				}
				else
					token.tokenType = START_TAG;

			}
			else if (inputString[i] == '/') { // end case
				i++;
				while (inputString[i] != '>') {	// loop to get all content
					// check for nested tags
					if (inputString[i] == '<') {
						tokenized = false;
						return false;
					}

					tag += inputString[i];
					i++;
				}
				
				// create token and append to vector				
				token.tokenType = END_TAG;
			}
		}
		else if (std::isalpha(inputString[i])) { // content case
			// get all of the content from between tags
			while (inputString[i] != '<') {
				// check for nested tags
				if (inputString[i] == '<') {
					tokenized = false;
					return false;
				}

				tag += inputString[i];
				i++;
			}

			// create token and append to vector
			token.tokenType = CONTENT;
			i--;
		}

		// if string is not empty, append it to vector and add element name to bag
		if (!tag.empty()) {
			token.tokenString = tag;
			tokenizedInputVector.push_back(token);
			if (token.tokenType != 2)
				elementNameBag->add(token.tokenString);
		}
	}

	tokenized = true;
	return true;
}  // end

// functions to check if the tags have valid characters
bool XMLParser::checkValidChar(const std::string &tagName) {
	for (const char c : invalidStarting)
		if (tagName[0] == c)
			return false;

	for (const char c : invalidChars)
		for (const char t : tagName)
			if (t == c)
				return false;

	return true;
}

// function to delete attributes from tags
std::string XMLParser::deleteAttributes(std::string input) {
	std::string cleaned;

	// read and append all characters up until whitespace
	for (const char c : input)
		if (std::isspace(c))
			break;
		else
			cleaned += c;
	
	return cleaned;
}

bool XMLParser::parseTokenizedInput()
{
	// follow the steps of "check valid parenthesis" from leetcode
	// https://redquark.org/leetcode/0020-valid-parentheses/

	// loop through tokens
	for (TokenStruct token : tokenizedInputVector) {
		// if start tag, push to parseStack
		if (token.tokenType == 1) 
			parseStack->push(token);
		// if end tag, check with top of stack
		else if (token.tokenType == 2)
			if (parseStack->peek().tokenType == 1 && parseStack->peek().tokenString == token.tokenString)
				parseStack->pop();
			else {
				parsed = false;
				return parsed;
			}
	}
	
	parsed = parseStack->isEmpty();
	return parsed;
}

// Method to clear the internal data structures
void XMLParser::clear()
{
	// clear the stack
	parseStack->clear();
	
	// clear the bag
	elementNameBag->clear();

	// clear the vector
	tokenizedInputVector.clear();
}

vector<TokenStruct> XMLParser::returnTokenizedInput() const
{
	return tokenizedInputVector;
}

bool XMLParser::containsElementName(const std::string &inputString) const
{
	// return false if either of the methods returned false
	if (!tokenized || !parsed) return false;

	// call bags contains function
	return elementNameBag->contains(inputString);
}

int XMLParser::frequencyElementName(const std::string &inputString) const
{
	// return false if either of the methods returned false
	if (!tokenized || !parsed) return false;

	// call bags freq. function
	return elementNameBag->getFrequencyOf(inputString);
}