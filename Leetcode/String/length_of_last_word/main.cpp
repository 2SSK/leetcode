// ==================================
//  You will input in the input.txt file
//  Output will be printed in output.txt file
// ==================================

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int lengthOfLastWord(string s);
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution solution;

  string input;
  getline(cin, input);

  cout << "Output: " << solution.lengthOfLastWord(input) << endl;

  return 0;
}

int Solution::lengthOfLastWord(string s) {
  int n = s.size() - 1;

  while (s[n] >= 0 && s[n] == ' ')
    n--;

  int length_of_last_word = 0;

  while (s[n] >= 0 && s[n] != ' ') {
    length_of_last_word++;
    n--;
  }

  return length_of_last_word;
};
