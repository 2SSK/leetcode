// ==================================
//  You will input in the input.txt file
//  Output will be printed in output.txt file
// ==================================

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  template <typename T> vector<T> readInput() {
    vector<T> inputArr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    T value;
    while (ss >> value) {
      inputArr.push_back(value);
    }

    return inputArr;
  }

  template <typename T> void printArr(vector<T> arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
      if (i == 0) {
        cout << "[ " << arr[i] << " | ";
      } else if (i == n - 1) {
        cout << arr[i] << " ]\n";
      } else {
        cout << arr[i] << " | ";
      }
    }
  }

  int maxArea(vector<int> &height);
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution solution;

  vector<int> input = solution.readInput<int>();

  int output = solution.maxArea(input);

  cout << "Output: " << output << "\n";

  return 0;
}

int Solution::maxArea(vector<int> &height) {
  int size = height.size();
  int l = 0;
  int r = size - 1;
  int max_area = 0;

  while (l < r) {
    int width = r - l;
    int current_height = min(height[l], height[r]);
    int current_area = width * current_height;
    max_area = max(max_area, current_area);

    if (height[l] < height[r]) {
      ++l;
    } else {
      --r;
    }
  }

  return max_area;
};
