#include <bits/stdc++.h>
using namespace std;

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, t;
  cin >> n >> t;

  vector<int> time(n);
  for (int i = 0; i < n; i++) {
    cin >> time[i];
  }

  int count = 0;
  int sum = 0;

  int i = 0, j = 0;

  while (i < n && j < n) {
    if (sum + time[j] <= t) {
      sum += time[j++];
      count = max(count, j - i);
    } else {
      sum -= time[i++];
    }
  }

  cout << count << "\n";

  return 0;
}
