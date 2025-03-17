// ==================================
//  You will input in the input.txt file
//  Output will be printed in output.txt file
// ==================================

#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s);
  int lengthOfLongestSubstring_Optimal(string s);
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution s;

  string input;
  getline(cin, input);

  cout << "output: " << s.lengthOfLongestSubstring_Optimal(input) << "\n";

  return 0;
}

int Solution::lengthOfLongestSubstring_Optimal(string s) {
  int n = s.size();
  vector<int> hash(256, -1);
  int l{}, r{}, maxLen{};

  while (r < n) {
    if (hash[s[r]] != -1) {
      l = max(l, hash[s[r]] + 1);
    }

    hash[s[r]] = r;
    maxLen = max(maxLen, r - l + 1);
    r++;
  }

  return maxLen;
};

int Solution::lengthOfLongestSubstring(string s) {
  int size = s.length();
  int maxLength{};

  for (int i{}; i < size; i++) {
    string temp{""};
    for (int j{i}; j < size; j++) {
      if (find(begin(temp), end(temp), s[j]) == end(temp)) {
        temp += s[j];
      } else {
        break;
      }
    }
    maxLength = max(maxLength, static_cast<int>(temp.length()));
  }

  return maxLength;
}
