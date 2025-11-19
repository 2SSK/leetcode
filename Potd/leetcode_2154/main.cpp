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

  bool binarySearch(vector<int> arr, int target);

  int findFinalValue(vector<int> &nums, int original);
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution solution;

  vector<int> input = solution.readInput<int>();

  int original;
  cin >> original;

  cout << "Output: " << solution.findFinalValue(input, original) << "\n";

  return 0;
}

int Solution::findFinalValue(vector<int> &nums, int original) {
  int target = original;

  while (binarySearch(nums, target)) {
    target *= 2;
  }

  return target;
}

bool Solution::binarySearch(vector<int> arr, int target) {
  sort(arr.begin(), arr.end());

  int start = 0;
  int end = arr.size() - 1;

  while (start <= end) {
    int mid = start + (end - start) / 2;

    if (arr[mid] == target) {
      return true;
    } else if (arr[mid] < target) {
      start = mid + 1;
    } else {
      end = mid - 1;
    }
  }

  return false;
}
