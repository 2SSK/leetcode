// ==================================
//  You will input in the input.txt file
//  Output will be printed in output.txt file
// ==================================

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void greet(string name);
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution s;

  int size;
  cin >> size;

  vector<string> names(size);
  for (int i{}; i < size; i++) {
    cin >> names[i];
  }

  for (auto name : names) {
    s.greet(name);
  }

  return 0;
}

void Solution::greet(string name) { cout << "Hello, " << name << "!\n"; }
