// ==================================
//  You will input in the input.txt file
//  Output will be printed in output.txt file
// ==================================

#include <bits/stdc++.h>
#include <iterator>
using namespace std;

class Solution {
public:
  void printArr(vector<int> arr);
  // Brute Force
  vector<int> maxSlidingWindow(vector<int> &nums, int k);
  // Optimal
  vector<int> optimal_maxSlidingWindow(vector<int> &nums, int k);
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution s;

  // No. of inputs
  int size;
  cin >> size;

  // Array of inputs
  vector<int> input(size);
  for (int i{}; i < size; i++) {
    cin >> input[i];
  }

  // sliding window size
  int k;
  cin >> k;

  // ouput
  vector<int> output = s.optimal_maxSlidingWindow(input, k);
  cout << "Output: ";
  s.printArr(output);

  return 0;
}

vector<int> Solution::optimal_maxSlidingWindow(vector<int> &nums, int k) {
  int size = nums.size();
  vector<int> maxArr;
  deque<int> dq;

  for (int i{}; i < size; i++) {
    if (!dq.empty() && dq.front() == i - k) {
      dq.pop_front();
    }

    while (!dq.empty() && nums[dq.back()] < nums[i]) {
      dq.pop_back();
    }

    dq.push_back(i);

    if (i >= k - 1) {
      maxArr.push_back(nums[dq.front()]);
    }
  }

  return maxArr;
}

vector<int> Solution::maxSlidingWindow(vector<int> &nums, int k) {
  int size = nums.size();

  // If array has only one element: return the array
  if (size == 1) {
    return nums;
  }

  // If array is smaller or equal to window return the max element
  if (size <= k) {
    int max = *std::max_element(nums.begin(), nums.end());
    return {max};
  }

  vector<int> maxArr;

  for (int i{}; i < size; i++) {
    if (i + k <= size) {
      int max = *std::max_element(begin(nums) + i, begin(nums) + i + k);
      maxArr.push_back(max);
    }
  }

  return maxArr;
};

void Solution::printArr(vector<int> arr) {
  int size = arr.size();

  cout << "| ";
  for (int i{}; i < size; i++) {
    if (i < size - 1)
      cout << arr[i] << " | ";
    else
      cout << arr[i] << " |\n";
  }
}
