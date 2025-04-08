// ==================================
//  You will input in the input.txt file
//  Output will be printed in output.txt file
// ==================================

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int trap(vector<int> &arr);
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution solution;

  vector<int> arr;
  string input;
  getline(cin, input);
  stringstream ss(input);
  int value;
  while (ss >> value) {
    arr.push_back(value);
  }

  cout << "Output: " << solution.trap(arr);

  return 0;
}

int Solution::trap(vector<int> &arr) {
  int size = arr.size();
  if (size <= 0)
    return 0;

  int l = 0, r = size - 1;
  int lMax = 0, rMax = 0;
  int total = 0;

  while (l <= r) {
    if (arr[l] <= arr[r]) {
      if (arr[l] >= lMax) {
        lMax = arr[l];
      } else {
        total += lMax - arr[l];
      }
      l++;
    } else {
      if (arr[r] >= rMax) {
        rMax = arr[r];
      } else {
        total += rMax - arr[r];
      }
      r--;
    }
  }

  return total;
}
