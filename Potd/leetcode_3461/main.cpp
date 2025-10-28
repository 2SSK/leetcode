#include <bits/stdc++.h>
#include <ios>
using namespace std;

class Solution {
public:
  bool hasSameDigits(string s);
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution solution;

  string s;
  cin >> s;

  cout << "Output: " << boolalpha << solution.hasSameDigits(s) << "\n";

  return 0;
}

bool Solution::hasSameDigits(string s) {
  string new_str = s;

  while (new_str.size() > 2) {
    string temp = "";
    for (int i = 1; i < new_str.size(); i++) {
      int new_digit = (new_str[i] - '0' + new_str[i - 1] - '0') % 10;
      temp.push_back(new_digit + '0');
    }
    new_str = temp;
  }

  if (new_str[0] == new_str[1]) {
    return true;
  }

  return false;
}
