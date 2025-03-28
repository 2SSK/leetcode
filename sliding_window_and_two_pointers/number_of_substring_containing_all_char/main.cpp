// ==================================
//  You will input in the input.txt file
//  Output will be printed in output.txt file
// ==================================

#include <bits/stdc++.h>
#include <functional>
using namespace std;

class Solution {
public:
  int numberOfSubstrings(string s);
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution s;

  string input;
  cin >> input;

  cout << "Output: " << s.numberOfSubstrings(input) << endl;

  return 0;
}

int Solution::numberOfSubstrings(string s) {
  int n = s.length();
  int left{}, right{}, counter{};
  map<char, int> mpp;

  while (right < n) {
    mpp[s[right]]++;
    while (mpp.size() == 3) {
      counter += n - right;
      mpp[s[left]]--;
      if (mpp[s[left]] == 0)
        mpp.erase(s[left]);
      left++;
    }
    right++;
  }
  return counter;
}
