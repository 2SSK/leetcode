#include <bits/stdc++.h>

using namespace std;

class solution {
public:
  int countSetBits(int n) {
    int count{};

    for (int i{1}; i <= n; i++) {
      int num = i;
      while (num > 1) {
        count += num & 1;
        num >>= 1;
      }

      if (num == 1)
        count++;
    }

    return count;
  }
};

int main() {
  freopen("input.txt", "r", stdin);
  solution sol;
  int n;
  cin >> n;

  cout << sol.countSetBits(n) << "\n";
}
