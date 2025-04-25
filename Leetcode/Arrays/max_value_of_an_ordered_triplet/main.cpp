// ==================================
//  You will input in the input.txt file
//  Output will be printed in output.txt file
// ==================================

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  long long maximumTripletValue(vector<int> &nums);
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution s;

  int size;
  cin >> size;

  vector<int> nums(size);
  for (int i{}; i < size; i++) {
    cin >> nums[i];
  }

  cout << "Output: " << s.maximumTripletValue(nums) << endl;

  return 0;
}

long long Solution::maximumTripletValue(vector<int> &nums) {
  int n = nums.size();
  if (n < 3)
    return 0;

  long long max_value = LLONG_MIN;

  for (int i = 0; i < n - 2; i++) {
    for (int j = i + 1; j < n - 1; j++) {
      for (int k = j + 1; k < n; k++) {
        long long curr_value = (nums[i] - nums[j]) * nums[k];
        max_value = max(max_value, curr_value);
      }
    }
  }

  return max_value;
};
