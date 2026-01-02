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

  int maxSubarraySum(vector<int> &arr, int k);
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution solution;

  vector<int> input = solution.readInput<int>();
  int k;
  cin >> k;

  cout << "Output: " << solution.maxSubarraySum(input, k) << endl;

  return 0;
}

int Solution::maxSubarraySum(vector<int> &arr, int k) {
  int n = arr.size();

  if (n < k)
    return 0;

  int sum = 0;
  for (size_t i = 0; i < k; i++) {
    sum += arr[i];
  }

  int maxSum = sum;

  for (int i = k; i < n; i++) {
    sum = sum - arr[i - k] + arr[i];
    maxSum = max(maxSum, sum);
  }

  return maxSum;
}
