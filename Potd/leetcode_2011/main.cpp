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

  int finalValueAfterOperations(vector<string> &operations);
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution solution;

  vector<string> input = solution.readInput<string>();

  cout << "Output: " << solution.finalValueAfterOperations(input);

  return 0;
}

int Solution::finalValueAfterOperations(vector<string> &operations) {
  int x = 0;

  for (const auto &c : operations) {
    if (c == "--X" || c == "X--" || c == "x--" || c == "--x") {
      x--;
    } else {
      x++;
    }
  }

  return x;
}
