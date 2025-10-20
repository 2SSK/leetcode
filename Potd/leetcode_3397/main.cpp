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

  int maxDistinctElements(vector<int> &nums, int k);
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution solution;

  vector<int> input = solution.readInput<int>();
  int k;
  cin >> k;

  cout << "Output: " << solution.maxDistinctElements(input, k) << "\n";

  return 0;
}

int Solution::maxDistinctElements(vector<int> &nums, int k) {
  sort(nums.begin(), nums.end());
  int cnt = 0, prev = INT_MIN;
  for (int num : nums) {
    int curr = min(max(num - k, prev + 1), num + k);
    if (curr > prev) {
      cnt++;
      prev = curr;
    }
  }

  return cnt;
}
