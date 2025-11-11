#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t) {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }

    if (k > 1) {
      cout << "YES\n";
    } else {
      if (is_sorted(a.begin(), a.end())) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    }

    --t;
  }

  return 0;
}
