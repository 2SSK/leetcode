#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  template <typename T> vector<T> readInput() {
    vector<T> inputArr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    T value;
    while (ss >> value) {
      inputArr.push_back(value);
    }

    return inputArr;
  }

  template <typename T> void printArr(vector<T> arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
      if (i == 0) {
        cout << "[ " << arr[i] << ", ";
      } else if (i == n - 1) {
        cout << arr[i] << " ]\n";
      } else {
        cout << arr[i] << ", ";
      }
    }
  }

  bool isBalanced(string &s) {
    stack<char> st;

    for (char it : s) {
      if (it == '(' || it == '{' || it == '[') {
        st.push(it);
      } else {
        if (st.empty())
          return false;

        switch (it) {
        case ')':
          if (st.top() != '(') {
            return false;
          }
          st.pop();
          break;
        case '}':
          if (st.top() != '{') {
            return false;
          }
          st.pop();
          break;
        case ']':
          if (st.top() != '[') {
            return false;
          }
          st.pop();
          break;
        }
      }
    }

    return st.empty();
  }
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution solution;

  int test_cases;
  cin >> test_cases;

  while (test_cases--) {
    string s;
    cin >> s;

    cout << "Output: " << boolalpha << solution.isBalanced(s) << endl;
  }

  return 0;
}
