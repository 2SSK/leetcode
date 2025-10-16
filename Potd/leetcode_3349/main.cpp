#include <bits/stdc++.h>
#include <ios>
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

  bool hasIncreasingSubarrays(vector<int> &nums, int k);
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution solution;

  vector<int> input = solution.readInput<int>();
  int k;
  cin >> k;

  cout << "Output: " << boolalpha << solution.hasIncreasingSubarrays(input, k);

  return 0;
}

bool Solution::hasIncreasingSubarrays(vector<int> &nums, int k) {
  int n = nums.size();
  if (2 * k > n)
    return false;

  int cur = 1;
  int prev = 0;

  for (int i = 1; i < n; ++i) {
    if (nums[i] > nums[i - 1]) {
      ++cur;
    } else {
      if (cur / 2 >= k || min(prev, cur) >= k) {
        return true;
      }
      prev = cur;
      cur = 1;
    }
  }

  if (cur / 2 >= k || min(prev, cur) >= k) {
    return true;
  }

  return false;
}
