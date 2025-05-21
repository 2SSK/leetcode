// ==================================
//  You will input in the input.txt file
//  Output will be printed in output.txt file
// ==================================

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

  template <typename T> void printArr(vector<T> arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
      if (i == 0) {
        cout << "[ " << arr[i] << " | ";
      } else if (i == n - 1) {
        cout << arr[i] << " ]\n";
      } else {
        cout << arr[i] << " | ";
      }
    }
  }

  int minSubArrayLen(int target, vector<int> &nums);
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution solution;

  int target = 0;
  cin >> target;
  cin.ignore();

  vector<int> input = solution.readInput<int>();

  cout << "Output: " << solution.minSubArrayLen(target, input) << endl;

  return 0;
}

int Solution::minSubArrayLen(int target, vector<int> &nums) {
  int n = nums.size();
  if (n == 0) {
    return 0;
  }

  int min_len = INT_MAX;
  int curr_sum = 0;
  int left = 0;

  for (int right = 0; right < n; right++) {
    curr_sum += nums[right];

    while (curr_sum >= target) {
      min_len = min(min_len, right - left + 1);
      curr_sum -= nums[left];
      left++;
    }
  }

  return min_len == INT_MAX ? 0 : min_len;
};
