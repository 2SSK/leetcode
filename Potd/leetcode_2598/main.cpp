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

  int findSmallestInteger(vector<int> &nums, int value);
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution solution;

  vector<int> input = solution.readInput<int>();
  int value;
  cin >> value;

  cout << "Output: " << solution.findSmallestInteger(input, value);

  return 0;
}

int Solution::findSmallestInteger(vector<int> &nums, int value) {
  vector<int> count(value, 0);
  for (auto &num : nums) {
    int mod = (num % value + value) % value;
    count[mod]++;
  }
  int mex = 0;
  while (count[mex % value] > 0) {
    count[mex % value]--;
    mex++;
  }
  return mex;
}
