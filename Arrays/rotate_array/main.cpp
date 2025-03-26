// ==================================
//  You will input in the input.txt file
//  Output will be printed in output.txt file
// ==================================

#include <bits/stdc++.h>
#include <utility>
using namespace std;

class Solution {
public:
  void rotate(vector<int> &nums, int k);
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  // Object of Solution class
  Solution s;

  // Size of input array
  int size;
  cin >> size;

  // Input Array
  vector<int> nums(size);
  for (int i{}; i < size; i++) {
    cin >> nums[i];
  }

  // Take `K`
  int k;
  cin >> k;

  // Call the rotate function
  s.rotate(nums, k);

  // Print the output
  cout << "\nOutput : ";
  for (int i = 0; i < size; i++) {
    if (i == 0) {
      cout << "| " << nums[i];
    } else if (i == (size - 1)) {
      cout << " | " << nums[i] << " |\n";
    } else {
      cout << " | " << nums[i];
    }
  }

  return 0;
}

void Solution::rotate(vector<int> &nums, int k) {
  int n = nums.size();

  if (n == 0 || n == k)
    return;

  k %= n;
  if (k < 0)
    k += n;

  auto reverse = [&](int start, int end) {
    while (start < end) {
      swap(nums[start++], nums[end--]);
    }
  };

  reverse(0, n - 1);
  reverse(0, k - 1);
  reverse(k, n - 1);
}
