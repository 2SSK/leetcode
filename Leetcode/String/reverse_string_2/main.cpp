// ==================================
//  You will input in the input.txt file
//  Output will be printed in output.txt file
// ==================================

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string reverseStr(string s, int k);
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution solution;

  string s;
  cin >> s;

  int k;
  cin >> k;

  cout << "Output: " << solution.reverseStr(s, k);

  return 0;
}

string Solution::reverseStr(string s, int k) {
  int n = s.size();

  for (int i = 0; i < n; i += 2 * k) {
    int left = i;
    int right = min(i + k - 1, n - 1);

    while (left < right) {
      swap(s[left], s[right]);
      left++;
      right--;
    }
  }

  return s;
};
