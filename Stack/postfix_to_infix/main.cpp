// ==================================
//  You will input in the input.txt file
//  Output will be printed in output.txt file
// ==================================

#include <bits/stdc++.h>
using namespace std;

class solution {
public:
  string postfixToInfix(string exp) {
    stack<string> st;
    string output;

    for (int i{}; i < exp.length(); i++) {
      if (isalpha(exp[i])) {
        string op(1, exp[i]);
        st.push(op);
      } else {
        string op1 = st.top();
        st.pop();
        string op2 = st.top();
        st.pop();
        st.push("(" + op2 + exp[i] + op1 + ")");
      }
    }

    for (int i{}; i < st.size(); i++) {
      output = st.top() + output;
      st.pop();
    }

    return output;
  }
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solution s;

  string exp;
  getline(cin, exp);

  cout << s.postfixToInfix(exp) << endl;

  return 0;
}
