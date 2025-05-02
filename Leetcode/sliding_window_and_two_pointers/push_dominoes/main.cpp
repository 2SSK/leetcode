// ==================================
//  You will input in the input.txt file
//  Output will be printed in output.txt file
// ==================================

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string pushDominoes(string dominoes);
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution solution;
  string dominoes;
  cin >> dominoes;

  cout << "Output: " << solution.pushDominoes(dominoes) << endl;

  return 0;
}

string Solution::pushDominoes(string dominoes) {
  int n = dominoes.length();
  vector<int> forces(n, 0);

  // Left to Right
  int force = 0;
  for (int i = 0; i < n; i++) {
    if (dominoes[i] == 'R') {
      force = n;
    } else if (dominoes[i] == 'L') {
      force = 0;
    } else if (force > 0) {
      force -= 1;
    }
    forces[i] += force;
  }

  // Right to Left
  force = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (dominoes[i] == 'L') {
      force = n;
    } else if (dominoes[i] == 'R') {
      force = 0;
    } else if (force > 0) {
      force -= 1;
    }
    forces[i] -= force;
  }

  // Construct the result based on net force
  string output = "";
  for (int i = 0; i < n; i++) {
    if (forces[i] > 0) {
      output += 'R';
    } else if (forces[i] < 0) {
      output += 'L';
    } else {
      output += '.';
    }
  }
  return output;
};
