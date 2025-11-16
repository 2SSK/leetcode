#include <bits/stdc++.h>
using namespace std;

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int x, y;
  cin >> x >> y;

  int total_score = (3 * x) + (2 * y);

  cout << total_score << "\n";

  return 0;
}
