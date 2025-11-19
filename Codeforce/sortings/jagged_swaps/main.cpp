#include <bits/stdc++.h>
using namespace std;

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (size_t i = 0; i < n; i++) {
      cin >> arr[i];
    }

    if (arr[0] == 1) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }

  return 0;
}
