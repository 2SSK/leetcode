#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int totalMoney(int n) {
    int total_money = 0;
    int monday = 1;

    while (n > 0) {
      for (int day = 0; day < min(n, 7); day++) {
        total_money += monday + day;
      }
      n -= 7;
      monday++;
    }

    return total_money;
  }
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution solution;

  int n;
  cin >> n;

  cout << "Output: " << solution.totalMoney(n) << "\n";

  return 0;
}
