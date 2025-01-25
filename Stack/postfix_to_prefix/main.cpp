// ==================================
//  You will input in the input.txt file
//  Output will be printed in output.txt file
// ==================================

#include <bits/stdc++.h>
#include <cctype>
using namespace std;

void printSt(stack<string> st) {
  for (int i{}; i < st.size(); i++) {
    cout << st.top();
    st.pop();
  }
}

class solution {
public:
  string postfixToPrefix(string exp) {
    stack<string> st;

    for (int i{}; i < exp.length(); i++) {
      if (isalpha(exp[i])) {
        st.push(string(1, exp[i]));
      } else {
        string op2{st.top()};
        st.pop();
        string op1{st.top()};
        st.pop();
        st.push(exp[i] + op1 + op2);
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

  cout << s.postfixToPrefix(exp) << endl;

  return 0;
}
