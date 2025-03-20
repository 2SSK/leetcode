// ==================================
//  You will input in the input.txt file
//  Output will be printed in output.txt file
// ==================================

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int removeDuplicates(vector<int> &nums);
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

  cout << "Output: " << s.removeDuplicates(input);

  return 0;
}

int Solution::removeDuplicates(vector<int> &nums) {
  map<int, int> mpp;
  for (auto num : nums) {
    mpp[num]++;
  }

  for (int i = 0; i < nums.size(); i++) {
    if (mpp[nums[i]] > 2) {
      nums.erase(begin(nums) + i);
      mpp[nums[i]]--;
      i--;
    }
  }

  return nums.size();
};
