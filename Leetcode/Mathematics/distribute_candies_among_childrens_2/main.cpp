// ==================================
//  You will input in the input.txt file
//  Output will be printed in output.txt file
// ==================================

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  long long distributeCandies(int n, int limit);
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution solution;

  int n, limit;
  cin >> n >> limit;

  cout << "Output: " << solution.distributeCandies(n, limit);

  return 0;
}

long long Solution::distributeCandies(int n, int limit) {
  long long res = 0;
  for (int i = 0; i <= min(limit, n); i++) {
    if (n - i <= 2 * limit)
      res += min(n - i, limit) - max(0, n - i - limit) + 1;
  }
  return res;
};
