// ==================================
//  You will input in the input.txt file
//  Output will be printed in output.txt file
// ==================================

#include <bits/stdc++.h>
#include <cctype>
using namespace std;

class Solution {
public:
  string reverseWords(string s);
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution solution;

  string input;
  getline(cin, input);

  cout << "Output: " << solution.reverseWords(input) << "\n";

  return 0;
}

string Solution::reverseWords(string s) {
  string reversed_string = "";
  string word = "";

  for (auto ch : s) {
    if (ch != ' ') {
      word.push_back(ch);
    } else {
      reversed_string =
          word + (reversed_string.empty() ? "" : " ") + reversed_string;
      word.clear();
    }
  }

  if (!word.empty()) {
    reversed_string =
        word + (reversed_string.empty() ? "" : " ") + reversed_string;
  }

  return reversed_string;
};
