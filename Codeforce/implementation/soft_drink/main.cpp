#include <bits/stdc++.h>
using namespace std;

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k, l, c, d, p, nl, np;
  cin >> n >> k >> l >> c >> d >> p >> nl >> np;

  int total_possbile_drink = (k * l) / nl;
  int total_slices = c * d;
  int total_possible_salt = p / np;

  int min_toast_total =
      min(total_possbile_drink, min(total_slices, total_possible_salt));

  cout << min_toast_total / n;

  return 0;
}
