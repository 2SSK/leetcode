// ==================================
//  You will input in the input.txt file
//  Output will be printed in output.txt file
// ==================================

#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool isSubsequence(string s, string t);
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution solution;

  string s;
  cin >> s;
  string t;
  cin >> t;

  cout << "Output: " << boolalpha << solution.isSubsequence(s, t) << endl;

  return 0;
}

bool Solution::isSubsequence(string s, string t) {
  int i = 0;
  int j = 0;

  while (i < s.size() && j < t.size()) {
    if (s[i] == t[j]) {
      i++;
    }
    j++;
  }

  return i == s.size();
};
