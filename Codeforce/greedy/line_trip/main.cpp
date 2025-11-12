#include <bits/stdc++.h>
using namespace std;

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n, x;
    cin >> n >> x;

    int prev = 0, ans = 0;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;

      ans = max(ans, a - prev);
      prev = a;
    }

    ans = max(ans, 2 * (x - prev));
    cout << ans << "\n";
  }
}
