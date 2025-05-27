// ==================================
//  You will input in the input.txt file
//  Output will be printed in output.txt file
// ==================================

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string invertDigit(string n);
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution solution;

  string n;
  cin >> n;

  cout << solution.invertDigit(n) << endl;

  return 0;
}

string Solution::invertDigit(string input) {
  string result = "";

  int n = input.length();
  for (int i = 0; i < n; i++) {
    int digit = input[i] - '0';
    int inverted_digit = 9 - digit;

    if (i == 0) {
      if (digit == 9) {
        result += '9';
      } else {
        result += char(min(digit, inverted_digit) + '0');
      }
    } else {
      result += char(min(digit, inverted_digit) + '0');
    }
  }

  return result;
}
