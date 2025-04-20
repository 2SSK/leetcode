// ==================================
//  You will input in the input.txt file
//  Output will be printed in output.txt file
// ==================================

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int romanToInt(string s);
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution solution;

  string input;
  getline(cin, input);

  cout << "Output: " << solution.romanToInt(input) << endl;

  return 0;
}

int Solution::romanToInt(string s) {
  unordered_map<char, int> mpp = {{'I', 1},   {'V', 5},   {'X', 10},  {'L', 50},
                                  {'C', 100}, {'D', 500}, {'M', 1000}};

  int total_integer = 0;
  int previous_integer = 0;

  for (int i = s.size() - 1; i >= 0; i--) {
    int current_integer = mpp[s[i]];

    if (current_integer < previous_integer) {
      total_integer -= current_integer;
    } else {
      total_integer += current_integer;
    }

    previous_integer = current_integer;
  }

  return total_integer;
}
