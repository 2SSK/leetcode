// ==================================
//  You will input in the input.txt file
//  Output will be printed in output.txt file
// ==================================

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool checkValidation(string s);
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution solution;

  string input;
  getline(cin, input);

  cout << "Output: " << boolalpha << solution.checkValidation(input) << endl;

  return 0;
}

bool Solution::checkValidation(string s) {
  int low = 0;
  int high = 0;

  for (char c : s) {
    if (c == '(') {
      low++;
      high++;
    } else if (c == ')') {
      low--;
      high--;
    } else {
      low--;
      high++;
    }

    if (high < 0) {
      return false;
    }

    if (low < 0) {
      low = 0;
    }
  }

  return low == 0;
};
