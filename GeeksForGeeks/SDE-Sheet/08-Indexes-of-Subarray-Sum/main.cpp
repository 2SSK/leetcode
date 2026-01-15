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
    if (n <= 1) {
      cout << "[ " << arr[0] << " ]\n";
    } else {
      for (int i = 0; i < n; i++) {
        if (i == 0) {
          cout << "[ " << arr[i] << ", ";
        } else if (i == n - 1) {
          cout << arr[i] << " ]\n";
        } else {
          cout << arr[i] << ", ";
        }
      }
    }
  }

  vector<int> subarraySum(vector<int> &arr, int target) {
    int left = 0;
    int sum = 0;

    for (int right = 0; right < arr.size(); right++) {
      sum += arr[right];

      while (sum > target && left <= right) {
        sum -= arr[left];
        left++;
      }

      if (sum == target) {
        return vector<int>(arr.begin() + left, arr.begin() + right + 1);
      }
    }

    return vector<int>(1, -1);
  }
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution solution;

  int test_cases;
  cin >> test_cases;
  cin.ignore();

  while (test_cases--) {
    vector<int> arr = solution.readInput<int>();
    int target;
    cin >> target;
    cin.ignore();

    vector<int> output = solution.subarraySum(arr, target);
    cout << "Output: ";
    solution.printArr(output);
  }

  return 0;
}
