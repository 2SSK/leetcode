// ==================================
//  You will input in the input.txt file
//  Output will be printed in output.txt file
// ==================================

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int findContentChildren(vector<int> &g, vector<int> &s);
};

vector<int> readInput() {
  vector<int> inputArr;

  string input;
  getline(cin, input);

  stringstream ss(input);
  int value;
  while (ss >> value) {
    inputArr.push_back(value);
  }

  return inputArr;
}

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution solution;

  vector<int> g = readInput();
  vector<int> s = readInput();

  cout << "Output: " << solution.findContentChildren(g, s);

  return 0;
}

int Solution::findContentChildren(vector<int> &g, vector<int> &s) {
  sort(begin(g), end(g));
  sort(begin(s), end(s));

  int i = 0, j = 0;

  while (i < g.size() && j < s.size()) {
    if (g[i] <= s[j]) {
      i++;
    }
    j++;
  }

  return i;
};
