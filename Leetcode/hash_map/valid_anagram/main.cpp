// ==================================
//  You will input in the input.txt file
//  Output will be printed in output.txt file
// ==================================

#include <bits/stdc++.h>
#include <ios>
#include <unordered_map>
using namespace std;

class Solution {
public:
  bool isAnagram(string s, string t);
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution solution;

  string s, t;
  cin >> s >> t;

  cout << "Output: " << std::boolalpha << solution.isAnagram(s, t);

  return 0;
}

bool Solution::isAnagram(string s, string t) {
  if (s.size() != t.size())
    return false;

  unordered_map<char, int> mp;

  for (const auto &ch : s) {
    mp[ch]++;
  }

  for (const auto &ch : t) {
    mp[ch]++;
  }

  return true;
};
