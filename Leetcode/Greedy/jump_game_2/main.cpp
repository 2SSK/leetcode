// ==================================
//  You will input in the input.txt file
//  Output will be printed in output.txt file
// ==================================

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int jump(vector<int> &nums);
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

  cout << "Output: " << s.jump(nums) << endl;

  return 0;
}

int Solution::jump(vector<int> &nums) {
  int n = nums.size();
  if (n == 1)
    return 0;

  int jumps = 0;
  int currentEnd = 0;
  int farthest = 0;

  for (int i = 0; i < n - 1; i++) {
    farthest = max(farthest, i + nums[i]);

    if (i == currentEnd) {
      jumps++;
      currentEnd = farthest;

      if (currentEnd >= n - 1) {
        break;
      }
    }
  }

  return jumps;
};
