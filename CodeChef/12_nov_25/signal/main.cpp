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

    string s;
    cin >> s;

    bool pulse = false;
    int output = 0;

    for (const auto &it : s) {
      if (it == '0') {
        pulse = true;
      } else if (pulse && it == '1') {
        output++;
      }
    }

    cout << output << "\n";
  }

  return 0;
}
