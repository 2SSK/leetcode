// ==================================
//  You will input in the input.txt file
//  Output will be printed in output.txt file
// ==================================

#include <bits/stdc++.h>
using namespace std;

class solution {
public:
  // Brute force approach
  int findXOR_BF(int l, int r) {
    int res{};

    while (l <= r) {
      res ^= l++;
    }

    return res;
  }

  // Optimized approach
  int xorUpTo(int n) {
    if (n % 4 == 0)
      return n;
    if (n % 4 == 1)
      return 1;
    if (n % 4 == 2)
      return n + 1;
    return 0;
  }

  int findXOR(int l, int r) { return xorUpTo(r) ^ xorUpTo(l - 1); }
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solution s;
  int l, r;
  cin >> l >> r;

  cout << s.findXOR(l, r) << endl;

  return 0;
}
