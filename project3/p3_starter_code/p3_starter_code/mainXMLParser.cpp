// main program to see if a file is a valid XML file
#include <iostream>
#include <fstream>
#include <string>
#include "XMLParser.hpp"

using namespace std;

int main () {
	bool success;
	string inputString;
	ifstream myfile ("./xmlFile.txt");
	XMLParser myParser;
	char c;

	// read in the test file
	if (myfile.is_open())
	{
		while (!myfile.eof()) {
			myfile.get(c);
			inputString.push_back(c);
		}
		myfile.close();
	}
	else {
		cout << "Unable to open (find) the input file";
		return -1;
	}
	
	cout << inputString;

	// try to tokenize the input string
	success = myParser.tokenizeInputString(inputString);
	cout << "tokenizeInputString success = " << success << endl;

	// look at the tokenized input string
	vector<TokenStruct> tokenizedInput = myParser.returnTokenizedInput();
	cout << "Number of tokens are " << tokenizedInput.size() << endl;
	for (int i=0; i<tokenizedInput.size(); i++) {
		cout << "Type: " << tokenizedInput[i].tokenType << " string: "  << tokenizedInput[i].tokenString << endl;
	}

	// try to parse the tokenized input string to see if it is valid XML
	success = myParser.parseTokenizedInput();
	cout << endl << "parseTokenizedInput success = " << success << endl;

	// see if the element named "heading" was there
	success = myParser.containsElementName("heading");
	cout << endl << "contains 'heading' element success = " << success << endl;

	// see how many times the element named "note" was there
	int number = myParser.frequencyElementName("note");
	cout << endl << "contains 'note' element this many times = " << number << endl << endl;

	// Create an instance of XMLParse
	XMLParser myXMLParser;
	string testString = "<?xml version=\"1.0\" encoding=\"UTF-8\"?><Note src='gmail'>  <From>Tom</From> <To>Alice</To> </Note>";
	success = myXMLParser.tokenizeInputString(testString);
	std::vector<TokenStruct> result = { TokenStruct{StringTokenType::DECLARATION, std::string("xml version=\"1.0\" encoding=\"UTF-8\"")},
								TokenStruct{StringTokenType::START_TAG, std::string("Note")},
								TokenStruct{StringTokenType::START_TAG, std::string("From")},
								TokenStruct{StringTokenType::CONTENT, std::string("Tom")},
								TokenStruct{StringTokenType::END_TAG, std::string("From")},
								TokenStruct{StringTokenType::START_TAG, std::string("To")},
								TokenStruct{StringTokenType::CONTENT, std::string("Alice")},
								TokenStruct{StringTokenType::END_TAG, std::string("To")},
								TokenStruct{StringTokenType::END_TAG, std::string("Note")}};
	std::vector<TokenStruct> output = myXMLParser.returnTokenizedInput();
	for (int i = 0; i < result.size(); i++) 
		cout << "result: " << result[i].tokenString << " output: " << output[i].tokenString << endl;

	return 0;
}
