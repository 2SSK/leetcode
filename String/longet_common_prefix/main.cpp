// ==================================
//  You will input in the input.txt file
//  Output will be printed in output.txt file
// ==================================

#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  template <typename T> vector<T> readInput() {
    vector<T> inputArr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    T value;
    while (ss >> value) {
      inputArr.push_back(value);
    }

    return inputArr;
  }

  string longestCommonPrefix(vector<string> &strs);
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution solution;

  vector<string> input = solution.readInput<string>();

  cout << "Output: " << solution.longestCommonPrefix(input) << endl;

  return 0;
}

string Solution::longestCommonPrefix(vector<string> &strs) {
  for (int i = 0; i < strs[0].size(); i++) {
    char c = strs[0][i];

    for (int j = 1; j < strs.size(); j++) {
      if (i >= strs[j].size() || strs[j][i] != c) {
        return strs[0].substr(0, i);
      }
    }
  }

  return strs[0];
};
