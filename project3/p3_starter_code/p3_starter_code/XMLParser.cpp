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
	return false;
}  // end

// TODO: Implement a helper function to delete attributes from a START_TAG
// or EMPTY_TAG string (you can change this...)
static std::string deleteAttributes(std::string input)
{
	return input;
}

// TODO: Implement the parseTokenizedInput method here
bool XMLParser::parseTokenizedInput()
{
	return false;
}

// Method to clear the internal data structures
void XMLParser::clear()
{
	// clear the stack
	while (!parseStack->isEmpty())
		parseStack->pop();
	
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

