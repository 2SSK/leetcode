// ==================================
//  You will input in the input.txt file
//  Output will be printed in output.txt file
// ==================================

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool checkPowersOfThree(int n);
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution s;

  int n;
  cin >> n;

  cout << "Output: " << std::boolalpha << s.checkPowersOfThree(n) << "\n";

  return 0;
}

bool Solution::checkPowersOfThree(int n) {
  while (n > 0) {
    int remainder = n % 3;

    if (remainder == 2) {
      return false;
    }

    n /= 3;
  }
  return true;
}
