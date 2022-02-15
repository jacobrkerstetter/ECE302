#include <string>
using std::string;

#include <iostream>
#include <stack>

#include <cctype> // for isalpha

#include "algebraic_expressions.hpp"

bool isoperator(char ch) {
  return ((ch == '+') || (ch == '-') || (ch == '/') || (ch == '*'));
}

int endPost(string s, int last) {
  int first = 0;

  if ((first > last)) {
    return -1;
  }

  char ch = s[last];
  if (isalpha(ch)) {
    return last;
  } else {
    if (isoperator(ch)) {
      int lastEnd = endPost(s, last - 1);
      if (lastEnd > -1) {
        return endPost(s, lastEnd - 1);
      } else {
        return -1;
      }
    } else {
      return -1;
    }
  }
}

bool isPost(string s) {
  int firstChar = endPost(s, s.size() - 1);

  return (firstChar == 0);
}

void convert(string &postfix, string &prefix) {

  std::stack<string> s;

  int len = postfix.size();

  for(int i = 0; i < len; i++){

    if(isoperator(postfix[i])){
      std::string op1 = s.top();
      s.pop();
      std::string op2 = s.top();
      s.pop();

      std::string tempString = postfix[i] + op1 + op2;
      s.push(tempString);
    }else{
      s.push(std::string(1, postfix[i]));
    }
    
  }

  prefix = "";
  while(!s.empty()){
    prefix += s.top();
    s.pop();
  }
  
}
