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

  int minOperations(vector<int> &nums);
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution solution;

  vector<int> input = solution.readInput<int>();

  cout << "Output: " << solution.minOperations(input) << "\n";

  return 0;
}

int Solution::minOperations(vector<int> &nums) {
  int n = nums.size();
  int num1 = 0;
  int g = 0;

  for (int x : nums) {
    if (x == 1) {
      num1++;
    }
    g = gcd(g, x);
  }

  if (num1 > 0) {
    return n - num1;
  }

  if (g > 1) {
    return -1;
  }

  int min_len = n;
  for (int i = 0; i < n; i++) {
    int g = 0;
    for (int j = i; j < n; j++) {
      g = gcd(g, nums[j]);
      if (g == 1) {
        min_len = min(min_len, j - i + 1);
        break;
      }
    }
  }

  return n - 1 + min_len - 1;
}
