#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }

    unordered_map<int, int> freq;
    for (int x : a)
      freq[x]++;

    // More than 2 distinct values → impossible
    if (freq.size() > 2) {
      cout << "NO\n";
      continue;
    }

    // Only 1 distinct value → always possible
    if (freq.size() == 1) {
      cout << "YES\n";
      continue;
    }

    // Exactly 2 distinct values
    auto it = freq.begin();
    int f1 = it->second;
    it++;
    int f2 = it->second;

    int odd = (n + 1) / 2;
    int even = n / 2;

    if ((f1 == odd && f2 == even) || (f2 == odd && f1 == even))
      cout << "YES\n";
    else
      cout << "NO\n";
  }

  return 0;
}
