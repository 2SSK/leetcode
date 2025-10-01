#include <bits/stdc++.h>
using namespace std;

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  unordered_map<string, string> mp;
  for (size_t i = 0; i < m; i++) {
    string a, b;
    cin >> a >> b;
    mp[a] = b;
  }

  vector<string> words(n);
  for (size_t i = 0; i < n; i++) {
    cin >> words[i];
  }

  for (const auto &word : words) {
    if (mp[word].length() < word.length()) {
      cout << mp[word] << " ";
    } else {
      cout << word << " ";
    }
  }

  return 0;
}
