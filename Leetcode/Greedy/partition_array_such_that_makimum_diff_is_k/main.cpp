// ==================================
//  You will input in the input.txt file
//  Output will be printed in output.txt file
// ==================================

#include <bits/stdc++.h>
using namespace std;

class Utils {
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
};

class Solution : public Utils {
public:
  int partitionArray(vector<int> &nums, int k);
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution solution;

  vector<int> input = solution.readInput<int>();
  int k;
  cin >> k;

  cout << "Output: " << solution.partitionArray(input, k);

  return 0;
}

int Solution::partitionArray(vector<int> &nums, int k) {
  sort(nums.begin(), nums.end());
  int count = 0;
  int i = 0;
  int n = nums.size();

  while (i < n) {
    int start = nums[i];
    count++;
    i++;

    while (i < n && nums[i] - start <= k) {
      i++;
    }
  }

  return count;
}
