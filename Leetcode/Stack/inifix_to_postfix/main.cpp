// ==================================
//  You will input in the input.txt file
//  Output will be printed in output.txt file
// ==================================

#include <bits/stdc++.h>
using namespace std;

class solution {
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

  string infixToPostfix(string &s) {
    stack<char> st;
    string res{};

    int i{}, n = s.size();

    while (i < n) {
      if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') ||
          (s[i] >= '0' && s[i] <= '9')) {
        res += s[i];
      } else if (s[i] == '(') {
        st.push(s[i]);
      } else if (s[i] == ')') {
        while (!st.empty() && st.top() != '(') {
          res += st.top();
          st.pop();
        }
        st.pop();
      } else {
        while (!st.empty() && priority(s[i]) <= priority(st.top())) {
          res += st.top();
          st.pop();
        }
        st.push(s[i]);
      }
      i++;
    }

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

  solution s;

  string input;
  getline(cin, input);

  string output = s.infixToPostfix(input);

  cout << "Ouput : " << output << "\n";

  return 0;
}
