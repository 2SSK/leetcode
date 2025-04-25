// ==================================
//  You will input in the input.txt file
//  Output will be printed in output.txt file
// ==================================

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string convert(string s, int numRows);
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution solution;

  string input;
  getline(cin, input);

  int numRows;
  cin >> numRows;

  cout << "Output: " << solution.convert(input, numRows) << endl;

  return 0;
}

string Solution::convert(string s, int numRows) {
  if (numRows == 1)
    return s;

  string output = "";

  for (int r = 0; r < numRows; r++) {
    int increment = 2 * (numRows - 1);
    for (int i = r; i < s.size(); i += increment) {
      output += s[i];
      if (r > 0 && r < numRows - 1 && i + increment - 2 * r < s.size()) {
        output += s[i + increment - 2 * r];
      }
    }
  }

  return output;
};
