// ==================================
//  You will input in the input.txt file
//  Output will be printed in output.txt file
// ==================================

#include <bits/stdc++.h>
#include <ios>
using namespace std;

class solution {
public:
  bool isValid(string s) {
    stack<char> st;
    for (size_t i{}; i < s.length(); i++) {
      char ch{s[i]};
      if (ch == '(' || ch == '{' || ch == '[') {
        st.push(ch);
      } else {
        if (st.empty()) {
          return false;
        }
        char top = st.top();
        if ((ch == ')' && top == '(') || (ch == '}' && top == '{') ||
            (ch == ']' && top == '[')) {
          st.pop();
        } else {
          return false;
        }
      }
    }
    return true;
  }
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solution s;

  string str;
  getline(cin, str);

  cout << std::boolalpha << s.isValid(str) << endl;

  return 0;
}
