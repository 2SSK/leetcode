// ==================================
//  You will input in the input.txt file
//  Output will be printed in output.txt file
// ==================================

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool canJump(vector<int> &nums);
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

  cout << "Output: " << boolalpha << s.canJump(input) << endl;

  return 0;
}

bool Solution::canJump(vector<int> &nums) {
  int size = nums.size();
  int maxReach = 0;

  for (int i{}; i < size && i <= maxReach; i++) {
    maxReach = max(maxReach, i + nums[i]);

    if (maxReach >= size - 1)
      return true;
  }

  return maxReach >= size - 1;
};
