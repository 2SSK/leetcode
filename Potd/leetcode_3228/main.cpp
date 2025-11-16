#include <bits/stdc++.h>
using namespace std;

int maxOperations(string s) {
  int ans = 0;
  int countOne = 0;

  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '0') {
      while ((i + 1) < s.length() && s[i + 1] == '0') {
        i++;
      }
      ans += countOne;
    } else {
      countOne++;
    }
  }

  return ans;
}

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;

  cout << "Output: " << maxOperations(s) << "\n";

  return 0;
}
