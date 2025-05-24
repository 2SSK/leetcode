// ==================================
//  You will input in the input.txt file
//  Output will be printed in output.txt file
// ==================================

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string minWindow(string s, string t);
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution solution;
  string s, t;
  cin >> s >> t;

  cout << "Output: " << solution.minWindow(s, t);

  return 0;
}

string Solution::minWindow(string s, string t) {
  if (t.empty() || s.empty() || s.size() < t.size())
    return "";

  unordered_map<char, int> t_freq;
  for (char c : t) {
    t_freq[c]++;
  }

  unordered_map<char, int> window_freq;
  int required = t_freq.size();
  int formed = 0;

  int left = 0, right = 0;
  int min_len = INT_MAX, min_left = 0;

  while (right < s.size()) {
    char c = s[right];
    window_freq[c]++;

    if (t_freq.count(c) && window_freq[c] == t_freq[c]) {
      formed++;
    }
    while (left <= right && formed == required) {
      if (right - left + 1 < min_len) {
        min_len = right - left + 1;
        min_left = left;
      }
      char left_char = s[left];
      window_freq[left_char]--;
      if (t_freq.count(left_char) &&
          window_freq[left_char] < t_freq[left_char]) {
        formed--;
      }
      left++;
    }
    right++;
  }

  return min_len == INT_MAX ? "" : s.substr(min_left, min_len);
};
