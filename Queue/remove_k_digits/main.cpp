// ==================================
//  You will input in the input.txt file
//  Output will be printed in output.txt file
// ==================================

#include <algorithm>
#include <bits/stdc++.h>
#include <cstdlib>
#include <string>
using namespace std;

class Solution {
public:
  string removeKdigits(string num, int k);
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution s;

  string num;
  cin >> num;

  int k;
  cin >> k;

  cout << "output = " << s.removeKdigits(num, k) << "\n";

  return 0;
}

string Solution::removeKdigits(string num, int k) {
  deque<char> dq;

  for (char digit : num) {
    while (!dq.empty() && k > 0 && dq.back() > digit) {
      dq.pop_back();
      k--;
    }
    dq.push_back(digit);
  }

  // Remove extra remaining digits if k is still greater than 0
  while (k > 0 && !dq.empty()) {
    dq.pop_back();
    k--;
  }

  // Construct the final result string
  string res;
  bool leadingZero = true;
  for (char digit : dq) {
    if (leadingZero && digit == '0')
      continue;
    leadingZero = false;
    res += digit;
  }

  return res.empty() ? "0" : res;
}
