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

  int maxIncreasingSubarrays(vector<int> &nums);
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution solution;

  vector<int> input = solution.readInput<int>();

  cout << "Output: " << solution.maxIncreasingSubarrays(input);

  return 0;
}

int Solution::maxIncreasingSubarrays(vector<int> &nums) {
  int n = nums.size();
  int count = 1, k = 0, ans = 0;

  for (int i = 1; i < n; ++i) {
    int currCount = 0;
    if (nums[i] > nums[i - 1]) {
      ++count;
    } else {
      k = count;
      count = 1;
    }
    ans = max(ans, min(k, count));
    ans = max(ans, count / 2);
  }

  return ans;
}
