#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maximum69Number(int num) {
    int maxNum = num;
    string numStr = to_string(num);

    for (const auto &i : numStr) {
      if (i == '6') {
        numStr.replace(numStr.find('6'), 1, "9");
        maxNum = stoi(numStr);
        break;
      }
    }

    return maxNum;
  }
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution solution;

  int input;
  cin >> input;

  cout << "Output: " << solution.maximum69Number(input) << endl;

  return 0;
}
