#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;

  vector<int> parts;
  int place = 1;

  while (n > 0) {
    int digit = n % 10;
    if (digit != 0)
      parts.push_back(digit * place);
    n /= 10;
    place *= 10;
  }

  cout << parts.size() << "\n";
  for (int i = parts.size() - 1; i >= 0; --i)
    cout << parts[i] << " ";
  cout << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--)
    solve();
}
