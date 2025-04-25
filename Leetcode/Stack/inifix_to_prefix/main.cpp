// ==================================
//  You will input in the input.txt file
//  Output will be printed in output.txt file
// ==================================

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int priority(char c) {
    if (c == '^')
      return 3;
    else if (c == '*' || c == '/')
      return 2;
    else if (c == '+' || c == '-')
      return 1;
    else
      return -1;
  }

  string infixToPrefix(string &s) {
    // Step 1: Reverse the string and swap parentheses
    string reversedInfix = reverse(s);

    // Step 2: Convert the reversed infix to postfix
    string postfix = infixToPostfix(reversedInfix);

    // Step 3: Reverse the postfix expression to get prefix
    string prefix = reverse(postfix);

    return prefix;
  }

private:
  string reverse(const string &s) {
    string res = "";
    for (int i = s.size() - 1; i >= 0; i--) {
      if (s[i] == '(')
        res += ')';
      else if (s[i] == ')')
        res += '(';
      else
        res += s[i];
    }
    return res;
  }

  string infixToPostfix(const string &s) {
    stack<char> st;
    string res;
    for (char c : s) {
      // If operand, add to result
      if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ||
          (c >= '0' && c <= '9')) {
        res += c;
      }
      // If '(', push to stack
      else if (c == '(') {
        st.push(c);
      }
      // If ')', pop until '('
      else if (c == ')') {
        while (!st.empty() && st.top() != '(') {
          res += st.top();
          st.pop();
        }
        st.pop(); // Pop '('
      }
      // If operator
      else {
        while (!st.empty() && priority(c) <= priority(st.top())) {
          res += st.top();
          st.pop();
        }
        st.push(c);
      }
    }

    // Pop all remaining operators
    while (!st.empty()) {
      res += st.top();
      st.pop();
    }

    return res;
  }
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution s;

  string input;
  getline(cin, input);

  string output = s.infixToPrefix(input);

  cout << "Ouput : " << output << "\n";

  return 0;
}
