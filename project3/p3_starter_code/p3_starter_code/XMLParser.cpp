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
	parseStack = new Stack<std::string>;

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
	// loop through input string
	// determine if start or end tag
	// create a token from TokenStruct
	// push_back to vector
	// if anything is invalid set tokenized to false, clear, and return false

	std::string content;
	TokenStruct token;

	// get rid of white space at the beginning
	int i = 0;
	while (std::isspace(inputString[i]))
		i++;

	// check for declaration
	if (inputString[i] == '<' && inputString[i+1] == '?') {
		content += "<?";
		while (inputString[i] != '?' && inputString[i+1] != '>')
			content += inputString[i];
		content += "?>";

		// add token to the vector
		token.tokenString = content;
		token.tokenType = DECLARATION;

		tokenizedInputVector.push_back(token);
	}

	for (int i; i < inputString.size(); i++) {
		std::string temp;
		StringTokenType type;
		if (inputString[i] == '<') {
			// create a temp string to hold the tag
			temp += "<";
			while (inputString[i] != '>')
				temp += inputString[i];
			// determine tag type
			if (temp[temp.size() - 1] == '/')
				token.tokenType = END_TAG;
			else token.tokenType = START_TAG;

			temp += ">";
			// delete attributes
			//temp = deleteAttributes(temp);
		}
		token.tokenString = temp;

		
	return true;
}  // end

// TODO: Implement a helper function to delete attributes from a START_TAG
// or EMPTY_TAG string (you can change this...)
static std::string deleteAttributes(std::string input)
{
	std::string cleaned;
	for (const char c : input)
		if (std::isspace(c))
			break;
		else
			cleaned += c;
	
	return cleaned;
}

// TODO: Implement the parseTokenizedInput method here
bool XMLParser::parseTokenizedInput()
{
	// follow the steps of "check valid parenthesis" from leetcode
	// https://redquark.org/leetcode/0020-valid-parentheses/
	
	return false;
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

// TODO: Implement the containsElementName method
bool XMLParser::containsElementName(const std::string &inputString) const
{
	// return false if either of the methods returned false
	if (!tokenized || !parsed) return false;

	return false;
}

// TODO: Implement the frequencyElementName method
int XMLParser::frequencyElementName(const std::string &inputString) const
{
	return -1;
}

