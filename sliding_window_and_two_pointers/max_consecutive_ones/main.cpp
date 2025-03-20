// ==================================
//  You will input in the input.txt file
//  Output will be printed in output.txt file
// ==================================

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int longestOnes(vector<int> &nums, int k);
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution s;

  int size;
  cin >> size;

  vector<int> input(size);
  for (int i{}; i < size; i++) {
    cin >> input[i];
  }

  int k;
  cin >> k;

  cout << "Output: " << s.longestOnes(input, k) << "\n";

  return 0;
}

int Solution::longestOnes(vector<int> &nums, int k) {
  int maxLen = 0;
  int l = 0, r = 0;
  int zeros = 0;

  while (r < nums.size()) {
    if (nums[r] == 0)
      zeros++;
    while (zeros > k) {
      if (nums[l] == 0)
        zeros--;
      l++;
    }
    if (zeros <= k) {
      int len = r - l + 1;
      maxLen = max(maxLen, len);
    }

    r++;
  }

  return maxLen;
}

int longestOnes(vector<int> &nums, int k) {
  int i{0}, j{0};

  while (j < nums.size()) {
    if (nums[j] == 0) {
      k--;
    }
    if (k < 0) {
      if (nums[i] == 0) {
        k++;
      }
      i++;
    }
    j++;
  }
  return j - i;
}
