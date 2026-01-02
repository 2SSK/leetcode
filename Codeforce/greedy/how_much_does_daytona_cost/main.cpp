#include <bits/stdc++.h>
using namespace std;

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n, k;
    cin >> n >> k;

    bool found = false;
    for (size_t i = 0; i < n; i++) {
      int el;
      cin >> el;

      if (el == k) {
        found = true;
      }
    }

    if (found) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }

  return 0;
}
