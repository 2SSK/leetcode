// ==================================
//  You will input in the input.txt file
//  Output will be printed in output.txt file
// ==================================

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  // Brute-force Approach
  int trap(vector<int> &height);
  vector<int> prefixMax(vector<int> &arr);
  vector<int> suffixMax(vector<int> &arr);

  // Optimal Approach
  int trapOptimal(vector<int> &arr);
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution s;

  int size;
  cin >> size;

  vector<int> arr(size);
  for (int i{}; i < size; i++) {
    cin >> arr[i];
  }

  int result = s.trapOptimal(arr);
  cout << "Result : " << result << "\n";

  return 0;
}

int Solution::trapOptimal(vector<int> &arr) {
  int n = arr.size();
  // Edge case : Empty array
  if (n == 0)
    return 0;

  // Variables
  int lMax{}, rMax{}, total{};
  // Pointers
  int l{}, r{n - 1};

  while (l < r) {
    if (arr[l] <= arr[r]) {
      if (lMax > arr[l]) {
        total += lMax - arr[l];
      } else {
        lMax = arr[l];
      }
      l++;
    } else {
      if (rMax > arr[r]) {
        total += rMax - arr[r];
      } else {
        rMax = arr[r];
      }
      r--;
    }
  }

  return total;
}

int Solution::trap(vector<int> &height) {
  int total{};
  vector<int> leftMax = prefixMax(height);
  vector<int> rightMax = suffixMax(height);

  for (int i{}; i < height.size(); i++) {
    if (height[i] < leftMax[i] && height[i] < rightMax[i]) {
      total += min(leftMax[i], rightMax[i]) - height[i];
    }
  }

  return total;
};

vector<int> Solution::prefixMax(vector<int> &arr) {
  int size = arr.size();
  vector<int> prefix(size);

  prefix[0] = 0;

  for (int i{}; i < size; i++) {
    prefix[i] = max(prefix[i - 1], arr[i]);
  };

  return prefix;
}

vector<int> Solution::suffixMax(vector<int> &arr) {
  int size = arr.size();
  vector<int> suffix(size);

  suffix[-1] = arr[-1];

  for (int i{size - 1}; i >= 0; i--) {
    suffix[i] = max(suffix[i + 1], arr[i]);
  }

  return suffix;
}
