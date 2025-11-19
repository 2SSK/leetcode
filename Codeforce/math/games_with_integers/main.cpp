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

    if (n % 3 != 0) {
      cout << "First\n";
    } else {
      cout << "Second\n";
    }
  }

  return 0;
}
