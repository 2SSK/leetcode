// ==================================
//  You will input in the input.txt file
//  Output will be printed in output.txt file
// ==================================

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int strStr(string haystack, string needle);
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution solution;

  string haystack;
  getline(cin, haystack);

  string needle;
  getline(cin, needle);

  cout << "Output: " << solution.strStr(haystack, needle) << endl;

  return 0;
}

int Solution::strStr(string haystack, string needle) {
  size_t pos = haystack.find(needle);

  return (pos != string::npos) ? pos : -1;
};
