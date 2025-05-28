#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  template <typename T> vector<T> readInput() {
    vector<T> input;
    string line;
    getline(cin, line);
    stringstream ss(line);
    T value;
    while (ss >> value) {
      input.push_back(value);
    }
    return input;
  }

  int maxSubArray(vector<int> &nums);
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution sol;

  vector<int> input = sol.readInput<int>();

  cout << "Output: " << sol.maxSubArray(input);

  return 0;
}

int Solution::maxSubArray(vector<int> &nums) {
  int n = nums.size();
  if (n == 0)
    return 0;

  int maxSum = nums[0];
  int currSum = nums[0];

  for (int i = 0; i < n; i++) {
    currSum = max(nums[i], currSum + nums[i]);
    maxSum = max(maxSum, currSum);
  }

  return maxSum;
};
