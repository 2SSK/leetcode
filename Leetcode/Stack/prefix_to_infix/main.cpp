// ==================================
//  You will input in the input.txt file
//  Output will be printed in output.txt file
// ==================================

#include <bits/stdc++.h>
#include <cctype>
using namespace std;

class solution {
public:
  string prefixToInfix(string exp) {
    stack<string> st;

    for (int i = exp.length() - 1; i >= 0; i--) {
      if (isalpha(exp[i])) {
        st.push(string(1, exp[i]));
      } else {
        string op1{st.top()};
        st.pop();
        string op2{st.top()};
        st.pop();
        string infix{"(" + op1 + exp[i] + op2 + ")"};
        st.push(infix);
      }
    }

    return st.top();
  }
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solution s;

  string exp;
  getline(cin, exp);

  cout << s.prefixToInfix(exp) << endl;

  return 0;
}
