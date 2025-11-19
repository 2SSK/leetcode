#include <bits/stdc++.h>
using namespace std;

bool check(string pattern, string target) {
  if (pattern.size() < target.size()) {
    return false;
  }

  for (int i = 0; i < pattern.size() - target.size() + 1; i++) {
    if (pattern.substr(i, target.size()) == target) {
      return true;
    }
  }

  return false;
}

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n, m;
    cin >> n >> m;

    string x, s;
    cin >> x >> s;

    int count = -1;

    string x0 = x;
    string x1 = x0 + x0;
    string x2 = x1 + x1;
    string x3 = x2 + x2;
    string x4 = x3 + x3;
    string x5 = x4 + x4;

    if (check(x0, s)) {
      count = 0;
    } else if (check(x1, s)) {
      count = 1;
    } else if (check(x2, s)) {
      count = 2;
    } else if (check(x3, s)) {
      count = 3;
    } else if (check(x4, s)) {
      count = 4;
    } else if (check(x5, s)) {
      count = 5;
    }

    cout << count << endl;
  }

  return 0;
}
