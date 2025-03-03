// ==================================
//  You will input in the input.txt file
//  Output will be printed in output.txt file
// ==================================

#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  long long subArrayRanges(vector<int> &nums);
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

  cout << "Output = " << s.subArrayRanges(input) << "\n";

  return 0;
}

long long Solution::subArrayRanges(vector<int> &nums) {
  int size = nums.size();
  long long totalRange{};

  for (int i{}; i < size; i++) {
    long long maxi{nums[i]}, mini{nums[i]};

    for (int j{i}; j < size; j++) {
      maxi = max(maxi, (long long)nums[j]);
      mini = min(mini, (long long)nums[j]);

      totalRange += maxi - mini;
    }
  }

  return totalRange;
};
