// ==================================
//  You will input in the input.txt file
//  Output will be printed in output.txt file
// ==================================

#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
  bool isIsomorphic(string s, string t);
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution solution;

  string s, t;
  cin >> s >> t;

  cout << "Output: " << boolalpha << solution.isIsomorphic(s, t);

  return 0;
}

bool Solution::isIsomorphic(string s, string t) {
  if (s.size() != t.size())
    return false;

  map<char, char> s_to_t;
  map<char, char> t_to_s;

  for (int i = 0; i < s.size(); i++) {
    char sc = s[i];
    char tc = t[i];

    if (s_to_t.count(sc) && s_to_t[sc] != tc)
      return false;

    if (t_to_s.count(tc) && t_to_s[tc] != sc)
      return false;

    s_to_t[sc] = tc;
    t_to_s[tc] = sc;
  }

  return true;
}
