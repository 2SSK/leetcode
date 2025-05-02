// ==================================
//  You will input in the input.txt file
//  Output will be printed in output.txt file
// ==================================

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int distinctValues(int n);
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution solution;
  int testCases;
  cin >> testCases;

  while (testCases--) {
    int n;
    cin >> n;

    cout << solution.distinctValues(n) << endl;
  }

  return 0;
}

int Solution::distinctValues(int n) {
  int maxVal = (n % 2 == 0) ? (n * n) / 2 : (n * n - 1) / 2;
  return maxVal / 2 + 1;
};
