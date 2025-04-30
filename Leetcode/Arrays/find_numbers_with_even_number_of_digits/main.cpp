// ==================================
//  You will input in the input.txt file
//  Output will be printed in output.txt file
// ==================================

#include <bits/stdc++.h>
#include <string>
using namespace std;

class Solution {
public:
  int findNumbers(vector<int> &nums);

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
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution solution;

  vector<int> input = solution.readInput<int>();

  cout << "Output: " << solution.findNumbers(input) << endl;

  return 0;
}

int Solution::findNumbers(vector<int> &nums) {
  int count = 0;

  for (auto num : nums) {
    if (to_string(num).length() % 2 == 0) {
      count++;
    }
  }

  return count;
};
