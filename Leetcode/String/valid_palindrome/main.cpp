// ==================================
//  You will input in the input.txt file
//  Output will be printed in output.txt file
// ==================================

#include <bits/stdc++.h>
#include <cctype>
#include <ios>
using namespace std;

class Solution {
public:
  bool isPalindrome(string s);
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution solution;

  string input;
  getline(cin, input);

  cout << "Output: " << boolalpha << solution.isPalindrome(input) << endl;

  return 0;
}

bool Solution::isPalindrome(string s) {
  string standarised_str = "";

  for (auto ch : s) {
    if (isalnum(ch)) {
      standarised_str += tolower(ch);
    }
  }

  int i = 0;
  int j = standarised_str.length() - 1;

  while (i < j) {
    if (standarised_str[i] != standarised_str[j]) {
      return false;
    }
    i++;
    j--;
  }

  return true;
};
