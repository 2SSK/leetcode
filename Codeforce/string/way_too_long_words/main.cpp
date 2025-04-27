// ==================================
//  You will input in the input.txt file
//  Output will be printed in output.txt file
// ==================================

#include <bits/stdc++.h>
#include <string>
using namespace std;

class Solution {
public:
  string abbr(string word);
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution solution;

  int size;
  cin >> size;

  for (int i = 0; i < size; i++) {
    string input;
    cin >> input;

    cout << solution.abbr(input) << endl;
  }

  return 0;
}

string Solution::abbr(string word) {
  int n = word.size();

  if (n <= 10)
    return word;

  return word.front() + to_string(n - 2) + word.back();
};
