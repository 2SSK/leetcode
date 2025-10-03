#include <bits/stdc++.h>
using namespace std;

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    long long a, b;
    cin >> a >> b;

    long long cnt1 = 0, cnt2 = 0;
    while (a % 2 == 0) {
      a /= 2;
      cnt1++;
    }

    while (b % 2 == 0) {
      b /= 2;
      cnt2++;
    }

    if (a != b) {
      cout << -1 << "\n";
    } else {
      if (cnt1 == cnt2) {
        cout << 0 << "\n";
      } else {
        long long diff = abs(cnt2 - cnt1);
        cout << diff / 3 + (diff % 3 != 0) << "\n";
      }
    }
  }

  return 0;
}
