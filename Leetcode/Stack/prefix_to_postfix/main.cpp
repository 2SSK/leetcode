// ==================================
//  You will input in the input.txt file
//  Output will be printed in output.txt file
// ==================================

#include <bits/stdc++.h>
#include <cctype>
using namespace std;

class solution {
public:
  string prefixToPostfix(string exp) {
    stack<string> st;

    for (int i = exp.size() - 1; i >= 0; i--) {
      if (isalpha(exp[i])) {
        st.push(string(1, exp[i]));
      } else {
        string op1{st.top()};
        st.pop();
        string op2{st.top()};
        st.pop();

        st.push(op1 + op2 + exp[i]);
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

  cout << s.prefixToPostfix(exp) << endl;

  return 0;
}
