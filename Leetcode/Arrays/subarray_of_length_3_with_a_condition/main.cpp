// ==================================
//  You will input in the input.txt file
//  Output will be printed in output.txt file
// ==================================

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int countSubarrays(vector<int> &nums);

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

  cout << "Output: " << solution.countSubarrays(input) << endl;

  return 0;
}

int Solution::countSubarrays(vector<int> &nums) {
  int n = nums.size();

  int output = 0;

  for (int i = 0; (i + 2) < n; i++) {
    if ((nums[i] + nums[i + 2]) * 2 == nums[i + 1]) {
      output++;
    }
  }

  return output;
};
