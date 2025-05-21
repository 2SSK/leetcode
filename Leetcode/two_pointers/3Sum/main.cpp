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

  template <typename T> void printSuperArr(vector<vector<T>> arr) {
    int n = arr.size();
    cout << "[\n";
    for (int i = 0; i < n; i++) {
      printArr(arr[i]);
    }
    cout << "]";
  }

  vector<vector<int>> threeSum(vector<int> &nums);
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution solution;

  vector<int> input = solution.readInput<int>();

  vector<vector<int>> output = solution.threeSum(input);

  cout << "Output: ";
  solution.printSuperArr(output);

  return 0;
}

vector<vector<int>> Solution::threeSum(vector<int> &nums) {
  int n = nums.size();
  vector<vector<int>> result;

  sort(begin(nums), end(nums));

  for (int i = 0; i < n - 2; i++) {
    if (i > 0 && nums[i] == nums[i - 1])
      continue;

    int left = i + 1, right = n - 1;
    while (left < right) {
      int sum = nums[i] + nums[left] + nums[right];

      if (sum == 0) {
        result.push_back({nums[i], nums[left], nums[right]});

        while (left < right && nums[left] == nums[left + 1])
          left++;

        while (left < right && nums[right] == nums[right - 1])
          right--;

        left++;
        right--;
      } else if (sum < 0) {
        left++;
      } else {
        right--;
      }
    }
  }

  return result;
};
