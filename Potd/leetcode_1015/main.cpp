#include <bits/stdc++.h>
using namespace std;

int smallestRepunitDivByK(int k);

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int k;
  cin >> k;

  cout << "Output: " << smallestRepunitDivByK(k) << "\n";

  return 0;
}

int smallestRepunitDivByK(int k) {
  long long remainder = 1 % k;
  int length = 1;

  while (length <= k) {
    if (remainder == 0)
      return length;

    remainder = (remainder * 10 + 1) % k;
    length++;
  }

  return -1;
}
